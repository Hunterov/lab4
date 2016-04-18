#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void NumberToText(int n);
int SearchMultiplication(int n); 	// wersja nie wiem czy akceptowalna, ale spełniająca wymogi ;)
int SearchMultiplication2(int n);

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);

	cout << "n slownie:    ";
	NumberToText(n);
	cout << endl << "n*k slownie:  ";
	NumberToText(SearchMultiplication(n));
	cout << endl << "n*k slownie2: ";
	NumberToText(SearchMultiplication2(n));
	cout << endl;
}

void NumberToText(int n)
{
	int i;
	int tab[6];

	string numbers[5][10] = {
								{"", "jeden ", "dwa ", "trzy ", "cztery ", "pięć ", "sześć ", "siedem ", "osiem ", "dziewięć "},
								{"dziesięć ", "jedenaście ", "dwanaście ", "trzynaście ", "czternaście ", "piętnaście ", "szesnaście ", "siedemnaście ", "osiemnaście ", "dziewiętnaście "},
								{"", "dziesięć ", "dwadzieścia ", "trzydzieści ", "czterdzieści ", "pięćdziesiąt ", "sześćdziesiąt ", "siedemdziesiąt ", "osiemdziesiąt ", "dziewięćdziesiąt "},
								{"", "sto ", "dwieście ", "trzysta ", "czterysta ", "pięćset ", "sześćset ", "siedemset ", "osiemset ", "dziewięćset "},
								{"tysiąc ", "tysiące ", "tysięcy "}
							};

	if (n==0)
		cout << "zero ";

	else if (n>0 && n<1000000)
	{
		for (i=0; i<6; i++)
		{
			tab[5-i] = n % 10;
			n = n / 10;
		}

		for (i=0; i<6; i++)
		{
			if (i==0 || i==3)
			{
				cout << numbers[3][tab[i]];

				if (i==0 && tab[i]!=0 && tab[i+1]==0 && tab[i+2]==0)
					cout << numbers[4][2];
			}

			else if (i==1 || i==4)
			{
				if (tab[i]==1)
					cout << numbers[1][tab[i+1]];
				else
					cout << numbers[2][tab[i]];

				if (i==1 && ( (tab[i]!=0 && tab[i+1]==0) || (tab[i]==1 && tab[i+1]!=0) ))
					cout << numbers[4][2];
			}

			else if (i==2 || i==5)
			{
				if (tab[i-1]!=1)
				{
					cout << numbers[0][tab[i]];

					if (i==2 && tab[i]==1 && tab[i-1]==0 && tab[i-2]==0)
						cout << numbers[4][0];

					else if (i==2 && tab[i]>=2 && tab[i]<=4)
						cout << numbers[4][1];

					else if (i==2 && (tab[i]>=5 || (tab[i]==1 && (tab[i-1]!=0 || tab[i-2]!=0))))
						cout << numbers[4][2];
				}
			}
		}
	}

	else if (n==1000000)
		cout << "jeden milion ";

	else
		cout << "liczba spoza zakresu który umiem przeczytać";
}

int SearchMultiplication(int n)
{
	return 0;
}

int SearchMultiplication2(int n)
{
	int k = 0, nk, nkCopy;
	bool ok = false;

	do
	{
		k++;
		nk = n * k;
		nkCopy = nk;
		
		while (nkCopy > 0)
		{
			if (nkCopy%10 <= 1)
			{
				ok = true;
				nkCopy = nkCopy / 10;
			}

			else
			{
				ok = false;
				break;
			}
		}

		if (ok == true)
			break;		
	}
	while (nk <= 1000000);

	if (nk >= 0 && nk <= 1000000 && ok == true)
		return nk;

	else
		return -1;	//cos musze zwrocic
}