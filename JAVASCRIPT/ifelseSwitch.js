let age = '18';
age = 18;
if(age == 19) console.log("age is 19")
else console.log("not 19")

//* in JS == only checks the value not the type if we want to check both values and types then ===
if(age === 19) console.log("age is 19");
else console.log("not 19");
//* and != and !== also exits in JS
var temp;
console.log(typeof temp);
if(typeof temp !== 'undefined') // This is to check wether a variable exist or not
    console.log("var is defined");
else
    console.log("Var is UNdefined");

/*
and => && and or => ||
*/
console.log(age == 19 ? "age is 19" : "age is not 19");
console.log(age === 19 ? "age is 19" : "age is not 19");

switch(age) {
    case 18:
        console.log("YOu can start driving drive");
        break;
    case 17:
        console.log("You can not drive");
        break;
    default:
        console.log("You are free to drive");
        break;
}