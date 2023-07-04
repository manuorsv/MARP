#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct tVarilla {
	int longitud, coste;
};

bool posibleVarilla(vector<tVarilla> const& v, int longitud) {
	vector<bool> posible(longitud + 1, false);
	posible[0] = true;

	for (int i = 0; i < v.size(); ++i) {
		for (int j = longitud; j >= v[i].longitud; --j) {
			posible[j] = posible[j] || posible[j - v[i].longitud];
		}
	}
	return posible[longitud];
}

void resolver(vector<tVarilla> const& v, int longitud) {
	vector<int> formasP(longitud + 1, 0);

	formasP[0] = 1;

	vector<int> minVar(longitud + 1, 0);

	for (int i = 0; i < v.size(); ++i) {
		if (v[i].longitud <= longitud) minVar[v[i].longitud] = 1;
	}

	vector<int> minCoste(longitud + 1, 0);

	for (int i = 0; i < v.size(); ++i) {
		if (v[i].longitud <= longitud) minCoste[v[i].longitud] = v[i].coste;
	}

	for (int i = 0; i < v.size(); ++i) {
		for (int j = longitud; j >= v[i].longitud; --j) {
				if (formasP[j] > 0 && formasP[j - v[i].longitud] > 0) {
					formasP[j] += formasP[j - v[i].longitud];
					minVar[j] = min(minVar[j], minVar[j - v[i].longitud] + 1);
					minCoste[j] = min(minCoste[j], minCoste[j - v[i].longitud] + v[i].coste);
				} 
				else if (formasP[j - v[i].longitud] > 0) {
					formasP[j] = formasP[j - v[i].longitud];
					minVar[j] = minVar[j - v[i].longitud] + 1;
					minCoste[j] = minCoste[j - v[i].longitud] + v[i].coste;
				}
			}
	}
	cout << ' ' << formasP[longitud] << ' ' << minVar[longitud] << ' ' << minCoste[longitud] << '\n';
 }

bool resuelveCaso() {
	int numVarillas;
	cin >> numVarillas;

	if (!std::cin)
		return false;

	int longitudVar;
	cin >> longitudVar;

	vector<tVarilla> varillas;
	tVarilla var;
	for (int i = 0; i < numVarillas; ++i) {
		cin >> var.longitud >> var.coste;
		varillas.push_back(var);
	}

	if (posibleVarilla(varillas, longitudVar)) {
		cout << "SI";
		resolver(varillas, longitudVar);
	}
	else {
		cout << "NO\n";
	}

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}