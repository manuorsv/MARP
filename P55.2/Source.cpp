#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	int numPeliculas, duracion, sol = 1;
	int horas, mins;
	vector<pair<int,int>> peliculas;
	char aux;

	cin >> numPeliculas;
	if (numPeliculas == 0)
		return false;

	for (int i = 0; i < numPeliculas; ++i) {
		cin >> horas >> aux>> mins >> duracion;
		int mins_dur = horas * 60 + mins;
		peliculas.push_back({ mins_dur, mins_dur + duracion });
	}
	sort(peliculas.begin(), peliculas.end());

	int j = 0;
	for (int i = 1; i < numPeliculas; ++i) {
		if (peliculas[i].first < peliculas[j].second) {
			if (peliculas[i].second < peliculas[j].second) j = i;
		}
		else if (peliculas[j].second + 10 <= peliculas[i].first) {
			j = i;
			++sol;
		}
	}

	cout << sol << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}