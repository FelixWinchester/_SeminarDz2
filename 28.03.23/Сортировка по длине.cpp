#include <iostream> 
#include <algorithm> 
#include <string> 
using namespace std; 
bool comp(string& s1, string& s2) { // объявление функции сравнения двух строк
    if (s1.length() == s2.length()) { // если длины строк равны
        return s1.length() < s2.length(); // возвращает результат сравнения длин строк
    }
    return s1.length() < s2.length(); // возвращает результат сравнения длин строк
}

int main() { 
    int n; 
    cin >> n; 
    string *a = new string [n]; // создание динамического массива строк
    for (int i = 0; i < n; i++) // цикл для ввода строк
        cin >> a[i];

    sort(a, a + n, comp); // сортировка массива строк

    for (int i = 0; i < n; i++) // цикл для вывода отсортированных строк
        cout << a[i] << " ";
 
    delete[]a; 
    return 0; 
}
