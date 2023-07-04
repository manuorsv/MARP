#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


void resuelveCaso() {
	int numPilas, voltajeNec, volt, numCoches=0;
	vector<int> pilas;

	cin >> numPilas >> voltajeNec;
	for (int i = 0; i < numPilas; ++i) {
		cin >> volt;
		pilas.push_back(volt);
	}
	sort(pilas.begin(), pilas.end());

	int i = 0, j = pilas.size() - 1;
	while (i < j) {
		if (pilas[i] + pilas[j] >= voltajeNec) {
			++numCoches;
			--j;
			++i;
		}
		else {
			++i;
		}
	}

	cout << numCoches << '\n';
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}
	return 0;
}