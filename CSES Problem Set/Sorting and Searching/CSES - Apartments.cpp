/*
* CSES - Apartments
* Tematica: Busqueda + Ordenamiento
* Idea: Dadas dos colecciones de valores formar la mayor cantidad de pares donde
* cada par se forma tomando un valor de cada coleccion con la condicion que la diferencia
* entre los valores que se tomen no superen un valor dado.
* Vamos a ordenar los valores e ir tomando los valores cuya diferencia no sobrepase
* la el valor descrito
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

int napartaments, napplicants, limit, answerA, answerB;
vector<int> apartaments, applicants;

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>napplicants>>napartaments>>limit;
    apartaments.resize(napartaments);
    applicants.resize(napplicants);
    for(int i=0;i<napplicants;i++) cin>>applicants[i];
    for(int i=0;i<napartaments;i++) cin>>apartaments[i];
    sort(applicants.begin(),applicants.end());
    sort(apartaments.begin(),apartaments.end());
    answerA=answerB=0;
    for(int idxApp=0,idxApa=0; idxApa<napartaments && idxApp < napplicants;){
        if(abs(apartaments[idxApa]-applicants[idxApp])<=limit){
            idxApa++;
            idxApp++;
            answerA++;
        }else if(apartaments[idxApa] > applicants[idxApp]){
            idxApp++;
        }else
            idxApa++;
    }

    for(int idxApp=napplicants-1,idxApa=napartaments-1; idxApa>=0 && idxApp >=0;){
        if(abs(apartaments[idxApa]-applicants[idxApp])<=limit){
            idxApa--;
            idxApp--;
            answerB++;
        }else if(apartaments[idxApa] > applicants[idxApp]){
            idxApa--;
        }else
            idxApp--;
    }

    cout<<max(answerA,answerB)<<ENDL;
    return 0;
}
