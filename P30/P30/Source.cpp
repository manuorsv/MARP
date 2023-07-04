#include <iostream>
using namespace std;
#include "Grafo.h"
#include <vector>

int grupoAmigos(vector<int> const& ady, int amigo, vector<bool> &visitado, Grafo const& g) {
	int tamGrupoAmigos = 1;
	visitado[amigo] = true;
	for (int i = 0; i < ady.size(); ++i) {
		if (visitado[ady[i]] == false) {
		tamGrupoAmigos += grupoAmigos(g.ady(ady[i]), ady[i], visitado, g);
		}
	}
	return tamGrupoAmigos;
}

void resuelveCaso() {
	int numAmigos, numParejas, a1, a2, maxAmigos = 0, numGrupo;

	cin >> numAmigos;

	vector<bool> verticeVisitado(numAmigos + 1);
	fill(verticeVisitado.begin() + 1, verticeVisitado.end(), false);
	Grafo parejasAmigos(numAmigos + 1);
	cin >> numParejas;
	for (int i = 0; i < numParejas; ++i) {
		cin >> a1 >> a2;
		parejasAmigos.ponArista(a1, a2);
	}
	for (int i = 1; i <= numAmigos; ++i) {
		numGrupo = grupoAmigos(parejasAmigos.ady(i), i, verticeVisitado, parejasAmigos);
		if (numGrupo > maxAmigos) {
			maxAmigos = numGrupo;
		}
	}

	cout << maxAmigos << '\n';

}


int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	return 0;
}