//TODO : so it is recommended to use let and const as they work like variable same in C++ :)
// function in the variable
/*
function greet(name,Thanks = `Thankyou`) {
    let msg = `Happy Birthday BOI ${name} and ${Thanks}`;
    return msg;
}
*/
//* This is function expression === anonymous function
const myGreet = function (name,Thanks = `Thankyou`) {
    let msg = `Happy Birthday BOI ${name} and ${Thanks}`;
    return msg;
}
let name = "skillF";
// greet(name);
let Myname = "Atul";
// let val = greet(Myname);
let val = myGreet(Myname,"Thanks a lot");
console.log(val);

const obj = {
    name : "skillF",
    game : function() { //* This is function expression === anonymous function
        return "Chess";
    }
};
console.log(obj.game());

arr = ["fruit","vegetable","furniture"];
arr.forEach(function(element,index,arr){
    console.log(element,index);
});

if(1) {
    let i = 234;
    console.log(i);
}
// console.log(i); //* error as let and const had block level scope so here only till if block

if(1) {
    var i = 234;
    console.log(i);
}
console.log(i); //* no error as var has function level scope so acting like a global variable


