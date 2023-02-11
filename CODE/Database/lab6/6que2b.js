const db = require("./connection");
const prompt = require("prompt-sync")({ sigint: true });

const course_name = prompt("Enter the course name :");

db.query(`select room , meet_at from class where name = ${course_name}`,[] , (err,result, fields) => {
    if(err) console.log(err.message);
    else console.log(result);
});

