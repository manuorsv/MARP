#include <iostream>
using namespace std;
#include <queue>
#include <vector>

bool resuelveCaso() {
	int from, to;

	cin >> from;
	if (!std::cin)
		return false;

	cin >> to;
	queue<int> q;
	vector<pair<bool, int>> visitado(10000, { false,0 });
	visitado[from] = {true,0};
	q.push(from);
	bool found = false;
	int v,v1,v2,v3, npul;
	while (!q.empty() && !found) {
		v = q.front();
		q.pop();
		npul = visitado[v].second;
		if (v == to) found = true;
		else {
			v1 = (v + 1)%10000;
			v2 = (v * 2)%10000;
			v3 = v / 3;
			if (!visitado[v1].first) {
				q.push(v1);
				visitado[v1] = {true, npul+1};
			}
			if (!visitado[v2].first) {
				q.push(v2);
				visitado[v2] = { true, npul + 1 };
			}
			if (!visitado[v3].first) {
				q.push(v3);
				visitado[v3] = { true, npul + 1 };
			}
		}
	}

	cout << npul << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}