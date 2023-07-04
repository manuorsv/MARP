#include <iostream>
using namespace std;
#include "Grafo.h"
#include <vector>

struct Coloreado {
	int color;
	bool visitado;
};

bool esBipartito(Grafo const& g, vector<int> const& ady, vector <Coloreado> &v, int num, int color) {
	int colorNext;
	bool esBip = true;

	if (!v[num].visitado) v[num] = { color, true };

	if (color == 1) colorNext = 2;
	else colorNext = 1;

	for (int i = 0; i < ady.size(); ++i) {
		if (!v[ady[i]].visitado) {
			esBip = esBip && esBipartito(g, g.ady(ady[i]), v, ady[i], colorNext);
		}
		else {
			if (v[ady[i]].color == v[num].color) return false;
			else esBip = true;
		}
	}

	return esBip;
}

bool resuelveCaso() {
	int numV, numA, e1, e2;

	cin >> numV;
	if (!std::cin)
		return false;

	Grafo g(numV);
	vector<Coloreado> verticesColor(numV);
	Coloreado aux = { 0, false };
	fill(verticesColor.begin(), verticesColor.end(), aux);

	cin >> numA;
	for (int i = 0; i < numA; ++i) {
		cin >> e1 >> e2;
		g.ponArista(e1, e2);
	}

	bool esBip = true;
	int i = 0;
	while (esBip && i < numV) {
		esBip = esBipartito(g, g.ady(i), verticesColor, i, 1);
		++i;
	}

	if (esBip) cout << "SI\n";
	else cout << "NO\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}