 /**
 * CSES - Sliding Window Distinc Values 
 * Temática: Slinding Window 
 * 
 * Idea: Una colección de n valores quiero hallar por cada posible
 * subcolección de k valores cuantos son diferentes entre si una 
 * clasica aplicación del sliding window
 */ 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
 
#ifdef LOCAL
    #define READ_FILE freopen("Input.txt","r",stdin);
    #define WRITE_FILE freopen("Output.txt","w",stdout);
#else
    #define READ_FILE 
    #define WRITE_FILE 
#endif
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 100010
#define MOD  1000000007
 
using namespace std;
using namespace __gnu_pbds;

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int n,k,distinc=0;
	map<int,int> frecuencies;
	cin>>n>>k;
	vector<int> values(n+1);
	vector<int> answers;
	for(int i=1;i<=n;i++) cin>>values[i];

	for(int i=1; i<=n;i++){
		if(i-k>=1){
			frecuencies[values[i-k]]--;
			if(frecuencies[values[i-k]]==0)
				distinc--;
		}
		if(frecuencies[values[i]]==0)
			distinc++;
		frecuencies[values[i]]++;
		if(i>=k)answers.push_back(distinc);	
	}
	for(auto x : answers){
		cout<<x<<" ";
	}

    return 0;
}

