#include <iostream>
using namespace std;
#include <vector>
#include "Matriz.h"
#include <string>



bool resuelveCaso() {
	string p;
	cin >> p;
	if (!std::cin)
		return false;

	int n = p.size();
	Matriz<string> m(n + 1, n + 1, "");

	/*for (int i = 0; i < n; ++i) {
		m[i][0] = "";
	}
	for (int j = 0; j < n; ++j) {
		m[0][j] = "";
	}*/
	for (int i = 1; i <= n; ++i) {
		m[i][i] = p[i-1];
	}

	string s1, s2;
	for (int i = n; i > 0; --i) {
		for (int j = i+1; j <= n; ++j) {
			if (p[i - 1] == p[j - 1]) {
				m[i][j] = p[i - 1] + m[i + 1][j - 1] + p[i - 1];
			}
			else {
				s1 = m[i + 1][j];
				s2 = m[i][j - 1];
				if (s1.size() >= s2.size()) m[i][j] = s1;
				else m[i][j] = s2;			
			}
		}
	}

	cout << m[1][n] << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}