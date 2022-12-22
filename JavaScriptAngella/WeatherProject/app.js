const { query } = require('express');
const express = require('express');
const https = require("https"); // native node module.
const bodyParser = require("body-parser");
const app = express();

app.use(bodyParser.urlencoded({extended : true}));

app.get("/" , function(req,res) {
    res.sendFile(__dirname + "/index.html");
});

app.post("/", (req,res) => {
    // console.log(req.body.cityName);
    const query = req.body.cityName;
    const apiKey = "938e81f84bcefaee1886881eab6c2823";
    const unit = "metric"
    const url = "https://api.openweathermap.org/data/2.5/weather?q="+ query +"&appid=" + apiKey + "&units=" + unit;
    https.get(url, (response) => {
        // console.log(response.statusCode);
        response.on("data" , function(data) {
            // const object  = {
                //     name : "Atul",
                //     favouriteFood : "Shahi Panner"
                // }
                // console.log(JSON.stringify(object));
            const weatherData = JSON.parse(data);
            const temp = weatherData.main.temp;
            const description = weatherData.weather[0].description;
            const icon = weatherData.weather[0].icon;
            const imgURL = "http://openweathermap.org/img/wn/" + icon + "@2x.png";
            // so for multiple things to send use write method.
            res.write("<p>The Weather is currently " + description + " </p>");
            res.write("<h1>The Temperature in "+ query + " is " + temp + " degrees Celcius.</h1>")
            res.write("<img src =" + imgURL + ">");
            res.send();
        });
    });
});

app.listen(3000,function(){
    console.log("Server is running on port 3000");
});