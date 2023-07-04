#include <iostream>
using namespace std;
#include "GrafoValorado.h"




bool resolver(GrafoValorado<int> const& g, int origen, int destino, int anchura, vector<bool>& v) {
	bool puedeLlegar = false;

	v[origen] = true;

	for (int i = 0; i < g.ady(origen).size(); ++i) {
		if (!v[g.ady(origen)[i].otro(origen)]) {
			if (anchura <= g.ady(origen)[i].valor()) {
				if (g.ady(origen)[i].otro(origen) == destino) {
					return true;
				}
				else {
					puedeLlegar = puedeLlegar || resolver(g, g.ady(origen)[i].otro(origen), destino, anchura, v);
				}
			}
		}
	}

	return puedeLlegar;
}

bool resuelveCaso() {
	int numIntersec, numCalles, anchura, numCamiones, i1, i2, origen, destino;
	bool puedeLlegar;

	cin >> numIntersec;
	if (!std::cin) {
		return false;
	}

	GrafoValorado<int> calles(numIntersec + 1);

	cin >> numCalles;
	for (int i = 0; i < numCalles; ++i) {
		cin >> i1 >> i2 >> anchura;
		Arista<int> a(i1, i2, anchura);
		calles.ponArista(a);
	}

	cin >> numCamiones;
	for (int i = 0; i < numCamiones; ++i) {
		cin >> origen >> destino >> anchura;
		vector<bool> v(numIntersec + 1);
		puedeLlegar = resolver(calles, origen, destino, anchura, v);

		if (puedeLlegar) cout << "SI\n";
		else cout << "NO\n";
	}

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}