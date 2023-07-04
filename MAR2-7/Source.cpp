#include <iostream>
using namespace std;
#include <vector>
#include "Matriz.h"
#include <algorithm>


bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;

	int c;
	vector<int> cubos(n);
	Matriz<int> m(n, n, 0);		//Max comida posible seleccionando desde el cubo i al j

	for (int i = 0; i < n; ++i) {
		cin >> c;
		cubos[i] = c;
	}

	for (int i = 0; i < n; ++i) m[i][i] = cubos[i];
	
	int v1, v2;
	for (int j = 0; j < n; ++j) {
		for (int i = j-1; i >= 0; --i) {
			//Cogemos el del extremo izquierdo
			if (j - i == 1) v1 = cubos[i];
			else if (cubos[i + 1] >= cubos[j]) v1 = cubos[i] + m[i + 2][j];
			else v1 = cubos[i] + m[i + 1][j - 1];
			//Cogemos el del extremo derecho
			if (j - i == 1) v2 = cubos[j];
			else if (cubos[j - 1] >= cubos[i]) v2 = cubos[j] + m[i][j - 2];
			else v2 = cubos[j] + m[i + 1][j - 1];

			m[i][j] = max(v1, v2);
		}
	}

	cout << m[0][n - 1] << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}