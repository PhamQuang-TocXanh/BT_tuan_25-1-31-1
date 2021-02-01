#include<cmath>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
/*int generateRandomNumber();//NGUOI DOAN SO MAY NGHI RA
void printAnswer(int guess,int secretNumber);
int getPlayerGuess();
char playAgain();

int main(int agrc, char *argv[]){
    srand(time(0));
    int guess,count_guess=0,point=10000;
    int secretNumber = generateRandomNumber();
    char ans='Y';
    do {
        guess = getPlayerGuess();
        printAnswer(guess, secretNumber);
        count_guess++;
        if(guess==secretNumber){
            for(int i=1;i<count_guess;i++){
                point-=2*(100-i+1);
            }
            cout << "You get " << point <<" point!" << endl;
            ans = playAgain();
            count_guess=0; cout << "\n\n\n\n\n";
            secretNumber = generateRandomNumber(); point=10000;
        }
    }while (guess != secretNumber && ( ans=='Y' || ans=='y' ));
    return 0;
}

char playAgain(){
    string s;
    cout << "Do you want to play again?(Yes/No): ";
    cin >> s;
    return s[0];
}
int generateRandomNumber(){
    return rand()%100+1;
}
void printAnswer(int guess,int secretNumber){
    if(guess>secretNumber){
        cout << "Too big!\n";
    }else if(guess<secretNumber){
        cout << "Too small\n";
    }else cout << "Congratuation!!! You won\n";
}
int getPlayerGuess(){
    int guess;
    cout << "Enter your guess(from 1 to 100): ";
    cin >> guess;
    return guess;
}*/


int selectNumber(int low, int high);//MAY DOAN SO NGUOI NGHI RA
char getHostAnswer(int X);
char playAgain();

int main(int agrc, char *argv[]){
    srand(time(0));
    int X, low = 1, high = 100;
    char answer, play = 'Y';
    do {
        X = selectNumber(low, high);
        answer = getHostAnswer(X);
        if (answer == '>')  high = X-1; // X lớn hơn nên giảm high
        if (answer == '<') low  = X+1; // X nhỏ hơn nên tăng low
        if (answer == '='){
            play = playAgain();
            answer = '.'; cout << "\n\n\n\n";
            low = 1, high = 100;
        }
    } while (answer != '=' && ( play == 'Y' || play == 'y' ));

}

char playAgain(){
    string ans;
    cout << "Do you want to play again?(Yes/No): ";
    cin >> ans;
    return ans[0];
}
int selectNumber(int low, int high)
{
    return rand() % (high-low+1) + low;
}
char getHostAnswer(int X)
{
    char answer;
    cout << "Is " << X
         << " your number? " <<endl;
    cout << "Your number is "; cin >> answer; cout << " my number." << endl;
    return answer;
}
