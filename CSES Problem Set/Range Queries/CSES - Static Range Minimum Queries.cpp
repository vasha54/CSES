/**
* CSES - Static Range Minimum Queries
* Temática: Estructura de Datos + Sparse Table
* Idea: Clasico problema de encontrar el minimo en un  rango del arreglo que no se
* se actualiza entre consultas
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

int st[K + 1][MAX_N],arrays [MAX_N],N,Q;

int  f(int a, int b){
    //return a+b;
    return min(a,b);
}

void init(){
    copy(arrays, arrays+MAX_N, st[0]);
    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= N; j++)
            st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

int querySum(int L,int R){
    int sum = 0;
    for (int i = K; i >= 0; i--) {
        if ((1 << i) <= R - L + 1) {
            sum += st[i][L];
            L += 1 << i;
        }
    }
    return sum;
}

int log2_floor(int i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int queryMin(int L,int R){
    int i = log2_floor(R - L + 1);
    int minimum = min(st[i][L], st[i][R - (1 << i) + 1]);
    return minimum;
}




signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    int l,r;
    cin>>N>>Q;
    for(int i=0;i<N;i++) cin>>arrays[i];
    init();
    for(int i=0;i<Q;i++){
        cin>>l>>r;
        l--;r--;
        cout<<queryMin(l,r)<<ENDL;
    }


    return 0;
}
