//Manuel Ortega Salvador, DG20

#include <iostream>
using namespace std;
#include "TreeMap_AVL.h"
#include <vector>


template <class T>
int resolver(map<T, T> const& avl, T k, T &k2) {
	if (avl.empty()) return -1;
	else if (k == avl.numElemsIzq() + k2) {
		return avl.root();
	}
	else if (avl.numElemsIzq() + k2 < k) {
		int kaux = avl.numElemsIzq() + k2;
		return resolver(avl.right(), k, kaux);
	}
	else if (k < avl.numElemsIzq() + k2) {
		return resolver(avl.left(), k, k2);
	}
}

bool resuelveCaso() {
	int numClaves, clave, numCheck, valueCheck, sol, altaux = 0;
	map<int, int> AVL;

	cin >> numClaves;
	if (numClaves == 0) return false;

	for (int i = 0; i < numClaves; ++i) {
		cin >> clave;
		AVL.insert({ clave, 0 });
	}

	cin >> numCheck;
	for (int i = 0; i < numCheck; ++i) {
		cin >> valueCheck;
		sol = resolver(AVL, valueCheck, altaux);
		if (sol == -1) cout << "??\n";
		else cout << sol << '\n';
	}

	cout << "----" << '\n';

	return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}