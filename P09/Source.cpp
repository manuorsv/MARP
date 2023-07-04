#include <iostream>
using namespace std;
#include "PriorityQueue.h"

class partComp {
public:
	bool operator()(pair<int, int> const& p1, pair<int, int> const& p2) {
		return ((p1.first / p1.second) > (p2.first / p2.second)) || (((p1.first / p1.second) == (p2.first / p2.second)) && ((p1.first % p1.second) > (p2.first % p2.second)));
	}
};

bool resuelveCaso() {
	int p;
	cin >> p;
	if (!std::cin)
		return false;
	int n;
	cin >> n;
	PriorityQueue<pair<int,int>, partComp> pq;
	int nInstr;
	for (int i = 0; i < n; ++i) {
		cin >> nInstr;
		pq.push({ nInstr,1 });
	}
	pair<int,int> instr;
	for (int j = 0; j < p-n; ++j) {
		pq.pop(instr);
		++instr.second;
		pq.push(instr);
	}

	int extra = 0;
	if (pq.top().first % pq.top().second != 0) extra = 1;
	cout << (pq.top().first/pq.top().second) + extra << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}