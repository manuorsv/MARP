using namespace std;
#include "PriorityQueue.h"

void resolver(PriorityQueue<int, std::greater<int>> &p9, PriorityQueue<int, std::greater<int>> &p1, int n, int &sol) {
	vector<int> pilas_usadas9v, pilas_usadas1v;
	for (int i = 0; i < n;  ++i) {
		int pila9v, pila1v;
		p9.pop(pila9v);
		p1.pop(pila1v);
		if (pila1v < pila9v) {
			pila9v -= pila1v;
			pilas_usadas9v.push_back(pila9v);
			sol += pila1v;
		}
		else if (pila9v < pila1v) {
			pila1v -= pila9v;
			pilas_usadas1v.push_back(pila1v);
			sol += pila9v;
		}
		else {
			sol += pila9v;
		}

		if (p9.empty() || p1.empty()) {
			break;
		}
	}
	for (int i = 0; i < pilas_usadas9v.size(); ++i) {
		p9.push(pilas_usadas9v[i]);
	}
	for (int i = 0; i < pilas_usadas1v.size(); ++i) {
		p1.push(pilas_usadas1v[i]);
	}
}

bool resuelveCaso() {
	int n9, n1, numDrones;

	cin >> numDrones >> n9 >> n1;
	if (!std::cin)
		return false;

	PriorityQueue<int, std::greater<int>> pilas9, pilas1;
	int durp;
	for (int i = 0; i < n9; ++i) {
		cin >> durp;
		pilas9.push(durp);
	}
	
	for (int i = 0; i < n1; ++i) {
		cin >> durp;
		pilas1.push(durp);
	}

	vector<int> tiempos;
	int sol;
	while (!pilas9.empty() && !pilas1.empty()) {
		sol = 0;
		resolver(pilas9, pilas1, numDrones, sol);
		tiempos.push_back(sol);
	}

	if (!tiempos.empty()) cout << tiempos[0];
	for (int i = 1; i < tiempos.size(); ++i) {
		cout << ' ' << tiempos[i];
	}
	cout << '\n';

	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}