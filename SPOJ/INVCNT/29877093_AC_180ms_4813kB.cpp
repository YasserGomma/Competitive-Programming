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
ll cnt = 0;
vector<int>v;
void merge(int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int>L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[mid + j + 1];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            v[k++] = L[i++];
        else
        {
            v[k++] = R[j++];
            cnt += n1 - i; //inversion
        }

    }
    while (i < n1)
        v[k++] = L[i++];

    while (j < n2)
        v[k++] = R[j++];

}
void mergesort(int l, int r)
{
    if (l >= r)return;

    int mid = l + (r - l) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, mid, r);

}
int main() {
   
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        v.clear();
        v.resize(n);
        cnt = 0;
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        mergesort(0, n - 1);
        cout << cnt << endl;
    }

}
