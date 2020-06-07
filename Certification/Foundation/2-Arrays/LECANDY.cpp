#include <iostream>

using namespace std;

bool    run_testcase(int n, int c);



int main() {
    int T;
    int N, C;

    cin >> T;

    while (T--) {
        cin >> N >> C;
        cout << (run_testcase(N, C) ? "Yes" : "No") << endl;
    }
}



bool    run_testcase(int n, int c) {
    int nc;
    int a;

    nc = 0;

    while (n--) {
        cin >> a;
        nc += a;
    }

    return(nc <= c);
}
