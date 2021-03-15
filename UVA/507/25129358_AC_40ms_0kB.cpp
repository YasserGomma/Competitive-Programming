
// Problem : B. Creating the Contest
// Contest : Codeforces Round #506 (Div. 3)
// URL : https://codeforces.com/contest/1029/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
typedef long long ll;
#define bay_bay return 0;
#define fori(n) for(int i=0;i<n;++i)
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
constexpr auto EPS = 1e-9;
#define ff fflush(stdout);
const ll Mod = 1e9 + 7;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
void GOAT()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);

}

int main()
{
	GOAT();
	int t,n,x;
	cin>>t;
	for(int ts=1;ts<=t;ts++){
		cin>>n;
		  int tmp = 1, st = INT_MAX, ed, sum = 0, ans = 0;
        for (int i = 2; i <= n; i++) {
            cin>>x;
            sum += x;
            if (sum < 0) sum = 0, tmp = i;
            if (sum >= ans) {
            	
                if (sum > ans || (sum == ans && (i - tmp > ed - st))) {
                    st = tmp;
                    ed = i;
                }
                ans = sum;
            }
        }
        if (ans > 0)
            cout<<"The nicest part of route "<<ts<<" is between stops "<<st<<" and "<<ed<<endl;
        else
           cout<<"Route "<<ts<<" has no nice parts"<<endl;
            }
}

