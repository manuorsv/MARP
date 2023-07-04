#include <iostream>
using namespace std;
#include "Digrafo.h"
#include <stack>

void dfs(Digrafo const& g, int s, vector<bool> &marked, vector<bool> &inStack, stack<int> &pila, bool &posible) {
	marked[s] = true;
	for (int w : g.ady(s)) {
		if (!marked[w]) 
			dfs(g, w, marked, inStack, pila, posible);
		else {
			if (!inStack[w]) 
				posible = false;
		}
	}
	pila.push(s);
	inStack[s] = true;
}
stack<int> resolver(Digrafo const& g, bool &posible) {
	vector<bool> marked(g.V(),false);
	vector<bool> inStack(g.V(), false);
	stack<int> pila;
	for (int i = 1; i < g.V(); ++i) {
		if (!marked[i])
			dfs(g, i, marked, inStack, pila, posible);
	}
	
	return pila;
}

bool resuelveCaso() {
	int N, M;
	cin >> N;
	if (!std::cin)
		return false;

	cin >> M;
	int v1, v2;
	Digrafo g(N + 1);
	for (int i = 0; i < M; ++i) {
		cin >> v1 >> v2;
		g.ponArista(v1, v2);
	}

	bool posible = true;
	stack<int> sol = resolver(g, posible);
	
	if (!posible)
		cout << "Imposible\n";
	else {
		stack<int> sol = resolver(g, posible);
		int v = sol.top();
		sol.pop();
		cout << v;
		while (!sol.empty()) {
			v = sol.top();
			sol.pop();
			cout << ' ' << v;
		}
		cout << '\n';
	}

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}