#include <iostream>
using namespace std;
#include "ConjuntosDisjuntos.h"
#include "Matriz.h"
#include <vector>

bool resuelveCaso() {
	int f,c;

	cin >> f;
	if (!std::cin)
		return false;

	cin >> c;
	getchar();
	Matriz<char> rejilla(f,c);
	ConjuntosDisjuntos cd(f * c);
	vector<int> sol;
	char e;
	int max = 0;
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) {
			e = getchar();
			rejilla[i][j] = e;
			if (e == '#') {
				if (rejilla.posCorrecta(i - 1, j - 1) && rejilla[i - 1][j - 1] == '#') cd.unir(i * c + j, (i - 1) * c + j - 1);
				if (rejilla.posCorrecta(i - 1, j) && rejilla[i - 1][j] == '#') cd.unir(i * c + j, (i - 1) * c + j);
				if (rejilla.posCorrecta(i - 1, j + 1) && rejilla[i - 1][j + 1] == '#') cd.unir(i * c + j, (i - 1) * c + j + 1);
				if (rejilla.posCorrecta(i, j - 1) && rejilla[i][j - 1] == '#') cd.unir(i * c + j, i * c + j - 1);
				if (max < cd.tam(i * c + j)) max = cd.tam(i * c + j);
			}
		}
		getchar();
	}
	sol.push_back(max);

	int k, fi, ci;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> fi >> ci;
		--fi;
		--ci;
		rejilla[fi][ci] = '#';
		if (rejilla.posCorrecta(fi - 1, ci - 1) && rejilla[fi - 1][ci - 1] == '#') cd.unir(fi * c + ci, (fi - 1) * c + ci - 1);
		if (rejilla.posCorrecta(fi - 1, ci) && rejilla[fi - 1][ci] == '#') cd.unir(fi * c + ci, (fi - 1) * c + ci);
		if (rejilla.posCorrecta(fi - 1, ci + 1) && rejilla[fi - 1][ci + 1] == '#') cd.unir(fi * c + ci, (fi - 1) * c + ci + 1);
		if (rejilla.posCorrecta(fi, ci - 1) && rejilla[fi][ci - 1] == '#') cd.unir(fi * c + ci, fi * c + ci - 1);
		if (rejilla.posCorrecta(fi, ci + 1) && rejilla[fi][ci + 1] == '#') cd.unir(fi * c + ci, fi * c + ci + 1);
		if (rejilla.posCorrecta(fi + 1, ci - 1) && rejilla[fi + 1][ci - 1] == '#') cd.unir(fi * c + ci, (fi + 1) * c + ci - 1);
		if (rejilla.posCorrecta(fi + 1, ci) && rejilla[fi + 1][ci] == '#') cd.unir(fi * c + ci, (fi + 1) * c + ci);
		if (rejilla.posCorrecta(fi + 1, ci + 1) && rejilla[fi + 1][ci + 1] == '#') cd.unir(fi * c + ci, (fi + 1) * c + ci + 1);
		if (max < cd.tam(fi * c + ci)) max = cd.tam(fi * c + ci);
		sol.push_back(max);
	}
	cout << sol[0];
	for (int i = 1; i < sol.size(); ++i) {
		cout << ' ' << sol[i];
	}
	cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}