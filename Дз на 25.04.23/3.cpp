#include <iostream>
using namespace std;
class SimpleVector {
    int size;
    int *data;

    public:
        SimpleVector() {
            size = 0;
            data = nullptr;
        }

        SimpleVector(int size) {
            this->size = size;
            data = new int[size];
        }

        ~SimpleVector() {
            delete[] data;
        }

        void push_back(int value) {
            int *temp = new int[size + 1];
            for (int i = 0; i < size; i++) {
                temp[i] = data[i];
            }
            temp[size] = value;
            
            delete[] data;
            data = temp;
            size++;
        }

        int operator[](int index) {
            return data[index];
        }
};

int main() {
    SimpleVector vec(3);
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    cout << vec[0] << endl; 
    cout << vec[1] << endl; 
    cout << vec[2] << endl; 
    cout << vec[3] << endl; 
}
