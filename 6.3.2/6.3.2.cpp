#include <iostream>
#include <iomanip>
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Sort(int* a, const int size, int i)
{
	int min = a[i];
	int imin = i;
	for (int j = i + 1; j < size; j++)
		if (min < a[j])
		{
			min = a[j];
			imin = j;
		}
	a[imin] = a[i];
	a[i] = min;
	if (i < size - 2)
		Sort(a, size, i + 1);
}
void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int main()
{
	const int n = 5;
	int a[n];
	int Low = -20;
	int High = 30;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	Sort(a, n, 0);
	Print(a, n, 0);
	return 0;
}
