#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void init(int tab[], int n) //funkcja zapełniająca tablicę tab o rozmiarze n losowymi licbami
{
	for (int i = 0; i < n; i++)
	{
		tab[i] = rand() % 100 + 1; //zapelniam tablice liczbami losowymi z przedzialu <1, 100>
	}
}

void print(int tab[], int n) //funkcja do wyświetlenia danych z tablicy
{
	for (int i = 0; i < n; i++)
	{
		cout << tab[i] << " ";
	}
}

int podzial(int tab[], int n, int p, int r)
{
	int x = tab[p]; //obieramy x
	//i,j, - indeksy w tablicy
	int i = p;
	int j = r;
	int w;

	while (true) //petla nieskonczona, wychodzimy z niej tylko za pomoca return j
	{
		while (tab[j] > x) //dopoki elementy sa wieksze od x
		{
			j--;
		}
		while (tab[i] < x) //dopoki elementy sa mniejsze od x
		{
			i++;
		}
		if (i < j) //zamieniamy miejscami, gdy i<j
		{
			w = tab[i];
			tab[i] = tab[j];
			tab[j] = w;
			i++;
			j--;
		}
		else //gdy i>=j zwrcamy j jako punkt podzialu tablicy
			return j;
	}
}

void sort(int tab[], int n, int p, int r) //sortowanie szybkie, quicksort
{
	int q;
	if (p < r)
	{
		q = podzial(tab, n, p, r); //dzielimy tablice na dwie czesci, q oznacza punkt podzialu
			//rekurencja
			sort(tab, n, p, q); //wywolujemy rekurencyjnie sort dla pierwszej czesci tablicy
			sort(tab, n, q + 1, r); //wywolujemy rekurencyjnie sort dla drugiej czesci tablicy
	}

}


int main()
{
	cout << "QuickSort" << endl;
	cout << "**********" << endl;

	int n;
	clock_t poczatek;
	clock_t koniec;
	double wynik;

	srand(time(NULL));
	cout << endl;

	poczatek = clock();

	cout << "Podaj ile liczb chcesz posortowac n = ";
	cin >> n;
	cout << endl;

	int* tab = new int[n];

	//zapelniam tablice
	init(tab, n);

	cout << "Zawartosc tablicy przed sortowaniem:"<<endl;
	print(tab, n);
	cout << endl;

	//wywoluje algorytm sortowania szybkiego, quicksort
	sort(tab, n, 0, n - 1);
	cout << endl;

	cout << "Zawartosc tablicy po sortowaniu:" << endl;
	print(tab, n);
	cout << endl;

	koniec = clock();
	wynik = (double)(koniec - poczatek) / CLOCKS_PER_SEC;
	cout << endl;

	cout << "Czas dzialania sortowania szybkiego: "<<wynik<<" sek"<<endl;


	return 0;
}