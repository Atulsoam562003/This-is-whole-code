function correctSounds(buttonInnerHtml) {
    switch(buttonInnerHtml) {
        case `w`: // this : is {
            var audio = new Audio(`sounds/tom-1.mp3`);
            audio.play();
        break; // this break; is }

        case `a`:
            var audio = new Audio(`sounds/tom-2.mp3`);
            audio.play();
        break;

        case `s`:
            var audio = new Audio(`sounds/tom-3.mp3`);
            audio.play();
        break;

        case `d`:
            var audio = new Audio(`sounds/tom-4.mp3`);
            audio.play();
        break;

        case `j`:
            var audio = new Audio(`sounds/snare.mp3`);
            audio.play();
        break;

        case `k`:
            var audio = new Audio(`sounds/crash.mp3`);
            audio.play();
        break;

        case `l`:
            var audio = new Audio("sounds/kick-bass.mp3");
            audio.play();
        break;

        default : // always recommended
            console.log(buttonInnerHtml);
        break;
    }
}

//* this is for button press
// function handleClick() { //* or we can replace it by an anonymous function
//     alert("I got CLicked!");
// }
for(var i = 0; i < document.querySelectorAll(".set button").length; i++) {
    document.querySelectorAll("button")[i].addEventListener("click",function () {
        // this is the identity of the button that triggered the event listener
        var buttonInnerHtml = this.innerHTML;
        correctSounds(buttonInnerHtml);
    });
}
//* this is for keyboard press
document.addEventListener("keydown",function(event) {
    correctSounds(event.key);
});

// var audio = new Audio(`sounds/tom-1.mp3`);
        // audio.play();