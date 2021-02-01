#include<iostream>
#include<cmath>
using namespace std;
bool so_nt(int n);
bool so_hoan_hao(int n);
bool so_chinh_phuong(int n);


int main(){
    int n; cin >> n;
    for (int i=2 ; i<=n ; i++){
        if(so_nt(i)) cout << "So nguyen to : " << i << endl;
        if(so_hoan_hao(i)) cout << "So hoan hao : " << i << endl;
        if(so_chinh_phuong(i)) cout << "So chinh phuong : " << i << endl;
    }
}


bool so_nt(int n){
    if( n<2 ) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
bool so_hoan_hao(int n){
    int sum=0;
    for(int i=1;i<n;i++){
        if(n%i==0) sum+=i;
    }
    if(sum==n) return true;
    return false;
}
bool so_chinh_phuong(int n){
    int nn=sqrt(n);
    if(nn*nn==n) return true;
    return false;
}
