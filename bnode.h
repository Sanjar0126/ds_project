#pragma once
#ifndef BNODE_H
#define BNODE_H
#include "Book.h"

struct booknode {
    Book data;
    struct booknode* next;
};
#endif