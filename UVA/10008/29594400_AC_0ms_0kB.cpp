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

int main()
{
    nGu();
    int n;
    cin >> n;
    map<char, int>mp;
    cin.ignore();
    while (n--)
    {
        string s;
        getline(cin ,s);
        for (auto &it : s)
        {
            if (isalpha(it))
            {
                if (islower(it))
                    it = toupper(it);
                mp[it]++;
            }

        }
       // cout << s << endl;

    }
    vector<pair<char, int >> v;
    for (auto it : mp)
        v.push_back(it);
    sort(all(v), [&](pair<char, int >a, pair<char, int >b) {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
        });
    for (auto it : v)
        cout << it.first << " " << it.second << endl;
  

}