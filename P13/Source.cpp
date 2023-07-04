#include <iostream>
using namespace std;
#include "Grafo.h"
#include <vector>
#include <queue>

void resolver(Grafo const& g) {
	vector<int> marked(g.V(), -1);
	bool esBip = true;
	int v,sol=0;
	queue<int> q;
	for (int i = 1; i < g.V(); ++i) {
		if (marked[i] == -1) {
			vector<int> nColor(2, 0);
			int color = 0;
			q.push(i);
			marked[i] = color;
			++nColor[color];
			while (!q.empty() && esBip) {
				v = q.front();
				q.pop();
				if (marked[v] == 0) color = 1;
				else color = 0;
				for (int w : g.ady(v)) {
					if (marked[w] == -1) {
						marked[w] = color;
						++nColor[color];
						q.push(w);
					}
					else if (marked[w] == marked[v]) {
						esBip = false;
						break;
					}
				}
			}
			sol += min(nColor[0], nColor[1]);
		}
	}

	if (esBip) cout << sol << '\n';
	else cout << "IMPOSIBLE\n";

}

bool resuelveCaso() {
	int N, C;
	cin >> N;
	if (!std::cin)
		return false;

	cin >> C;
	Grafo g(N + 1);
	int v1, v2;
	for (int i = 0; i < C; ++i) {
		cin >> v1 >> v2;
		g.ponArista(v1, v2);
	}

	resolver(g);

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}