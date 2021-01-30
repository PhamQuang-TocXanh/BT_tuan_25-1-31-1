#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    long a[n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>a[i][j];
        }
    }
    long min1=1000000,min2=1000000;
    for(int i=0;i<n;i++){
        if(a[i][0]<min1) min1=a[i][0];
        if(a[i][1]<min2) min2=a[i][1];
    }
    cout<<min1*min2;
}
