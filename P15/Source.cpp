#include <iostream>
using namespace std;
#include "Grafo.h"
#include <queue>

void resolver(Grafo const& g, int s, int l) {
	vector<bool> visitado(g.V(), false);
	queue<pair<int, int>> q;
	int count = 1;
	bool limite = false;
	q.push({ s,0 });
	visitado[s] = true;
	int v, dist;
	while (!q.empty() && !limite) {
		v = q.front().first;
		dist = q.front().second;
		q.pop();
		if (dist == l) limite = true;
		else {
			for (int w : g.ady(v)) {
				if (!visitado[w]) {
					q.push({ w,dist + 1 });
					visitado[w] = true;
					++count;
				}
			}
		}
	}
	
	cout << g.V() - 1 - count << '\n';
}

bool resuelveCaso() {
	int N, C;

	cin >> N;
	if (!std::cin)
		return false;

	cin >> C;
	Grafo g(N+1);
	int n1, n2;
	for (int i = 0; i < C; ++i) {
		cin >> n1 >> n2;
		g.ponArista(n1, n2);
	}

	int K; 
	cin >> K;
	int s, l;
	for (int i = 0; i < K; ++i) {
		cin >> s >> l;
		resolver(g, s, l);
	}
	cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}