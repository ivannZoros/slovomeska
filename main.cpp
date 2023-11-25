#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <time.h>
#include <algorithm>
using namespace std;
void ranndword() {
    vector <string> words = {"apples","banana","viseliza","dogs","rogaliks"};
    srand(time(0));
    int num = rand() % 5;
}
int main() {
    int flag = 0;
     vector <string> words = {"apples","banana","viseliza","dogs","rogaliks"};
    srand(time(0));
    int num = rand() % 5;
    string word = words[num];
    shuffle(words[num].begin(),words[num].end(), std::mt19937(std::random_device()()));
    int lives = 3;
    string ans;
    bool isgameover = false;
    while(!isgameover) {
        cout << "The words is - " <<word << endl;
        cout << "Your lives - " << lives << endl;
        cout << "Enter answer" << endl;
        cout << words[num] << endl;
        cin >> ans;
        if (ans == "help"){
            string help = words[num].substr(0, words[num].size() / 2);
            cout << "1/2 of words is - " << help << endl;
            flag++;
        }
        if (ans == "help" && flag == 4){
            cout << "Only 3 help!" << endl;
        }
        if (ans == words[num]) {
            cout << "Win!!Contuinue? - y/n" << endl;
            string cont;
            if (cont == "y"){
                num = rand() % 5;
            }else if(cont == "n") {
                isgameover = true;
            }
        } else if (ans != "help" || ans != "y" ) {
            lives--;
            cout << "wrong" << endl;
        }
        if (lives == 0){
            cout << "GAME OVER" << endl;
            break;
        }
    }

}


