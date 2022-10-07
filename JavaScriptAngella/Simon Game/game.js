var buttonColors = ["red" , "blue" , "green", "yellow"];
var gamePattern = [];
var userClickPattern = [];

var level = 0;
var started = false;


$(document).keypress(function(){
    if(!started) {
        $("h1").text("Level" + level);
        nextSequence();
        started = true;
    }
});

// $("[type = button]").on("click",function(event){ //* we cannot do this as this is targeting a single element
//     var userChosenColor = event.target.id;
//     userClickPattern.push(userChosenColor);
//     animatePress(userChosenColor);
//     playSound(userChosenColor);

//     checkAnswer(userClickedPattern.length - 1);
// });

$(".btn").click(function() {
    var userChosenColor = $(this).attr("id");
    userClickPattern.push(userChosenColor);

    playSound(userChosenColor);
    animatePress(userChosenColor);

    checkAnswer(userClickPattern.length - 1);
});

function checkAnswer(currentLevel) {
    if(gamePattern[currentLevel] === userClickPattern[currentLevel]) {
        console.log("success");

        if(userClickPattern.length === gamePattern.length) {
            setTimeout(function() {
                nextSequence();
            },1000);
        }
    } else {
        console.log("wrong");
        playSound("wrong");

        $("body").addClass("game-over");
        setTimeout(function(){
            $("body").removeClass("game-over");
        },200);
        $("h1").text("Game Over, Press Any Key to Restart");
        startOver();
    }
}
function nextSequence() {

    userClickPattern = [];
    level++;
    $("h1").text("Level " + level);
    var randomNumber = Math.floor(Math.random() * 4);
    var randomChosenColor = buttonColors[randomNumber];
    gamePattern.push(randomChosenColor);

    $("#" + randomChosenColor).fadeIn(100).fadeOut(100).fadeIn(100);
    playSound(randomChosenColor);
}

function playSound(name) {
    var audio = new Audio("sounds/" + name + ".mp3");
    audio.play();
}

function animatePress(currentColor) {
    $("#" + currentColor).addClass("pressed");
    setTimeout(function(){
        $("#" + currentColor).removeClass("pressed");
    },100);
}

function startOver() {
    level = 0;
    gamePattern = [];
    started = false;
}

