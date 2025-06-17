/**
* CSES - Word Combinations
* Temática : String-> Trie + Programación Dinámica
*    
* Idea: Dada una sequencia de caracteres y un listado de palabras se quiere
* calcular la forma en que se puede concatenar el listado de palabras tal que 
* se obtenga la sequencia de caracteres original.
*/
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define REP_INDEX_1(x) for(int i=1;i<=x;i++)
#define REP_INDEX_0(x) for(int i=0;i<x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 1000010
#define MAX_TREE (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y) 
#define mid (l+r)/2
 
const int ROW_SPARSE_TABLE = floor(log2(MAX_N) +1 );
 
using namespace std;
using namespace __gnu_pbds;

vector<int> dp(5005);
vector<vector<int> > tries(1e6 + 5, vector<int>(26));
vector<bool> is_leaf(1e6 + 5);
int trieNodeCount = 0;

void insertWordInTrie(string& word){
    int currentNode = 0;
    for (char& ch : word) {
        if (!tries[currentNode][ch - 'a'])
            tries[currentNode][ch - 'a'] = ++trieNodeCount;
        currentNode = tries[currentNode][ch - 'a'];
    }
    is_leaf[currentNode] = true;
}

int countWays(int start, string S){
    int currentNode = 0, ways = 0;
    for (int i = start; i < S.size(); i++) {
        if (!tries[currentNode][S[i] - 'a'])
            return ways;
        currentNode = tries[currentNode][S[i] - 'a'];
        if (is_leaf[currentNode])
            ways = (ways + dp[i + 1]) % MOD; 
    }
    return ways;
}

signed main()
{
	
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
	string sequence,word;
	int K;
	cin>>sequence;
	cin>>K;
	for (int i = 0; i < K; i++) {
        cin>>word;
		insertWordInTrie(word); 
    }
    dp[sequence.size()] = 1; 
    for (int i = sequence.size() - 1; i >= 0; i--) {
        dp[i] = countWays(i, sequence);
    }
    cout << dp[0]<<ENDL; 
    return 0;
}