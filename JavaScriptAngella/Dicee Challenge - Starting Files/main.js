var random = Math.floor(Math.random() * 6) + 1;
var randomDiceImage = "dice" + random + ".png";

var randomImageSrc = "images/" + randomDiceImage;

var img1 = document.querySelectorAll("img")[0];

img1.setAttribute("src",randomImageSrc);

var random2 = Math.floor(Math.random() * 6) + 1;
randomDiceImage = "dice" + random2 + ".png";
randomImageSrc = "images/" + randomDiceImage;
var img2 = document.querySelectorAll("img")[1];

img2.setAttribute("src",randomImageSrc);

// if player 1 wins
if(random > random2)
    document.querySelector("h1").innerHTML = "⛳Player 1 Wins!";
else if(random < random2)
    document.querySelector("h1").innerHTML = "Player 2 Wins!⛳";
else document.querySelector("h1").innerHTML = "⛳Draw⛳!"