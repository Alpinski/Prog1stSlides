//--------------------------------------------------------------------------------------
// 
//--------------------------------------------------------------------------------------
#include "Player.h"
#include <math.h>

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
Player::Player()
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Player::~Player()
{
}

//--------------------------------------------------------------------------------------
// Calculates the damage the player will do with an attack.
//
// Param:
//		eType: The type of the weapon the player currently has equipped.
//		level: The player's current level.
//		bonus: Any bonus damage from buffs.
// Return:
//		Returns an int containing the total damage the player will do with next attack.
//--------------------------------------------------------------------------------------
int Player::CalculateDamage(EWeapon eType, int level, int bonus)
{
	return 0;
}

//--------------------------------------------------------------------------------------
// Calculate the Heuristic using the Diagonal Shortcut method to get from the start
// position to the destination position.
//
// Better but slightly slower than Manhattan Method:
//		Mathf.Abs((nDestX - nCurrentX) + (nDestZ - nCurrentZ)) * 10;
//		http://www.policyalmanac.org/games/heuristics.htm
//
// Param:
//		nCurrentX: start X position
//		nCurrentZ: start Z position
//		nDestX: destination X position
//		nDestZ: destination Z position
// Return:
//		Returns the cost to move one space on the path.
//--------------------------------------------------------------------------------------
int Player::CalculateHeuristic(int nCurrentX, int nCurrentZ, int nDestX, int nDestZ)
{
	int xDistance = abs(nCurrentX - nDestX);
	int yDistance = abs(nCurrentZ - nDestZ);
	int H = 0;

	if(xDistance > yDistance)
			H = 14 * yDistance + 10 * (xDistance - yDistance);
	else
			H = 14 * xDistance + 10 * (yDistance - xDistance);

	return H;
}

//--------------------------------------------------------------------------------------
// Calculates the index of a node adjacent to a specified node in a square grid.
//
// Param:
//		nNodeX: The X index of the node to check.
//		nNodeZ: The Z index of the node to check.
//		nAdjacentID: Which adjacent node to calulcate
//		|0|1|2|
//		|3| |4|
//		|5|6|7|
// Return:
//		The index of the adjacent node.
//--------------------------------------------------------------------------------------
int Player::CalculateAdjacency(int nNodeX, int nNodeZ, int nAdjacentID)
{
	// If the index is greater than 3, increase it by one to skip over the centre node
	// as we are only dealing with adjacent nodes.
	// |0|1|2|
	// |3| |4|
	// |5|6|7|
	int nGridIndex = nAdjacentID;
	if(nGridIndex > 3)
		nGridIndex += 1;

	// Find the X and Z index of the adjacent node.
	int x = nNodeX + (nGridIndex % 3) - 1;
	int z = nNodeZ + (nGridIndex / 3) - 1;
		
	// Out of bounds
	if(x < 0 || x >= m_nSizeX)
		return -1;

	// Out of bounds
	if(z < 0 || z >= m_nSizeZ)
		return -1;
		
	int nIndex = z * m_nSizeX + x;
	return nIndex;
}