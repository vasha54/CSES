/**
 * CSES - Increasing Subsequence
 * Temática: Programación Dinámica : LIS
 *
 * Idea: Algoritmo clasico para calcular la longitud de la máxima subsecuencias
 * de elementos creciente
 */
#include <bits/stdc++.h>
#include <math.h>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_INPUT_FILE freopen("Input.txt","r",stdin);
#define WRITE_OUTPUT_FILE freopen("Output.txt","w",stdout);
#define MAX_N 50
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;

int lengthOfLIS(vector<LL>& nums){
   int n = nums.size();
   vector<LL> ans;

   ans.push_back(nums[0]);

   for (int i = 1; i < n; i++) {
      if (nums[i] > ans.back()) {
         ans.push_back(nums[i]);
      }
      else {
         int low = lower_bound(ans.begin(), ans.end(),nums[i])-ans.begin();
         ans[low] = nums[i];
      }
   }
   return ans.size();
}

int main() {
	OPTIMIZAR_IO
	//PRESICION(0)
	//READ_INPUT_FILE
	//WRITE_OUTPUT_FILE
	int n;
	cin>>n;
	vector<LL> values(n);
	for(int i=0;i<n;i++) cin>>values[i];
	cout<<lengthOfLIS(values)<<ENDL;
    return 0;
}
