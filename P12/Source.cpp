#include <iostream>
using namespace std;
#include "ConjuntosDisjuntos.h"
#include "Matriz.h"
#include <vector>

bool resuelveCaso() {
	int f, c;

	cin >> f;
	if (!std::cin)
		return false;

	cin >> c;
	getchar();
	Matriz<char> rejilla(f, c);
	ConjuntosDisjuntos cd(f * c);
	vector<int> sol;
	char e;
	int max = 0, count = 0;
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) {
			e = getchar();
			rejilla[i][j] = e;
			if (e == '#') {
				++count;
				if (rejilla.posCorrecta(i - 1, j) && rejilla[i - 1][j] == '#') {
					if (!cd.unidos(i * c + j, (i - 1) * c + j)) {
						cd.unir(i * c + j, (i - 1) * c + j);
						--count;
					}
				}
				if (rejilla.posCorrecta(i, j - 1) && rejilla[i][j - 1] == '#') {
					if (!cd.unidos(i * c + j, i * c + j - 1)) {
						cd.unir(i * c + j, i * c + j - 1);
						--count;
					}
				}
				if (rejilla.posCorrecta(i + 1, j) && rejilla[i + 1][j] == '#') {
					if (!cd.unidos(i * c + j, (i + 1) * c + j))
					{
						cd.unir(i * c + j, (i + 1) * c + j);
						--count;
					}
				}
				if (rejilla.posCorrecta(i, j + 1) && rejilla[i][j + 1] == '#') {
					if (!cd.unidos(i * c + j, i * c + j + 1)) {
						cd.unir(i * c + j, i * c + j + 1);
						--count;
					}
				}
				if (max < cd.tam(i * c + j)) max = cd.tam(i * c + j);
			}
		}
		getchar();
	}
	cout << count << ' ' <<  max << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}