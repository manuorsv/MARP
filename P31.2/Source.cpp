#include <iostream>
using namespace std;
#include "Grafo.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"
#include <vector>


bool resuelveCaso() {
	int N, C;

	cin >> N;
	if (!std::cin) return false;

	cin >> C;
	int to, from;
	Grafo g(N+1);
	for (int i = 1; i <= N; ++i) {
		cin >> to >> from;
		g.ponArista(to, from);
	}
	pair<int, int> par_v_tamady;
	PriorityQueue<pair<int, int>, std::greater> pq;
	for (int i = 1; i <= N; ++i) {
		par_v_tamady = { i, g.ady(i).size() };
		pq.push(par_v_tamady);
	}

	ConjuntosDisjuntos c(N + 1);
	vector<bool> marked(N + 1, false);
	int i, ad;
	bool imposible = false;
	while (!pq.empty() && !imposible) {
		pq.pop(par_v_tamady);
		i = par_v_tamady.first;
		ad = par_v_tamady.second;
		if (!marked[i]) {
			marked[i] = true;
			for (int w : g.ady(i)) {
				if (!marked[w]) {
					marked[w] = true;
					c.unir(i, w);
				}
			}
		}
		else {
			for (int w : g.ady(i)) {
				if (unidos(i, w) && buscar(i) != i && buscar(w) != w) {  //Estan unidos y la interseccion con guardia no es ninguna de las dos --> Queda una calle sin poder cubrir
					imposible = true;
					break;
				}			
			}
		}
	}

	if (imposible) cout << "IMPOSIBLE\n";
	else cout << c.num_cjtos - 1 << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}