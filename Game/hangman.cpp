#include<vector>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<cstring>
using namespace std;
const string file = "in.txt\0";
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
string randomWord();
char getPlayerGuess();
string updateWord(string hiden,string word, char c);
void renderGame(string guessedWord, int badGuess);
bool contains(string word, char c);
void diplayResult(bool lost, string word);
void playGame();
string toLowerCase(const string& s);
////

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

////
string randomWord(const string path){
    vector<string> word;
    int count=0;
    ifstream inF(path.c_str());
    if(inF.is_open()){
        while(!inF.eof()){
            string s;
            inF >> s; word.push_back(s); count++;
        }
    }else{
		cout << "Unable to open file!" << endl;
	}
	inF.close();
	if(word.size()<=0){
		cout << "File is empty!" << endl; return "";
	}
    return toLowerCase (word[rand()%count]);
}/////////////////////////////
char getPlayerGuess(){
	cout << "Enter your guess: ";
    char c; cin >> c; 
	c = tolower(c);
	return c;
}/////////////////////////////
string updateWord(string hiden,string word, char c){
    for (int i=0;i<word.size();i++){
        if(word[i]==c){
            hiden[i]=c;
        }
    }
    return hiden;
}/////////////////////////////
void renderGame(string guessedWord, int badGuess){
    cout << figure[badGuess] ;
    cout << "Number of wrong guess: " << badGuess << endl
         << "Hiden word: " << guessedWord << endl;
}/////////////////////////////
bool contains(string word, char c){
	return (word.find_first_of(c) != string::npos);
}/////////////////////////////
void diplayResult(bool lost, string word){
    if(lost){
        cout << figure[7];
        cout << "You lost! "<<endl
             << "The secret word is: " << word <<endl;
    }else{
        cout << "Congratuation!!! You won\n"
             << "The secret word is: " << word <<endl;
    }
}/////////////////////////////
void playGame(){
    string secretWord = randomWord(file);
    string hidenWord = string(secretWord.size(), '-');
    int badCountGuess=0 ;
    do{
        renderGame(hidenWord, badCountGuess);
        char guess = getPlayerGuess();
        if(contains(secretWord, guess)){
            hidenWord = updateWord(hidenWord, secretWord, guess);
        }else badCountGuess++;
    }while(badCountGuess<maxBadGuess&&hidenWord!=secretWord);
    diplayResult(badCountGuess==7 , secretWord);
}/////////////////////////////
string toLowerCase(const string& s){
	string res = s;
	int sz = s.size();
	for(int i=0;i<sz;i++){
		res[i] = tolower(s[i]);
	}
	return res;
}