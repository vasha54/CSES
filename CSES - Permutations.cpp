/**
 * CSES - Permutations
 * Temática: Add - Hoc
 *
 * Idea: Se tiene todos los valores de 1 a N y se quiere conformar con dicho valores
 * una permutación tal que dos valores consecutivos su diferencia no sea 1. De
 * no ser posible imprimir NO SOLUTION. Siempre que N sea mayor que 3 o igual 1 será posible
 * construir dicha permutación. Como te piden imprimir cualquiera una variante
 * es imprimir todos los numeros pares ordenamos primero y luego todos los numeros
 * impares ordenados en ambos casos de forma creciente
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
	int N;
	cin >> N;
	if (1<N && N <= 3) {
		cout << "NO SOLUTION" << ENDL;
	} else {
		for (int i = 2; i <= N; i += 2) {
			cout << i << " ";
		}
		for (int i = 1; i <= N; i += 2) {
			cout << i << " ";
		}
	}
	return 0;
}

