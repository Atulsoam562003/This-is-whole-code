let element = document.createElement('li');

let text = document.createTextNode(`I am a text node`);
element.appendChild(text);

// add a class name to this li element
element.className = `childul`;
element.id = `createdLi`;
// element.setAttribute(`title`,`myTitle`);
// element.innerText = `Hello this is explicitly created`;
// element.innerHTML = `<b>Hello this is explicitly created</b>`;

// using query selector to append this element into the DOM
let ul = document.querySelector('ul.this'); //* we will get the first ul having class "this"
ul.appendChild(element); //* DYNAMICALLY INSERTED
// console.log(ul);
// console.log(element);

let elem2 = document.createElement(`h3`);
elem2.id = `elem2`;
elem2.className = `elem2`;
let tNode = document.createTextNode(`this is created node for lm2`);
elem2.appendChild(tNode);

element.replaceWith(elem2); //* NOW ELEMENT IS REPLACED WITH ELEM2

let myul = document.getElementById(`myul`);
myul.replaceChild(element,document.getElementById(`fui`)); // element in now new child

myul.removeChild(document.getElementById(`lui`)); //* => child removed

// let pr = elem2.getAttribute(`id`);
let pr = elem2.getAttribute(`class`);
elem2.removeAttribute(`id`); //* attribute removed
console.log(elem2,pr);
