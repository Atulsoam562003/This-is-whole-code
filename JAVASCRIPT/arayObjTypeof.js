let name = "Atul";
console.log("My string is " + name);
console.log("Data type is " + (typeof name));

// Numbers
let numbers = 12;
console.log("Data type is " + (typeof numbers));

// bool
let isDriver = true;
console.log("Data type is " + (typeof isDriver));

//NULL
let null_var = null; //* in JS the null is in the small letters
console.log("Data type is " + (typeof null_var));

// Undefined
let undef = undefined;
console.log("Data type is " + (typeof undef));

//TODO: NOW! REFERENCE DATATYPES
//* C/C++ , JAVA... are statically typed but JS and Python are dynamically typed

let myarr = [1,2,'3',"4",true,null,0]; //arrays
console.log(typeof myarr);
console.log(myarr);

//Object literals
let marks = {
    harry:34,
    Atul :50,
    Akash : 50 //* if Akash Soam then error so for that 'Akash soam' ==> now correct
};
console.log(marks);
console.log(typeof marks);

function findName() {

}
console.log(typeof findName);

let date = new Date();
console.log(typeof date);





