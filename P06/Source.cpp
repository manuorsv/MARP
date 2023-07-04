#include <iostream>
using namespace std;
#include "PriorityQueue.h"
#include <queue>


struct Cliente {
	int tiempo, caja;
};

bool operator<(Cliente const& t1, Cliente const& t2) {
	return (t1.tiempo < t2.tiempo) || (t1.tiempo == t2.tiempo && t1.caja < t2.caja);
}

void resolver(PriorityQueue<Cliente>& pq, queue<int>& c, int t) {
	if (!c.empty()) {
		Cliente cl = { t, c.front() };
		pq.push(cl);
		c.pop();
	}
	else {
		int caja = pq.top().caja;
		int tm = pq.top().tiempo;
		pq.pop();
		Cliente newcl = { t + tm, caja };
		pq.push(newcl);
	}
}

bool resuelveCaso() {
	int numCajas, numClientes, tiempo;
	PriorityQueue<Cliente> cajasOcupadas;
	queue<int> cajasLibres;
	Cliente cliente;

	cin >> numCajas >> numClientes;
	if (numCajas == 0 && numClientes == 0)
		return false;

	for (int i = 1; i <= numCajas; ++i) {
		cajasLibres.push(i);
	}

	for (int i = 0; i < numClientes; ++i) {
		cin >> tiempo;
		resolver(cajasOcupadas, cajasLibres, tiempo);
	}

	if (!cajasLibres.empty()) cout << cajasLibres.front() << '\n';
	else {
		cout << cajasOcupadas.top().caja << '\n';
	}


	return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}