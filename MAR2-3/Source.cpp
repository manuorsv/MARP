#include <iostream>
using namespace std;
#include "Matriz.h"
#include <algorithm>


bool resuelveCaso() {
	int N;
	cin >> N;
	if (!std::cin)
		return false;

	Matriz<int> tablero(N+1, N+1);
	int casilla;
	for (int i = 1; i < N+1; ++i) {
		for (int j = 1; j < N+1; ++j) {
			cin >> casilla;
			tablero[i][j] = casilla;
		}
	}
	for (int i = 0; i < N + 1; ++i)
		tablero[0][i] = 0;
	for (int i = 1; i < N + 1; ++i)
		tablero[i][0] = 0;

	int mejor;
	vector <int> mejorSol = tablero[1];
	int anterior;
	for (int i = 2; i < N + 1; ++i) {
		anterior = 0;
		for (int j = 1; j < N + 1; ++j) {
			if (j < N) mejor = max(anterior, max(mejorSol[j], mejorSol[j + 1]));
			else mejor = max(anterior, mejorSol[j]);
			anterior = mejorSol[j];
			mejorSol[j] = mejor + tablero[i][j];
		}
	}

	int maximo = mejorSol[1];
	int posMaximo = 1;
	for (int j = 2; j < N + 1; ++j) {
		if (mejorSol[j] > maximo) {
			maximo = mejorSol[j];
			posMaximo = j;
		}
	}
	cout << mejorSol[posMaximo] << " " << posMaximo << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}