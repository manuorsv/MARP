#include <iostream>
using namespace std;
#include "PriorityQueue.h"
#include <unordered_map>

struct usuarioFrec {
	int id;
	int frecuencia;
};

bool operator <(usuarioFrec const& u1, usuarioFrec const& u2) {
	return (u1.frecuencia < u2.frecuencia) || ((u1.frecuencia == u2.frecuencia) && (u1.id < u2.id));
}

bool resuelveCaso() {
	int numUsuarios, numEnvios;
	usuarioFrec usuario, usuarioAux;
	unordered_map<int, int> listaUsuarios;
	PriorityQueue<usuarioFrec> pq;

	cin >> numUsuarios;
	if (numUsuarios == 0)
		return false;

	for (int i = 0; i < numUsuarios; ++i) {
		cin >> usuario.id >> usuario.frecuencia;
		listaUsuarios.insert({ usuario.id, usuario.frecuencia });
		pq.push(usuario);
	}

	cin >> numEnvios;
	for (int i = 0; i < numEnvios; ++i) {
		pq.pop(usuarioAux);
		cout << usuarioAux.id << '\n';
		usuarioAux.frecuencia += listaUsuarios.at(usuarioAux.id);
		pq.push(usuarioAux);
	}
	cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}