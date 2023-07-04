#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct ActividadesComp {
	bool operator()(pair<int, int> const& a1, pair<int, int> const& a2) {
		return a1.second < a2.second || (a1.second == a2.second && a1.first < a2.first);
	}
};

void repartirTarea(pair<int, int> const& t, vector<pair<int, int>> &v) {
	bool repartido = false;
	int i = 0;
	while (i < v.size() && !repartido) {
		if (v[i].second <= t.first) {
			v[i] = t;
			repartido = true;
		}
		else {
			++i;
		}
	}
	if (!repartido) {
		v.push_back(t);
	}
}

bool resuelveCaso() {
	int numActividades, actBeg, actEnd;

	cin >> numActividades;
	if (numActividades == 0)
		return false;

	vector<pair<int, int>> actividades;
	for (int i = 0; i < numActividades; ++i) {
		cin >> actBeg >> actEnd;
		actividades.push_back({ actBeg, actEnd });
	}
	sort(actividades.begin(), actividades.end(), ActividadesComp());

	int numNecesarios=1;

	for (int i = 1; i < numActividades; ++i) {
		bool asignado = false;
		int j = i - numNecesarios;
		while (j != i && !asignado) {
			if (actividades[j].second <= actividades[i].first) {
				asignado = true;
			}
			++j;
		}
		if (!asignado) ++numNecesarios;
	}

	cout << numNecesarios - 1 << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}