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

    return(0);
}



bool    run_testcase(int n, int c) {
    int A, necessary;

    necessary = 0;

    for (int i = 0; i < n; i++) {
        cin >> A;
        necessary += A;
    }

    return(necessary <= c);
}
