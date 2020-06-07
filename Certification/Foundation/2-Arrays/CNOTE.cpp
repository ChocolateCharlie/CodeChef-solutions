#include <iostream>

using namespace std;

bool    run_testcase(int nb_pages, int k, int n);



int main() {
    int T;
    int X, Y, K, N;

    cin >> T;

    while (T--) {
        cin >> X >> Y >> K >> N;
        cout << (run_testcase(X - Y, K, N) ? "LuckyChef" : "UnluckyChef") << endl;
    }
}



bool    run_testcase(int nb_pages, int k, int n) {
    bool    lucky;
    int     p, c;

    lucky = false;

    while (n--) {
        cin >> p >> c;
        if (p >= nb_pages && c <= k)    { lucky = true; }
    }

    return(lucky);
}
