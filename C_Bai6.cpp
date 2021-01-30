#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=j+1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        int num=a[i][0];
        for(int j=0;j<n-1;j++){
            a[i+1][j]=a[i][j+1];
        }
        a[i+1][n-1]=num;
        cout<<endl;
    }
    return 0;
}

