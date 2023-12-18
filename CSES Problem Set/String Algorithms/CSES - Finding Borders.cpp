/**
* CSES - Finding Borders
* Temática: Z-Algorithm
* Idea: Dada una cadena encontrar todas las longitudes de los bordes de
* cadena. Un borde es una secuencia de la palabra que aparece como prefijo
* y como sufijo en la misma cadena. Aplicando el Z-Algorithm una vez solo
* basta con recorrer el arreglo z i ver si se cumple que i+z[i] == x donde
* x es la longitud de la cadena inicial para cada z[i] que cumpla eso existe
* en la cadena un borde cuya longitud es z[i]. Almacenamos esas longitudes
* la ordenamos e imprimimos
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 200010
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define K 25
using namespace std;

vector<int> z_function(string s) {
   int n = s.size();
   vector<int> z(n);
   int l = 0, r = 0;
   for(int i = 1; i < n; i++) {
      if(i < r) {
         z[i] = min(r - i, z[i - l]);
      }
      while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
         z[i]++;
      }
      if(i + z[i] > r) {
         l = i;
         r = i + z[i];
      }
   }
   return z;
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    string text;
    vector<int> lborders;
    int ntext;
    cin>>text;
    ntext = text.size();
    vector<int> z = z_function(text);
    for(int i=ntext-1;i>=0;i--){
       if(z[i]>0 && z[i]+i==ntext)lborders.push_back(z[i]);
    }
    //sort(lborders.begin(),lborders.end());
    for(int i =0;i<lborders.size();i++){
        if(i)cout<<" ";
        cout<<lborders[i];
    }
    cout<<ENDL;

    return 0;
}
