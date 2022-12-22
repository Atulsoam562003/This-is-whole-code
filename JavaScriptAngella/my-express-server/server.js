const express = require("express");
const app = express();
// it listen to a specific port for any HTTP request that get send to our server.
// "/" represent root or home page of the website.
app.get("/",function(request,response){ // what will happens when our browser makes a get request in touch of our server.
    // console.log(request);
    response.send("<h1>Hello World!</h1>"); // send method to send a response.
});

app.get("/contact",function(req,res){
    res.send("Contact me at : atul@gmail.com");
});

app.get("/about",function(req,res){
    res.send("I am Atul Soam !");
});

app.listen(3000,function(){
    console.log("Server started on port 3000");
});
