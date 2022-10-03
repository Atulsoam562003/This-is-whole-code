function fibonacciGenerator(n) {
    var arr = [];
    if(n == 1) arr.push(0);
    if(n == 2) arr.push(1);
    var prev = 0,now = 1;
    for(var i = 1; i <= n; i++) {
        arr.push(prev);
        var current = prev + now;
        prev = now;
        now = current;
    }
    return arr;
}

console.log(fibonacciGenerator(10));
