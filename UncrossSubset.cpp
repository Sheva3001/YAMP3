#include "MyList.h"
#include "UncrossSubset.h"

UncrossSubset::UncrossSubset(int _n) {
	n = _n;
	set = new Set[n];
	info = new int[n];
}

void UncrossSubset::makeSet(int x) {
	set[x].count = 1;
	set[x].list = new List;
	set[x].list->addToHead(x);
	info[x] = x;
}

int UncrossSubset::find(int x) {
	return info[x];
}

void UncrossSubset::subsetUnion(int x, int y) {
	if (set[x].list->head == 0)
		set[x].list->head = set[y].list->head;
	else
		set[x].list->tail->next = set[y].list->head;
	set[x].list->tail = set[y].list->tail;
	set[y].list->head = 0;
	set[y].list->tail = 0;
	set[x].count += set[y].count;
	set[y].count = 0;

	List::Node* p = new List::Node;
	p = set[x].list->head;
	while (p) {
		info[p->data] = x;
		p = p->next;
	}
}