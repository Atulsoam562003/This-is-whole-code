const db = require("./connection");
const prompt = require("prompt-sync")({ sigint: true });

const room_name = prompt("Enter the room name :");

db.query(`select name from class where room = ${room_name}`,[] , (err,result, fields) => {
    if(err) console.log(err.message);
    else console.log(result);
});