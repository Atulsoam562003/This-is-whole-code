function fibonacciGenerator(n) {
    var arr = [];
    var prev = 0,now = 1;
    for(var i = 1; i <= n; i++) {
        arr.push(prev);
        var current = prev + now;
        prev = now;
        now = current;
    }
    return arr;
}

console.log(fibonacciGenerator(5));
