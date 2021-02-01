#include<cmath>
#include<iostream>
using namespace std;
int main(){
    double a,b,c;
    do{
        cout << "Nhap he so cua p/trinh bac 2: ";
        cin>>a>>b>>c;
    }while(a==0);
    double delta=b*b-4*a*c;
    if(delta==0){
        cout << "Phuong trinh co 1 nghiem: " << -b/(2*a);
    }else if(delta>0){
        cout << "Phuong trinh co 2 no: \n  x1= " << (-b+sqrt(delta))/(2*a)
            << " va x2= " << (-b-sqrt(delta))/(2*a) << endl;
    }else{
        cout << "Phuong trinh co 2 no phuc: \n  x1= " << -b/(2*a) << "+" << sqrt(-delta)/(2*a) << "i "
            << " va x2= " << -b/(2*a) << "-" << sqrt(-delta)/(2*a) << "i " << endl;
    }
}
