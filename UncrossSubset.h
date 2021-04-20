#pragma once
#include "MyList.h"

struct Set {
	int count;
	List* list;
};

class UncrossSubset {
	int n;
	Set* set;
	int* info;
public:
	UncrossSubset(int _n);
	void makeSet(int x);
	int find(int x);
	void subsetUnion(int x, int y);
};