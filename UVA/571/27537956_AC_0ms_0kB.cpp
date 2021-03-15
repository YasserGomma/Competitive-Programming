/*(وَمَا تَوْفِيقِي إِلَّا بِاللَّه) */
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())	
#define sz(v) v.size()
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int MOD = (int)1e9 + 7;
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void COME_BACK()
{
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
}
int main()
{
    COME_BACK();
    int a, b, n; 
    while (cin >> a >> b >> n)
    {
        cout << "fill A" << endl;
        int aa = a, bb = 0;
        while (aa != n||b!=n)
        {
            int temp = b - bb;
            temp = min(aa, temp);
            bb += temp;
            aa -= temp;
            cout << "pour A B" << endl;
            if (aa == n || bb == n)break;
            if (!aa) {
                aa = a;
                cout << "fill A" << endl;
            }
            if (bb == b)
            {
                bb = 0;
                cout << "empty B" << endl;
            }
        }
        cout << "success" << endl;
    }
}