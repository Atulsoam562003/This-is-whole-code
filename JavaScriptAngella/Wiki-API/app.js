const express = require("express");
const bodyParser = require(`body-parser`);
const mongoose = require("mongoose");
const { log } = require("console");

mongoose.set('strictQuery',true);

const app = express();

app.set('view engine' ,'ejs');
app.use(bodyParser.urlencoded({extended : true}));
app.use(express.static("public"));

mongoose.connect('mongodb://localhost:27017/wikiDB');

const articlesSchema = {
    title : String ,
    content : String
}

const Article = mongoose.model("Article" , articlesSchema);

// Request targeting all Article.

app.route("/articles")
    .get((req,res) =>{
        Article.find({},(err,foundArticles) => {
            if(!err)
                res.send(foundArticles);
            else res.send(err);
        })
    })
    .post(function(req,res) {
        const newArticle = new Article({
            title : req.body.title ,
            content : req.body.content
        });
        newArticle.save(function(err) {
            if(!err)
                res.send("Successfully send a new Article.")
            else res.send(err);
        });
    })
    .delete((req,res)=> {
        Article.deleteMany({},function(err) {
            if(!err) res.send("Successfully deleted all articles");
            else res.send(err);
        });
    });

// Request targeting specific Article.

app.route("/articles/:articleTitle")
    .get(function(req,res) {
        Article.findOne({title : req.params.articleTitle} ,function(err,foundArticle){
            if(foundArticle) res.send(foundArticle);
            else console.log("No Articles matching that title was found");
        });
    })
    .put(function(req,res) {
            Article.findOneAndUpdate(
            {title : req.params.articleTitle} ,
            {title : req.body.title , content : req.body.content} ,
            {overwrite : true} ,
            function(err) {
                if(!err) res.send("Successfully updated Article");
            }
        );
    })
    .patch(function(req,res) {
        Article.findOneAndUpdate(
            {title : req.params.articleTitle} ,
            {$set : req.body} ,
            function(err) {
                if(!err) res.send("Successfully updated Article")
                res.send(err);
            }
        );
    })
    .delete((req,res) => {
        Article.findOneAndDelete({title : req.params.articleTitle} ,(err) => {
            if(!err) res.send("Successfully Deleted Article!")
            else res.send(err);
        });
    });

app.listen(process.env.PORT || 3000 , function() {
    console.log("Server started on port 3000");
});
