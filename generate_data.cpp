#include<bits/stdc++.h>

using namespace std;
using lli = long long int;

lli rd (lli L, lli R) {
    return 1LL * rand() * rand() % (R - L + 1) + L;
}

double rd_double () {
    return 1.0 * rd(100, 200) / rd(300, 400);
}

vector<double> random_data (int N) {
    vector<double> a;
    while(N--) a.emplace_back(rd(-100000, 1000000) + (rd(0, 1) ? 1 : -1) * rd_double());
    return a;
}

int main () {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    cin.tie(0); cin.tie(0);

    vector<double> a;

    for (int i = 0; i < 10; i++) {
        a = random_data(rd(1000000 - 100, 1000000));
        if (i == 0) sort(a.begin(), a.end());
        if (i == 1) sort(a.begin(), a.end(), greater<double>());

        
        stringstream ss; ss << "sort" << i << ".inp";
        ofstream inp(ss.str().c_str());
        for (auto x : a) inp << fixed << setprecision(3) << x << " "; cout << endl;
        inp.close();
    }
    return 0;
}
