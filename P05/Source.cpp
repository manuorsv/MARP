#include <iostream>
using namespace std;
#include "PriorityQueue.h"
#include <string>

struct Paciente {
	string nombre;
	int gravedad;
	int tiempoLlegada;
};

bool operator <(Paciente const& p1, Paciente const& p2) {
	return (p1.gravedad > p2.gravedad) || ((p1.gravedad == p2.gravedad) && (p1.tiempoLlegada < p2.tiempoLlegada));
}

bool resuelveCaso() {
	int numEventos;
	char evento;
	Paciente paciente, pacienteAux;
	PriorityQueue<Paciente> listaPacientes;

	cin >> numEventos;
	if (numEventos == 0)
		return false;

	for (int i = 0; i < numEventos; ++i) {
		cin >> evento;
		if (evento == 'I') {
			cin >> paciente.nombre >> paciente.gravedad;
			paciente.tiempoLlegada = i;
			listaPacientes.push(paciente);
		}
		else {
			listaPacientes.pop(pacienteAux);
			cout << pacienteAux.nombre << '\n';
		}
	}
	cout << "---\n";

	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}