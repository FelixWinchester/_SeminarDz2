#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
class Conference {
public:
    Conference() {}
    Conference(string name, string date, bool isOnline, string topic) :
        name_(name), date_(date), isOnline_(isOnline), topic_(topic) {}

    string getName() const { return name_; }
    string getDate() const { return date_; }
    bool getIsOnline() const { return isOnline_; }
    string getTopic() const { return topic_; }

    bool operator==(const Conference& other) const {
        return name_ == other.name_ && date_ == other.date_ && isOnline_ == other.isOnline_ && topic_ == other.topic_;
    }

private:
    string name_;
    string date_;
    bool isOnline_;
    string topic_;
};

int main() {
    vector<Conference> conferencesVec;
    list<Conference> conferencesList;

    // Создаем экземпляры класса "Конференция" и добавляем их в вектор и список
    Conference conf1("Conference 1", "2023-06-10", true, "Topic 1");
    Conference conf2("Conference 2", "2023-06-15", false, "Topic 2");
    Conference conf3("Conference 3", "2023-06-20", true, "Topic 1");
    Conference conf4("Conference 4", "2023-06-25", false, "Topic 3");
    Conference conf5("Conference 5", "2023-06-30", true, "Topic 2");

    conferencesVec.push_back(conf1);
    conferencesVec.push_back(conf2);
    conferencesVec.push_back(conf3);
    conferencesVec.push_back(conf4);
    conferencesVec.push_back(conf5);

    conferencesList.push_back(conf1);
    conferencesList.push_back(conf2);
    conferencesList.push_back(conf3);
    conferencesList.push_back(conf4);
    conferencesList.push_back(conf5);

    // Удаляем мероприятия, не удовлетворяющие определенному условию
    conferencesVec.erase(remove_if(conferencesVec.begin(), conferencesVec.end(), [](const Conference& conf) { return conf.getIsOnline(); }), conferencesVec.end());

    conferencesList.remove_if([](const Conference& conf) { return conf.getTopic() != "Topic 2"; });

    // Подсчитываем количество удовлетворяющих другому условию из оставшихся
    int count = count_if(conferencesVec.begin(), conferencesVec.end(),
        [](const Conference& conf) { return conf.getTopic() == "Topic 1"; });

    cout << "Number of conferences with topic 'Topic 1': " << count << endl;

    count = count_if(conferencesList.begin(), conferencesList.end(),
        [](const Conference& conf) { return conf.getDate() > "2023-06-20"; });

    cout << "Number of conferences after June 20: " << count << endl;

    return 0;
}
