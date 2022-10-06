// jQuery() is same as
// $("h1").css("color","red");

// document.querySelector("h1");//* this is same as ...

$("h1");

// document.querySelectorAll("button"); //* is same as

$("button"); //TODO : so we can select one as well as many

/*SO we can change any CSS properties:-
    syntax =>
    $("h1").css("NameOfProperty","valueOfProperty");
    OR
    we can see the property ...
    console.log($(h1).css("color"));
    //*So Single value then getting the value and Double value and setting the value of it
*/
$("h1").addClass("big-title margin-50");

console.log($("h1").hasClass("margin-50"));

//*Now manipulating the text
$("h1").text("Hello World!");

$("button").text("Don't Click Me");
// to add HTML
$("button").html("<em><b>HI!</b></em>")

//* FOR ATTRIBUTES
// console.log($("img").attr("src"));

$("a").attr("href","https://www.microsoft.com");

$("h1").attr("class");

//TODO : how to add event listeners to our HTML elements using jQuery
/*
$("h1").click(function(){
    $("h1").css("color","red");
});
*/

// with vanilla JS
/*
for (var i = 0 ; i < document.querySelectorAll("button").length; i++) {
    document.querySelectorAll("button")[i].addEventListener("click",function() {
        document.querySelector("h1").style.color = "green";
    });
}
*/
// Now by jQuery :)
$("button").click(function(){
    $("h1").css("color","green");
});
// for detecting the key strokes
$("input").keydown(function(event){
    // console.log(event.key); // event.key give the key which is pressed
    $("h1").text(event.key);
});
// if for whole document then => $(document) //*now quotation

//TODO: a lot of event listener ways are also their
$("h1").on("mouseover",function(){
    $("h1").css("color","lightgreen");
});

$("h1").before("<button>New!</button>"); //* what ever HTML you want to add before h1 TAG!

$("h1").after("<button>New!</button>"); //* what ever HTML you want to add after h1 TAG!

// but if you want to add before or after the content of the H1 but inside the h1 tag then...

$("h1").append("<button>New!</button>");
$("h1").prepend("<button>New!</button>");


//* if we want to remove the elements
// $("button").remove();

//todo: website animation with the jQuery
$("button").on("click",function() {
    // $("h1").hide();
    // $("h1").toggle();
    // $("h1").fadeOut(); // so now it will reduce the opacity of the h1 and then remove
    // $("h1").fadeToggle();
    // slideUp or slideDown or it's toggle version
    // $("h1").slideToggle();
    //* to define a custom behaviour
    // $("h1").animate({opacity:0.5}); // second value has to be number wether in string or in integer

    // chaining of the animations
    $("h1").slideUp().slideDown().animate({opacity:0.5});
});
// $("h1").show(); // to show up the element
//$("h1").fadeIn();