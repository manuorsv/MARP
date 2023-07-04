#include <iostream>
using namespace std;
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"
#include <climits>

void resolver(GrafoDirigidoValorado<int> const& g, int from, vector<int> &distTo) {
	IndexPQ<int> pq(g.V() + 1);
	distTo[from] = 0;
	pq.push(from, 0);
	pair<int, int> p;
	while (!pq.empty()) {
		p.first = pq.top().elem;
		p.second = pq.top().prioridad;
		pq.pop();
		for (AristaDirigida<int> e : g.ady(p.first)) {
			int w = e.to();
			if (distTo[w] > distTo[p.first] + e.valor()) {
				distTo[w] = distTo[p.first] + e.valor();
				pq.update(w, distTo[w]);
			}
		}
	}
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!std::cin)
		return false;

	int S, T, P; 
	cin >> S >> T >> P;
	GrafoDirigidoValorado<int> g(N + 1);
	int to, from, tmp;
	for (int i = 0; i < P; ++i) {
		cin >> from >> to >> tmp;
		AristaDirigida<int> e(to, from, tmp);
		g.ponArista(e);
	}
	vector<int> distTo(g.V() + 1, INT_MAX);
	int sol = 0;
	resolver(g, S, distTo);
	for (int i = 1; i <= N; ++i) {
		if (i != S) {
			if (distTo[i] <= T) ++sol;
		}
	}
	cout << sol << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}