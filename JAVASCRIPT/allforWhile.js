// //* for
// for (let index = 0; index < array.length; index++) {
//     const element = array[index];

// }
// //* for each
// array.forEach(element => {

// });
// //* for in
// for (const key in object) {
//     if (Object.hasOwnProperty.call(object, key)) {
//         const element = object[key];

//     }
// }
// //* for of
// for (const iterator of object) {

// }
/* IN JS RECOMMENDED TO USE === */
// NOW START ==>
for(let i = 0; i < 10; i++) console.log(i);
console.log();
let j  = 10;
while(j < 0) {
    console.log(j);
    j--;
}
j = 10;
do {
    console.log(j);
    j--;
}while(j < 0);

let arr = [2,34,6,45,7,34];
arr.forEach(function(element){ //* this is for-each loop in JS (Range based for loop)
    console.log(element);
});
arr.forEach(function(element,index,arr){ //* more the one arguments
    console.log(element,index,arr);
})
//OR
console.log();
for (let i = 0; i < arr.length; i++) {
    const element = arr[i];
    console.log(element);
}

let obj = {
    name: "Atul Soam",
    age : 78,
    type: "Awesome Programmer",
    Os : "Windows and Ubuntu"
}
for(let key in obj) { //* for in loop
    // console.log(obj[key]);
    console.log(`The ${key} of object is ${obj[key]}`);
}