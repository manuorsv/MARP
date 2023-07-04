#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!std::cin)
		return false;

	vector<int> ataques(N);
	int n_personas;
	for (int i = 0; i < N; ++i) {
		cin >> n_personas;
		ataques[i] = n_personas;
	}
	sort(ataques.begin(), ataques.end(), std::greater<int>());
	vector<int> defensa(N);
	for (int i = 0; i < N; ++i) {
		cin >> n_personas;
		defensa[i] = n_personas;
	}
	sort(defensa.begin(), defensa.end(), std::greater<int>());
	
	int sol = 0, j = 0;
	for (int i = 0; i < N; ++i) {
		if (defensa[j] >= ataques[i]) {
			++sol;
			++j;
		}		
	}

	cout << sol << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}