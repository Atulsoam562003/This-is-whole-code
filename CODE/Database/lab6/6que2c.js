const db = require("./connection");
const prompt = require("prompt-sync")({ sigint: true });

const faculty_name = prompt("Enter the faculty name :");

db.query(`select name from class natural join faculty where fname =  ${faculty_name}`,[] , (err,result, fields) => {
    if(err) console.log(err.message);
    else console.log(result);
});