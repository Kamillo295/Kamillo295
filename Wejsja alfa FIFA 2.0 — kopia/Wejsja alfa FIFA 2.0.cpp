#include <iostream>
#include <vector>
#include <iomanip>
#include "Kluby.h"
#include "Matching.h"

using namespace std;

void losownie_grupa();

int main()
{
    srand(time(NULL));
    vector<Klub> kluby = utworz_liste_klubow();

    //nagłówki tabeli
    cout << left << setw(8) << "Indeks"
        << setw(25) << "Nazwa Klubu"
        << setw(5) << "Sila" << endl;
    cout << string(38, '-') << endl;

    //info o każdym klubie
    for (int i = 0; i < kluby.size(); i++) {
        kluby[i].wyswietl_info();
    }

    losownie_grupa();


    return 0;
}
