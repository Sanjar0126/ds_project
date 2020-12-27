#pragma once
#ifndef SNODE_H
#define SNODE_H
#include "Student.h"

struct studentnode {
    Student data;
    struct studentnode* next;
};
#endif