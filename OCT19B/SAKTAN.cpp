#include <iostream>
#define ull unsigned long long

using namespace std;

ull run_testcase(ull n, ull m, ull q);



int main() {
    int T;
    ull N, M, Q;

    cin >> T;

    while (T--) {
        cin >> N >> M >> Q;
        cout << run_testcase(N, M, Q) << endl;
    }

	return(0);
}



ull run_testcase(ull n, ull m, ull q) {
    bool    rows[n] = {false};
    bool    cols[m] = {false};
    ull     orows = 0;
    ull     ocols = 0;
    ull     x, y;

    while (q--) {
        cin >> x >> y;

        orows = (rows[x - 1] ? orows - 1 : orows + 1);
        rows[x - 1] = ! rows[x - 1];

        ocols = (cols[y - 1] ? ocols - 1 : ocols + 1);
        cols[y - 1] = ! cols[y - 1];
    }

    return (orows * (m - ocols) + ocols * (n - orows));
}
