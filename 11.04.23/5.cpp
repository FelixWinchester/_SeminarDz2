
#include <iostream>
#include <string>

using namespace std;

class rectangle {
  // Объявление приватных полей класса
  double x_lv, y_lv, x_pv, y_pv, x_ln, y_ln, x_pn, y_pn, dlina, shirina;
public:
  // Объявление конструкторов класса
  rectangle(double dlina, double shirina)
  {
    sp(0, 0, dlina, shirina);
  }
  rectangle(double x_lv, double y_lv, double x_pn, double y_pn)
  {
    sp(x_lv, y_lv, x_pn, y_pn);
  }
  rectangle(double x_lv, double y_lv, double dlina, double shirina)
  {
    sp(x_lv, y_lv, dlina, shirina);
  }
  // Объявление методов класса для установки значений полей
  bool setLength(double dlina)
  {
    if (dlina > 0)
    {
      this->dlina = dlina;
      return true;
    }
    else return false;
  }
  bool sS(double shirina)
  {
    if (shirina > 0)
    {
      this->shirina = shirina;
      return true;
    }
    else return false;
  }
  bool setPoints(double x_lv, double y_lv, double x_pn, double y_pn)
  {
    this->x_lv = x_lv;
    this->y_lv = y_lv;
    this->x_pn = x_pn;
    this->y_pn = y_pn;
    return true;
  }
  bool sp(double x_lv, double y_lv, double x_pn, double y_pn)
  {
    setPoints(x_lv, y_lv, x_pn, y_pn);
    return true;
  }
  bool sp(double x_lv, double y_lv, double dlina, double shirina)
  {
    setPoints(x_lv, y_lv, 0, 0);
    setLength(dlina);
    sS(shirina);
    return true;
  }
  // Объявление методов класса для вычисления значений полей
  bool dlina(double x_lv, double y_lv, double x_pn, double y_pn)
  {
    this -> dlina = abs(x_lv - x_pn);
    cout << dlina << endl;
    return true;
  }
  bool shirina(double x_lv, double y_lv, double x_pn, double y_pn)
  {
    this->shirina = abs(y_lv - y_pn);
    cout << shirina << endl;
    return true;
  }
  bool tochki(double x_lv, double y_lv, double dlina, double shirina)
  {
    this->x_ln = x_lv;
    this->y_lv = y_lv - shirina;
    this->x_pv = x_lv + dlina;
    this->y_pv = y_lv;
    this->x_pn = x_lv + dlina;
    this->y_pn = y_lv - shirina;
    cout << x_lv << ' ' << y_lv << ' ' << ' ' << x_ln << ' ' << y_ln << ' ' << x_pv << ' ' << y_pv << x_pn << ' ' << y_pn;
  }
  // Объявление методов класса для изменения значений полей
  void swap(double dlina, double shirina)
  {
    this->dlina = dlina;
    this->shirina = shirina;
  }
  void swap_tochki(double x_lv, double y_lv)
  {
    this->x_lv = x_lv;
    this->y_lv = y_ln;
    this->x_ln = x_lv;
    this->y_lv = y_lv - shirina;
    this->x_pv = x_lv + dlina;
    this->y_pv = y_lv;
    this->x_pn = x_lv + dlina;
    this->y_pn = y_lv - shirina;
  }
};
