#include <iostream>
#define NB_HOUSES   100

using namespace std;

int run_testcase(int m, int h);



int main() {
    int T;
    int M, X, Y;

    cin >> T;

    while (T--) {
        cin >> M >> X >> Y;
        cout << run_testcase(M, X * Y) << endl;
    }
}



int run_testcase(int m, int h) {
    bool    houses[NB_HOUSES];
    int     c;
    int     nb_safe;

    nb_safe = 100;
    for (int i = 0; i < NB_HOUSES; i++) { houses[i] = true; }

    while (m--) {
        cin >> c;

        for (int i = c - h - 1; i < c + h; i++) {
            if (i > -1 && i < NB_HOUSES && houses[i]) {
                nb_safe--;
                houses[i] = false;
            }
        }
    }

    return(nb_safe);
}
