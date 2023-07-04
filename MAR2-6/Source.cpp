#include <iostream>
using namespace std;
#include "Matriz.h"
#include <unordered_map>
#include <algorithm>
#include <climits>

bool resuelveCaso() {
	int p, r;
	cin >> p;
	if (!std::cin)
		return false;

	cin >> r;
	Matriz<int> m(p,p,INT_MAX);			  //Minima distancia entre persona numero i y la j
	unordered_map<string, int> personas;  //Persona asignada a un numero
	int num = 0;
	string persona1, persona2;
	for (int i = 0; i < r; ++i) {
		cin >> persona1 >> persona2;
		if (!personas.count(persona1)) {
			personas.insert({ persona1, num });
			++num;
		}
		if (!personas.count(persona2)) {
			personas.insert({ persona2, num });
			++num;
		}
		m[personas[persona1]][personas[persona2]] = 1;  //Hay camino entre ambas personas (longitud 1)
		m[personas[persona2]][personas[persona1]] = 1;
	}

	for (int i = 0; i < p; ++i) m[i][i] = 0;

	for (int k = 0; k < p; ++k) {
		for (int i = 0; i < p; ++i) {
			for (int j = 0; j < p; ++j) {
				if (m[i][k] != INT_MAX && m[k][j] != INT_MAX) {
					m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
				}
			}
		}
	}

	int max = 0;
	for (int i = 0; i < p; ++i) {
		for (int j = 0; j < p; ++j) {
			if (max < m[i][j]) max = m[i][j];
		}
	}

	if (max == INT_MAX) cout << "DESCONECTADA\n";
	else cout << max << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}