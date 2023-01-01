//Map -Create a new array by doing something with each item in an array.

//Filter - Create a new array by keeping the items that return true.

//Reduce - Accumulate a value by doing something to each item in an array.

//Find - find the first item that matches from an array.

//FindIndex - find the index of the first item that matches.

import emojipedia from "./emojipedia";

const finalArray = emojipedia.map(element => element.meaning.substring(0,100));
console.log(finalArray);

var numbers = [13,12,4,,2,5,343];

// const newNumbers = numbers.map(element => element * 2);
const newNumbers = numbers.map(element => element < 10);
