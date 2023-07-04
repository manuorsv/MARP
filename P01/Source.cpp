//Manuel Ortega Salvador, MARP23

#include <iostream>
using namespace std;
#include "bintree_eda.h"

struct AVL {
	bool isAVL;
	int max, min;		//Maximo del hijo izquierdo, minimo del hijo derecho
};

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
		return esArbolEquilibrado(t.left()) && esArbolEquilibrado(t.right()) && abs(altura(t.left()) - altura(t.right())) <= 1;
	}
}

template <typename T>
AVL esAVL(bintree<T> const& t) {
	if (t.empty()) {
		return { true, -1, -1 };
	}
	else {
		AVL avl;
		if (t.left().empty() && t.right().empty()) {
			return { true, t.root(), t.root() };
		}
		if (t.left().empty()) {
			AVL AVL_right = esAVL(t.right());
			avl.isAVL = AVL_right.isAVL && t.root() < AVL_right.min;
			avl.max = max(t.root(), AVL_right.max);
			avl.min = min(t.root(), AVL_right.min);
		}
		else if (t.right().empty()) {
			AVL AVL_left = esAVL(t.left());
			avl.isAVL = AVL_left.isAVL && t.root() > AVL_left.max;
			avl.min = min(t.root(), AVL_left.min);
			avl.max = max(t.root(), AVL_left.max);
		}
		else {
			AVL AVL_right = esAVL(t.right());
			AVL AVL_left = esAVL(t.left());
			avl.isAVL = AVL_left.isAVL && AVL_right.isAVL && t.root() > AVL_left.max && t.root() < AVL_right.min;
			avl.max = max(max(t.root(), AVL_left.max), AVL_right.max);
			avl.min = min(min(t.root(), AVL_left.min), AVL_right.min);
		}
		return avl;
	}
}

void resuelveCaso() {
	bintree<int> tree;
	tree = leerArbol(-1);
	AVL avlTree = esAVL(tree);
	if (avlTree.isAVL && esArbolEquilibrado(tree)) cout << "SI\n";
	else cout << "NO\n";
}

int main() {
	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	return 0;
}