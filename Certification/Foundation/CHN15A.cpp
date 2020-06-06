#include <iostream>

using namespace std;

int run_testcase(int n, int k);



int main() {
    int T;
    int N, K;

    cin >> T;

    while (T--) {
        cin >> N >> K;
        cout << run_testcase(N, K) << endl;
    }

    return(0);
}



int run_testcase(int n, int k) {
    int w, v;

    w = 0;

    for (int i = 0; i < n; i++) {
        cin >> v;
        if (!((v + k) % 7)) w++;
    }

    return(w);
}
