#include <iostream>
using namespace std;
#include "Grafo.h"
#include <vector>

int resolver(Grafo const& g, int u, vector<bool>& m, vector<int> &misma_sol) {
	m[u] = true;
	misma_sol.push_back(u);
	int sol = 1;
	for (int w : g.ady(u)) {
		if (!m[w]) {
			m[w] = true;
			sol += resolver(g, w, m, misma_sol);
		}
	}
	return sol;
}

bool resuelveCaso() {
	int nUsuarios, nGrupos;

	cin >> nUsuarios;
	if (!std::cin)
		return false;

	Grafo g(nUsuarios+1);
	cin >> nGrupos;
	int numPersonasGrupo, idUsuario, aux;
	for (int i = 0; i < nGrupos; ++i) {
		cin >> numPersonasGrupo;
		if(numPersonasGrupo !=0 ) cin >> aux;
		for (int j = 1; j < numPersonasGrupo; ++j) {
			cin >> idUsuario;
			g.ponArista(aux, idUsuario);
			aux = idUsuario;
		}
	}
	vector<bool> marked(nUsuarios + 1, false);
	vector<int> sol(nUsuarios + 1, 0);
	int solucion;
	for (int i = 1; i <= nUsuarios; ++i) {
		if (sol[i] == 0) {
			vector<int> misma_sol;
			solucion = resolver(g, i, marked, misma_sol);
			for (int j = 0; j < misma_sol.size(); ++j) {
				sol[misma_sol[j]] = solucion;
			}
		}
	}

	cout << sol[1];
	for (int i = 2; i <= nUsuarios; ++i) {
		cout << ' ' << sol[i];
	}
	cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}