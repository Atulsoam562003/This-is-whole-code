const {createPool}  = require('mysql');

const pool = createPool({
    host : "localhost" ,
    user : "root" ,
    password : "root" ,
    database :"btech",
    connectionLimit : 10
});

module.exports = pool;

