#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

double iterativeFastPower(int x, double p) {
    double ret = 1.0;
    while (x) {
        if (x & 1)
            ret = ret * (1 - p) + (1 - ret) * p;
        p =2*(p*(1-p));
        x = x >> 1;
    }
    return ret;
}
int main()
{


    double a, b;
    cin >> a >> b;
    cout <<fixed<<setprecision(7)<< iterativeFastPower(a, b) << endl;

}