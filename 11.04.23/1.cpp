#include <iostream> 
#include <string> 
using namespace std; 
class BowlingBall { 
  int weight; // объявление переменной "вес"
  string color; // объявление переменной "цвет"
public:
  static int count; // объявление статической переменной "количество"

  BowlingBall() { // конструктор без параметров
    count++; // увеличение значения статической переменной на 1
  } 

  BowlingBall(int weight, string color) { // конструктор с параметрами
    count++; // увеличение значения статической переменной на 1
    setParams(weight, color); // вызов функции для задания параметров
  }

  BowlingBall(const BowlingBall& other) { // конструктор копирования
    setParams(other.weight, other.color); // вызов функции для задания параметров
    count++; // увеличение значения статической переменной на 1
  }

  bool setWeight(int weight) { // функция для задания веса
    if (weight > 0) { // если вес больше 0
      this->weight = weight; // присвоить значение переменной "вес"
      return true; // вернуть true
    }
    return false; // иначе вернуть false
  }

  bool setColor(string color) { // функция для задания цвета
    if (color != "") { // если цвет не пустой
      this->color = color; // присвоить значение переменной "цвет"
      return true; // вернуть true
    }
    return false; // иначе вернуть false
  }

  void setParams(int weight, string color) { // функция для задания параметров
    setWeight(weight); // вызов функции для задания веса
    setColor(color); // вызов функции для задания цвета
  }

  void print() { // функция для вывода на экран
    cout << weight << " (" << color << ")\n"; // вывод значения переменной "вес" и "цвет"
  }

  // ++b
  BowlingBall& operator++() { // перегрузка оператора "++" (префиксный инкремент)
    weight++; // увеличение значения переменной "вес" на 1
    return *this; // возврат ссылки на текущий объект
  }

  // b++
  BowlingBall operator++(int) { // перегрузка оператора "++" (постфиксный инкремент)
    BowlingBall tmp(*this); // создание временной копии текущего объекта
    weight++; // увеличение значения переменной "вес" на 1
    return tmp; // возврат временной копии
  }
};

int BowlingBall::count = 0; // инициализация статической переменной "количество"

int main() 
{

  BowlingBall ball1(10, "purple"); // создание объекта "ball1" класса "Боулинговый шар" с параметрами
  (++ball1).print(); // применение префиксного инкремента и вывод на экран

  BowlingBall ball2(3, "green"); // создание объекта "ball2" класса "Боулинговый шар" с параметрами
  ball2++.print(); // применение постфиксного инкремента и вывод на экран

}
