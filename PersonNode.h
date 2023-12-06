#pragma once

#include "PersonInfo.h"
using namespace std;

#include <string>

struct PersonNode {
public:
	PersonInfo data;
	PersonNode* next;
	PersonNode* prev;

	explicit PersonNode(PersonInfo person);
};
