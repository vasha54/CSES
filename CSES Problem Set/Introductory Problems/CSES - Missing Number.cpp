/**
 * CSES - Missing Number
 * Temática: Aritemetica - Algebra
 *
 * Idea: Dado un N y N-1 numeros decir el numero de [1-N] que falta. Si conocemos
 * N aplicamos sumatoria Gauss para N luego le vamos restando a dicho valor los valores
 * leido y el valor final será el que el falte
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
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
	PRESICION(0)

	LL N,sum,x;
	cin>>N;
	sum=N*(N+1)/2;
	for(LL i=1;i<N;i++){
		cin>>x;
		sum-=x;
	}
	cout<<sum<<ENDL;
	return 0;
}

