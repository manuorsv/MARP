#include <iostream> 
using namespace std;
#include "PriorityQueue.h"

bool resuelveCaso() {
	int nActividades;

	cin >> nActividades;
	if (nActividades == 0) {
		return false;
	}

	int ini, fin;
	PriorityQueue<int> p_ini, p_fin;
	for (int i = 0; i < nActividades; ++i) {
		cin >> ini >> fin;
		p_ini.push(ini);
		p_fin.push(fin);
	}

	int nAmigos = -1;
	int maxAmigos = -1;
	while (!p_ini.empty()) {
		if (p_ini.top() < p_fin.top()) {
			++nAmigos;
			p_ini.pop();
		}
		else {
			--nAmigos;
			p_fin.pop();
		}
		if (nAmigos > maxAmigos) maxAmigos = nAmigos;
	}

	cout << maxAmigos << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}