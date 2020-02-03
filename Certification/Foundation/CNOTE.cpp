#include <iostream>

using namespace std;

bool    run_testcase(int z, int k, int n);



int main() {
    int T;
    int X, Y, K, N;

    cin >> T;

    while (T--) {
        cin >> X >> Y >> K >> N;
        cout << (run_testcase(X - Y, K, N) ? "LuckyChef" : "UnluckyChef") << endl;
    }

    return(0);
}



bool    run_testcase(int z, int k, int n) {
    bool    lucky;
    int     p, c;

    lucky = false;

    for (int i = 0; i < n; i++) {
        cin >> p >> c;
        if (p >= z && c <= k)   lucky = true;
    }

    return(lucky);
}
