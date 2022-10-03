function name(money) {
    console.log("we get this much of milk " + money);
    return money % 1.5;
}

// console.log(name(25));
// console.log(Math.floor(25/1.5));
function calculateBottels(startMoney,costPerBottle) {
    var numberOfBottles = startMoney/costPerBottle;
    return numberOfBottles;
}
// console.log("The number of bottles we get are : " + Math.floor(calculateBottels(15,2.65)));
function calculateBMI(height,weight) {
    return (weight/(Math.pow(height,2)));
}
console.log("My BMI is : " + Math.round(calculateBMI(1.80,70)));

var n = Math.random();
// console.log(n);
n *= 6;
n = Math.floor(n) + 1;
console.log(n);

var guestList = ["Atul" , "Akash" , "Papa" , "Mummy"];
console.log(guestList);
console.log(guestList.length);
console.log(guestList[0]);

if(guestList.includes(`Om`)) console.log("He is there");
else console.log("He is not present");

var output = [];
var count = 1;
function fizzBuzz() {
    while(count <= 100) {
        if(count % 3 === 0 && count % 5 === 0) {
            output.push("FizzBuzz");
        } else if(count % 3 == 0) output.push("Fizz");
        else output.push(count);
        count++;
    }
    console.log(output);
}
fizzBuzz();
