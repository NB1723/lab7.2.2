#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <time.h>

using namespace std;
void Create(int** a, const int size, const int low, const int high, int i, int j);
void Print(int** a, const int size, int i, int j);
int Trans(int** a, const int size, int i, int j, int tmp);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));

    int low = -17;
    int high = 14;
    int size;
    int tmp = 0;
    cout << "¬вед≥ть розм≥р квадратноњ матриц≥: ";
    cin >> size;
    cout << endl;

    int** a = new int* [size];
    for (int i = 0; i < size; i++)
        a[i] = new int[size];
    cout << setw(21) << "ѕочаткова матриц€" << endl;
    Create(a, size, low, high, 0, 0); cout << endl;
    Print(a, size, 0, 0); cout << endl;
    cout << setw(23) << "“ранспонована матриц€" << endl;
    Trans(a, size, 0, 0, tmp); cout << endl;
    Print(a, size, 0, 0); cout << endl;
    for (int i = 0; i < size; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
void Create(int** a, const int size, const int low, const int high, int i, int j)
{
    if (j < size)
    {
        a[i][j] = low + rand() % (high - low + 1);
        return Create(a, size, low, high, i, j + 1);
    }
    if (i < size - 1)
        return Create(a, size, low, high, i + 1, 0);
}
void Print(int** a, const int size, int i, int j)
{
    if (j < size)
    {
        cout << setw(4) << a[i][j];
        Print(a, size, i, j + 1);
    }
    cout << endl;
    if (i < size - 1)
        Print(a, size, i + 1, 0);
}

int Trans(int** a, const int size, int i, int j, int tmp)
{
    if (j < size)
    {
        if(tmp == a[i][j])
           
            a[j][i] = tmp;
            return Trans(a, size, i, j, tmp);
    }
    else
            return Trans(a, size, i, j, tmp);    
}