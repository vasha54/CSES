/**
 * CSES - Weird Algorithm
 * Temáticas: Add -Hoc
 *
 * Idea:
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 1005
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
	//PRESICION(20)
	long n;
	bool fPrint = true;

	cin >> n;
	while (n != 1) {
		if (!fPrint)
			cout << " ";
		cout << n;
		if (n % 2 == 0)
			n /= 2;
		else if (n % 2 == 1 && n > 1)
			n = n * 3 + 1;
		fPrint = false;
	}

	if (!fPrint)
		cout << " ";
	cout << n;

	return 0;
}

