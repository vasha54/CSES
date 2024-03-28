/*
* CSES - Ferris Wheel
* Idea: Dada una colección  de valores se quiere hallar la mínima cantidad de
* valores que va tener al final la coleccion si se sab que se puede funsionar
* dos valores de la colección original siempre y cuando la suma de ambos valores
* no supera un valor determinado. Para resolver el problema vamos ordenar los
* valores. Luego con dos punteros uno al comienzo y otro al final veremos cuando
* los elementos que apuntan su suma sean menores que el llimite dado en ese caso
* se toman eso dos valores como uno. Si la suma sobrepasa el valor vamos a
* decrementar solo el puntero del final.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 100010
#define MOD 1000000007
#define EPS 1e-4
#define INF 1000000000
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define Point pair<int, int>
#define X first
#define Y second
#define PLUS '+'
#define MINUS '-'
#define SPACE ' '
using namespace std;

int nchilds, ngondolas, child1, child2, maxWeigth, idxChild2, principio, fin, pivot;
vector<int> childs;
vector<bool> selects;

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>nchilds>>maxWeigth;

    childs.resize(nchilds);
    selects.resize(nchilds,false);

    for(int i=0;i<nchilds;i++) cin>>childs[i];

    sort(childs.begin(),childs.end());

    ngondolas = 0;

    principio = 0;
    fin = nchilds -1;

    while(principio < fin){
        if(childs[principio]+childs[fin] > maxWeigth){
            fin--;
        }else{
            ngondolas++;
            selects[principio]=selects[fin]=true;
            principio++;
            fin--;
        }
    }
    for(int i=0;i<nchilds;i++) ngondolas+= (!selects[i]);

    cout<<ngondolas<<ENDL;

    return 0;
}
