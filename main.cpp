#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <limits>
using namespace std;

void cleanCin(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void wordInput(string& word) {
    string bannedSymbols = "0123456789!@#$%^&*()_+-=<>?/\\|[]{},.;:'\" "; // example

    cout << "The word must not contain numeric characters, symbols, or spaces\n";
    cout << "Enter a word: ";
    while (true) {
        try {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "> ";
            getline(cin, word);

            for (size_t i = 0; i < word.size(); i++) {
                if (bannedSymbols.find(word[i]) != string::npos) {
                    throw std::runtime_error("The word must not contain numeric characters, symbols, or spaces");
                }
            }
            break;        
        } catch (const std::exception& e) {
            std::cout << e.what() << "\n";
        }
    }
}

void playGame(string& word){
    char charToGuess;
    vector<char> foundChars;
    int br = 0;
    string wordOutput(word.size(), '_');

    while (br < 8) {
       cout << "Take a guess!\n>";
       bool found = false;
       cin >> charToGuess;
       cleanCin();
       for(size_t i = 0; i < word.size();i++){
        if(word[i] =='0') continue;
        if(word[i] == charToGuess ){
            found = true;
            wordOutput[i] = charToGuess;
            word[i] = '0';
            foundChars.push_back(charToGuess);
        }
       }
       if(!found){
        br++;
        cout << "There is no \'" << charToGuess << "\' in the word" << endl;
       }
       for(size_t i = 0; i < wordOutput.size();i++ )
       {
        cout << wordOutput[i];
       }
       cout << "\n";
    }
}

int main(){
    string word;
    cout << R"(
            _    _                                             
            | |  | |                                            
            | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __      
            |  __  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \     
            | |  | | (_| | | | | (_| | | | | | | (_| | | | |    
            |_|  |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|    
                                __/ |                         
                                |___/                          

                        +----+
                        |    |
                        O    |
                        /|\   |
                        / \   |
                                |
                        =========

            Menu:
            1: Add New Word
            2: Play Game
            0: Quit

            You pick: )";

    int option;
    while(true){
    cin >> option;
    switch (option) {
        case 1:wordInput(word);break;
        
        case 2:playGame(word);break;
        
        case 0: return 0;
        
        default: cout << "Invalid option";
            
    }
    cout << R"(Menu:
            1: Add New Word
            2: Play Game
            0: Quit

            You pick: )";
}

}