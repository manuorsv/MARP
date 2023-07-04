#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct EdificioComparator {
	bool operator ()(pair<int, int> const& e1, pair<int, int> const& e2) {
		return e1.first < e2.first || ((e1.first == e2.first) && (e1.second < e2.second));
	}
};


bool resuelveCaso() {
	int numEdificios, extL, extR;

	cin >> numEdificios;
	if (numEdificios == 0)
		return false;

	vector<pair<int, int>> edificios;

	for (int i = 0; i < numEdificios; ++i) {
		cin >> extL >> extR;
		edificios.push_back({ extL, extR });
	}
	sort(edificios.begin(), edificios.end(), EdificioComparator());

	int i = 1, numTuneles = 1;
	pair< int, int > edif = edificios[0];

	while (i < numEdificios) {
		if (edificios[i].second < edif.second) {
			edif = edificios[i];
		}
		else if (edificios[i].first >= edif.second) {
			++numTuneles;
			edif = edificios[i];
		}
		++i;
	}

	cout << numTuneles << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}