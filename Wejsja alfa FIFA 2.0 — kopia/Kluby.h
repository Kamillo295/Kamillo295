#pragma once
#ifndef KLUBY_H
#define KLUBY_H

#include <string>
#include <vector>
using namespace std;

class Klub
{
public:
    int indeks;
    string nazwa;
    int sila;

public:
    Klub(int indeks = 99, string nazwa = "brak", int sila = 0);
    void wyswietl_info();
    ~Klub();
};

// deklaracja funkcji, która zwraca wektor klubów
vector<Klub> utworz_liste_klubow();

#endif // !KLUBY_H
