#include "plist.h"
#pragma once

class AddingExistingItem {};

class RemovingExistingItem {};

class UList : public PList
{
public:
    void add(int value, int num);
    bool exist(int value);
    void delValue(int value);
};
