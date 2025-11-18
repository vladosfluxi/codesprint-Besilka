// #include <algorithm>
#include <cstdio>
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

string bannedSymbols = "123456789-=+_(*&^%$#@!)/?.>,<\'\";:[]{}~ "; //List of banned symbols



void wordInput(string& word){
    cout << "The word must no contain numeric characters, symbols or spaces\n";
    while(true){
    try{
        cout << ">";
        getline(cin,word);

        for(size_t i = 0; i < word.size()-1;i++){
            if(bannedSymbols.find(word[i])){
                throw runtime_error("The word must not contain numeric characters, symbols or spaces");
                break;
            }
        }
        break;        
    }catch( const exception& e){
        cout << e.what() << "\n";
    }
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
            1: Play Game
            2 Add New Word
            0: Quit

            You pick: )";

    int option;
    cin >> option;
    switch (option) {
        case 1:
        case 2:
        case 0: return 0;
        default: cout << "Invalid option";
            
    }

}