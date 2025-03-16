//
// Created by szymon on 3/16/25.
//

#ifndef NUMBERTILE_H
#define NUMBERTILE_H
#include "ValueTile.h"


class NumberTile : public ValueTile<int> {
public:
    NumberTile() = delete;

    explicit NumberTile(int ordinal, int number);

    int getValue() const override;
};


#endif //NUMBERTILE_H
