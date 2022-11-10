#include <iostream>
#include <time.h>
using namespace std;

void Create(int* mas, const int n, int A, int B)
{
	for (int i = 0; i < n; i++) {
		mas[i] = A + rand() % (B - A + 1);
	}
}
void Print(int* mas, const int n) {
	cout << "A {";
	for (int i = 0; i < n; i++)
		cout << " " << mas[i];
	cout << "}";
	cout << endl;
}
void Found_Max(int* mas, const int n, int& max_el, int& index_max) {
	int i = 0;
	max_el = mas[i];
	index_max = 0;
	for (i = 0; i < n; i++) {
		if (mas[i] > max_el) {
			max_el = mas[i];
			index_max = i;
		}
	}
}void  Found_Min(int* mas, const int n, int& min_el, int& index_min) {
	int i = 0;
	min_el = mas[i];
	for (i = 0; i < n; i++) {
		if (mas[i] < min_el) {
			min_el = mas[i];
			index_min = i;
		}
	}
}
void Obmin(int* mas, const int n, int& index_max, int& index_min) {
	int prom_in = 0;

	prom_in = mas[index_max];
	mas[index_max] = mas[index_min];
	mas[index_min] = prom_in;
}
int main()
{
   srand(time(NULL));

   const int a = 20;
   int A[a]{};

	Create(A, a, -20, 50);
	Print(A, a);

	int index_max = 0;
	int max_el = 0;
	int index_min = 0;
	int min_el = 0;
	Found_Max(A, a, max_el, index_max);
	Found_Min(A, a, min_el, index_min);

	cout << "max_el " << max_el <<"  index_max " << index_max << endl;
	cout << "min_el " << min_el <<"  index_min " << index_min << endl;

	Obmin(A, a, index_max, index_min);
	Print(A, a);


   return 0;
}