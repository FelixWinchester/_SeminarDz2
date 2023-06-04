#include <iostream>
#include <string>
using namespace std;
class Conference {
private:
    string name;
    string location;
    string* speakers;
    int numSpeakers;
    int maxSpeakers;
    int numAttendees;
public:
    // Конструкторы
    Conference() {
        name = "";
        location = "";
        numSpeakers = 0;
        maxSpeakers = 10;
        speakers = new string[maxSpeakers];
        numAttendees = 0;
    }
    Conference(string n, string l, int num) {
        name = n;
        location = l;
        numSpeakers = 0;
        maxSpeakers = 10;
        speakers = new string[maxSpeakers];
        numAttendees = num;
    }
    // Деструктор
    ~Conference() {
        delete[] speakers;
    }
    // Методы
    void addSpeaker(string speaker) {
        if (numSpeakers == maxSpeakers) {
            // Увеличиваем размер массива вдвое
            maxSpeakers *= 2;
            string* newSpeakers = new string[maxSpeakers];
            for (int i = 0; i < numSpeakers; i++) {
                newSpeakers[i] = speakers[i];
            }
            delete[] speakers;
            speakers = newSpeakers;
        }
        speakers[numSpeakers] = speaker;
        numSpeakers++;
    }
    void printSpeakers() {
        cout << "Speakers: ";
        for (int i = 0; i < numSpeakers; i++) {
            cout << speakers[i] << ", ";
        }
        cout << endl;
    }
    // Перегруженные операторы
    bool operator==(const Conference& other) const {
        return name == other.name && location == other.location && numAttendees == other.numAttendees;
    }
    bool operator!=(const Conference& other) const {
        return !(*this == other);
    }
};

int main() {
    Conference conf1("AI Conference", "San Francisco", 500);
    Conference conf2("Web Conference", "New York", 300);
    conf1.addSpeaker("John Smith");
    conf1.addSpeaker("Jane Doe");
    conf2.addSpeaker("Bob Johnson");
    conf2.addSpeaker("Alice Lee");
    conf1.printSpeakers();
    conf2.printSpeakers();
    if (conf1 == conf2) {
        cout << "The conferences are the same." << endl;
    } else {
        cout << "The conferences are different." << endl;
    }
    return 0;
}
