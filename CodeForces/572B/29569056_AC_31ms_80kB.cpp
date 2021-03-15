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
    // freopen("out.txt", "w", stdout);
#endif
}
bool l(pair< pair<char, int>, int>& a, pair< pair<char, int>, int>& b)
{
    return a.first.second < b.first.second;

}
bool g(pair< pair<char, int>, int>& a, pair< pair<char, int>, int>& b)
{
    return a.first.second > b.first.second;
}
int main()
{
    nGu();
    int n, s;
    cin >> n >> s;
    map<pair<char, int>, int>mp;
    for (int i = 0; i < n; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        mp[{c, a}] += b;
    }
    vector<pair< pair<char, int>, int>>S, B;
    for (auto it : mp)
    {
        if (it.first.first == 'B')
            B.push_back(it);
        else
            S.push_back(it);
    }
    sort(all(B), g);
    sort(all(S), l);

    for (int i = min((int)sz(S),s)-1; i >=0 ; i--)
        cout << S[i].first.first << " " << S[i].first.second << " " << S[i].second << endl;
    for (int i = 0; i < min((int)sz(B), s); i++)
        cout << B[i].first.first << " " << B[i].first.second << " " << B[i].second << endl;

}
