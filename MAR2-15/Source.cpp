#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct tCancion {
	float duracion, valor;
};

bool operator <(tCancion const& c1, tCancion const& c2) {
	return (c1.valor / c1.duracion) < (c2.valor / c2.duracion);
}

bool operator >(tCancion const& c1, tCancion const& c2) {
	return (c1.valor / c1.duracion) > (c2.valor / c2.duracion);
}

struct nodo {
	int k;
	float beneficio, beneficioOpt, ocupadoA, ocupadoB;
};

bool operator >(nodo const& n1, nodo const& n2) {
	return n1.beneficioOpt > n2.beneficioOpt;
}

bool operator <(nodo const& n1, nodo const& n2) {
	return n1.beneficioOpt < n2.beneficioOpt;
}

float optimista(vector<tCancion> const& canciones, float T, int k, float beneficio, float ocupadoA, float ocupadoB, int n) {
	float opt = beneficio;
	float hueco = 2 * T - (ocupadoA + ocupadoB);
	int j = k + 1;
	while (j <= n && canciones[j].duracion <= hueco) {
		hueco -= canciones[j].duracion;
		opt += canciones[j].valor;
		j++;
	}
	if (j <= n) {
		opt += (hueco / canciones[j].duracion) * canciones[j].valor;
	}
	return opt;
}

float pesimista(vector<tCancion> const& canciones, float T, int k, float beneficio, float ocupadoA, float ocupadoB, int n) {
	float ocupadoAAux = ocupadoA;
	float ocupadoBAux = ocupadoB;
	float pes = beneficio;
	int j = k + 1;
	while (j <= n && (ocupadoAAux <= T || ocupadoBAux <= T)) {
		if (ocupadoAAux + canciones[j].duracion <= T) {
			ocupadoAAux += canciones[j].duracion;
			pes += canciones[j].valor;
		}
		else if (ocupadoBAux + canciones[j].duracion <= T) {
			ocupadoBAux += canciones[j].duracion;
			pes += canciones[j].valor;
		}
		j++;
	}
	return pes;
}



bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	float T;
	cin >> T;
	vector<tCancion> canciones(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> canciones[i].duracion >> canciones[i].valor;

	sort(canciones.begin() + 1, canciones.end(), greater<tCancion>());

	nodo X, Y; priority_queue<nodo> C;
	Y.k = 0; Y.beneficio = 0; Y.ocupadoA = 0; Y.ocupadoB = 0;
	Y.beneficioOpt = optimista(canciones, T, Y.k, Y.beneficio, Y.ocupadoA, Y.ocupadoB, n);
	C.push(Y);
	float mejor = pesimista(canciones, T, Y.k, Y.beneficio, Y.ocupadoA, Y.ocupadoB, n);
	while (!C.empty() && C.top().beneficioOpt >= mejor) {
		Y = C.top(); C.pop();
		X.k = Y.k + 1;
		// Lo meto en la cara A si es posible
		if (Y.ocupadoA + canciones[X.k].duracion <= T) {
			X.beneficio = Y.beneficio + canciones[X.k].valor;
			X.ocupadoA = Y.ocupadoA + canciones[X.k].duracion;
			X.ocupadoB = Y.ocupadoB;
			X.beneficioOpt = Y.beneficioOpt;
			if (X.k == n) mejor = X.beneficio;
			else C.push(X);
		}
		// Lo meto en la cara B si es posible y no es simetrico al caso anterior
		if (Y.ocupadoA != Y.ocupadoB && Y.ocupadoB + canciones[X.k].duracion <= T) {
			X.beneficio = Y.beneficio + canciones[X.k].valor;
			X.ocupadoA = Y.ocupadoA;
			X.ocupadoB = Y.ocupadoB + canciones[X.k].duracion;
			X.beneficioOpt = Y.beneficioOpt;
			if (X.k == n) mejor = X.beneficio;
			else {
				C.push(X);
				mejor = max(mejor, pesimista(canciones, T, X.k, X.beneficio, X.ocupadoA, X.ocupadoB, n));
			}
		}
		// No lo meto
		X.ocupadoA = Y.ocupadoA;
		X.ocupadoB = Y.ocupadoB;
		X.beneficio = Y.beneficio;
		X.beneficioOpt = optimista(canciones, T, X.k, X.beneficio, X.ocupadoA, X.ocupadoB, n);
		if (X.beneficioOpt >= mejor) {
			if (X.k == n) mejor = X.beneficio;
			else {
				C.push(X);
				mejor = max(mejor, pesimista(canciones, T, X.k, X.beneficio, X.ocupadoA, X.ocupadoB, n));
			}
		}
	}
	cout << mejor << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}