/**
 * CSES - Bit Strings
 * Temática: Algebra : Exponenciación binaria
 *
 * Idea: Dado  un valor n decir cuantas cadenas binarias de n bits se puede formar
 * la solución estan sencilla como 2 elevado a la n lo que sucede que n estan grande
 * que se debe modular solución.
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

LL binpow( LL a, LL n) {
	LL res = 1;
	while (n) {
		if (n & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		n >>= 1;
	}
	return res;
}

int main() {
	OPTIMIZAR_IO
	PRESICION(0)
	LL N;
	cin >> N;
	cout<<binpow(2,N)<<ENDL;
	return 0;
}

