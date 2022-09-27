let Myname = "Atul"; // single and double quotes are same in JS
const greeting = "Good morning Atul";

console.log(greeting + " " + Myname);

Myname = greeting.concat("this",' is my name',Myname);
console.log(Myname);

let html;
/*
html = '<h1> this is heading </h1>
'
*/
console.log(Myname.length);
console.log(Myname.toLowerCase()); //*but original string is always intact it is not going to change
console.log(Myname.toUpperCase());

console.log(Myname[5]);

console.log(Myname.indexOf("Atul"));
console.log(Myname.lastIndexOf("Atul"));
console.log(Myname.charAt(5));

console.log(Myname.endsWith("Atul"));
console.log(Myname.includes("Akash")); // checking wether it is present or not
console.log(Myname.substring(0,12)); //*just like c++ [start,end)
console.log(Myname.slice(-4)); //* give the last four char
console.log(Myname.slice(0,12)); // => same like substr

console.log(Myname.split(' ')); //* ==> space work as an delimiter to slice the string

console.log(Myname.replace("this","it")); //only replace the first occurrence

let fruit1 = "Orange"
let fruit2 = "Apple"
let myHtml = `Hello ${Myname}
            <h1> This is heading </h1>
            <p>You like ${fruit1} and ${fruit2} </p> `;
// document.body.innerHTML = myHtml;

console.log(`My name is Atul soam`);
let first  = "Atul";
let last = "Soam";
console.log(`My name is ${first}. My last name is ${last} .`); //* THIS IS TEMPLATE LITERALS
// in ES 6 template literals \n is same as ==> ENTER
let a = 20;
let b = 30;
console.log(`fifty is ${a + b} and
not ${2*(a + b)} .`);



