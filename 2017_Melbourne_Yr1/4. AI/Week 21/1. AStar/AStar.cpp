#include "AStar.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}

bool AStar::CalculatePath(AStarNode* pStart, AStarNode* pEnd, vector<AStarNode*>* finishedPath)
{
	// Reset everything incase there was a previous path.
	// Add start node to open list.

	//While there are still nodes in the open list
		//Get the node from the open list with the lowest F Score, we'll call that currentNode.
		//Remove currentNode from the open list.
		//Add currentNode to the closed list.

		//if currentNode is the end node, we are finished.
			//Build path (remember it is backwards so we need to fix that)
			//Return that we found a valid path.

		//Loop through all of currentNode's neighbours
			//Skip neighbours that are already in the closed list.
			
			//if neighbour is already in open list...
				//Check if this current path is better than old path (lower F Score).
					//Update G Score.
					//Update F Score.
					//Update Prev node pointer.

			//else (neighbour not in open list)
				//Calculate G Score.
				//Calculate H Score.
				//Calculate F Score.
				//Set Prev node pointer.
				//Add neighbour to open list.



	//No path found if we got to here, so return false.
}

void AStar::SortOpenList()
{
	for (size_t i = 0; i < m_OpenList.size(); ++i)
	{
		for (size_t j = 0; j < m_OpenList.size() - 1; ++j)
		{
			if (m_OpenList[j]->m_nFScore > m_OpenList[j + 1]->m_nFScore)
			{
				AStarNode* swap = m_OpenList[j];
				m_OpenList[j] = m_OpenList[j + 1];
				m_OpenList[j + 1] = swap;
			}
		}
	}
}