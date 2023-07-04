#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class hora {

public:
	hora(int h, int m)
	{
		if (0 <= h && h <= 23 && 0 <= m && m <= 59) {
			horas = h;
			minutos = m;
		}
		else {
			throw domain_error("ERROR");
		}
	}
	hora() : horas(0), minutos(0) {}
	bool operator<(hora const& h2) {
		return horas < h2.horas || (horas == h2.horas && minutos < h2.minutos);
	}
	bool operator<=(hora const& h2) {
		return horas <= h2.horas || (horas == h2.horas && minutos <= h2.minutos);
	}
	bool operator==(hora const& h2) {
		return horas == h2.horas && minutos == h2.minutos;
	}
	int h() const { return horas; }
	int m() const { return minutos; }
	hora operator+(hora const& h2) {
		hora sol;
		int min = minutos + h2.minutos;
		sol.minutos = min % 60;
		int hora = horas + h2.horas;
		sol.horas = hora + min / 60;
		return sol;
	}
private:
	int horas, minutos;
};

class pelicula {
public:
	pelicula() : horaIni(), horaFin(), duracion() {}
	pelicula(hora h1, hora h2) : horaIni(h1), horaFin(h1 + h2), duracion(h2) {}
	bool operator<(pelicula const& p2) {
		return (horaFin < p2.horaFin);
	}
	hora hIni() const { return horaIni; }
	hora hFin() const { return horaFin; }
	hora dur() const { return duracion; }
private:
	hora horaIni, horaFin, duracion;
};

istream& operator>> (istream & i, hora &h1) {
	char aux;
	int h, m, s;
	i >> h >> aux >> m ;
	i.ignore();
	h1 = { h, m };
	return i;
}


bool resuelveCaso() {
	int numPeliculas, duracion, sol=1;
	hora horaPeli;
	vector<pelicula> peliculas;
	char aux;

	cin >> numPeliculas;
	if (numPeliculas == 0)
		return false;

	for (int i = 0; i < numPeliculas; ++i) {
		cin >> horaPeli >> duracion;
		int h = duracion / 60;
		int m = duracion % 60;
		hora dur = hora(h, m);		
		peliculas.push_back(pelicula(horaPeli, dur));
	}
	sort(peliculas.begin(), peliculas.end());
	hora h_aux(0, 10);

	int j = 0;
	for (int i = 1; i < numPeliculas; ++i) {
		if (peliculas[i].hIni() < peliculas[j].hFin()) {
			if (peliculas[i].hFin() < peliculas[j].hFin()) j = i;
		}
		else if (peliculas[j].hFin() + h_aux <= peliculas[i].hIni()) {
			j = i;
			++sol;
		}
	}

	cout << sol << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}