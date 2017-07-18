
var entity = function (spec) {
    var that = {
        position: spec.position,
        boundingRadius: spec.boundingRadius,
        rotation: spec.rotation     // amount of rotation of the entity, in radians
    };
    
    that.draw = function (context) {
        context.beginPath();
        context.lineWidth = "1";
        context.strokeStyle = "red";
        context.arc(0, 0, this.boundingRadius, 0, 2 * Math.PI);
        context.stroke();
    };    
    
    that.getBoundingRadius = function () {
        return that.boundingRadius;
    };

    return that;
};