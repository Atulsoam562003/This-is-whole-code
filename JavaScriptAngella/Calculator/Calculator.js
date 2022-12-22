const express = require("express");
const bodyParser = require('body-parser');
const app = express();

app.use(bodyParser.urlencoded({extended : true}));

app.get("/",function(req,res){
    res.sendFile(__dirname + "/index.html");
});

app.post("/index.html",function(req,res){
    // [|||||] --> MiddleWare --> Browser //* and that middle ware is the BODY PARSER

    var num1 = Number(req.body.n1);
    var num2 = Number(req.body.n2);

    var result = num1 + num2;
    res.send("The result of the calculation is " + result);
});


app.get("/bmicalculator",function(req,res){
    res.sendFile(__dirname + "/bmiCalculator.html")
});

app.post("/bmicalculator",function(req,res){
    var weight = parseFloat(req.body.weight);
    var height = parseFloat(req.body.height);

    var bmi = weight / (height * height);
    res.send("Your BMI is: " + bmi);
});

app.listen(3000,function(){
    console.log("Sever is running on port 3000");
});