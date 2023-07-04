#include <iostream>
using namespace std;
#include <vector>
#include "Matriz.h"
#include <climits>
#include <algorithm>



bool resuelveCaso() {
	int N;
	cin >> N;
	if (!std::cin)
		return false;

	int PMax, PMin;
	cin >> PMax >> PMin;

	vector <pair<int, int>> bombillas(N);
	int potencia, coste;
	for (int i = 0; i < N; ++i) {
		cin >> potencia;
		bombillas[i].first = potencia;
	}
	for (int i = 0; i < N; ++i) {
		cin >> coste;
		bombillas[i].second = coste;
	}

	vector<int> v(PMax + 1, INT_MAX);
	v[0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = PMax; j >= 0; --j) {
			int minC = INT_MAX;
			for (int k = 0; k * bombillas[i - 1].first <= j; ++k) {
				if (v[j - k * bombillas[i - 1].first] != INT_MAX) minC = min(minC, v[j - k * bombillas[i - 1].first] + k * bombillas[i - 1].second);
			}
			v[j] = minC;
		}
	}

	int minP = PMax;
	for (int i = PMax-1; i >= PMin; --i) {
		if (v[i] <= v[minP]) minP = i;
	}

	if (v[minP] != INT_MAX) cout << v[minP] << ' ' << minP << '\n';
	else cout << "IMPOSIBLE\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}