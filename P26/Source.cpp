#include <iostream>
using namespace std;
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"
#include <climits>


vector<int> dijsktraElem(int posIni, int n, GrafoDirigidoValorado<int> const& g) {
	vector<AristaDirigida<int>> aristaTo(n);
	vector<int> distTo(n, INT_MAX);
	IndexPQ <int> pq(n);
	distTo[posIni] = 0;
	pq.push(posIni, 0);

	while (!pq.empty()) {
		int v = pq.top().elem;
		pq.pop();
		for (AristaDirigida<int> a : g.ady(v)) {
			int v1 = a.from(); int v2 = a.to();
			if (distTo[v2] > distTo[v1] + a.valor()) {
				distTo[v2] = distTo[v1] + a.valor();
				aristaTo[v2] = a;
				pq.update(v2, distTo[v2]);
			}
		}
	}
	return distTo;
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!std::cin) 
		return false;

	GrafoDirigidoValorado<int> g1(n), g2(n);
	int c;
	cin >> c;
	int ini, fin, val;
	for (int j = 0; j < c; ++j) {
		cin >> ini >> fin >> val;
		g1.ponArista(AristaDirigida<int>(ini - 1, fin - 1, val));
		g2.ponArista(AristaDirigida<int>(fin - 1, ini - 1, val));
	}
	int o, p, cont = 0;
	cin >> o >> p;
	vector<int> distTo1(n, INT_MAX);
	IndexPQ <int> pq1(n);
	distTo1[o - 1] = 0;
	pq1.push(o - 1, 0);

	while (!pq1.empty()) {
		int v = pq1.top().elem;
		pq1.pop();
		for (AristaDirigida<int> a : g1.ady(v)) {
			int v1 = a.from(); int v2 = a.to();
			if (distTo1[v2] > distTo1[v1] + a.valor()) {
				distTo1[v2] = distTo1[v1] + a.valor();
				pq1.update(v2, distTo1[v2]);
			}
		}
	}

	vector<int> distTo2(n, INT_MAX);
	IndexPQ <int> pq2(n);
	distTo2[o - 1] = 0;
	pq2.push(o - 1, 0);

	while (!pq2.empty()) {
		int v = pq2.top().elem;
		pq2.pop();
		for (AristaDirigida<int> a : g2.ady(v)) {
			int v1 = a.from(); int v2 = a.to();
			if (distTo2[v2] > distTo2[v1] + a.valor()) {
				distTo2[v2] = distTo2[v1] + a.valor();
				pq2.update(v2, distTo2[v2]);
			}
		}
	}

	bool imposible = false;
	for (int i = 0; i < p; ++i) {
		cin >> ini;
		if (!imposible) {
			int ida = distTo1[ini - 1];
			int vuelta = distTo2[ini - 1];
			if (ida == INT_MAX || vuelta == INT_MAX) imposible = true;
			else cont += ida + vuelta;
		}
	}
	if (imposible) cout << "Imposible" << endl;
	else cout << cont << endl;
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}