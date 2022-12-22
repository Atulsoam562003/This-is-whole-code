/* one way to use Mongo DB is
* native mongoDB driver
 const MongoClient = require("mongodb").MongoClient;
 const { equal } = require("assert");
 const assert = require(`assert`);
 const { log } = require("console");
*/

const mongoose = require('mongoose');
mongoose.set('strictQuery', true);
mongoose.connect(`mongodb://localhost:27017/fruitsDB`);

const fruitsSchema = new mongoose.Schema({
    name : {
        type : String ,
        required : [true , 'Please provide the name']
    } ,
    rating :{
        type : Number ,
        min : 1,
        max : 10
    } ,
    review : String
});

const Fruit = mongoose.model("Fruit" , fruitsSchema);
// now creating the document from the model.
// const fruit = new Fruit ({
//     name : "Apple" ,
//     rating : 9 ,
//     review : "Pretty solid as a fruit !"
// })
const fruit = new Fruit ({
    rating : 10 ,
    review : "Peaches are so yummy!"
})
// fruit.save();

const personSchema = new mongoose.Schema({
    name : String ,
    age : Number ,
    favoriteFruit : fruitsSchema
});

const Person = mongoose.model("Person" , personSchema);

const pineapple = new Fruit({
    name : "PineApple" ,
    score : 9 ,
    review : "Great Fruit"
});

pineapple.save();

Person.updateOne({name : "Atul"} , {favoriteFruit : pineapple}, (err) => {
    if(err) console.log(err);
    else console.log("Updation Done!");
})
// const person = new Person ({
//     name : "Atul" ,
//     age : 19 ,
//     favoriteFruit : pineapple
// })
// person.save();

const kiwi = new Fruit ({
    name : "kiwi" ,
    score : 10 ,
    review : "the Best Fruit!"
})
const orange = new Fruit ({
    name : "orange" ,
    score : 9 ,
    review : "Too sour to me!"
})
const banana = new Fruit ({
    name : "banana" ,
    score : 10 ,
    review : "best best best Awesome !"
})

// Fruit.insertMany([kiwi,orange,banana] ,(err) => {
//     if(err) console.log(err);
//     else console.log("Successfully saved all the fruits to FruitsDB");
// })

Fruit.find((err,fruits) => {
    if(err) console.log(err);
    else {
        mongoose.connection.close();

        fruits.forEach(fruit => {
            console.log(fruit.name);
        });
    }
})

// Fruit.updateOne({_id :"63a097f2ca833c6c1e6651a2"} ,{name : "Peach"} ,(err) => {
//     if(err) console.log(err);
//     else console.log(`Successfully Updated the Document`);
// });

// Fruit.deleteOne({_id : "63a097f2ca833c6c1e6651a2"} , (err) => {
//     if(err) console.log(err);
//     else console.log("successfully Deleted");
// })

// Person.deleteMany({name : "Atul"} , (err) => {
//     if(err) console.log(err);
//     else console.log("Successfully Deleted All!");
// })








// Connection URL
/*const url = 'mongodb://localhost:27017';

// database name
const dbName = 'fruitsDB';

// Create a new mongoClient
const client = new MongoClient(url, {useNewUrlParser : true});

// use connect method to connect to client
client.connect(function(err){
    assert.equal(null,err);
    console.log('connected Successfully to server');

    const db = client.db(dbName);

    findDocument(db,function () {
        client.close();
    })

}); */

/* const insertDocuments = function(db,callback) {
    // get the document collection
    const collection = db.collection('fruits');

    collection.insertMany ([
        {
            name : "Apple" ,
            score : 8 ,
            review : "Great Fruit"
        } ,
        {
            name : "Orange" ,
            score: 6,
            review : "Kinda sour"
        } ,
        {
            name : "Banana" ,
            score : 9 ,
            review : "Great stuff!"
        }
    ] ,function (err,result) {
        assert.equal(err,null);
        // assert.equal(3,result.result.n);
        // assert.equal(3,result.ops.length);
        console.log(`Inserted 3 documents into the collection`);
        callback(result);
      })
} */

const findDocument = function(db,callback) {
    // Get the documents collection
    const collection = db.collection('fruits');
    // find some documents
    collection.find({}).toArray(function(err,fruits){
        assert.equal(err,null);
        console.log("Founds the following records");
        console.log(fruits);
        callback(fruits);
    });
}

