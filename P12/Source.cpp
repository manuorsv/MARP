//Manuel Ortega Salvador, DG20

#include <iostream>
using namespace std;
#include "TreeMap_AVL.h"
#include <vector>

template <class T>
void resolver(map<T, T> const& avl, T inf, T sup, vector<T> &sol) {
	if (!avl.empty()) {
		if (inf <= avl.root() && avl.root() <= sup) {
			resolver(avl.left(), inf, sup, sol);
			sol.push_back(avl.root());
			resolver(avl.right(), inf, sup, sol);
		}
		else if (avl.root() < inf) {
			resolver(avl.right(), inf, sup, sol);
		}
		else if (sup < avl.root()) {
			resolver(avl.left(), inf, sup, sol);
		}
	}
}

bool resuelveCaso() {
	int numClaves, clave, limInf, limSup;
	map<int, int> AVL;

	cin >> numClaves;
	if (numClaves == 0) return false;

	for (int i = 0; i < numClaves; ++i) {
		cin >> clave;
		AVL.insert({ clave, 0 });
	}

	cin >> limInf >> limSup;
	vector<int> sol;
	resolver(AVL, limInf, limSup, sol);

	if (sol.empty()) cout << '\n';
	else {
		cout << sol[0];
		for (int i = 1; i < sol.size(); ++i) {
			cout << ' ' << sol[i];
		}
		cout << '\n';
	}

	return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}