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
}



int run_testcase(int n, int k) {
    int nb_Wlike;
    int i;

    nb_Wlike = 0;

    while (n--) {
        cin >> i;
        if ((i + k) % 7 == 0)   { nb_Wlike++; }
    }

    return(nb_Wlike);
}
