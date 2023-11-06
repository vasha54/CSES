/**
* CSES - Longest Palindrome
* Tematica : String  : Manacher
* Idea: Clasico ejercicio de dado un string encontrar el subpalindrome mayor en la
* cadena.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 200020
#define EPS 1e-9
#define INF 1000000000
#define MOD 1000000007
#define READ_FILE freopen("Input.txt","r",stdin);
#define int long long
#define uint unsigned int

using namespace std ;

string manacher(string _text){
   int n=_text.size();
   int rad[2*n];
   int i,j,k;
   for(i=0,j=0;i<2*n;i+=k, j=max(j-k,0LL)){
      while(i-j>=0 && i+j+1<2*n && _text[(i-j)/2]==_text[(i+j+1)/2])
        ++j;
      rad[i]=j;
      for(k=1; i-k>=0 && rad[i]-k>=0 && rad[i-k]!=rad[i]-k ;++k)
         rad[i+k]=min(rad[i-k],rad[i]-k);
    }
    int posRad=-1;
    int bestRad=LONG_MIN;

    for(int i=0;i<2*n;i++){
        if(rad[i]>bestRad){
            bestRad=rad[i];
            posRad=i;
        }
    }

    int b,length,e;
    b = ( posRad % 2==0 ? posRad/2 - rad[posRad]/2 : posRad/2 - rad[posRad]/2+1);
    e=posRad/2 + rad[posRad]/2;
    length = e-b+1;
    return _text.substr(b,length);
}


signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    string word;
    cin>>word;
    cout<<manacher(word);
    return 0;
}
