#include<cmath>
#include<iostream>
using namespace std;
int main(){
    double x;
    int y;
    cin>>x>>y;
    double ans=1;
    for(int i=1;i<=y;i++){
        ans*=x;
    }
    cout<<ans<<endl<<pow(x, y);
}
