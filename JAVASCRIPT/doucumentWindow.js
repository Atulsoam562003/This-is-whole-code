let a = window.document;
// DOM of JS that is HTML has a tree like structure
a = document.forms;
// console.log(a);

// If we want to make array by some collections of data ex:- from HTML collections
/*
a = document.all;
Array.from(a).forEach(function(element){
    console.log(element);
})
*/
a = document.links[0] //* extract all the links from that DOM
// a = document.images;
// a = document.scripts;
a = document.scripts[0];
console.log(a);