#include <iostream>
using namespace std;
#include "PriorityQueue.h"

bool resuelveCaso() {
	int numSumandos;
	long long int sumando, esfuerzo = 0, suma, sumando1, sumando2;
	PriorityQueue<long long int> pq;

	cin >> numSumandos;
	if (numSumandos == 0)
		return false;

	for (int i = 0; i < numSumandos; ++i) {
		cin >> sumando;
		pq.push(sumando);
	}

	while (pq.size() > 1) {
		pq.pop(sumando1);
		pq.pop(sumando2);
		suma = sumando1 + sumando2;
		esfuerzo += suma;
		pq.push(suma);
	}

	cout << esfuerzo << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}