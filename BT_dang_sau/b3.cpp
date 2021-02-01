#include<cmath>
#include<iostream>
using namespace std;
string ktr_tamgiac(double a, double b, double c){
    if((a+b<=c)||(a+c<=b)||(c+b<=a)) return "Khong phai tam giac";
    if(a==b&&a==c) return "Tam giac deu";
    if(a==b){
        if(a*a+b*b==c*c) return "Tam giac vuong can";
        else return "Tam giac can";
    }
    if(c==b){
        if(a*a==b*b+c*c) return "Tam giac vuong can";
        else return "Tam giac can";
    }
    if(a==c){
        if(a*a+c*c==b*b) return "Tam giac vuong can";
        else return "Tam giac can";
    }
    if(a*a+c*c==b*b||a*a==b*b+c*c||a*a+b*b==c*c) return "Tam giac vuong";
    return "Tam giac thuong";
}
int main(){
    double a,b,c;
    cin>>a>>b>>c;
    cout<<ktr_tamgiac(a, b, c);
}
