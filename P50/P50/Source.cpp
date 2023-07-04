#include <iostream>
using namespace std;
#include <vector>

bool resuelveCaso() {
	int numAgujeros, longCinta, numCintas = 0, posAgujero;
	vector<pair<int,int>> manguera;

	cin >> numAgujeros;
	if (!std::cin) {
		return false;
	}

	cin >> longCinta;

	for (int i = 0; i < numAgujeros; ++i) {
		cin >> posAgujero;
		if (manguera.empty()) {
			manguera.push_back({ posAgujero, posAgujero + longCinta });
			++numCintas;
		}
		else {
			if (manguera[i - 1].second < posAgujero) {
				++numCintas;
				manguera.push_back({ posAgujero, posAgujero + longCinta });
			}
			else {
				manguera.push_back({ posAgujero, manguera[i - 1].second });
			}
		}
	}

	cout << numCintas << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}