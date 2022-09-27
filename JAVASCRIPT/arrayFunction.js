//*TODO => one thing to notice we cannot change the variable when it is const but we can by function which take the variable as an reference
let marks = [34,121,42,4235,5,43,78];
const fruits = ['apple',"orange","atul"];
const mixed = [1,"atul",true,[2,3,43],undefined];
// console.log(mixed);

// array constructor
const arr = new Array(23,543,0,12,'banana');
// console.log(arr);

// console.log(arr.length);  //* no curly braces so it is a METHOD
// console.log(Array.isArray(arr)); //* curly braces so it is a FUNCTION


let value = marks.indexOf(5);
// console.log(value);

//* mutating the array (mutating === modifying)
marks.push(34); //* push at the end
marks.unshift(2022); //* push at the beginning
marks.pop(); //* pop form the end
marks.shift(); //* pop form the front

marks.splice(1,2); // => remove the two elements starting from the 1st index
// console.log(marks);
marks.reverse();
let marks2 = [1,2,323,"Akash"];
marks = marks.concat(marks2); //* this return the array not passed by reference

// console.log(marks);

let myObj = {
    name:"Atul",
    course: "btech",
    marks : [12,131,24,0],
    isActive : true
};

console.log(myObj);
console.log(myObj.marks); //*OR
console.log(myObj['marks']);
// console.log(myObj.isActive);
// console.log(myObj.name);