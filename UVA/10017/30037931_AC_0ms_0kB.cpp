#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define mm(v) memset(v, 0, sizeof(v))
#define deb(x)   cout << "[" <<#x << "=" << x << "]" << endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int mod = (int)1e9 + 7;
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void nGu()
{
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int m,N,cnt=0;
map<char, set<int>>mp;
void   show_towers()
{
    cout << endl;
    for (auto it : mp)
    {
        cout << it.first << "=>";
        if (sz(it.second)) {
            cout << "  ";
            for (auto x = it.second.begin(); x != it.second.end(); ++x)
                cout << ' ' << -*x;
        }
        cout << endl;

    }
}
void towerOfHanoi(int n, char from_rod, char aux_rod, char to_rod)
{

    if (cnt == m)return;
    if (n > 1)
    {
        towerOfHanoi(n - 1, from_rod, to_rod, aux_rod);
        if (cnt == m)return;
        cnt++;
        mp[from_rod].erase(-n);
        mp[to_rod].insert(-n);
        show_towers();
        towerOfHanoi(n - 1, aux_rod, from_rod, to_rod);

    }
    else
    {
        mp[from_rod].erase(-n);
        mp[to_rod].insert(-n);
        cnt++;
        show_towers();
    }
    
}
int main()
{

    nGu();
    int t = 1;
    while (cin >> N >> m&&N) {
        mp.clear();
        cout << "Problem #" << t++ << endl ;
        for (int i = 1; i <= N; i++)
            mp['A'].insert(-i);
        mp['B'] = {};
        mp['C'] = {};
        show_towers();
        cnt = 0;
        towerOfHanoi(N, 'A', 'B', 'C');
        cout << endl;
    }
}