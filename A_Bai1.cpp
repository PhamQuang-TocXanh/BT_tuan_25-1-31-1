#include<iostream>
using namespace std;
//3 cach
/*int main(){
    for(int i=0;i<=100;i++){
        if(i%2==0) cout<<i<<" ";
    }
    return 0;
}*/


/*int main(){
    int i=0;
    while(i<=100){
        if(i%2==0) cout<<i<<" ";
        i++;
    }
    return 0;
}*/


int main(){
    int i=-1;
    do{
        i++;
        if(i%2!=0) continue;
        cout<<i<<" ";
    }while(i<=100);
    return 0;
}

//em nghĩ cách c là tốt nhất
