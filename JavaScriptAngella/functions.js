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