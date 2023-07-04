//Manuel Ortega Salvador, MARP23

#include <iostream>
using namespace std;
#include "bintree_eda.h"

template <typename T>
int altura(bintree<T> const& t) {
	if (t.empty()) return 0;
	else return max(altura(t.left()), altura(t.right())) + 1;
}

template <typename T>
bool esArbolEquilibrado(bintree<T> const& t) {
	if (t.empty()) {
		return true;
	}
	else {
		return esArbolEquilibrado(t.left()) && esArbolEquilibrado(t.right()) && (altura(t.left()) == altura(t.right()) || abs(altura(t.left()) - altura(t.right())) == 1);
	}
}

void resuelveCaso() {
	bintree<char> tree;
	tree = leerArbol('.');
	if (esArbolEquilibrado(tree)) cout << "SI\n";
	else cout << "NO\n";
}

int main() {
	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	return 0;
}