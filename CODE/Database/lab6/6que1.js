const db = require("./connection");
const prompt = require("prompt-sync")({ sigint: true });

const table_name = prompt("Enter the table name :");

db.query(`select * from ${table_name}`,[] , (err,result, fields) => {
    if(err) console.log(err.message);
    else console.log(result);
});

