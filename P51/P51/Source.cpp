#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	int numEsquiadores, altura;
	vector<int> esquiadores, esquis;

	cin >> numEsquiadores;
	if (numEsquiadores == 0)
		return false;

	for (int i = 0; i < numEsquiadores; ++i) {
		cin >> altura;
		esquiadores.push_back(altura);
	}
	sort(esquiadores.begin(), esquiadores.end());

	for (int i = 0; i < numEsquiadores; ++i) {
		cin >> altura;
		esquis.push_back(altura);
	}
	sort(esquis.begin(), esquis.end());

	int sumaDif = 0;
	for (int i = 0; i < numEsquiadores; ++i) {
		sumaDif += abs(esquiadores[i] - esquis[i]);
	}
	cout << sumaDif << '\n';

	return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}