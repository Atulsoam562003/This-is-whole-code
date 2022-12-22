//jshint esversion:6

// const fs = require("fs"); //* node native packages
// fs.copyFileSync("file1.txt","file2.txt");

// var superheroes = require('superheroes'); //* NPMs external packages.
// var nameOfSuper = superheroes.random();
// console.log(nameOfSuper);

const supervillains = require(`supervillains`);
supervillains.all;
var nameOfVillain = supervillains.random();
console.log(nameOfVillain);