/**
 * CSES - Palindrome Reorder
 * Temática: String + Add - Hoc + Greedy
 *
 * Idea: Dada una cadena se quiere reordenar tal que forme un palindrome. Para lo
 * grar lo anterior se requiere que la cantidad de letras de cada tipo sea par
 * y que una sola letra su cantidad sea impar.
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

string word, palindrome, A, B, C;
int counting[ALPHABET_SIZE];

int main() {
	OPTIMIZAR_IO
	PRESICION(0)

	cin >> word;
	palindrome = A = C = B = "";
	fill(counting, counting + ALPHABET_SIZE, 0);

	int sums = 0;

	for (int i = 0; i < word.size(); i++) {
		counting[word[i] - 'A']++;
	}

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		string t = string(counting[i] / 2, 'A' + i);
		A = A + t;
		B = t + B;
		counting[i] -= (t.size() * 2);
		sums += counting[i];
	}

	if (sums == 1 || sums == 0) {
		for (int i = 0; i < ALPHABET_SIZE; i++) {
			if (counting[i] == 1)
				C = string(1, 'A' + i);
		}
		palindrome = A + C + B;
		cout << palindrome << ENDL;
	} else {
		cout << "NO SOLUTION" << ENDL;
	}

	return 0;
}

