#include <iostream> 
#include <string> 
#include <cstdlib> //подключение библиотеки для работы со случайными числами

using namespace std;
int randomInt(int a, int b) { //функция, возвращающая случайное целое число в диапазоне от a до b
  return rand() % (b - a + 1) + a;
}
class BowlingBall { //определение класса "боулинговый шар"
  int weight; //поле "вес"
  string color; //поле "цвет"
public:
  static int count; //статическое поле "количество"

  BowlingBall() { //конструктор без параметров
    count++; //увеличение количества шаров
  } // = default;

  BowlingBall(int weight, string color) { //конструктор с параметрами
    count++; //увеличение количества шаров
    setParams(weight, color); //установка параметров шара
  }

  BowlingBall(const BowlingBall& other) { //конструктор копирования
    setParams(other.weight, other.color); //установка параметров шара, скопированных из другого шара
    count++; //увеличение количества шаров
  }

  bool setWeight(int weight) { //метод для установки веса шара
    if (weight > 0) { //если вес положительный
      this->weight = weight; //установка веса
      return true; //возвращение true
    }
    return false; //возвращение false в случае, если вес отрицательный
  }
  bool setColor(string color) { //метод для установки цвета шара
    if (color != "") { //если цвет не пустой
      this->color = color; //установка цвета
      return true; //возвращение true
    }
    return false; //возвращение false в случае, если цвет пустой
  }
  void setParams(int weight, string color) { //метод для установки параметров шара
    setWeight(weight); //установка веса
    setColor(color); //установка цвета
  }
  bool operator<(const BowlingBall& other) { //оператор сравнения
    return weight < other.weight; //возвращение true, если вес текущего шара меньше веса другого
  }
  bool operator==(const BowlingBall& other) { //оператор сравнения
    return (weight == other.weight) && (color == other.color); //возвращение true, если вес и цвет текущего шара равны весу и цвету другого
  }

  void print() { //метод для вывода информации о шаре
    cout << weight << " (" << color << ")\n";
  }

  // ++b
  BowlingBall& operator++() { //префиксный оператор инкремента
    weight++; //увеличение веса на 1
    return *this; //возвращение ссылки на текущий объект
  }
  // b++
  BowlingBall operator++(int) { //постфиксный оператор инкремента
    BowlingBall tmp(*this); //создание временного объекта, копирующего текущий
    weight++; //увеличение веса на 1
    return tmp; //возвращение временного объекта
  }
};

int BowlingBall::count = 0; //инициализация статического поля "количество"

int main()
{
  setlocale(LC_ALL, "Russian"); //установка локали для корректного вывода на русском языке
  srand(time(NULL)); //инициализация генератора случайных чисел текущим временем
  int n = 10; //количество шаров
  string* colors = new string[10]; //динамический массив строк для хранения цветов
  colors[0] = "red"; //установка цвета для каждого элемента массива
  colors[1] = "green";
  colors[2] = "purple";
  colors[3] = "pink";
  colors[4] = "blue";
  colors[5] = "magenta";
  colors[6] = "yellow";
  colors[7] = "white";
  colors[8] = "black";
  colors[9] = "gray";
  cout << "Не отсортированные\n\n";
  BowlingBall* balls = new BowlingBall[n]; //динамический массив объектов класса "боулинговый шар"
  int randWeight, col; //переменные для хранения случайных значений веса и цвета
  for (int i = 0; i < n; i++) { //цикл для заполнения массива шарами со случайными параметрами
    randWeight = randomInt(1, 11); //генерация случайного веса
    col = randomInt(0, 9); //генерация случайного цвета
    balls[i].setParams(randWeight, colors[col]); //установка параметров шара
    balls[i].print(); //вывод информации о шаре
  }
  cout << "\nОтсортированные\n\n";
  for (int i = 1; i < n; i++) //сортировка массива шаров методом пузырька
    for (int j = i; j > 0 && (balls[j] < balls[j - 1]); j--) //сравнение элементов массива и их перемещение в соответствии с порядком
      swap(balls[j - 1], balls[j]); //обмен значениями
  for (int i = 0; i < n; i++) //цикл для вывода отсортированных шаров
    balls[i].print(); //вывод информации о шаре
}
