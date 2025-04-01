//
// Created by szymon on 3/16/25.
//

#ifndef EMPTYTILE_H
#define EMPTYTILE_H
#include "Tile.h"

/**
 * Class representing empty tile. Every n-puzzle game has on of these.
 */
class EmptyTile : public Tile {
public:
    EmptyTile() = delete;

    /**
     * @param ordinal ordinal of this board in a tile
     */
    EmptyTile(int ordinal);
};


#endif //EMPTYTILE_H
