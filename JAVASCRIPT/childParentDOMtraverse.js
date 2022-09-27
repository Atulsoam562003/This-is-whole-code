let cont = document.querySelector('.child');
cont = document.querySelector(`.container`);
// let nodeName = cont.childNodes[3].nodeName;
// let nodeName = cont.children[3].nodeName;
let nodeName = cont.childNodes[3].nodeType;
// console.log(nodeName);
// console.log(nodeType);
//*Node Types
/*
1 -> element
2 -> Attributes
3 -> Text Node
8 -> Comment
9 -> Document
10 -> docType
*/
// console.log(cont.childNodes); //* recommended is to use children
// console.log(cont.children);

let container = document.querySelector('div.container');
console.log(container.children[3].children[0].children);

// console.log(container.firstChild); //* now recommended as also give us text,doctype ,comments
console.log(container.firstElementChild); //* use this

console.log(container.lastElementChild);
console.log(container.childElementCount);

console.log(container.firstElementChild.parentNode);
// console.log(container.firstElementChild.nextSibling);
console.log(container.firstElementChild.nextElementSibling);




