#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** X, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j);
void Print(int** X, const int rowCount, const int colCount, int i, int j);
void Sort(int** X, const int rowCount, const int colCount, int i0, int i1, int j);
void Change(int** X, const int row1, const int row2, const int colCount, int j);
void Calc(int** X, const int rowCount, const int colCount, int& S, int& k, int i, int j);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -12;
	int High = 23;
	int rowCount = 7;
	int colCount = 6;

	int** X = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		X[i] = new int[colCount];

	int i = 0;
	int j = 0;
	int i0 = 0;
	int i1 = 0;
	Create(X, rowCount, colCount, Low, High, i, j);
	Print(X, rowCount, colCount, i, j);
	Sort(X, rowCount, colCount, i0, i1, j);
	Print(X, rowCount, colCount, i, j);
	int S = 0;
	int k = 0;
	Calc(X, rowCount, colCount, S, k, i, j);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(X, rowCount, colCount, i, j);

	for (int i = 0; i < rowCount; i++)
		delete[] X[i];
	delete[] X;
	return 0;
}
void Create(int** X, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j)
{
	X[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(X, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(X, rowCount, colCount, Low, High, i + 1, 0);
}
void Print(int** X, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << X[i][j];
	if (j < colCount - 1)
		Print(X, rowCount, colCount, i, j + 1);
	else
	{
		cout << endl;
		if (i < rowCount - 1)
		{
			Print(X, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl;
	}
}
void Sort(int** X, const int rowCount, const int colCount, int i0, int i1, int j)
{
	if ((X[i1][0] > X[i1 + 1][0])
		||
		(X[i1][0] == X[i1 + 1][0] &&
			X[i1][1] > X[i1 + 1][1])
		||
		(X[i1][0] == X[i1 + 1][0] &&
			X[i1][1] == X[i1 + 1][1] &&
			X[i1][3] < X[i1 + 1][3]))
		Change(X, i1, i1 + 1, colCount, j);
	if (i1 < rowCount - i0 - 2)
		Sort(X, rowCount, colCount, i0, i1 + 1, j);
	else
		if (i0 < rowCount - 1)
			Sort(X, rowCount, colCount, i0 + 1, 0, j);
}
void Change(int** X, const int row1, const int row2, const int colCount, int j)
{
	int tmp = X[row1][j];
	X[row1][j] = X[row2][j];
	X[row2][j] = tmp;
	if (j < colCount - 1)
		Change(X, row1, row2, colCount, j + 1);

}
void Calc(int** X, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
	if (X[i][j] % 2 != 0 || !(X[i][j] < 0))
	{
		S += X[i][j];
		k++;
		X[i][j] = 0;
	}
	if (j < colCount - 1)
		Calc(X, rowCount, colCount, S, k, i, j + 1);
	else
		if (i < rowCount - 1)
			Calc(X, rowCount, colCount, S, k, i + 1, 0);
}