#include <iostream>
#include <fstream>
#include "Graph.h"
using namespace std;

void readFile(int**& array, int*& external, ifstream& file, int& n) {
	file >> n; int i, j, weight;

	external = new int[n];
	for (int i = 0; i < n; i++) {
		file >> external[i];
	}

	array = new int* [n];
	for (int i = 0; i < n; i++)
		array[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			array[i][j] = 0;

	while (!file.eof()) {
		file >> i;
		file >> j;
		file >> weight;
		array[i][j] = array[j][i] = weight;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	int** array; int* external; int n;
	ifstream file("file.txt");
	
	readFile(array, external , file, n);
	Graph G(array, n);
	int res = G.wires(array, external, n);
	cout << res << endl;

	return 0;
}