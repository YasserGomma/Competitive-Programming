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
    int n, q;
    cin >> n >> q;
    map<string, string>mp;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        mp[a] = b;
    }
    while (q--)
    {
        string s;
        cin >> s;
        bool ok = 0;
        for (auto it : mp)
        {
            if (it.first == s)
            {
                ok = 1;
                cout << it.second << endl;
                break;
            }
        }
        if (ok)continue;
        if (s.back() == 'y')
        {
            string vowel = "aeiouy";
            if (vowel.find(s[sz(s) - 2]) == string::npos)
                s.pop_back(), s += "ies";
            else
                s += 's';
        }
        else if (s.back() == 'o' || s.back() == 's' || s.back() == 'x')
            s += "es";
        else if (s.back() == 'h' && (s[sz(s) - 2] == 'c' || s[sz(s) - 2] == 's'))
            s += "es";
        else
            s += 's';
        cout << s << endl;
    }
}