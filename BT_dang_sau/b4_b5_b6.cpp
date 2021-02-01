#include<cmath>
#include<iostream>
using namespace std;
int ucln(int a, int b){
    while(a*b!=0){
        if(a>b) a=a%b;
        else b=b%a;
    }
    return a+b;
}
int bcnn(int a, int b){
    if(b>a){
        int c=a;a=b;b=c;
    }int bc;
    for(bc=a;;bc++){
        if(bc%a==0&&bc%b==0) break;
    }
    return bc;
}
void phanso(int a, int b){
    int u=ucln(a, b);
    a=a/u; b=b/u;
    cout<<a<<"/"<<b;
}
int main(){
    int a,b;cin>>a>>b;
    cout<<bcnn(a,b)<<endl<<ucln(a,b)<<endl;
    phanso(a,b);
}
