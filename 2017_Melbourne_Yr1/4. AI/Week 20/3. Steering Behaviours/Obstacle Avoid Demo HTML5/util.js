// general utility functions


Function.prototype.method = function (name, func) {
    this.prototype[name] = func;
    return this;
};

// superior()
// Make a superior method that takes a method name and returns a function that 
// invokes that method. The function will invoke the original method even if the 
// property is changed
Object.method('superior', function (name) {
    var that = this,
        method = that[name];
    return function () {
        return method.apply(that, arguments);
    };
});

//
// integer()
// Convert a number to an integer (i.e., turn a floating point variable into an integer)
// Example usage:
//      document.writeln((-10 / 3).integer(  ));  // -3
Number.method('integer', function () {
    return Math[this < 0 ? 'ceiling' : 'floor'](this);
});

//
// trim()
// Remove any trailing whitespace from a string
// Example usage:
//      document.writeln('"' + "   neat   ".trim(  ) + '"');
String.method('trim', function () {
    return this.replace(/^\s+|\s+$/g, '');
});
