#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define deb(x)   cout << "[" <<#x << "=" << x << "]" << endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int mod = (int)1e9 + 7;
#define clr(v, d)		memset(v, d, sizeof(v))
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
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
double x, y;
double f(double h) {
    double a, b;
    a = x - 2.0 * h;
    b = y - 2.0 * h;
    if (a < 0 || b < 0)
        return 0;
    return h * a * b;

}

double ts() {
    double lo = 0, sz = min(x,y);
    for (; sz > 1e-20; sz *= 2.0 / 3) {
        double a = lo + sz / 3, b = a + sz / 3;
        if (f(a) < f(b)) lo = a;
    }
    return f(lo);
}

int main()
{
	
    int t;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        cout << fixed << setprecision(7) << ts() << endl;
    }


}