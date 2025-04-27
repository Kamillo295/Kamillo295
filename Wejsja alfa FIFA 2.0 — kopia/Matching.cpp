#include "Matching.h"
#include <iostream>
#include <vector>
#include <cstdlib>  // dla rand(), srand()
#include <ctime>    // dla time()
#include <algorithm>

using namespace std;

// Struktura meczu
struct Mecz {
    int klub1;
    int klub2;
};

void losuj_mecze(vector<Klub>& kluby) {
    srand(time(0)); // inicjalizacja generatora losowego

    int n = kluby.size();
    vector<vector<int>> przeciwnicy(n);
    vector<Mecz> mecze;

    while (true) {
        bool pelne = true;

        for (int i = 0; i < n; ++i) {
            while (przeciwnicy[i].size() < 4) {
                pelne = false;
                int los = rand() % n;

                if (los != i &&
                    przeciwnicy[i].size() < 4 &&
                    przeciwnicy[los].size() < 4 &&
                    find(przeciwnicy[i].begin(), przeciwnicy[i].end(), los) == przeciwnicy[i].end()) {

                    przeciwnicy[i].push_back(los);
                    przeciwnicy[los].push_back(i);

                    if (i < los) // ¿eby nie dublowaæ meczu
                        mecze.push_back({ i, los });
                }
            }
        }

        if (pelne) break;
    }

    cout << "\n=== Wylosowane Mecze ===\n";
    for (auto& m : mecze) {
        cout << kluby[m.klub1].nazwa << " vs " << kluby[m.klub2].nazwa << endl;
    }
}
