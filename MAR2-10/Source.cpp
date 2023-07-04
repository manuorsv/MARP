#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	int nPeliculas;
	cin >> nPeliculas;
	if (nPeliculas == 0)
		return false;

	int horaIni, minIni, minutosFin, dur;
	char c;
	int minutosIni;
	vector<pair<int, int>> peliculas;
	for (int i = 0; i < nPeliculas; ++i) {
		cin >> horaIni >> c >> minIni >> dur;
		minutosIni = horaIni * 60 + minIni;
		peliculas.push_back({ minutosIni, dur });
	}
	sort(peliculas.begin(), peliculas.end());
	vector<int> v(24 * 60 + 10 + 1, 0);

	for (int i = 1; i < nPeliculas+1; ++i) {
		for (int j = 1450; j >= peliculas[i - 1].first + peliculas[i - 1].second + 10; --j) {
			v[j] = max(v[j], v[peliculas[i - 1].first] + peliculas[i - 1].second);
		}
	}

	cout << v[1450] << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}