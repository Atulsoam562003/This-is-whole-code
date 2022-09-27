console.log("HELLO");

/* element selectors
1. single element selectors
2. multi element selectors
*/
//TODO: Single element selectors

let element = document.getElementById("first");
// element = element.className
element.style.color = "red";
element.innerText = "ATul is good boy";
element.innerHTML = "<b>ATul is good boy</b>";
console.log(element);

// let sel = document.querySelector('#first');
// let sel = document.querySelector('.child');
// let sel = document.querySelector('b');
// let sel = document.querySelector('h1');
let sel = document.querySelector('div');
console.log(sel);

//TODO: Multiple element selectors
let elems = document.getElementsByClassName(`container`);
// console.log(elems);
// console.log(elems[2]);
console.log(elems[0].getElementsByClassName(`child`)); // we can do chaining
elems = document.getElementsByTagName('div');
console.log(elems);

// Iterating the HTML collections
Array.from(elems).forEach(element => {
    console.log(element);
});

