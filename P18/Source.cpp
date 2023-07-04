#include <iostream>
using namespace std;
#include "Digrafo.h"

bool resuelveCaso() {
	int V, A;

	cin >> V;
	if (!std::cin)
		return false;

	cin >> A;
	int v1, v2;
	Digrafo g1(V), g2(V);
	for (int i = 0; i < A; ++i) {
		cin >> v1 >> v2;
		g1.ponArista(v1, v2);
		g2.ponArista(v2, v1);				//Hacemos el grafo inverso
	}
	bool found = false;
	int i = 0, sumidero;
	while (!found && i < V) {
		if (g2.ady(i).size() == V - 1 && g1.ady(i).empty()) {
			found = true;
			sumidero = i;
		}
		++i;
	}
	if (!found) cout << "NO\n";
	else cout << "SI " << sumidero << '\n';
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}