/**
* CSES - String Matching
* Temática: Z-Algorithm
* Idea: Clasico problema de la cantidad de ocurrencia de una cadena dentro de otra como
* subcadena. Utilizar la idea del Z-Algorithm para determinar esto
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
    string text, pattern, s;
    int ntext, npattern, occurrences = 0;
    cin>>text;
    cin>>pattern;
    s=pattern+"#"+text;

    vector<int> z = z_function(s);
    ntext = text.size();
    npattern = pattern.size();

    for(int i=0;i<ntext;i++){
        if(z[i + npattern + 1] == npattern) occurrences++;
    }
    cout<<occurrences<<ENDL;
    return 0;
}
