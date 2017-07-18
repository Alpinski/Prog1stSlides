
var ZOMBIE_COUNT = 10;

// single global variable to contain all variables used in the
// game in a structured hierarchy
// By reducing our global footprint to a single name, we significantly 
// reduce the chance of bad interactions with other applications, 
// widgets, or libraries. 
var game = {};

	// get first canvas element and its context
game.canvas = document.getElementById("gameCanvas");
game.context = game.canvas.getContext("2d");

//game.debug = document.getElementById("debugLayer");

game.canvas.width = window.innerWidth;
game.canvas.height = window.innerHeight;

game.identityMatrix = new Matrix3x3();

game.rand = new PseudoRandom(5423339992.21, Math.random(), 10000);


game.sprites = {
};

//game.sprites.player = new Sprite("player.png");
//game.sprites.player.buildFrames(8, 1, 32, 32, 0, 0, 0, 0, 0.05);
//game.sprites.player.setOffset(16, 16);

game.sprites.zombie = new Sprite("./car.png");
game.sprites.zombie.buildFrames(1, 1, 36, 42, 0, 0, 0, 0, -1);
game.sprites.zombie.setOffset(16, 21);



	// store the frame timing information inside the game structure.
	// This gives us easy access to fps variables throughout the game
	// (more useful for debugging)
game.frame = {
	fps: 0,
	fpsCount: 0,
	fpsTime: 0,
	dt: 0,
	startFrameMillis: Date.now(),
	endFrameMillis: Date.now()
};


	// create the player object
//game.player = player(game.sprites.player, game.canvas.width/2, game.canvas.height/2);

	// set up the mouse and keyboard event handler
game.keyboard = new Keyboard();

window.innerWidth = 640;
window.innerHeight = 640;

game.tileWidth = window.innerWidth>>5;
game.tileHeight = window.innerHeight>>5;
game.width = game.tileWidth<<5;
game.height = game.tileHeight<<5;

game.zombies = new Array();
for(var zombieIdx=0; zombieIdx<ZOMBIE_COUNT; zombieIdx++)
{	
	game.zombies[zombieIdx] = zombie(game.sprites.zombie.copy(), 
			(3*36)+game.rand.next()%200, (36)+game.rand.next()%80);
}

game.pathfinder = new Pathfinder(game.tileWidth, game.tileHeight);

//
// update(deltaTime)
// Updates the objects in our game.
// dt refers to the delta time - the amount of time it took the last frame to 
// update. We use this value to control the speed of animations, etc. in 
// the game
// Author: Samuel Cartwright, 30/10/12
function update(dt)
{
//	game.player.update(dt);
	
	game.pathfinder.update(dt);
	
	for(var zombieIdx=0; zombieIdx<ZOMBIE_COUNT; zombieIdx++)
	{
		if(game.zombies[zombieIdx].alive == true)
		{
			game.zombies[zombieIdx].update(dt);
		}
	}
}

//
// draw(context)
// Draws a single frame of our game.
// Author: Samuel Cartwright, 30/10/12
function draw(c)
{

 //   game.debug.innerHTML = ">> FPS: " + game.frame.fps;
    
	// clear the background with black
	c.fillStyle = "#FFF";		
	c.fillRect(0, 0, game.width, game.height);
		
	game.pathfinder.draw(c);
	
	
	for(var x=0, count=0; count<game.tileWidth; count++, x+=32)
	{
		c.beginPath();
		c.lineWidth="1";
		c.strokeStyle="black";
		c.moveTo(x, 0);
		c.lineTo(x, game.height);
		c.stroke();
	}

	for(var y=0, count=0; count<game.tileHeight; count++, y+=32)
	{
		c.beginPath();
		c.lineWidth="1";
		c.strokeStyle="black";
		c.moveTo(0, y);
		c.lineTo(game.width, y);
		c.stroke();		
	}
	
//	game.player.draw(c);
	
	for(var i=0; i<ZOMBIE_COUNT; i++)
	{
		if(game.zombies[i].alive == true)
		{
			game.zombies[i].draw(c);
		}
	}
}


//
// drawFrame(context)
// This is the main game loop. The function will draw/update one frame of 
// the game.
// This function is called repeatedly by setting up a setTimeout, with an 
// interval of 0 milliseconds (i.e., run the game as fast as we can).
// Timing for animations etc is controlled using the game.frame.dt delta
// time variable.
// Author: Samuel Cartwright, 30/10/12
function drawFrame(c)
{		
	game.frame.endFrameMillis = game.frame.startFrameMillis;
	game.frame.startFrameMillis = Date.now();

	game.frame.dt = game.frame.startFrameMillis - game.frame.endFrameMillis;
	
		// modify the delta time to something we can use
		// we want 1 to represent 1 second, so if the delta is in milliseconds
		// we divide it by 1000 (or multiply by 0.001). This will make our 
		// animations appear at the right speed, though we may need to use
		// some large values to get objects movement and rotation correct
	var dt = game.frame.dt * 0.001;
		// validate it within range
	if(dt > .4)
		dt = .4;
	
		// update the game object
	update(dt);
		// draw the scene
	draw(c);		
	
	// update the frame counter 
	game.frame.fpsTime += game.frame.dt;
	game.frame.fpsCount++;
	if(game.frame.fpsTime >= 1000)
	{
		game.frame.fpsTime = 0;
		game.frame.fps = game.frame.fpsCount;
		game.frame.fpsCount = 0;		
	}
	
	setTimeout("drawFrame(game.context)", 0);
}

	// call the drawFrame function to start the game loop.
	// call frame will recursively call itself
drawFrame(game.context);
