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

int matrix[15][40];
int main()
{
	COME_BACK();
    int t; cin >> t;
  
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin>>matrix[i][j];
        }

        bool output = true;
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++)
                sum += matrix[j][i];
            if (sum != 2) output = false;
        }
        bool vertex[15][15];
        memset(vertex, false, sizeof(vertex));
        if (output) 
        {
            for (int i = 0; i < m; i++) {
                int first, second, j = 0;
                while (matrix[j][i] != 1)j++; 
                first = j++;
                while (matrix[j][i] != 1)j++; 
                second = j;
                if (!vertex[first][second]) 
                    vertex[first][second] = vertex[second][first] = true;
                else 
                    output = false;
            }
        }

        if (output)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}