#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include "Matriz.h"

bool resuelveCaso() {
	int T;
	cin >> T;
	if (!std::cin)
		return false;

	int nCofres, prof, oro;
	cin >> nCofres;

	vector <pair<pair<int, int>,bool>> cofres;
	Matriz<int> m(nCofres+1, T+1);					//m[i][j] max oro con i cofres a profundidad j

	for (int i = 0; i < nCofres; ++i) {
		cin >> prof >> oro;
		cofres.push_back({ { prof, oro }, false });
	}

	for (int i = 1; i < T + 1; ++i) m[0][i] = 0;
	for (int i = 0; i < nCofres + 1; ++i) m[i][0] = 0;

	for (int i = 1; i < nCofres + 1; ++i) {
		for (int j = 1; j <= T; ++j) {
			if (3 * cofres[i - 1].first.first > j) m[i][j] = m[i - 1][j];
			else m[i][j] = max(m[i - 1][j], m[i-1][j - 3 * cofres[i - 1].first.first] + cofres[i - 1].first.second);
		}
	}

	int maxCofres = 0;
	int j = T;
	for (int i = nCofres; i > 0; --i) {
		if (m[i][j] != m[i - 1][j]) {
			cofres[i - 1].second = true;
			++maxCofres;
			j -= 3 * cofres[i - 1].first.first;
		}
	}

	cout << m[nCofres][T] << '\n';
	cout << maxCofres << '\n';
	for (int i = 0; i < nCofres; ++i) {
		if (cofres[i].second) {
			cout << cofres[i].first.first << ' ' << cofres[i].first.second << '\n';
		}
	}

	cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}