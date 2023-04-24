#include <iostream>

using namespace std;

template <typename l>
class List
{
	struct Item
	{
		l inf;
		Item* next;
		Item(l x, Item* ref = nullptr) : inf(x), next(ref) {}
	} 
    *first = nullptr, *last = nullptr;
public:
	void add(l x)
	{
		Item *item = new Item(x);
		if (last != nullptr)
			last->next = item;
		last = item;
		if (first == nullptr)
			first = last;
	}

    void pop_back()
  {
    if (first == nullptr) 
      return;
    if (first == last) 
    {
      delete first;
      first = nullptr;
      last = nullptr;
      return;
    }
    Item* t = first;
    while (t->next != last)
      t = t->next;
    delete last; 
    last = t;
    last->next = nullptr; 
  }

	void print()
	{
		for (Item* t = first; t != nullptr; t = t->next)
			cout << t->inf << " ";
		cout << endl;
	}
    void duplicateEven()
    {
      if (first == nullptr) 
         return;
      Item* t = first;
      while (t != nullptr)
      {
        if (t->inf % 2 == 0)
        {
          Item* newItem = new Item(t->inf, t->next); 
          t->next = newItem; 
          if (t == last)
            last = newItem;
          t = t->next; 
        }
        t = t->next;
      }
    }
     ~List() 
    {
    while (first != nullptr) 
    {
      this->pop_back();
     
    }
  }
};

int main()
{
	List<int> lst;
    lst.add(1);
	  lst.add(2);
	  lst.add(3);
	  lst.add(3);
	  lst.add(6);
	  lst.print();
    lst.duplicateEven();
    lst.print();
    lst.~List();
    system("pause");
}
