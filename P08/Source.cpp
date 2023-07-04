#include <iostream>
using namespace std;
#include "PriorityQueue.h"

bool resuelveCaso() {
	int numEventos;

	cin >> numEventos;
	if (!std::cin)
		return false;

	PriorityQueue<int, std::greater<int>> mitad_izq;
	PriorityQueue<int> mitad_der;
	int numCliente;
	for (int i = 0; i < numEventos; ++i) {
		cin >> numCliente;
		if (mitad_izq.empty() && mitad_der.empty()) {
			if (numCliente == 0)
				if (i < numEventos - 1) cout << "ECSA ";
				else cout << "ECSA\n";
			else
				mitad_izq.push(numCliente);
		}
		else {
			if (numCliente != 0) {
				if (numCliente < mitad_izq.top())
					mitad_izq.push(numCliente);
				else mitad_der.push(numCliente);

				if (mitad_izq.size() - mitad_der.size() == 2) {
					int numCambio;
					mitad_izq.pop(numCambio);
					mitad_der.push(numCambio);
				}
				else if (mitad_der.size() - mitad_izq.size() == 1) {
					int numCambio;
					mitad_der.pop(numCambio);
					mitad_izq.push(numCambio);
				}
			}

			else {
				if (i < numEventos-1) cout << mitad_izq.top() << ' ';
				else cout << mitad_izq.top() << '\n';
				mitad_izq.pop();
				if (mitad_der.size() - mitad_izq.size() == 1) {
					int numCambio;
					mitad_der.pop(numCambio);
					mitad_izq.push(numCambio);
				}
			}
		}
	}


	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}