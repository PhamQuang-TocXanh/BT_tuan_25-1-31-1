#include<iostream>
using namespace std;
/*int main(){
    int k;cin>>k;
    for(;k>=3;k/=3);
    cout<<k;
    return 0;
}*/



/*int main(){
    int k;cin>>k;
    while(k>=3) k/=3;
    cout<<k;
    return 0;
}*/




int main(){
    int k;cin>>k;
    if(k>=3)
    do{
        k/=3;
    }while(k>=3);
    cout<<k;
    return 0;
}
