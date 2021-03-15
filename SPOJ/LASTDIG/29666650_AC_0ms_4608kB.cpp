#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int iterativeFastPower(int x, int p, int mod=10) {
    int ret = 1;
    while (p) {
        if (p & 1)
            ret = (1ll * ret * x) % mod;
        x = (1ll * x * x) % mod;
        p >>= 1;
    }
    return ret;
}
int main()
{
    int t;
    cin >> t;
    int a, b;
    while (t--)
    {
        cin >> a >> b;
        cout << iterativeFastPower(a, b) % 10 << endl;
    }
}