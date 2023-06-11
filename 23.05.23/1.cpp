/*
а)  Вставить элементы равные нулю до и после первого минимального.
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> vec;
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    int min = vec[0];
    int min_index = 0;
    // Находим индекс первого минимального элемента
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] < min) {
            min = vec[i];
            min_index = i;
        }
    }
    // Вставляем элементы равные нулю до и после первого минимального элемента
    vec.insert(vec.begin() + min_index, 0);
    vec.insert(vec.begin() + min_index + 3, 0);

    for (int i = 0; i < vec.size(); i++) {
       cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
Алгоритм имеет линейную временную сложность O(n), где n - количество элементов в векторе. 
В алгоритме используется один цикл для нахождения индекса первого минимального элемента, который работает за O(n), и четыре операции вставки, каждая из которых работает за O(1). 
Таким образом, общая временная сложность алгоритма составляет O(n + 4) = O(n), что является линейной сложностью.
*/
/*
б) Заменить средний элемент на максимальный отрицательный. 
Если среднего элемента нет (количество элементов чётное) или максимальный определить невозможно, ничего не менять, но сообщить об ошибке.
*/
#include <iostream>
#include <list>
using namespace std;
int main() {
    list<int> values;
    int value;
    while (cin >> value) {
        values.push_back(value);
    }
    int sum = 0;
    int count = 0;
    int max_negative = INT_MIN;
    int middle_value = 0;
    bool has_middle = false;
    for (int value : values) {
        sum += value;
        count++;
        if (value < 0 && value > max_negative) {
            max_negative = value;
        }
    }
    if (count % 2 == 1) {
        middle_value = *(next(values.begin(), count / 2));
        has_middle = true;
    }
    if (!has_middle) {
        cout << "There is no middle element." << endl;
    } else if (max_negative == INT_MIN) {
        cout << "There is no negative element." << endl;
    } else {
        int index = count / 2;
        auto it = next(values.begin(), index);
        *it = max_negative;
        cout << "Middle element was replaced with max negative: " << *it << endl;
    }
    return 0;
}
/*
Алгоритм имеет линейную временную сложность O(N), где N - количество элементов в списке. 
В цикле for мы проходим по всем элементам списка, чтобы вычислить сумму, количество элементов и максимальный отрицательный элемент. Это занимает O(N) времени.
Затем мы проверяем наличие среднего элемента и максимального отрицательного элемента. Это занимает постоянное время O(1).
Если все условия выполняются, то мы выполняем замену элемента, используя операцию next(), которая работает за O(1) времени.
Таким образом, общая временная сложность алгоритма равна O(N).
*/
