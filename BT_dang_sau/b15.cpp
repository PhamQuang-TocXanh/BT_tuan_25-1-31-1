#include <iostream>
using namespace std;

long long * fibo( )
{
  static long long  r[10000];
  r[0]=0; r[1]=1;
  for (int i = 2; i < 70; ++i)
  {
    r[i] = r[i-1] + r[i-2];
  }
  return r;
}
int main ()
{
   long long *p;
   cout << "Nhap vao so n: ";
   long long n; cin >> n; bool have = true;
   p = fibo();
   for ( int i = 0; i < 70; i++ )
   {
       if(n==*(p+i)){
        cout << "Yes" << endl; have = true;
        break;
       }else{
        have = false ;
       }
   }
   if(have){
    cout << "Cac so thuoc day Fibonacci <= " << n << " la: \n" ;
    for ( int i = 0; *(p+i) <= n; i++ )
        {
            cout << "F[" << i << "]= " << *(p+i) <<endl;
        }
   }else cout << "No" << endl;

   return 0;
}
