#include "Graph.h"
#include <queue>
using namespace std;

Graph::Graph(int _n) {
	n = _n;
	matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;
}

Graph::Graph(int** array, int _n):
	Graph(_n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = array[i][j];
}

Graph::Graph(const Graph& g):
	Graph(g.matrix,g.n){}

Graph::~Graph() {
	for (int i = 0; i < n; i++)
		delete matrix[i];
	delete[]matrix;
}

void Graph::addEdge(int i, int j, int weight) {
	if (i < n && j < n && i >= 0 && j >= 0)
		matrix[i][j] = matrix[j][i] = 1;
}

void Graph::deleteEdge(int i, int j) {
	matrix[i][j] = matrix[j][i] = 0;
}

void Graph::deleteVertex(int cur) {
	int** matr = new int* [n];
	for (int i = 0; i < n - 1; i++)
		matr[i] = new int[n - 1];
	for (int i = 0; i < cur; i++) {
		for (int j = 0; j < cur; j++)
			matr[i][j] = matrix[i][j];
		for (int j = cur + 1; j < n; j++)
			matr[i][j] = matrix[i][j];
	}
	for (int i = cur + 1; i < n; i++) {
		for (int j = 0; j < cur; j++)
			matr[i][j] = matrix[i][j];
		for (int j = cur + 1; j < n; j++)
			matr[i][j] = matrix[i][j];
	}
	for (int i = 0; i < n; i++)
		delete matrix[i];
	delete[]matrix;
	matrix = matr;
}

void Graph::dfs(int cur, bool*& visit) {
	visit[cur] = true;
	for (int i = 0; i < n; i++)
		if (matrix[i][cur] == 1 && visit[i] == false)
			dfs(i, visit);
}

void Graph::dfs(int cur, bool*& visit, int& vertex) {
	visit[cur] = true;
	vertex++;
	for (int i = 0; i < n; i++)
		if (matrix[i][cur] == 1 && visit[i] == false)
			dfs(i, visit, vertex);
}

void Graph::bfs(int cur, bool*& visit) {
	queue<int> q; visit[cur] = true; int tmp;
	q.push(cur);
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		for(int i=0;i<n;i++)
			if (matrix[i][tmp] == 1 && visit[i] == false) {
				visit[i] = true;
				q.push(i);
			}
	}
}

void Graph::DFS() {
	bool* visit = new bool[n];
	for (int i = 0; i < n; i++)
		visit[i] = false;
	for (int i = 0; i < n; i++)
		if (visit[i] == false)
			dfs(i, visit);
}

void Graph::BFS() {
	bool* visit = new bool[n];
	for (int i = 0; i < n; i++)
		visit[i] = false;
	for (int i = 0; i < n; i++)
		if (visit[i] == false)
			bfs(i, visit);
}

int Graph::wires(int** array, int* external, int _n) {
	//Считаем рёбра
	int Edges = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (array[i][j] > 0)
				Edges++;
	Edges = Edges / 2;

	// Разбиваем на компоненты связности и считаем рёбра
	int vertex; int res = 0; int assocVertex = 0; int MaxConnComp = 0;
	bool* visit = new bool[n];
	for (int i = 0; i < n; i++)
		visit[i] = false;
	for (int i = 0; i < n; i++) {
		if (visit[i] == false && external[i] == 1) {
			vertex = 0;
			dfs(i, visit, vertex);
			assocVertex += vertex;
			res += vertex * (vertex - 1) / 2;
			if (vertex > MaxConnComp)
				MaxConnComp = vertex;
		}
	}
	int LeftVertex = n - assocVertex;
	res += LeftVertex * (LeftVertex - 1) / 2;
	res += LeftVertex * MaxConnComp;
	res -= Edges;

	return res;
}
