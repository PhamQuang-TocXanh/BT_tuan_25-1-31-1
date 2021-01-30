#include<iostream>
using namespace std;
int main(){
    int n;
    int x=-99;
    do{
        cin>>n;
        if(x!=n){
            cout<<n<<" ";
        }x=n;
    }while(n>=0);
}
