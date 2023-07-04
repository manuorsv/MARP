#include<iostream>
using namespace std;
#include "Matriz.h"
#include <string>
#include<algorithm>

bool resuelveCaso() {
	string cadena1, cadena2;
	cin >> cadena1;
	if (!std::cin)
		return false;

	cin >> cadena2;
	Matriz<int> subcadenas(cadena1.size()+1, cadena2.size()+1);
	for (int i = 0; i < cadena1.size() + 1; ++i) {
		subcadenas[i][0] = 0;
	}
	for (int j = 0; j < cadena2.size() + 1; ++j) {
		subcadenas[0][j] = 0;
	}

	int m = cadena1.size();
	int n = cadena2.size();

	for (int i = 1; i < m+1; ++i) {
		for (int j = 1; j < n+1; ++j) {
			if (cadena1[i-1] == cadena2[j - 1]) {
				subcadenas[i][j] = subcadenas[i - 1][j - 1] + 1;
			}
			else {
				 subcadenas[i][j] = max(subcadenas[i-1][j],subcadenas[i][j - 1]);
			}
		}
	}
	
	int k = subcadenas[m][n];
	string lcs(k,'\0');
	int i = m, j = n;
	while (i > 0 && j > 0) {
		if (cadena1[i - 1] == cadena2[j - 1]) {
			lcs[k-1] = cadena1[i - 1];
			--i;
			--j;
			--k;
		}
		else if (subcadenas[i - 1][j] > subcadenas[i][j - 1]) --i;
		else --j;
	}

	cout << lcs << '\n';
	
	return true;

}

int main() {
	while (resuelveCaso());
	return 0;
}