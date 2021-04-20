#pragma once
#include <fstream>
using namespace std;

class Graph {
	int n;
	int** matrix;
public:
	Graph(int _n);
	Graph(int** array, int _n);
	Graph(const Graph& g);
	~Graph();
	void addEdge(int i, int j, int weight = 1);
	void deleteEdge(int i, int j);
	void deleteVertex(int cur);
private:
	void dfs(int cur, bool*& visit);
	void dfs(int cur, bool*& visit, int& vertex);
	void bfs(int cur, bool*& visit);
public:
	void DFS();
	void BFS();
	int wires(int** array, int* external, int _n);
};