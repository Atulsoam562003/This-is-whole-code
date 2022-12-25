require("dotenv").config();
const express = require("express");
const bodyParser = require("body-parser");
const ejs = require("ejs");
const mongoose = require("mongoose");
const session = require("express-session");
const passport = require("passport");
const passportLocalMongoose = require("passport-local-mongoose");
const GoogleStrategy = require('passport-google-oauth20')
const findOrCreate = require('mongoose-findorcreate');

const app = express();
``
app.use(express.static("public"));
app.set('view engine' , 'ejs');
app.use(bodyParser.urlencoded({
    extended : true
}));

app.use(session({
    secret : "Our little secret." ,
    resave : false ,
    saveUninitialized : false
}));

app.use(passport.initialize());
app.use(passport.session());

mongoose.set('strictQuery' , true);
mongoose.connect("mongodb://localhost:27017/userDB");

const userSchema = new mongoose.Schema ({
    email : String,
    password : String ,
    googleId : String,
    secret : String
});

userSchema.plugin(passportLocalMongoose);
userSchema.plugin(findOrCreate);

const User = new mongoose.model("User" ,userSchema);

passport.use(User.createStrategy());

passport.serializeUser((user,done) => {
    done(null,user.id);
});
passport.deserializeUser((id,done) => {
    User.findById(id,(err,user) => {
        done(err,user);
    });
});

passport.use(new GoogleStrategy({
    clientID : process.env.CLIENT_ID ,
    clientSecret : process.env.CLIENT_SECRET ,
    callbackURL : "http://localhost:3000/auth/google/secrets" ,
    userProfileURL : "https://www.googleapis.com/oauth2/v3/userinfo"
    },
    (accessToken,refreshToken,profile,cb) => {
        console.log(profile);

        User.findOrCreate({googleId : profile.id} , (err,user) => {
            return cb(err,user);
        });
    }
));

app.get("/" , (req,res) => {
    res.render('home');
});

app.get("/login" , (req,res) => {
    res.render('login');
});
app.get("/register" , (req,res) => {
    res.render('register');
});

app.get("/secrets" ,(req,res) => {
    User.find({"secret": {$ne : null}} , (err,foundUsers) => {
        if(err) console.log(err);
        else
            if(foundUsers)
                res.render("secrets" ,{userWithSecrets : foundUsers});
    });
});

app.get("/submit" ,(req,res) => {
    if(req.isAuthenticated()) res.render("submit");
    else res.redirect("/login");
})

app.get('/logout', function (req, res){
    req.session.destroy(function (err) {
      res.redirect('/');
    });
});

app.post('/submit' ,(req,res) => {
    const submittedSecret = req.body.secret;
    User.findById(req.user.id , (err,foundUser) => {
        if(err) console.log(err);
        else
            if(foundUser) {
                foundUser.secret = submittedSecret;
                foundUser.save(() => {
                    res.redirect("/secrets");
                });
            }
    });
});

app.get('/auth/google',
  passport.authenticate('google', { scope: ['profile'] }));

app.get('/auth/google/secrets',
  passport.authenticate('google', { failureRedirect: '/login' }),
  function(req, res) {
    // Successful authentication, redirect home.
    res.redirect('/secrets');
  });

app.post("/register" , (req,res) => {
    User.register({username : req.body.username} ,req.body.password ,(err,user) => {
        if(err) {
            console.log(err);
            res.redirect("/register");
        } else {
            passport.authenticate("local")(req,res,() => {
                res.redirect("secrets");
            });
        }
    });
})

app.post("/login" ,(req,res) => {
    const user = new User({
        username : req.body.username ,
        password : req.body.password
    });

    req.login(user, (err) => {
        if(err) console.log(err);
        else
            passport.authenticate("local")(req,res ,() => {
                res.redirect('/secrets');
            });
    });

});

app.listen(process.env.PORT || 3000 , () => {
    console.log("Sever is started at port 3000.");
})