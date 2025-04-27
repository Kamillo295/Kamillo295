#include "Kluby.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

Klub::Klub(int i, string n, int s)
{
    indeks = i;
    nazwa = n;
    sila = s;
}

void Klub::wyswietl_info()
{
    cout << left << setw(8) << indeks
        << setw(25) << nazwa
        << setw(5) << sila << endl;
}

Klub::~Klub()
{

}

vector<Klub> utworz_liste_klubow() {
    return {
        Klub(0, "FC Barcelona", 90),
        Klub(1, "Real Madrid", 88),
        Klub(2, "Manchester City", 92),
        Klub(3, "Bayern Monachium", 89),
        Klub(4, "Paris Saint-Germain", 87),
        Klub(5, "Liverpool", 86),
        Klub(6, "Arsenal", 84),
        Klub(7, "Inter Mediolan", 85),
        Klub(8, "AC Milan", 83),
        Klub(9, "Juventus", 82),
        Klub(10, "Chelsea", 81),
        Klub(11, "Atletico Madryt", 80),
        Klub(12, "Borussia Dortmund", 79),
        Klub(13, "Napoli", 78),
        Klub(14, "Benfica", 77),
        Klub(15, "Ajax", 76)
    };
}
