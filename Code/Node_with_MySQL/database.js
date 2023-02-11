const {createPool} = require('mysql');

const pool = createPool({
    host : "localhost" ,
    user : "root" ,
    password : "root" ,
    database : "btech",
    connectionLimit :10
});

pool.query(`select * from class where fid = ?`,[489221823] , (err,result , fields)=>{
    if(err) return console.log(err);
    return console.log(result);
});

module.exports = pool;
