#include <iostream>
using namespace std;
#include "GrafoValorado.h"
#include <vector>
#include "PriorityQueue.h"
#include <queue>
#include <climits>

int BFS(GrafoValorado<int> const& g, int from, int to) {
	queue<int> q;
	vector<bool> marked(g.V()+1, false);
	vector<int> edgeTo(g.V()+1,-1);
	marked[from] = true;
	q.push(from);
	int v,w;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (Arista<int> e : g.ady(v)) {
			if (e.uno() == v) w = e.otro(v);
			else w = e.uno();
			if (!marked[w]) {
				edgeTo[w] = v;
				marked[w] = true;
				q.push(w);
			}
		}
	}
	
	//Recorremos edgeTo desde el vertice destino hasta el origen contando el numero de aristas por las que pasamos
	int dist = 0, vert = to;
	if (edgeTo[vert] == -1 && vert != from) return -1; //Si no hay camino 
	else {
		while (vert != from) {
			++dist;
			vert = edgeTo[vert];
		}
		return dist;
	}
}
int resolver(GrafoValorado<int> const& g, int from, int to, vector<pair<int,int>> &distTo, IndexPQ<pair<int,int>> &pq) {
	vector<int> edgeTo(g.V() + 1,-1);
	distTo[from]= { 0,0 };
	pq.push(from, {0,0});
	pair<int, pair<int, int> > p;
	while (!pq.empty()) {
		p.first = pq.top().elem;
		p.second = pq.top().prioridad;
		pq.pop();
		for (Arista<int> e : g.ady(p.first)) {
			int w;
			if (e.uno() == p.first) w = e.otro(p.first);
			else w = e.uno();
			if (distTo[w].first > distTo[p.first].first + e.valor()) {
				distTo[w].first = distTo[p.first].first + e.valor();
				distTo[w].second = distTo[p.first].second + 1;
				edgeTo[w] = p.first;
				pq.update(w, distTo[w]);
			}
			else if (distTo[w].first == distTo[p.first].first + e.valor()) {
				if (distTo[w].second > distTo[p.first].second + 1) {
					distTo[w].second = distTo[p.first].second + 1;
					edgeTo[w] = p.first;
					pq.update(w, distTo[w]);
				}
			}
		}
	}
	return distTo[to].second;
}

bool resuelveCaso() {
	int N, C;

	cin >> N;
	if (!std::cin)
		return false;

	cin >> C;
	GrafoValorado<int> g(N + 1);
	int to, from, dist;
	Arista<int> a;
	for (int i = 0; i < C; ++i) {
		cin >> to >> from >> dist;
		a = { to,from,dist };
		g.ponArista(a);
	}
	int nConsultas;
	cin >> nConsultas;
	vector<pair<int,bool>> sol;
	for (int i = 0; i < nConsultas; ++i) {
		IndexPQ<pair<int,int>> pq(N+1);
		vector<pair<int, int>> distTo(N + 1, { INT_MAX,-1 });
		cin >> from >> to;
		int dist = resolver(g, from, to, distTo, pq);		//Devuelve numero de calles recorridas
		int callesMin = BFS(g, from,to);					//Devuelve numero de calles recorridas sin tener el cuenta el peso de cada arista
		if (callesMin < dist) {								
			sol.push_back({ distTo[to].first, false });
		}
		else {
			sol.push_back({ distTo[to].first,true });
		}
	}

	for (int i = 0; i < nConsultas; ++i) {
		if (sol[i].first != INT_MAX) {					//Hay camino
			cout << sol[i].first;
			if (sol[i].second) cout << " SI\n";
			else cout << " NO\n";
		}
		else cout << "SIN CAMINO\n";
	}
	cout << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}