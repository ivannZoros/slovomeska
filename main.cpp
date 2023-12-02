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

bool check_answer(const string& correct_answer, const string& ans) {
    return correct_answer == ans;
}
int main() {
    srand(time(0));
    int lives = 3;
    int help = 3;
    vector<string> words = {"apples", "banana", "viseliza", "dogs", "rogaliks"};
    int numwords = words.size();
    cout << "Your lives - " << lives << endl;
    cout << "You can use - " << help << "  help" << endl;
    string ans;
    for (int i = 0; i < numwords; i++) {
        string correct_word = words[i];
        string shuffle_word = shufle(correct_word);
        cout << "The words is - " << correct_word << endl;
        cin >> ans;
        if (check_answer(correct_word, ans)) {
            cout << "WIN!" << endl;
            if (i == numwords - 1) {
                cout << "The words have been shuffled" << endl;
                shuffle(words.begin(), words.end(), std::mt19937(std::random_device()()));
            }
        } else if (ans == "help" && help > 0) {
            cout << "Help -  " << correct_word.substr(0, correct_word.length() / 2) << endl;
            help--;
            i--;
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