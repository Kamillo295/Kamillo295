#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include "Kluby.h"
#include "Matching.h"
#include <windows.h>

using namespace std;

int grupa[16][5];
int ogranicznik[16] = { 0 };
int temp = 0, licznik = 0, odNowa = 0;
int a = 0;
int b = 0;

void losownie_grupa_v2()
{
	for (int i = 0; i < 16; i++)
	{
		grupa[i][0] = i;
		for (int j = 1; j < 5; j++)
		{
			grupa[i][j] = -1;
		}
	}

	a = rand() % 16;
	b = (rand() % 4) + 1;
	int test = 0;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			while (grupa[a][b] != -1)
			{
				a = rand() % 16;
				b = (rand() % 4) + 1;
				licznik++;
			}

			grupa[a][b] = i;

			for (int k = 0; k < 5; k++)
			{
				if (b != k)
					while (grupa[a][b] == grupa[a][k])
					{
						grupa[a][b] = -1;
						while (grupa[a][b] != -1)
						{
							a = rand() % 16;
							b = (rand() % 4) + 1;
						}
					}
			}
			grupa[a][b] = i;
			for (int i = 0; i < 16; i++)
			{
				cout << endl;
				for (int j = 0; j < 5; j++)
				{
					if (j == 1)
					{
						cout << " |  ";
					}

					cout << setw(2) << grupa[i][j] << " ";
				}
			}
			Sleep(500);
			system("cls");

			temp = grupa[a][b];
			ogranicznik[temp]++;
		}
	}




	for (int i = 0; i < 16; i++)
	{
		cout << endl;
		for (int j = 0; j < 5; j++)
		{
			if (j == 1)
			{
				cout << " |  ";
			}

			cout << setw(2) << grupa[i][j] << " ";
		}
	}

	cout << endl;
	cout << endl;
	int suma = 0;
	for (int i = 0; i < 16; i++)
	{
		cout << i << ". " << ogranicznik[i] << endl;
		suma += ogranicznik[i];
	}
	//cout << suma << endl << licznik << endl << odNowa << endl;

	cout << "licznik: " << licznik << endl;


	int sprawdzator = 0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (grupa[i][j] == grupa[i][k] && j != k)
				{
					sprawdzator++;
					//cout << i << " " << j << endl;
				}
			}

		}
	}
	cout << "Tyle sie zjebalo: " << sprawdzator / 2 << endl;
	//cout << "test: " << test << endl;
}