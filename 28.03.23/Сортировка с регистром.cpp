#include <iostream> 
#include <algorithm> 
#include <string> 
using namespace std; 

void sort(string* a, int n) { // объявление функции "sort" с аргументами "a" и "n"
    for (int i = 0; i < n - 1; i++) // цикл от 0 до n-1
        for (int j = n - 1; j > i; j--) { // цикл от n-1 до i
            if (a[j].size() < a[j - 1].size()) // если размер a[j] меньше размера a[j-1]
                swap(a[j], a[j - 1]); // меняем местами a[j] и a[j-1]
            if (a[j].size() == a[j - 1].size()) { // если размер a[j] равен размеру a[j-1]
                string a1 = "", a2 = ""; // объявляем две пустые строки
                for (int f = 0; f < a[j].size(); f++) { // цикл от 0 до размера a[j]
                    a1 += tolower(a[j][f]); a2 += tolower(a[j - 1][f]); // добавляем в строку a1 и a2 соответствующие символы из a[j] и a[j-1], приводя их к нижнему регистру
                }
                if (a1 < a2) swap(a[j], a[j - 1]); // если a1 меньше a2, меняем местами a[j] и a[j-1]
            }

        }
}

int main() { 
    int n; cin >> n; // объявление переменной "n" и ввод её значения
    string* a = new string[n]; // объявление указателя "a" на массив строк размера "n"
    for (int i = 0; i < n; i++) // цикл от 0 до n
        cin >> a[i]; // ввод i-ой строки в массив "a"
    sort(a, n); // вызов функции "sort" для сортировки массива "a"
    for (int i = 0; i < n; i++) // цикл от 0 до n
        cout << a[i] << endl; // вывод i-ой строки из массива "a"
    delete[] a; 
}
