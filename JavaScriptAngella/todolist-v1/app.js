const express = require("express");
const bodyParser = require("body-parser");
const date = require(__dirname + "/date.js");

const app = express();
const items = ["Buy Food" , "Cook Food" , "Eat Food"];
let workItems = [];
/* views is the folder where view engine by default will go and look for the files you are trying to render. */
app.set("view engine" , "ejs");

app.use(bodyParser.urlencoded({extended : true}));
app.use(express.static("public"));

app.get("/" ,(req,res) => {
    let day = date.getDate();
    res.render("list", {listTitle : day , newListItems : items});
})
app.post("/" ,(req,res) => {

    let item = req.body.newItem;
    if(req.body.list === "Work") {
        workItems.push(item);
        res.redirect("/work");
    }
    else {
        items.push(item);
        // res.render("list" , {newListItem : item});
        res.redirect("/");
    }
});

app.get("/work", (req,res) => {
    res.render("list",{listTitle : "Work List" , newListItems : workItems});
});

app.listen(3000,function() {
    console.log("Server started at port 3000");
});