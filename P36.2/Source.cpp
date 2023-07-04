#include <iostream>
using namespace std;
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"


bool resuelveCaso() {
	int nIslas, nPuentes;

	cin >> nIslas;
	if (!std::cin)
		return false;

	cin >> nPuentes;
	int from, to, coste;
	GrafoValorado<int> g(nIslas+1);
	ConjuntosDisjuntos c(nIslas+1);
	PriorityQueue<Arista<int>> pq;
	for (int i = 0; i < nPuentes; ++i) {
		cin >> from >> to >> coste;
		Arista<int> a(from, to, coste);
		g.ponArista(a);
		pq.push(a);
	}
	
	vector<int> disto(nIslas + 1);
	Arista<int> e;
	int costeMin = 0;
	while (!pq.empty()) {
		pq.pop(e);
		int from = e.uno(), to = e.otro(from);
		if (!c.unidos(from, to)) {
			c.unir(from, to);
			costeMin += e.valor();
		}
	}
	if (c.num_cjtos() > 2) cout << "No hay puentes suficientes\n";
	else cout << costeMin << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}