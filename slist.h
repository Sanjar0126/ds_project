#pragma once
#ifndef SLIST_H
#define SLIST_H
#include "snode.h"

class StudentList {
protected:
	studentnode* uhead, * utail;
public:
	StudentList() {
		uhead = NULL;
		utail = NULL;
	}
};
#endif 