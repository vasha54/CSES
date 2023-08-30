/**
 * CSES - Two Set
 * Temática: Aritmetica - Algebra : Sumatoria Gauss
 *
 * Idea: Dado un N se quiere determinar si se puede crear dos conjuntos con todos
 * los numeros naturales del 1 al N con la condinción que la suma de los valores
 * en cada cojunto sea la misma. Aplicando la sumatoria de Gauss podemos saber la
 * suma de todos los numeros naturales de 1 a N. Algunas sumatoria con determinados
 * valores N el resultado será un número impar esto indicará que para que para esos
 * N no habrá forma de dividir en dos grupos los valores de 1 a N en dos cojuntos
 * tal que la suma de los valores en cada conjunto sea igual. Esto sucede para los
 * N pares y no divisibles por 4 y para los N impares pero que la cantidad de
 * numeros impares de 1 a N sea impar.
 * Los cojuntos si se podran formar cuando N sea divisible por cuatro o  N sea
 * impar pero la cantidad de numeros impares entre 1 y N sea par.
 */
#include <bits/stdc++.h>
#include <math.h>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_INPUT_FILE freopen("Input.txt","r",stdin);
#define MAX_N 85
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;



int main() {
	OPTIMIZAR_IO
	//PRESICION(0)
	//READ_INPUT_FILE
	LL N;
	vector<LL> c1,c2;
	cin>>N;
	if(N%4==0){
        for(int i=1;i<=N;i+=4){
            c1.push_back(i);
            c1.push_back(i+3);
            c2.push_back(i+1);
            c2.push_back(i+2);
        }
    }else if(N%2==1 && ((N-1)/2 +1)%2==0){
        c1.push_back(1);
        c1.push_back(2);
        c2.push_back(3);
        for(int i=4;i<=N;i+=4){
            c1.push_back(i);
            c1.push_back(i+3);
            c2.push_back(i+1);
            c2.push_back(i+2);
        }
    }

    if(c1.empty()==false && c2.empty()==false){
        cout<<"YES"<<ENDL;
        cout<<c1.size()<<ENDL;
        for(int i=0;i<c1.size();i++){
            if(i)cout<<" ";
            cout<<c1[i];
        }
        cout<<ENDL;
        cout<<c2.size()<<ENDL;
        for(int i=0;i<c2.size();i++){
            if(i)cout<<" ";
            cout<<c2[i];
        }
        cout<<ENDL;
    }else{
        cout<<"NO"<<ENDL;
    }
	return 0;
}
