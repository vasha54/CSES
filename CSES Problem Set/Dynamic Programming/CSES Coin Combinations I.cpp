/**
 * CSES Coin Combinations I
 * Temáticas: Programacion Dinamica + Coin Change
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

ULL countWays(vector<int> coins, int x) {
	vector<ULL> counts(x + 10, 0);
	counts[0] = 1L;
	for (int i = 0; i <= x; i++) {
		if (counts[i] == 0L)
			continue;
		for (int c : coins) {
			if (i + c <= x) {
				counts[i + c] += counts[i];
				counts[i + c] %= MOD;
			}
		}
	}
	return counts[x];
}

int main() {
	OPTIMIZAR_IO
	int ncoins, x;
	cin >> ncoins >> x;
	vector<int> coins(ncoins), solutions;
	for (int i = 0; i < ncoins; i++)
		cin >> coins[i];
	cout << countWays(coins, x) << ENDL;
	return 0;
}

