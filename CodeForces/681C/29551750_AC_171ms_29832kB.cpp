#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define pb push_back
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

int main() {
    nGu();
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>>pr;
    vector<string>v;
    while (n--)
    {
        string s, t;
        int x;
        cin >> s;
        if (s == "insert")
        {
            cin >> x;
            t = "insert " + to_string(x);
            v.push_back(t);
            pr.push(x);
        }
        else if (s == "getMin")
        {
            cin >> x;

            while (pr.size() && pr.top() < x)
            {

                v.push_back("removeMin");
                pr.pop();
            }

            if (!sz(pr) || pr.top() > x)
            {
                t = "insert " + to_string(x);
                v.push_back(t);
                pr.push(x);
            }
            t = "getMin " + to_string(x), v.push_back(t);
        }
        else
        {
            if (!sz(pr))
                v.push_back("insert 0");
            else
                pr.pop();
            v.push_back("removeMin");

        }
    }

    cout << sz(v) << endl;
    for (auto it : v)
        cout << it << endl;
}