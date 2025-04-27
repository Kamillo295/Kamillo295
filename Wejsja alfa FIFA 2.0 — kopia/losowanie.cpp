#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include "Kluby.h"
#include "Matching.h"

using namespace std;

int grupa[16][5];
int ogranicznik[16];
int temp = 0, licznik = 0;

void losownie_grupa()
{
	srand(time(NULL));
	for (int i = 0 ; i < 16 ; i++)
	{
		grupa[i][0] = i;

		for (int j = 1;j < 5;j++)
		{
			
			grupa[i][j] = rand() % 16;
			temp = grupa[i][j];
			for (int k = 0;k < 5;k++)
			{
				if (k != j)
				{
					while (grupa[i][j] == grupa[i][k])
					{
						grupa[i][j] = rand() % 16;
						temp = grupa[i][j];
						licznik++;
					}
				}
					
				while (ogranicznik[temp] > 3)
				{
					grupa[i][j] = rand() % 16;
					temp = grupa[i][j];
					licznik++;
				}				

				/*if (grupa[i][j] == grupa[i][k])
				{
					i = 0;
					j = 1;
					for(int f=0;f<16;f++)
					ogranicznik[f] = 0;
				}*/
			}
			ogranicznik[temp]++;
		}
	}
	cout << endl;
	cout << endl;
	cout << endl;


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
	cout << suma << endl << licznik << endl;
}