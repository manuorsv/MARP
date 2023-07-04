#include <iostream>
using namespace std;
#include "Matriz.h"
#include <vector>
#include <algorithm>
#include <climits>

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!std::cin)
		return false;

	vector<pair<int, int>> monedas(N);
	int valor;
	for (int i = 0; i < N; ++i) {
		cin >> valor;
		monedas[i].first = valor;
	}
	int cant;
	for (int i = 0; i < N; ++i) {
		cin >> cant;
		monedas[i].second = cant;
	}
	int M;
	cin >> M;

	vector<int> v(M + 1, INT_MAX);
	v[0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = M; j >= 0; --j) {
			int minC = INT_MAX;
			for (int k = 0; k <= monedas[i - 1].second && k*monedas[i - 1].first <= j; ++k) {
				if (v[j - k * monedas[i - 1].first] != INT_MAX) minC = min(minC, v[j - k * monedas[i - 1].first]+k);
			}
			v[j] = minC;
		}
	}

	if (v[M]!=INT_MAX) cout << "SI " << v[M] << '\n';
	else cout << "NO\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}