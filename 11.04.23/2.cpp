#include <iostream> 
#include <string> 

using namespace std; 

class BowlingBall { 
  int weight; // поле "вес" шара
  string color; // поле "цвет" шара
public:
  static int count; // статическое поле "количество" шаров
  BowlingBall() { // конструктор по умолчанию
    count++; // увеличение счетчика на 1
  } 

  BowlingBall(int weight, string color) { // конструктор с параметрами
    count++; // увеличение счетчика на 1
    setParams(weight, color); // вызов метода установки параметров
  }

  BowlingBall(const BowlingBall& other) { // конструктор копирования
    setParams(other.weight, other.color); // вызов метода установки параметров
    count++; // увеличение счетчика на 1
  }

  bool setWeight(int weight) { // метод установки веса
    if (weight > 0) { // если вес положительный
      this->weight = weight; // установка веса
      return true; // возвращается true
    }
    return false; 
  }
  bool setColor(string color) { // метод установки цвета
    if (color != "") { // если строка не пустая
      this->color = color; // установка цвета
      return true; // возвращается true
    }
    return false; 
  }
  void setParams(int weight, string color) { // метод установки параметров
    setWeight(weight); // вызов метода установки веса
    setColor(color); // вызов метода установки цвета
  }
  bool operator<(const BowlingBall& other) { // перегрузка оператора "<"
    return weight < other.weight; // возвращается результат сравнения весов
  }
  bool operator==(const BowlingBall& other) { // перегрузка оператора "=="
    return (weight == other.weight) && (color == other.color); // возвращается результат сравнения весов и цветов
  }

  void print() { // метод печати информации о шаре
    cout << weight << " (" << color << ")\n"; // выводится вес и цвет шара
  }

  // ++b
  BowlingBall& operator++() { // перегрузка оператора "++" (префиксная форма)
    weight++; // увеличение веса на 1
    return *this; // возвращается ссылка на объект
  }
  // b++
  BowlingBall operator++(int) { // перегрузка оператора "++" (постфиксная форма)
    BowlingBall tmp(*this); // создание временного объекта
    weight++; // увеличение веса на 1
    return tmp; // возвращается временный объект
  }
};

int BowlingBall::count = 0; 

int main() // функция main
{
  BowlingBall b1(10, "red"); // создание объекта "шар" с параметрами
  BowlingBall b2(11, "green"); // создание объекта "шар" с параметрами
  BowlingBall b3(b2); // создание объекта "шар" как копии другого объекта
  BowlingBall b4(10, "red"); // создание объекта "шар" с параметрами
  cout << (b1 < b2) << endl; // выводится результат сравнения весов шаров
  cout << (b1 == b2) << endl; // выводится результат сравнения весов и цветов шаров
  cout << (b3 == b2) << endl; // выводится результат сравнения весов и цветов шаров
  cout << (b1 == b4) << endl; // выводится результат сравнения весов и цветов шаров
  cout << (b3 < b1) << endl; // выводится результат сравнения весов шаров
 
}
