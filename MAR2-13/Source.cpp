#include<iostream>
using namespace std;
#include "Matriz.h"
#include <string>
#include<algorithm>

bool resuelveCaso() {
	string p;
	cin >> p;
	if (!std::cin)
		return false;

	string r = p;
	reverse(r.begin(), r.end());

	int n = p.size();

	Matriz<int> subcadenas(n + 1, n + 1);
    for (int i = 0; i <= n; ++i) subcadenas[i][0] = 0;
    for (int j = 0; j <= n; ++j) subcadenas[0][j] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[i - 1] == r[j - 1]) subcadenas[i][j] = subcadenas[i - 1][j - 1] + 1;
            else subcadenas[i][j] = max(subcadenas[i - 1][j], subcadenas[i][j - 1]);
        }
    }
    int k = subcadenas[n][n];
    int b = k + 2 * (n - k), a = 0;
    string lcs(b + 1, '\0');
    --b;
    int i = n, j = n;
    while (a <= b) {
        if (p[i - 1] == r[j - 1]) {
            lcs[a] = p[i - 1];
            lcs[b] = p[i - 1];
            --i; 
            --j;      
            --b;
            ++a;
        }
        else if (subcadenas[i - 1][j] > subcadenas[i][j - 1]) {
            lcs[a] = p[i - 1];
            lcs[b] = p[i - 1];
            --i;
            --b;
            ++a;
        }
        else {
            lcs[a] = r[j - 1];
            lcs[b] = r[j - 1];            
            --j;
            --b;
            ++a;
        }
    }

    lcs.pop_back();

	cout << n - k << ' ' << lcs << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}