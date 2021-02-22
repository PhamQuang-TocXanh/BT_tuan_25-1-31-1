#include<vector>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
const int maxBadGuess = 7;
const string figure[]={
	"-------------   \n"
	" |              \n"
	" |              \n"
	" |              \n"
	" |              \n"
	" |              \n"
	" |              \n"
	"***             \n",
	"-------------   \n"
	" |        |     \n"
	" |              \n"
	" |              \n"
	" |              \n"
	" |              \n"
	" |              \n"
	"***             \n",
	"-------------   \n"
	" |        |     \n"
	" |        0     \n"
	" |              \n"
	" |              \n"
	" |              \n"
	" |              \n"
	"***             \n",
	"-------------   \n"
	" |        |     \n"
	" |        0     \n"
	" |        |     \n"
	" |              \n"
	" |              \n"
	" |              \n"
	"***             \n",
	"-------------   \n"
	" |        |     \n"
	" |        0     \n"
	" |       /|     \n"
	" |              \n"
	" |              \n"
	" |              \n"
	"***             \n",
	"-------------   \n"
	" |        |     \n"
	" |        0     \n"
	" |       /|\\   \n"
	" |              \n"
	" |              \n"
	" |              \n"
	"***             \n",
	"-------------   \n"
	" |        |     \n"
	" |        0     \n"
	" |       /|\\   \n"
	" |       /      \n"
	" |              \n"
	" |              \n"
	"***             \n",
	"-------------   \n"
	" |        |     \n"
	" |        0     \n"
	" |       /|\\   \n"
	" |       / \\   \n"
	" |              \n"
	" |              \n"
	"***             \n"
};
const char file[]="in.txt";
string randomWord();
char getPlayerGuess();
string updateWord(string hiden,string word, char c);
void renderGame(string guessedWord, int badGuess);
bool contains(string word, char c);
void diplayResult(bool lost, string word);
void playGame();


int main(int agrc, char *argv[]){
    srand(time(0));
    char play='Y';
    do{
        playGame();
        cout << "Do you want to play again?(Yes/No): ";
        string ans; cin >> ans; play=ans[0];
    }while(play == 'Y' || play == 'y');
    return 0;
}


string randomWord(){
    vector<string> word;
    int count=0;
    ifstream inF(file);
    if(inF.is_open()){
        while(!inF.eof()){
            string s;
            inF >> s; word.push_back(s); count++;
        }
    }
    return word[rand()%count];
}
char getPlayerGuess(){
    char c; cin >> c;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    return c;
}
string updateWord(string hiden,string word, char c){
    for (int i=0;i<word.size();i++){
        if(word[i]==c){
            hiden[i]=c;
        }
    }
    return hiden;
}
void renderGame(string guessedWord, int badGuess){
    cout << figure[badGuess] ;
    cout << "Number of wrong guess: " << badGuess << endl
         << "Hiden word: " << guessedWord << endl;
}
bool contains(string word, char c)
{
	return (word.find_first_of(c) != string::npos);
}
void diplayResult(bool lost, string word){
    if(lost){
        cout << figure[7];
        cout << "You lost! "<<endl
             << "The secret word is: " << word <<endl;
    }else{
        cout << "Congratuation!!! You won\n"
             << "The secret word is: " << word <<endl;
    }
}
void playGame(){
    string secretWord = randomWord();
    string hidenWord = string(secretWord.size(), '-');
    int badCountGuess=0 ;cout<<secretWord;
    do{
        renderGame(hidenWord, badCountGuess);
        char guess = getPlayerGuess();
        if(contains(secretWord, guess)){
            hidenWord = updateWord(hidenWord, secretWord, guess);
        }else badCountGuess++;
    }while(badCountGuess<maxBadGuess&&hidenWord!=secretWord);
    diplayResult(badCountGuess==7 , secretWord);
}
