#include <iostream>
using namespace std;
#include "Grafo.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"
#include <vector>

struct ActividadesComp {
	bool operator()(pair<int, int> const& a1, pair<int, int> const& a2) {
		return a1.second > a2.second || (a1.second == a2.second && a1.first > a2.first);
	}
};

bool resuelveCaso() {
	int N, C;

	cin >> N;
	if (!std::cin) return false;

	cin >> C;
	int to, from;
	Grafo g(N + 1);
	for (int i = 0; i < C; ++i) {
		cin >> to >> from;
		g.ponArista(to, from);
	}
	pair<int, int> par_v_tamady;
	PriorityQueue<pair<int, int>, ActividadesComp> pq;
	for (int i = 1; i <= N; ++i) {
		par_v_tamady = { i, g.ady(i).size() };
		pq.push(par_v_tamady);
	}

	ConjuntosDisjuntos c(N + 1);
	vector<bool> marked(N + 1, false);
	int i, ad;
	int descontar = 1;
	bool imposible = false;
	while (!pq.empty() && !imposible) {
		pq.pop(par_v_tamady);
		i = par_v_tamady.first;
		ad = par_v_tamady.second;
		if (!marked[i]) {
			marked[i] = true;
			if (ad == 0) ++descontar;
			else {
				for (int w : g.ady(i)) {
					if (!marked[w]) {
						marked[w] = true;
						c.unir(w, i);
					}
				}
			}
		}
		else {
			for (int w : g.ady(i)) {
				if (c.unidos(i, w) && c.buscar(i) != i && c.buscar(w) != w) {  //Estan unidos y la interseccion con guardia no es ninguna de las dos --> Queda una calle sin poder cubrir
					imposible = true;
					break;
				}
			}
		}
	}

	if (imposible) cout << "IMPOSIBLE\n";
	else cout << c.num_cjtos() - descontar << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}