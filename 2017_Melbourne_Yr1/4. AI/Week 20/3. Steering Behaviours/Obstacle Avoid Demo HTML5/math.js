
var KPI_OVER_180 = Math.PI / 180;
var K180_OVER_PI = 180 / Math.PI;
var KPI_OVER_2 = Math.PI / 2;


function deg2Rad(degrees)
{
	return degrees * KPI_OVER_180; // or: (degrees/180)*Math.PI
}

function rad2Deg(radians)
{
	return radians * K180_OVER_PI; // or: (radians/Math.PI)*180
}

//
// shear(c, kx, ky)
// Shear transform:
// x' = x + kx*y;
// y' = y + ky*x; 
// Author: Samuel Cartwright, 01/11/12
function shear(c, kx, ky)
{
	c.transform(1, ky, kx, 1, 0, 0); 
}

//
// rotateAbout(c, theta, x, y)
// Rotate theta radians clockwise around (x,y).
// This can also be accomplished with a translate,
// rotate, translate back sequence of transformations.
// Author: Samuel Cartwright, 01/11/12
function rotateAbout(c, theta, x, y) 
{
	var ct = Math.cos(theta), st = Math.sin(theta);
	c.transform(ct, -st, st, ct, -x*ct-y*st+x, x*st-y*ct+y);
}

//
// lookat(x, y)
// Return the angle of rotation necessary for an object to be 'looking at'
// an x,y coordinate
// The angle is returned in radians
// Author: Samuel Cartwright, 01/11/12
function lookAt(x, y)
{
	return Math.atan2(y, x) + KPI_OVER_2;
}

//
// rand(floor, ceil)
// Return a random number within the range of the two input variables
// Author: Samuel Cartwright, 01/11/12
function rand(floor, ceil)
{
	return Math.floor((Math.random()*ceil)+floor);
}

//
// PseuoRand
// A random function to produce predictable random numbers
// (also, the JavaScript random function doesn't give very good random numbers)
var PseudoRandom = function(gen1, seed, max) {
	this.gen1 = gen1;
	this.gen2 = gen1 * 2;
	this.seed = seed;
	this.max = max;
};

PseudoRandom.prototype.next = function(){
	var newSeed = (this.gen1 * this.seed) + this.gen2;
	
	newSeed %= this.max;
	this.seed = newSeed;
	return this.seed;
};

//
// nextClamped
// Returns a random number clamped between -1 and 1
//
PseudoRandom.prototype.nextClamped = function () {
	var a = this.next();
	var b = this.next();
	
	var r = ((a & b>>1)^this.next())/(this.max>>1);
	return r-1;
};

// 
// clamp
// Validate the input value to ensure it is within the given range. If not,
// the value will be clamped to the min and max values.
function clamp(min, max, val) {
    if(val < min)
        return min;
    if(val > max)
        return max;
    return val;
};

/////
// Intersection Tests

//
// Intersection of 2 implicit lines in 2D (from 3D Math Primer for Graphics and Game Dev, p282)
// also look at this post: http://www.gamedev.net/topic/346591-2d-line-intersection/
// Each line segment consists of a starting position (point) and a vector (length and direction)
function findLinesIntersection(point1, vector1, point2, vector2, precision) {

    var a1 = -vector1.y;
    var b1 = vector1.x;
    var d1 = a1 * point1.x + b1 * point1.y;
        
    var a2 = -vector2.y;
    var b2 = vector2.x;
    var d2 = a2 * point2.x + b2 * point2.y;

    var denominator = (a1*b2 - a2*b1);
    
    if(denominator === 0)
        return null;
        
        // find the x and y intersection
    var intersection = createVector2(
            (b2*d1 - b1*d2) / denominator, 
            (a1*d2 - a2*d1) / denominator);
    
        // check intersection lies on the first line segment
    if(vector1.x >= 0) {
        if(intersection.x < point1.x - precision || intersection.x > point1.x + vector1.x + precision) {
            return null;
        }
    } else if(intersection.x > point1.x + precision || intersection.x < point1.x + vector1.x - precision) {
        return null;
    }
    
    if(vector1.y >= 0) {
        if(intersection.y < point1.y - precision || intersection.y > point1.y + vector1.y + precision) {
            return null;
        }
    } else if(intersection.y > point1.y + precision || intersection.y < point1.y + vector1.y - precision) {
        return null;
    } 
    
        // check intersection lies on the second line segment
    if(vector2.x >= 0) {
        if(intersection.x < point2.x - precision || intersection.x > point2.x + vector2.x + precision) {
            return null;
        }
    } else if(intersection.x > point2.x + precision || intersection.x < point2.x + vector2.x - precision) {
        return null;
    }
    
    if(vector2.y >= 0) {
        if(intersection.y < point2.y - precision || intersection.y > point2.y + vector2.y + precision) {
            return null;
        }
    } else if(intersection.y > point2.y + precision || intersection.y < point2.y + vector2.y - precision) {
        return null;
    } 
    
    return intersection;
}


