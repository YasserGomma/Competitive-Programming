#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include <ext/numeric>
#define endl '\n'
using namespace __gnu_cxx;
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
ll gcd(ll a, ll b)
{
    return (a) ? gcd(b % a, a) : b;
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
void nGu()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
typedef vector<vector<unsigned int>> vvi;
struct matrixMultiply
{
    int n;
    matrixMultiply(int x)
    {
        n = x;
    }
    vvi operator()(const vvi& a, const vvi& b)
    {
        vvi ret(a.size(), vector<unsigned int>(b[0].size()));
        for (int i = 0; i < a.size(); ++i)
        {
            for (int j = 0; j < b[0].size(); ++j)
            {
                for (int k = 0; k < a[0].size(); ++k)
                {

                    ret[i][j] += (a[i][k] * b[k][j]);
                }
            }
        }
        return ret;
    }
};
vvi identity_element(const matrixMultiply& x)
{
    vvi ret(x.n, vector<unsigned int>(x.n));
    for (int i = 0; i < x.n; ++i)
    {
        ret[i][i] = 1;
    }
    return ret;
}

int main()
{
  long long n;
	cin >> n;
	matrixMultiply M(0);
   vvi grid=vector<vector<unsigned int>>(65,vector<unsigned int>(65));
	grid[64][64] = 1; // the answer moves on to next step
	for(int cell = 0; cell < 64; ++cell) {
		grid[cell][64] = 1; // add to the answer
		for(int cell2 = 0; cell2 < 64; ++cell2) {
			int row = cell / 8;
			int col = cell % 8;
			int row2 = cell2 / 8;
			int col2 = cell2 % 8;
			int d_row = abs(row - row2);
			int d_col = abs(col - col2);
			if((d_row == 2 && d_col == 1) || (d_row == 1 && d_col == 2)) {
				grid[cell][cell2] = 1;
			}
		}
	}
	vvi total = power(grid, n + 1,M); // n+1 because answer is taken as sum from previous iteration
	cout << total[0][64] << endl;

}
