#include<iostream>
using namespace std;
int main(){
    double a1,b1,c1,a2,b2,c2;
    cout<<"He so phuong trinh 1: ";cin>>a1>>b1>>c1;
    cout<<"He so phuong trinh 2: ";cin>>a2>>b2>>c2;
    double D=a1*b2-a2*b1;
    double Dx=c1*b2-b1*c2;
    double Dy=a1*c2-a2*c1;
    if(D!=0){
        cout<<"Phuong trinh co no duy nhat: x="<<Dx/D<<"va y="<<Dy/D;
    }else{
        if(Dx+Dy==0){
            cout<<"He phuong co vo so no ";
        }else{
            cout<<"He phuong trinh vo no ";
        }
    }

    return 0;
}
