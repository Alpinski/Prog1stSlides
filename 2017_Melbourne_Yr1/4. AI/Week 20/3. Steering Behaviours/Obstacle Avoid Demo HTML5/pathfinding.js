
var NODE_TYPE = {
    EMPTY : 0x00,
    WALL : 0x01,
    VISITED : 0x10
};

var PathNode = function (x, y, cost) {
	this.position = createVector2(x,y);
	this.cost = cost;
	this.type = NODE_TYPE.EMPTY;
	
	this.entities = new Array();
};


var Pathfinder = function (tileX, tileY) {
	this.xCount = tileX;
	this.yCount = tileY;
	
    var dataSet = [
                   [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
                   [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1],
                   [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
                   [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
                   [1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1],
                   [1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1],
                   [1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1],
                   [1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1],
                   [1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1],
                   [1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1],
                   [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,1, 1],
                   [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1],
                   [1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1],
                   [1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1],
                   [1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1],
                   [1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1],
                   [1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1],
                   [1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
                   [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1],
                   [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
                   ];
	
	this.data = new Array();
	for(var y=0; y<tileY; y++)
	{
		this.data[y] = new Array();
		for(var x=0; x<tileX; x++)
		{
			this.data[y][x] = new PathNode(x, y, 0);
			
			if(y < dataSet.length && x < dataSet[y].length)
            this.data[y][x].type = dataSet[y][x];
		}
	}	
		
	this.maxCost = 0;
};

Pathfinder.prototype.onload = function(data) {
	for(var y=0; y<data.walls.length; y++)
	{
		if(y >= game.tileHeight)
			continue;
		for(var x=0; x<data.walls[y].length; x++)
		{
			if(x >= game.tileWidth)
				continue;
			this.data[y][x].type = data.walls[y][x]; 
		}
	}
};

Pathfinder.prototype.getTileCost = function (x, y) {
	if (x >= 0 && x < this.xCount && y >= 0 && y < this.yCount) {
		return (this.data[y][x].type & NODE_TYPE.WALL == NODE_TYPE.WALL) ? -1 : this.data[y][x].cost;
	}
	return -1;
};
	
//
// sortEntities
// Clear the spatial partition grid and re-add all game entities to the grid
// This has to be done every frame so we can accurately and efficiently track the 
// position of in-game entities. 
//
Pathfinder.prototype.sortEntities = function () {

    // clear closed list
    for (var y = 0; y < this.yCount; y++) {
        for (var x = 0; x < this.xCount; x++) {
            this.data[y][x].cost = 0;
            this.data[y][x].type &= ~NODE_TYPE.VISITED; // set node to not yet visited
            this.data[y][x].entities.length = 0;
        }
    }    
    
    // add the zombies to the grid
    for (var zombieIdx = 0; zombieIdx < ZOMBIE_COUNT; zombieIdx++) {
        if (game.zombies[zombieIdx].alive === true) {
            this.addEntity(game.zombies[zombieIdx]);
        }
    }
    // add the player to the grid
 //   this.addEntity(game.player);
};

Pathfinder.prototype.addEntity = function(entity) {
    // assumes the entity radius is less than the dimensions of a tile
    var radius = entity.getBoundingRadius();
    var tileY = entity.position.y>>5;
    var tileX = entity.position.x>>5;
    
    // get all the tiles the entity is currently on (will be at most 4)
    var xOff = entity.position.x%32;
    var yOff = entity.position.y%32;
                            
    if (!(tileY > 0 && tileY < game.tileHeight && tileX > 0 && tileX < game.tileWidth)) {
        return;    // position out of bounds
    }               
        
     // add current tile    
    this.data[tileY][tileX].entities.push(entity);
    
    // add left tile
    if(xOff < radius && tileX-1 > 0) {
        this.data[tileY][tileX-1].entities.push(entity);
        
        // up
        if(yOff < radius && tileY-1 > 0) {
            this.data[tileY-1][tileX].entities.push(entity);
            this.data[tileY-1][tileX-1].entities.push(entity);
        }            
        // down
        else if(yOff > 32-radius && tileY+1 < game.tileHeight) {
            this.data[tileY+1][tileX].entities.push(entity);
            this.data[tileY+1][tileX-1].entities.push(entity);
        }
        return;
    }           
    // right
    if(xOff > 32-radius && tileX+1 < game.tileWidth) {
        this.data[tileY][tileX+1].entities.push(entity);
        
        // up
        if(yOff < radius && tileY-1 > 0) {
            this.data[tileY-1][tileX].entities.push(entity);
            this.data[tileY-1][tileX+1].entities.push(entity);
        }            
        // down
        else if(yOff > 32-radius && tileY+1 < game.tileHeight) {
            this.data[tileY+1][tileX].entities.push(entity);
            this.data[tileY+1][tileX+1].entities.push(entity);
        }
        return;
    }       
    
    // up
    if(yOff < radius && tileY-1 > 0) {
        this.data[tileY-1][tileX].entities.push(entity);
        return;
    }            
    // down
    if(yOff > 32-radius && tileY+1 < game.tileHeight) {
        this.data[tileY+1][tileX].entities.push(entity);
        return;
    } 
};

Pathfinder.prototype.update = function(dt) {
	// do a basic Dijkstra's algorithm, finding the distance
	// from the player for each tile.
	// Cost of each tile is equal to the number of enemies on the tile.
	


    this.sortEntities();
    
    return;
/*    
	this.maxCost = 0;
	
	// get the players tile
	var playerX = game.player.position.x >> 5;
	var playerY = game.player.position.y >> 5;
	
	if(playerX < 0)
		playerX = 0;
	if(playerX >= this.xCount)
		playerX = this.xCount-1;
	
	if(playerY < 0)
		playerY = 0;
	if(playerY >= this.yCount)
		playerY = this.yCount-1;
			
	var openList = new Array();
	openList.push(this.data[playerY][playerX]);
	
	while(openList.length > 0)
	{
		// sort the open list
		openList.sort(function(a,b){return a.cost-b.cost;});
		
		var node = openList.shift();
		node.type = node.type | NODE_TYPE.VISITED;
				
		// get the 4 neighboring tiles
		var neighbor = new Array();
		neighbor[0] = (node.position.x > 0)?createVector2(node.position.x-1, node.position.y):null;	// left
		neighbor[1] = (node.position.x+1 < this.xCount)?createVector2(node.position.x+1, node.position.y):null;	// right
		neighbor[2] = (node.position.y > 0)?createVector2(node.position.x, node.position.y-1):null;	// up
		neighbor[3] = (node.position.y+1 < this.yCount)?createVector2(node.position.x, node.position.y+1):null;	// down
		
		for(var i=0; i<4; i++)
		{
			if(neighbor[i] == null)
				continue;
			
			if((this.data[neighbor[i].y][neighbor[i].x].type & NODE_TYPE.WALL) == NODE_TYPE.WALL)
				continue;
			
				// if node not in open list
			if(IsNodeInList(openList, neighbor[i]) == false)
			{
					// and if node not in closed list (i.e., node not yet visited)
				if((this.data[neighbor[i].y][neighbor[i].x].type & NODE_TYPE.VISITED) == 0)
				{					
						// cost = 1 + cost of current node
						//	also increment the cost of the tile for each entity on the tile
					var cost =  1 + node.cost + (this.data[neighbor[i].y][neighbor[i].x].entities.length<<1);
					this.data[neighbor[i].y][neighbor[i].x].cost = cost;					
					openList.push(this.data[neighbor[i].y][neighbor[i].x]);
					
					if(cost > this.maxCost)
						this.maxCost = cost;
				}// end if not in closed list
			}// end if not in open list
		}// end for each neighbor
	}// end while openList not empty
	
	*/
};

Pathfinder.prototype.draw = function(context) {
	
	for(var y=0; y<this.yCount; y++)
	{
		for(var x=0; x<this.xCount; x++)
		{	
			if(this.data[y][x].type & NODE_TYPE.WALL == NODE_TYPE.WALL)
			{
				context.fillStyle = "#000";
				context.fillRect(x<<5, y<<5, 32, 32);
			}
//			else
//			{
//				var col = Color.hsl(this.data[y][x].cost/this.maxCost, 1, 0.7);
//				context.fillStyle = col.hexTriplet();
//				context.fillRect(x<<5, y<<5, 32, 32);
//			}
		}
	}	
};

function IsNodeInList(array, vector2) {
	for(var i=0; i<array.length; i++)
	{
		if(array[i].position.x == vector2.x && array[i].position.y == vector2.y)
		{
			return true;
		}
	}
	return false;
};
