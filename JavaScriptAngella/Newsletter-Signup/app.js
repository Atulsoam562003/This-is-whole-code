const express = require('express');
const bodyParser = require("body-Parser");
const request = require('request');
const https = require("https");
const app = express();

app.use(bodyParser.urlencoded({extended : true}));

app.use(express.static("public"));

app.get("/" , function(req,res) {
    res.sendFile(__dirname + "/signup.html");
});

app.post("/",function(req,res) {
    const firstName = req.body.fName;
    const lastName = req.body.lName;
    const email = req.body.email;

    var data = {
        members : [
            {
                email_address : email ,
                status : "subscribed"
            }
        ]
    };
    var jsonData = JSON.stringify(data);

    const options =  {
        url : "https://us12.api.mailchimp.com/3.0/lists/57e7cee4e3",
        method : "POST" ,
        headers : {
            "Authorization" : "Atul 5590d8e61c37caaca35d84b7649cc257-us12"
        },
        body : jsonData
    }

    request(options, function(error , response ,body) {
        if(error) console.log(error);
        else console.log(response.statusCode);
    })
});

app.listen(process.env.PORT || 3000 ,() =>{
    console.log("Server is running on port 3000");
});


//API key -> eabdc1d0bd58c77094d040448d7d85e7-us12
//List ID -> 57e7cee4e3