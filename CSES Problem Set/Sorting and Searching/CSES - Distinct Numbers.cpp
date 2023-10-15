/**
* CSES - Distinct Numbers
* Tematica : Ordenamiento
* Idea: Dada una lista de numeros determinar cuantos números diferentes existen
* entre ellos. Se ordena los numeros y se cuenta cuantas pares de la forma
* [i-1],[i] son diferentes y el conteo debe empezar a partir de 1 y no en 0 como
* es costumbre
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 200010
#define EPS 1e-9
#define INF 1000000000
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define int long long

using namespace std;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int n,c=1;
    cin>>n;
    vector<int> numbers(n);

    for(int i=0;i<n;i++) cin>>numbers[i];
    sort(numbers.begin(),numbers.end());

    for(int i=1;i<n;i++) if(numbers[i]!=numbers[i-1]) c++;

    cout<<c<<ENDL;

    return 0;
}
