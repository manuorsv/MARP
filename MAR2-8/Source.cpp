#include <iostream>
using namespace std;
#include "Matriz.h"
#include <vector>
#include <algorithm>
#include <climits>

bool resuelveCaso() {
	int l, n;
	cin >> l >> n;
	if (l == 0 && n == 0)
		return false;

	vector<int> cortes(n+2);
	int c;
	cortes[0] = 0;
	for (int i = 1; i < n+1; ++i) {
		cin >> c;
		cortes[i] = c;
	}
	cortes[n + 1] = l;
	Matriz<int> m(n + 2, n + 2, 0);

	for (int j = 0; j < n + 2; ++j) {
		for (int i = j - 2; i >= 0; --i) {
			int minim = INT_MAX;
			for (int k = i + 1; k < j; ++k) {
				minim = min(minim, m[i][k] + m[k][j]);
			}
			m[i][j] = minim + 2*(cortes[j] - cortes[i]);
		}
	}
	cout << m[0][n + 1] << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}