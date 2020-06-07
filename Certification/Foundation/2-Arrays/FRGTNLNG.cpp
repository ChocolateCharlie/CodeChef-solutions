#include <iostream>
#include <string>

using namespace std;

void    run_testcase(int n, int k);



int main() {
    int T;
    int N, K;

    cin >> T;

    while (T--) {
        cin >> N >> K;
        run_testcase(N, K);
    }
}



void    run_testcase(int n, int k) {
    bool    ex[n];
    int l;
    string  d[n];
    string  w;

    for (int i = 0; i < n; i++) {
        cin >> d[i];
        ex[i] = false;
    }

    while (k--) {
        cin >> l;

        for (int i = 0; i < l; i++) {
            cin >> w;

            for (int j = 0; j < n; j++) {
                if (d[j] == w)  { ex[j] = true; }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << (ex[i] ? "YES" : "NO");
        if (i < n - 1)  { cout << " "; }
    }
    cout << endl;
}
