#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;
set<string> split_string_to_set(const string& str) {
    istringstream iss(str);
    set<string> words;
    string word;
    while (iss >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.insert(word);
    }
    return words;
}

int main() {
    string str1, str2;
    cout << "Pervaya stroka: ";
    getline(cin, str1);
    cout << "Vtoraya stroka: ";
    getline(cin, str2);

    set<string> words1 = split_string_to_set(str1);
    set<string> words2 = split_string_to_set(str2);

    set<string> common_words, unique_words;

    set_intersection(words1.begin(), words1.end(), words2.begin(), words2.end(),
                          inserter(common_words, common_words.begin()));
    set_symmetric_difference(words1.begin(), words1.end(), words2.begin(), words2.end(),
                                  inserter(unique_words, unique_words.begin()));

    cout << "Slova, kotorie est' v obeih strokah odnovremenno:" << "\t";
    for (const auto& word : common_words) {
        cout << word << ' ';
    }
    cout << endl;

    cout << "Slova, kotorie est' tolko v odnoi iz dvuh strok:" << "\t";
    for (const auto& word : unique_words) {
        cout << word << ' ';
    }
    cout << endl;

    return 0;
}
