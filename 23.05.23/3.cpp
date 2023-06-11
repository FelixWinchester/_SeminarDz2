// a)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для проверки, является ли число простым
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> v;
    int n;
    // Считывание элементов вектора до ввода числа 0
    cout << "Enter the elements of the vector (0 to stop): ";
    while (cin >> n && n != 0) {
        v.push_back(n);
    }
    // Разделение вектора, перемещение простых чисел в начало
    auto it = stable_partition(v.begin(), v.end(), is_prime);
    // Вывод разделенного вектора
    cout << "The vector after partitioning: ";
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
// b)
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// Функция для проверки, является ли число простым
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    list<int> lst;
    int n, x;
    // Считывание количества элементов в списке
    cin >> n;
    // Считывание элементов списка
    for (int i=0; i<n; i++){
        cin >> x;
        lst.push_back(x);
    }
    // Разделение списка, перемещение простых чисел в начало
    auto it = stable_partition(lst.begin(), lst.end(), is_prime);
    // Вывод разделенного списка
    cout << "The list after partitioning: ";
    for (auto i = lst.begin(); i != lst.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
