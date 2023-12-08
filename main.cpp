#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <time.h>
#include <algorithm>
using namespace std;
string shufle(const string& words) {
    string shuffle_word = words;
    shuffle(shuffle_word.begin(),shuffle_word.end(), std::mt19937(std::random_device()()));
    return shuffle_word;
}

bool check_answer(const string& correct_word, const string& ans) {
    if (correct_word == ans){
        return true;
    }
    return false;
}
int main() {
    srand(time(0));
    int lives = 3;
    int help = 3;
    vector<string> words = {"apple", "banana", "viseliza", "dogs", "rogalik"};
    int numwords = words.size();
    for (int i = 0; i < numwords;) {
        string correct_word = words[i];
        string shuffle_word = shufle(correct_word);
        cout << "Your lives - " << lives << endl;
        cout << "You can use - " << help << "  help" << endl;
        cout << correct_word << " - ans" << endl;
        cout << "The words is - " << shuffle_word << endl;
        string ans;
        cin >> ans;
        if (ans == "help" && help > 0) {
            cout << "Help -  " << correct_word.substr(0, correct_word.length() / 2) << endl;
            help--;
            //--i;
            } else if (check_answer(correct_word, ans)) {
                cout << "Next!" << endl;
                i++;
                if (i == (numwords - 1)) {
                    cout << "WIN" << endl;
                    shuffle(words.begin(), words.end(), std::mt19937(std::random_device()()));
                }
            } else if (ans == "help" && help == 0) {
                cout << "All helps have been used" << endl;
            } else {
                cout << "Wrong" << endl;
                lives--;
                if (lives == 0) {
                    cout << "GAME OVER" << endl;
                    return 0;
                }
            }
        }
    }

