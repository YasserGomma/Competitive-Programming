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
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
void GOAT()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
#endif

}
int n, t;
vector<int>v;
int mem[200][200][200];
int to = 0;
int solve(int rem, int f,int t)
{
    if (rem == 0)
        return 0;
    int& ret = mem[rem][f][t];
    if (ret!= 0x3F3F3F3F)
        return ret;
    int o = to - (n - rem) * 8 - f * 5 - t * 10;
    if (o >= 8)
        ret = min(ret, solve(rem - 1, f, t) + 8);
    if(o>=3&&f>=1)
        ret = min(ret, solve(rem - 1, f-1, t) + 4);
    if (o >= 3 && t >= 1)
        ret = min(ret, solve(rem - 1, f+1, t-1) + 4);
    if(f>=2)
        ret = min(ret, solve(rem - 1, f-2, t) + 2);
    if(t>=1)
    ret = min(ret, solve(rem - 1, f , t - 1) + 1);
    return ret;





}
int a[130][130];
int main()
{
	GOAT();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (i)a[i][j] += a[i - 1][j];
            if (j)a[i][j] += a[i][j - 1];
            if (i&&j)a[i][j] -= a[i - 1][j - 1];

        }
    }
    int mx = INT_MIN;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        for (int ei = i; ei < n; ei++)
            for (int ej = j; ej < n; ej++)
        {
            int sub = a[ei][ej];
            if (i)sub -= a[i - 1][ej];
            if (j)sub -= a[ei][j - 1];
            if (i && j)sub += a[i - 1][j - 1];
            mx = max(sub, mx);
        }
    cout << mx << endl;





}