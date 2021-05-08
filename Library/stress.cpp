#include "bits/stdc++.h"

using namespace std;
#define rep2(i, s, e) for(int i=s;i<=(int)e;++i)
#define rep(i, n) for(int i=0;i<(int)n;++i)

class Random {
public:
    Random() = default;

    Random(std::mt19937::result_type seed) : eng(seed) {}

    long long DrawNumber(long long min, long long max);

private:
    std::mt19937 eng{std::random_device{}()};
};

long long Random::DrawNumber(long long min, long long max) {
    if (max < min)return 0;
    return std::uniform_int_distribution<long long>{min, max}(eng);
}


Random rnd;

void generate() {
    ofstream cout("test.in");
//    int n = 2;
//    cout << t << endl;
//    while (t--) {
        int n = rnd.DrawNumber(1, 5);
        int q = rnd.DrawNumber(1, 3);
        cout<<n<<" " << q << "\n";
        for(int i = 0; i <n ; i++){
            int x = rnd.DrawNumber(1, 4);
            cout<<x <<" \n"[i==n-1];
//            while (m--)
//                cout<<char(rnd.DrawNumber('a','c'));
//            cout<<'\n';
        }
        while(q--) {
            int l = rnd.DrawNumber(1, n);
            int r = rnd.DrawNumber(l, n);
            int k = rnd.DrawNumber(1, r-l+1);

            cout<<l << " " << r <<" " << k << endl;

        }
//    }
    cout.close();
}

int main() {
    system("g++ -lm -O3 -std=c++17 -DLOCAL -pipe -o wa.exe ./MKTHNUM.cpp");
    system("g++ -lm -O3 -std=c++17 -pipe -o ac.exe ./AC.cpp");
    int tc = 1;


    while (1) {
        cerr << "Case " << tc++ << endl;
        generate();
        system("ac.exe <test.in >ac.txt");
        if (system("wa.exe <test.in >wa.txt"))break;


        //  cerr << tc++ << endl;
        ifstream acs("ac.txt");
        ifstream was("wa.txt");

        string ac, wa;
        getline(was, wa, (char) EOF);

        getline(acs, ac, (char) EOF);
        was.close();

        acs.close();

//		cout << ac << endl;
//		cout << wa << endl;
        //if (ac !="YES\n")
        if (ac != wa)
            break;
    }
}
