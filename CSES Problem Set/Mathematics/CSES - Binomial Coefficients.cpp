/**
* CSES - Binomial Coefficients
* Tematica : Combinatoria: Coeficientes Binomiales
* Idea: Clasica idea de calcular el coeficiente de K en N modulado 10^9+7.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define MAX_N 1000010
#define EPS 1e-9
#define INF 1LL<<60
#define MOD 1000000007
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define int long long
#define uint unsigned int

using namespace std ;


vector<int> factorial, inverse_factorial;


int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

vector<int> invs(const std::vector<int> &a, int m) {
    int n = a.size();
    if (n == 0) return {};
    vector<int> b(n);
    int v = 1;
    for (int i = 0; i != n; ++i) {
        b[i] = v;
        v = (v) * a[i] % m;
    }
    int x, y;
    gcd(v, m, x, y);
    x = (x % m + m) % m;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = (x) * b[i] % m;
        x = (x) * a[i] % m;
    }
    return b;
}

void calculateFactorial(){
   factorial.resize(MAX_N);
   factorial[0] = 1;
   for (int i = 1; i < MAX_N; i++) {
      factorial[i] = factorial[i - 1] * i % MOD;
   }
   inverse_factorial = invs(factorial,MOD);
}

int binomial_coefficient(int n, int k) {
    return factorial[n] * inverse_factorial[k] % MOD* inverse_factorial[n - k] % MOD;
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int n,k,cases;
    calculateFactorial();

    cin>>cases;
    while(cases--){
        cin>>n>>k;
        cout<<binomial_coefficient(n,k)<<ENDL;
    }

    return 0;
}
