var WANDER_JITTER = 10;
var WANDER_RADIUS = 30;
var WANDER_DISTANCE = 40;

var MAX_VELOCITY = 60;

var FEELER_ANGLE_MIN = deg2Rad(-25);
var FEELER_ANGLE_MAX = deg2Rad(25);

var zombie = function (sprite, x, y) {

    var that = entity({
            position : createVector2(x, y),
            boundingRadius : 10,
            rotation : 0}),
        super_draw = that.superior('draw');

    that.sprite = sprite;
    that.health = 100;

    that.currentVelocity = new Vector2();
    that.targetVelocity = new Vector2();
    
    that.targetVelocity.randomize(); // create a random, normalized vector
    that.targetVelocity.multiplyScalar(MAX_VELOCITY);

    var tmpFeeler = createVector2(0, -100);
    
    that.feelers = new Array();
    that.feelers.push( tmpFeeler.copy() );
    
    that.collideForce = new Vector2();
    that.lastForce = new Vector2();
    
    tmpFeeler.y = -60;
    
    var m = new Matrix3x3();
    m.setRotation(FEELER_ANGLE_MAX);
    that.feelers.push( m.multiplyByVector(tmpFeeler) );
    
    m.setRotation(FEELER_ANGLE_MIN);
    that.feelers.push( m.multiplyByVector(tmpFeeler) );
    
        
    that.hasCollision = false;
    that.collisions = new Array();
    that.closestPoints = new Array();
    
    that.alive = true;

    
    that.getWidth = function() {
        return that.sprite.getWidth();
    };

    that.getHeight = function() {
        return that.sprite.getHeight();
    };

    that.update = function (dt) {
        if (that.alive === false) {
            return;
        }       
       
        var s = that.currentVelocity.length();
        
        that.feelers[0].normalize();        
        that.feelers[1].normalize();
        that.feelers[2].normalize();

        if(s > 0) {
            that.feelers[0].y = -(s<<1);
            that.feelers[1].multiplyScalar(s);
            that.feelers[2].multiplyScalar(s);
        }

        
        var force = that.wallAvoid();
        
        if(force.x !== 0 || force.y !== 0)
        {
            that.collideForce = force.copy();
            
            that.lastForce.multiplyScalar(0.7);
            force.multiplyScalar(0.3);
            force.add(that.lastForce);
            
         //   that.targetVelocity.set(force.x, force.y);
            that.targetVelocity.add(force);
            that.targetVelocity.normalize();
            that.targetVelocity.multiplyScalar(MAX_VELOCITY);
        }      
        that.lastForce = force.copy();
        
        that.updateVelocity(dt);
        that.rotation = lookAt(that.currentVelocity.x, that.currentVelocity.y);
        if(isNaN(that.rotation))
            that.rotation = 0;
        
        that.applyVelocity(dt);
        
        if(isNaN(this.position.x) || isNaN(this.position.y)) {
            this.position.x = 0;
            this.position.x = 0;
        }

        that.sprite.update(dt);
    };

    that.wallAvoid = function () {
        var force = new Vector2();

        that.hasCollision = false;
        that.collisions.length = 0;
        that.closestPoints.length = 0;

        var x = (that.position.x > 0) ? that.position.x>>5 : 0;
        var y = (that.position.y > 0) ? that.position.y>>5 : 0;
        
        var m = new Matrix3x3();
        m.setRotation(that.rotation);        
        m.setTranslationWithVector(that.position);
        
        var wallTrans = new Matrix3x3();
        var wallV = createVector2(0, -36);
                
        // examine each feeler in turn
        for(var fIdx = 0; fIdx < that.feelers.length; fIdx++) {
            // run through each wall checking for any intersection points
            
            var distToClosestIP = Number.MAX_VALUE;
            var closestPoint = null;
            var normal;
            
            var feeler = m.multiplyByVector(that.feelers[fIdx]);
            var feelerV = feeler.copy();
            feelerV.subtract(that.position);
            
            var minX = (feeler.x < that.position.x) ? ((feeler.x > 0)? feeler.x>>5 : 0) : x;
            var maxX = (feeler.x > that.position.x) ? feeler.x>>5 : x;
            var minY = (feeler.y < that.position.y) ? ((feeler.y > 0)? feeler.y>>5 : 0) : y;
            var maxY = (feeler.y > that.position.y) ? feeler.y>>5 : y;
            
            var n = Math.sqrt( ((maxX-minX) * (maxX-minX)) + ((maxY-minY) * (maxY-minY)) );
            
            for(var i = minX; i <= maxX && i < game.tileWidth; i++) {
                for(var j = minY; j <= maxY && j < game.tileHeight; j++) {
                    var dx = Math.abs(i - x);
                    var dy = Math.abs(j - y);
                                        
                    // if this tile [j][i] is a wall
                    if(game.pathfinder.data[j][i].type === NODE_TYPE.WALL) {
                        
                        // debug information
                        that.hasCollision = true;
                        that.collisions.push(fIdx);    
                        
                        var wallPoint = createVector2( (i<<5)+36, (j<<5)+36);
                        
                        //get the intersection of the feeler with the wall                        
                        for(var wIdx = 0; wIdx < 4; wIdx++) {
                            
                            wallTrans.setupRotation( -(KPI_OVER_2 * wIdx) );
                            var Vi = wallTrans.multiplyByVector(wallV);
                            
                            if(wIdx === 1)
                                wallPoint.y -= 36;
                            else if(wIdx === 2)
                                wallPoint.x -= 36;
                            else if(wIdx === 3)
                                wallPoint.y += 36;
                             
                            // get the intersection of the 2 line segments
                            var intersect = findLinesIntersection(wallPoint, Vi, that.position, feelerV, 0.1);
                            if(intersect === null)
                                continue;
                                                                                    
                            var dist = intersect.copy();
                            dist.subtract(that.position);
                            dist.abs();
                            
                            var len = dist.length();
                            if(len < distToClosestIP) {
                                distToClosestIP = len;
                                closestPoint = intersect;
                                switch(wIdx) {
                                case 0: normal = createVector2(1, 0); break;
                                case 1: normal = createVector2(0, -1); break;
                                case 2: normal = createVector2(-1, 0); break;
                                case 3: normal = createVector2(0, 1); break;
                                }
                                
                            }
                       } // end for each wall edge
                    } // end if tile is wall              
                } // end for each x
            } // end for each y         

            // if an intersection point has been detected, calculate a force 
            // that will direct the agent away
            if(closestPoint != null) {
                that.closestPoints.push(closestPoint);  // debug only

                // calculate by what distance the projected position of the agent 
                // will overshoot the wall
                var overshoot = feeler.copy();
                overshoot.subtract(closestPoint);

                if(fIdx != 0) {
                    normal.multiplyScalar(2);
                }
                
//                if(force.x === 0 && force.y === 0) {
//                    force.set(that.lastForce.x, that.lastForce.y);
//                }
                
                // create a force in the direction of the magnitude of the overshoot
                normal.multiplyScalar(overshoot.length());
                force.add(normal);
           //     force = normal.copy();
            }
            
        } // end for each feeler
        
        return force;
    };
    
    
    //
    // updateVelocity
    // interpolates from the current velocity to the target velocity
    //
    that.updateVelocity = function (dt) {
//        if (that.currentVelocity.isEqualTo(that.targetVelocity)) {
//            that.targetVelocity.normalize();
//            that.targetVelocity.multiplyScalar(MAX_VELOCITY);
//        }
        
        if (that.position.x + that.targetVelocity.x < 0) {
            that.targetVelocity.x = -that.targetVelocity.x;
        }
        if (that.position.x + that.targetVelocity.x > game.width) {
            that.targetVelocity.x = -that.targetVelocity.x;
        }

        if (that.position.y + that.targetVelocity.y < 0) {
            that.targetVelocity.y = -that.targetVelocity.y;
        }
        if (that.position.y + that.targetVelocity.y > game.height) {
            that.targetVelocity.y = -that.targetVelocity.y;
        }

        var diffV = that.targetVelocity.copy();
        diffV.subtract(that.currentVelocity);
        diffV.normalize();
        diffV.multiplyScalar(dt * 30);
        that.currentVelocity.add(diffV);

        // bounds check
        if (that.targetVelocity.x < 0) {
            if (that.currentVelocity.x < that.targetVelocity.x) {
                that.currentVelocity.x = that.targetVelocity.x;
            }
        } else {
            if (that.currentVelocity.x > that.targetVelocity.x) {
                that.currentVelocity.x = that.targetVelocity.x;
            }
        }

        if (that.targetVelocity.y < 0) {
            if (that.currentVelocity.y < that.targetVelocity.y) {
                that.currentVelocity.y = that.targetVelocity.y;
            }
        } else {
            if (that.currentVelocity.y > that.targetVelocity.y) {
                that.currentVelocity.y = that.targetVelocity.y;
            }
        }
    };

    //
    // applyVelocity
    //
    that.applyVelocity = function (dt) {
        var force = that.currentVelocity.copy();
        force.multiplyScalar(dt);
        that.position.add(force);
    };

    //
    // draw
    //
    that.draw = function (c) {
        if (that.alive == false)
            return;

        var trans = new Matrix3x3();
        trans.setupRotation(that.rotation);
        trans.setTranslationWithVector(that.position);
        trans.applyToContext(c);

        that.sprite.draw(c);
        
        super_draw(c);

        for(var i=0; i<that.feelers.length; i++) {
            var col = false;
            
            c.beginPath();
            
            if(that.hasCollision === true) {
                for(var cIdx=0; cIdx<that.collisions.length; cIdx++) {
                    if(that.collisions[cIdx] === i) {
                        col = true;
                        break;
                    }
                }
            }
            
            if(col === true) {
                c.lineWidth = "1";
                c.strokeStyle = "red";                
            } else {
                c.lineWidth = "1";
                c.strokeStyle = "green";
            }            

            c.moveTo(0, 0);
            c.lineTo(that.feelers[i].x, that.feelers[i].y);
            c.stroke();
        }       
        
        
        game.identityMatrix.applyToContext(c);
        

        c.beginPath();
        c.lineWidth = "3";
        c.strokeStyle = "blue";
        c.moveTo(that.position.x, that.position.y);
        c.lineTo(that.position.x + that.collideForce.x, that.position.y + that.collideForce.y);
        c.stroke();
        
        for(var i=0; i<that.closestPoints.length; i++) {
            c.beginPath();
            c.lineWidth="1";
            c.strokeStyle="blue";
            c.fillStyle="yellow";
            c.arc(that.closestPoints[i].x, that.closestPoints[i].y, 2, 0, 2*Math.PI);
            c.stroke();
            c.arc(that.closestPoints[i].x, that.closestPoints[i].y, 2, 0, 2*Math.PI);
            c.fill();
        }
        
    };

    return that;
};