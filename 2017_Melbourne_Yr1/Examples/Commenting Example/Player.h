def//--------------------------------------------------------------------------------------
// Class for the player
//
//--------------------------------------------------------------------------------------
#pragma once

//--------------------------------------------------------------------------------------
// An enum list of the different weapon types the player can equip
//--------------------------------------------------------------------------------------
enum EWeapon
{
	EWEAPON_SWORD,
	EWEAPON_AXE,
	EWEAPON_BOW
};

//--------------------------------------------------------------------------------------
// Player object
// Stores data used by the player, handles rendering and input.
//--------------------------------------------------------------------------------------
class Player
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	Player();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Player();

	//--------------------------------------------------------------------------------------
	// Claculates the damage the player will do with an attack.
	//
	// Param:
	//		eType: The type of the weapon the player currently has equipped.
	//		level: The player's current level.
	//		bonus: Any bonus damage from buffs.
	// Return:
	//		Returns an int containing the tota damage the player will do with next attack.
	//--------------------------------------------------------------------------------------
	int CalculateDamage(EWeapon eType, int level, int bonus);

	//--------------------------------------------------------------------------------------
	// Calculate the Heuristic using the Diagonal Shortcut method to get from the start
	// position to the destination position.
	//
	// Param:
	//		nCurrentX: start X position
	//		nCurrentZ: start Z position
	//		nDestX: destination X position
	//		nDestZ: destination Z position
	// Return:
	//		Returns the cost to move one space on the path.
	//--------------------------------------------------------------------------------------
	int CalculateHeuristic(int nCurrentX, int nCurrentZ, int nDestX, int nDestZ);

	//--------------------------------------------------------------------------------------
	// Calculates the index of a node adjacent to a specified node in a square grid.
	//
	// Param:
	//		nNodeX: The X index of the node to check.
	//		nNodeZ: The Z index of the node to check.
	//		nAdjacentID: Which adjacent node to calulcate
	// Return:
	//		The index of the adjacent node.
	//--------------------------------------------------------------------------------------
	int CalculateAdjacency(int nNodeX, int nNodeZ, int nAdjacentID);

private:
	//Currently equipped weapon.
	EWeapon m_eEquipedWeapon;

	//Maximum grid size X and Z.
	int m_nSizeX;
	int m_nSizeZ;
};

