//* Type Conversion
let myVar;
myVar = String(34);
console.log(myVar, typeof myVar);

let booleanVar = String(true);
console.log(booleanVar,typeof booleanVar);

let date = String(new Date());
console.log(date,typeof date);

let arr = String([1,2,3,4,5]);
console.log(arr.length,typeof arr);

let arr1 = [1,2,3,4,5];
console.log(arr1.length,typeof arr1);

let i = 8;
console.log(i.toString());
console.log(i);

let str = Number("1234");
str = Number("123D"); //* it will be NaN
console.log(str,typeof str);

let number = parseInt('34');
console.log(number,typeof number);

// for decimal numbers
number = parseFloat('34.02310023');
// console.log(number,typeof number); //* Or
console.log(number.toFixed(3),number); //* toFixed is same is fixed setprecision in C++

//* Type Coercion
let myStr = "698";
let myNum = 34;

console.log(myStr + myNum);

