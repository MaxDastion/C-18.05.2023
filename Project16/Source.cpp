#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split_string(string& str) {
    vector<string> words;
    string word;
    for (char c : str) {
        if (isalnum(c)) {
            word += c;
        }
        else {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
            if (!isspace(c)) {
                words.emplace_back(1, c);
            }
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

int main() {
    string input_str;
    cout << "Enter strig: ";
    getline(cin, input_str);
    auto words = split_string(input_str);
    for ( auto& word : words) {
        cout << word << endl;
    }
}
