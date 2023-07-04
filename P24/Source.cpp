#include <iostream>
using namespace std;
#include "GrafoValorado.h"
#include "IndexPQ.h"
#include <vector>
#include <climits>
#include <queue>

void visitar(GrafoValorado<int> const& g, vector<int>& distTo, vector<int>& numCaminos, int v)  {
	for (Arista<int> e : g.ady(v)) {
		int w = e.otro(v);
		if (distTo[w] > distTo[v] + e.valor()) {
			distTo[w] = distTo[v] + e.valor();
			visitar(g, distTo, numCaminos, w);
			numCaminos[w] = numCaminos[v];
		}
		else if (distTo[w] == distTo[v] + e.valor()) {
			visitar(g, distTo, numCaminos, w);
			++numCaminos[w];
		}
	}
}
void resolver2(GrafoValorado<int> const& g, int from, vector<int>& distTo, vector<int>& numCaminos) {
	distTo[from] = 0;
	visitar(g, distTo, numCaminos, from);
	
}
void resolver3(GrafoValorado<int> const& g, int from, vector<int>& distTo, vector<int>& numCaminos) {
	queue<int> pq;
	distTo[from] = 0;
	numCaminos[from] = 1;
	pq.push(from);
	int p;
	while (!pq.empty()) {
		p = pq.front();
		pq.pop();
		for (Arista<int> e : g.ady(p)) {
			int w = e.otro(p);
			if (distTo[w] > distTo[p] + e.valor()) {
				distTo[w] = distTo[p] + e.valor();
				pq.push(w);
				numCaminos[w] = numCaminos[p];
			}
			else if (distTo[w] == distTo[p] + e.valor()) {
				++numCaminos[w];
			}
		}
	}
}
void resolver(GrafoValorado<int> const& g, int from, vector<int>& distTo, vector<int>& numCaminos) {
	IndexPQ<int> pq(g.V() + 1);
	distTo[from] = 0;
	numCaminos[from] = 1;
	pq.push(from, 0);
	pair<int, int> p;
	while (!pq.empty()) {
		p.first = pq.top().elem;
		p.second = pq.top().prioridad;
		pq.pop();
		for (Arista<int> e : g.ady(p.first)) {
			int w = e.otro(p.first);
			if (distTo[w] > distTo[p.first] + e.valor()) {
				distTo[w] = distTo[p.first] + e.valor();
				pq.update(w, distTo[w]);
				numCaminos[w] = numCaminos[p.first];
			}
			else if (distTo[w] == distTo[p.first] + e.valor()) {
				numCaminos[w] += numCaminos[p.first];
			}
		}
	}
}

bool resuelveCaso() {
	int N, C;
	cin >> N;
	if (!std::cin)
		return false;

	cin >> C;
	int v1, v2, l;
	Arista<int> a;
	GrafoValorado<int> g(N+1);
	for (int i = 0; i < C; ++i) {
		cin >> v1 >> v2 >> l;
		a = { v1, v2, l };
		g.ponArista(a);
	}

	vector<int> distTo(g.V() + 1, INT_MAX);
	vector<int> numCaminos(g.V() + 1, 0);
	int sol = 0;
	resolver(g, 1, distTo, numCaminos);
	cout << numCaminos[N] << '\n';
	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}