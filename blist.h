#pragma once
#ifndef BLIST_H
#define BLIST_H
#include "bnode.h"

class BookList {
protected:
	booknode* bhead, * btail;
public:
	BookList() {
		bhead = NULL;
		btail = NULL;
	}
};

#endif 