#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	int numPartidos, puntuacion, ajaj;
	vector<int> rivales, Broncos;

	cin >> numPartidos;
	if (numPartidos == 0)
		return false;

	for (int i = 0; i < numPartidos; ++i) {
		cin >> puntuacion;
		rivales.push_back(puntuacion);
	}
	sort(rivales.begin(), rivales.end());

	for (int i = 0; i < numPartidos; ++i) {
		cin >> puntuacion;
		Broncos.push_back(puntuacion);
	}
	sort(Broncos.begin(), Broncos.end(), greater<int>());

	int i = 0, sumaDif = 0;
	while (i < Broncos.size() && Broncos[i] > rivales[i]) {
		sumaDif += Broncos[i] - rivales[i];
		++i;
	}
	cout << sumaDif << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}