//
// Created by szymon on 3/16/25.
//

#ifndef EMPTYTILE_H
#define EMPTYTILE_H
#include "Tile.h"


class EmptyTile : public Tile {
public:
    EmptyTile() = delete;
    EmptyTile(int ordinal);
};


#endif //EMPTYTILE_H
