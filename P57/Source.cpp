#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	int C, F, N;

	cin >> C >> F >> N;
	if (C == 0 && F == 0 && N == 0)
		return false;
	
	int ini, fin;
	vector<pair<int, int>> trabajos;
	for (int i = 0; i < N; ++i) {
		cin >> ini >> fin;
		trabajos.push_back({ ini,fin });
	}
	sort(trabajos.begin(), trabajos.end());
	int minTrabajos = 0, finIntervalo = C;
	pair<int, int> ultTabajo;
	if (N != 0) ultTabajo = trabajos[0];
	bool imposible = false, salir = false;
	int i = 0;
	while (i < N && !imposible && !salir) {
		if (trabajos[i].first > finIntervalo) {
			if (ultTabajo.first <= finIntervalo) {
				++minTrabajos;
				finIntervalo = ultTabajo.second;
				ultTabajo = trabajos[i];
			}
			else imposible = true;
		}
		if (finIntervalo >= F) salir = true;
		if (trabajos[i].first <= finIntervalo && !salir) {
			if (trabajos[i].second >= ultTabajo.second) ultTabajo = trabajos[i];
		}
		++i;
	}
	if (!salir) {
		if (ultTabajo.first <= finIntervalo) {
			++minTrabajos;
			finIntervalo = ultTabajo.second;
		}
		else imposible = true;
	}
	if (finIntervalo < F)  imposible = true;

	if (imposible) cout << "Imposible\n";
	else cout << minTrabajos << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
