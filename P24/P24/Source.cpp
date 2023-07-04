#include <iostream>
using namespace std;
#include "PriorityQueue.h"
#include <vector>

bool resuelveCaso() {
	int numValores, valor;
	PriorityQueue<int, greater<int>> mitadInf;
	PriorityQueue<int> mitadSup;
	vector<int> medianas;
	int aux;

	cin >> numValores;
	if (numValores == 0)
		return false;

	for (int i = 0; i < numValores; ++i) {
		cin >> valor;

		if (mitadInf.size() == 0) {
			mitadInf.push(valor);
		}
		else {
			if (mitadSup.size() > 0) {
				if (valor < mitadSup.top()) {
					mitadInf.push(valor);
				}
				else mitadSup.push(valor);
			}
			else {
				if (valor < mitadInf.top()) {
					mitadInf.push(valor);
				}
				else mitadSup.push(valor);
			}
		}

		if (mitadInf.size() - mitadSup.size() > 1) {
			mitadInf.pop(aux);
			mitadSup.push(aux);
		}
		else if (mitadSup.size() - mitadInf.size() > 1) {
			mitadSup.pop(aux);
			mitadInf.push(aux);
		}

		if ((mitadInf.size() + mitadSup.size()) % 2 == 0) {
			medianas.push_back(mitadInf.top() + mitadSup.top());
		}
		else {
			if(mitadInf.size() > mitadSup.size()) medianas.push_back(2 * mitadInf.top());
			else medianas.push_back(2 * mitadSup.top());
		}
	}

	cout << medianas[0];
	for (int i = 1; i < medianas.size(); ++i) {
		cout << ' ' << medianas[i];
	}
	cout << '\n';

	return true;
}


int main() {
	while (resuelveCaso());

	return 0;
}
