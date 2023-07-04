#include <iostream>
using namespace std;
#include "PriorityQueue.h"
#include <queue>


struct Tarea {
	int ini, fin, periodo;
};

bool operator<(Tarea const& t1, Tarea const& t2) {
	return (t1.ini < t2.ini) || ((t1.ini == t2.ini) && (t1.fin < t2.fin));
}

bool resuelveCaso() {
	int numTareasUnicas, numTareasPeriodicas, tiempoCheck;
	PriorityQueue<Tarea> pq;
	Tarea tarea, tareaAux;
	queue<Tarea> tareaEnProc;

	cin >> numTareasUnicas;
	if (!std::cin)
		return false;

	cin >> numTareasPeriodicas >> tiempoCheck;

	for (int i = 0; i < numTareasUnicas; ++i) {
		cin >> tarea.ini >> tarea.fin;
		tarea.periodo = 0;
		pq.push(tarea);
	}
	for (int i = 0; i < numTareasPeriodicas; ++i) {
		cin >> tarea.ini >> tarea.fin >> tarea.periodo;
		pq.push(tarea);
	}

	bool conflicto = false;
	int i = 0;
	while (conflicto == false && i < tiempoCheck) {
		if (!tareaEnProc.empty()) {
			if (tareaEnProc.front().fin == i) {
				if (tareaEnProc.front().periodo > 0) {
					tareaAux = tareaEnProc.front();
					tareaAux.ini += tareaAux.periodo;
					tareaAux.fin += tareaAux.periodo;
					pq.push(tareaAux);
				}
				tareaEnProc.pop();
			}
		}
		if (pq.size() >= 1) {
			if (pq.top().ini == i) {
				pq.pop(tareaAux);

				if (tareaEnProc.empty()) {
					tareaEnProc.push(tareaAux);
				}
				else conflicto = true;

				if (pq.size() >= 1) {
					if (pq.top().ini == i) conflicto = true;
				}
			}
		}

		++i;
	}

	if (conflicto) cout << "SI\n";
	else cout << "NO\n";

	return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}