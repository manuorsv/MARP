#include <iostream>
using namespace std;
#include "Grafo.h"
#include <vector>
#include <queue>

bool resuelveCaso() {
	int V, A;
	cin >> V;
	if (!std::cin)
		return false;

	cin >> A;
	Grafo g(V);
	int v1, v2;
	for (int i = 0; i < A; ++i) {
		cin >> v1 >> v2;
		g.ponArista(v1, v2);
	}

	vector<pair<bool, int>> visitado(V, { false,-1 });
	queue<pair<int,int>> q;
	q.push({ 0,-1 });
	int count = 0;
	pair<int, int> nodo;
	bool esLibre = true;
	while (!q.empty() && esLibre) {
		nodo = q.front();
		q.pop();
		visitado[nodo.first] = {true, nodo.second};
		++count;
		for (int v : g.ady(nodo.first)) {
			if(!visitado[v].first)
				q.push({ v,nodo.first });
			else if (v != nodo.second) {
				esLibre = false;
				break;
			}
		}
		if (!esLibre) break;
	}

	if (count == V && esLibre) cout << "SI\n";
	else cout << "NO\n";
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}