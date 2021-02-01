#include<cmath>
#include<iomanip>
#include<iostream>
using namespace std;
int Salary(int hour);
int thue(int salary);
double TN_sau_thue(int salary);
double tong_du_no_1_nam(int money);



int main(){
    cout<<fixed<<setprecision(0)<<"So tien no sau 1 nam: "<<tong_du_no_1_nam(10000000)<<endl;//10.000.000 tien mua may tinh
    int sotienno=tong_du_no_1_nam(10000000), so_tien_vay=10000000;
    int dem_thang=0,month=9,year=2016; double khoan_thanh_toan;
    do{
        cout << "--Nhap so gio lam viec cua thang "<< month << "/" << year <<": ";
        int hour;cin>>hour;
        cout << "So tien ngan hang tinh lai vao cuoi thang " << month << "/" << year << ": " << so_tien_vay*0.02 << endl;
        so_tien_vay=so_tien_vay*1.02;
        int tong_TN_1_thang=1500000-2000000+TN_sau_thue(Salary(hour));
        so_tien_vay-=tong_TN_1_thang;
        cout << "Thu nhap cua thang " << month << "/" << year << ": " << tong_TN_1_thang << endl;
        if (month+1==13){
            month=0; year++;
        }
        cout << "So tien du no cua sinh vien vao dau thang " << month+1 << "/" << year << ": " << so_tien_vay <<endl;
        dem_thang++; month++;
        khoan_thanh_toan = so_tien_vay + tong_TN_1_thang;
    }while(so_tien_vay>0);
    cout << "Sau " << dem_thang << " thang thi tra het no \n"
         << "Khoan thanh toan cuoi cung voi ngan hang: " << khoan_thanh_toan << endl;
    return 0;
}



int Salary(int hour){
    int salary=100*12000;
    if(hour==100) return salary;
    int extra_hour=hour-100;
    if(extra_hour>=1&&extra_hour<=50){
        salary=salary+extra_hour*16000;
    }else if(extra_hour<=100){
        salary=salary+50*16000+(extra_hour-50)*20000;
    }else if(extra_hour>100){
        salary=salary+50*16000+50*20000+(extra_hour-100)*25000;
    }
    return salary;
}
int thue(int salary){
    int bao_hiem=salary*9/100;
    salary=salary-bao_hiem;
    if(salary<=1000000) return 0;
    else if(salary<=1500000) return (salary-1000000)*10/100;
    else if(salary<=2000000) return (salary-1500000)*15/100+50000;
    else return 50000+75000+(salary-2000000)*20/100;
}
double TN_sau_thue(int salary){
    return double(salary*91/100-thue(salary));
}
double tong_du_no_1_nam(int money){
    //double lai_suat=1;
    for(int i=1;i<=12;i++){
        //lai_suat*=1.02;
        money=round(money*1.02);
    }
    return money;
}
