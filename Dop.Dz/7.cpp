#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;
char find_most_common_starting_letter(const string& input) {
    map<char, int> letter_count;
    bool new_word = true;

    for (char c : input) {
        if (c == ' ') {
            new_word = true;
        } else if (new_word) {
            char lower_c = tolower(c);
            letter_count[lower_c]++;
            new_word = false;
        }
    }
    char most_common_letter = ' ';
    int max_count = 0;

    for (const auto& entry : letter_count) {
        if (entry.second > max_count) {
            max_count = entry.second;
            most_common_letter = entry.first;
        }
    }
    return most_common_letter;
}
int main() {
    string input;
    getline(cin, input);

    char most_common_starting_letter = find_most_common_starting_letter(input);
    cout << "Наиболее часто встречающаяся начальная буква: " << most_common_starting_letter << endl;

    return 0;
}
// input: Kak je hochetsya tyanochku, huden'kuiy, blednuiy ne ochen' visokuiy
// Res: h
