#pragma once
#ifndef _LEVELMAP_H
#define _LEVELMAP_H

using namespace std;
#include "constants.h"

class LevelMap
{
public:
	LevelMap(int map[MAP_HEIGHT][MAP_WIDTH]);
	~LevelMap();

	int GetTileAt(unsigned int h, unsigned int w);
	void ChangeTileAt(unsigned int row, unsigned int column, unsigned int mew_value);

private:
	int** m_map;
};

#endif //_LEVELMAP_H