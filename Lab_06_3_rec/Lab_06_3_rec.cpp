#include <iostream>
#include <iomanip>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
}

template <typename T>
void Sort(T* a, const int size, int i)
{ // метод обміну (бульбашки)
	int k = 0; // показник, чи були обміни
	for (int j = 0; j < size - i; j++) // номер поточного елемента
		if (a[j] < a[j + 1]) // якщо порушено порядок
		{ // - обмін елементів місцями
			int tmp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = tmp;
			k = 1;
		}
	if (k == 0) // якщо обмінів - не було,
		return; // то припиняємо процес
	if (i < size - 1) // i - лічильник ітерацій
		Sort(a, size, i + 1); // перехід до наступної ітерації
}

void SortRec(int* a, const int size, int i)
{ 
	int k = 0; 
	for (int j = 0; j < size - i; j++) 
		if (a[j] < a[j + 1]) 
		{ 
			int tmp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = tmp;
			k = 1;
		}
	if (k == 0) 
		return; 
	if (i < size - 1) 
		Sort(a, size, i + 1); 
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 10;
	int a[n];
	int Low = 1;
	int High = 31;
	Create(a, n, Low, High, 0);
	cout << "array =                   ["; Print(a, n, 0); cout << "  ]" << endl;
	SortRec(a, n, 1);
	cout << "sorted array (recursive)= ["; Print(a, n, 0); cout << "  ]" << endl << endl;
	Create(a, n, Low, High, 0);
	cout << "array =                   ["; Print(a, n, 0); cout << "  ]";
	Sort(a, n, 1); cout << endl;
	cout << "sorted array  (template)= ["; Print(a, n, 0); cout << "  ]";
	return 0;
}
