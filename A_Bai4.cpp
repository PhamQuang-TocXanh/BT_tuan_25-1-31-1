
#include<iostream>
using namespace std;
bool check_date(int day, int month, int year);
void congngay(int day, int month, int year, int k);

int main(){
    int d,m,y;char c;
    cout<<"Enter a date: ";
    cin>>d>>c>>m>>c>>y;
    while(check_date(d,m,y)==false){
        cout<<"Wrong date! Enter again: ";
        cin>>d>>c>>m>>c>>y;
    }
    int k;
    if(check_date(d,m,y)){
        do{
            cin>>k;
            congngay(d, m, y, k);
        }while(k!=0);
    }
    return 0;
}

bool check_date(int day, int month, int year){
    if(month>=13||month<1) return false;
    if(day<1) return false;
    switch(month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(day>31) return false;break;
        case 4: case 6: case 9: case 11:
            if(day>30) return false;break;
        case 2:
            if( ( year%4==0&&year%100!=0 )||year%400==0 ){
                if(day>29) return false;
            }else{
                if(day>28) return false;
            }break;
    }
    return true;
}
void congngay(int day, int month, int year, int k){
    int ngayn=(year-1)*365+year/4;
    int thang[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ngayt=0;
    for(int i=0;i<month-1;i++){
        ngayt+=thang[i];
    }
    int ngay=ngayn+ngayt+day+k;
    int nam=0,ngay_cua_nam=0;
    while(ngay_cua_nam<ngay){
        ngay_cua_nam+=365;nam++;
        if(nam%4==0) ngay_cua_nam++;
    }
    if(nam%4==0) ngay_cua_nam-=366;
    else ngay_cua_nam-=365;
    int thangg=0,ngay_cua_thang=0,songay_conlai=ngay-ngay_cua_nam;
    for(int i=0;ngay_cua_thang<songay_conlai;i++){
        ngay_cua_thang+=thang[i];
        thangg++;
    }
    ngay_cua_thang=ngay_cua_thang-thang[thangg-1];
    int ngayy=ngay-ngay_cua_nam-ngay_cua_thang;
    cout<<ngayy<<"-"<<thangg<<"-"<<nam<<endl;
}
