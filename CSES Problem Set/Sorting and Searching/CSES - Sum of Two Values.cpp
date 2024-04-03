/**
* CSES - Sum of Two Values
* Temática: Busqueda Binaria
* Idea: Dada una colección de valores determinar si existe dos valores que sumados
* dan un valor X. Si es asi dar las posiciones de estos en el arreglo con indexacion
* 1. Tener en cuenta que si X = a + b y b es igual a buscar en rangos que no incluya
* la posición de a.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 1010
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define K 25
using namespace std;

int  x,n,a,b,pa,pb;
vector<pair<int,int> > values;

int searchBinary(int b, int e, int y){
    int pivot;
    while(b<=e){
        pivot = (b+e)/2;
        if(values[pivot].first==y) return values[pivot].second;
        else if(values[pivot].first > y) e=pivot-1;
        else b=pivot+1;
    }
    return -1;
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE

    cin>>n>>x;
    values.resize(n+1);
    for(int i=1;i<=n;i++){
     cin>>a;
     values[i]=make_pair(a,i);
    }
    sort(values.begin()+1,values.end());
    pa=pb=-1;

    for(int i=1;i<=n && pb==-1;i++){
        a = values[i].first;
        pa = values[i].second;
        b = x - a;
        pb = searchBinary(i+1,n,b);
    }

    ((pb!=-1) ? cout<<min(pa,pb)<<" "<<max(pa,pb)<<ENDL : cout<<"IMPOSSIBLE"<<ENDL);
    return 0;
}
