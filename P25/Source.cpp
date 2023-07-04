#include <iostream>
using namespace std;
#include "PriorityQueue.h"



bool resuelveCaso() {
	int primPajaro, nParejas;
	PriorityQueue<int, std::greater<int>> mitad_izq;
	PriorityQueue<int> mitad_der;

	cin >> primPajaro >> nParejas;
	if (primPajaro == 0 && nParejas == 0)
		return false;

	mitad_izq.push(primPajaro);

	int pajaro1, pajaro2;
	for (int i = 0; i < nParejas; ++i) {
		cin >> pajaro1 >> pajaro2;
		if (pajaro1 < mitad_izq.top())
			mitad_izq.push(pajaro1);
		else mitad_der.push(pajaro1);

		if (pajaro2 < mitad_izq.top())
			mitad_izq.push(pajaro2);
		else mitad_der.push(pajaro2);
		
		if (mitad_izq.size() - mitad_der.size() == 3) {
			int pajaro_mover;
			mitad_izq.pop(pajaro_mover);
			mitad_der.push(pajaro_mover);
		}
		else if (mitad_der.size() - mitad_izq.size() == 1) {
			int pajaro_mover;
			mitad_der.pop(pajaro_mover);
			mitad_izq.push(pajaro_mover);
		}

		if (i == 0) cout << mitad_izq.top();
		else cout << ' ' << mitad_izq.top();
	}

	cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
