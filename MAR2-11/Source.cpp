#include <iostream>
using namespace std;
#include <vector>
#include "Matriz.h"
#include <algorithm>

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!std::cin)
		return false;

	Matriz<int> m(N, N, 0);
	vector<int> trozos(N);

	int f;
	for (int i = 0; i < N; ++i) {
		cin >> f;
		trozos[i] = f;
	}

	int v1, v2, v3;
	for (int j = 0; j < N; ++j) {
		for (int i = j - 1; i >= 0; --i) {
			//if ((j - i - 1) % 2 == 0) {
				if (j - i == 1) {
					if ((trozos[i] == 1 && trozos[j] == 1) || (trozos[i] == 2 && trozos[j] == 2)) m[i][j] = 1;
					else m[i][j] = 0;
				}
				else {
					//Cogemos ambos extremos izquierdo y derecho
					if ((trozos[i] == 1 && trozos[j]==1) || (trozos[i]==2 && trozos[j]==2)) v1 = 1 + m[i + 1][j - 1];
					else v1 = m[i + 1][j - 1];
					//Cogemos ambos extremo derecho
					if ((trozos[j] == 1 && trozos[j - 1] == 1) || (trozos[j] == 2 && trozos[j - 1] == 2)) v2 = 1 + m[i][j - 2];
					else v2 = m[i][j - 2];
					//Cogemos ambos extremo izquierdo
					if ((trozos[i] == 1 && trozos[i + 1] == 1) || (trozos[i] == 2 && trozos[i + 1] == 2)) v3 = 1 + m[i + 2][j];
					else v3 = m[i + 2][j];

					m[i][j] = max(v1, max(v2, v3));
				}
			//}
		}
	}

	cout << m[0][N - 1] << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}