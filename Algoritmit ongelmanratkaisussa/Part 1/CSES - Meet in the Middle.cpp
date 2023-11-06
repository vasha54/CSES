/**
* CSES - Meet in the Middle
* Tematica : Meet in the Middle
* Idea: Dado una coleccion de valores contar la cantidad de formas que puedo
* agruparlos tal que las sumas de las agrupaciones sumen un valor x. Aplicar la
* Meet in the Middle de dividir el conjunto incial en dos subcojuntos calular
* todos los posibles valores de sumas de esos subconjuntos y luego combinar los
* subcojuntos cuales sus suman dan x
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define MAX_N 25
#define EPS 1e-9
#define INF 1000000000
#define MOD 1000000007
#define READ_FILE freopen("Input.txt","r",stdin);
#define int long long
#define uint unsigned int

using namespace std ;

int n,x,extra,sa,sb,answer;
vector<int> A,Sa,B,Sb;
pair<vector<int>::iterator, vector<int>::iterator> result;


signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE

    cin>>n>>x;
    extra = 0;
    A.resize(n/2);
    B.resize(n/2);
    for(int i=0;i<n/2;i++){
        cin>>A[i]>>B[i];
    }

    if(n & 1) cin>>extra;

    int mask = 1<<(n/2);

    for(int i=0;i<mask;i++){
        sa =sb =0;
        for(int j=0;j<(n/2);j++){
            if( i & (1<<j)){
                sa+=A[j];
                sb+=B[j];
            }
        }
        Sb.push_back(sb);
        Sa.push_back(sa);
        if( n & 1) Sa.push_back(sa+extra);
    }

    sort(Sa.begin(),Sa.end());

    answer = 0;

    for(int i=0;i<Sb.size();i++){
        sa = x - Sb[i];
        result = equal_range( Sa.begin(), Sa.end(), sa );
        if(binary_search(Sa.begin(), Sa.end(),sa)){
            answer+=(result.second-result.first);
        }
    }

    cout<<answer<<ENDL;

    return 0;
}
