#include <iostream>
#include <string>

using namespace std;

uint64_t    run_testcase(int n);



int main() {
    int T;
    int N;

    cin >> T;

    while (T--) {
        cin >> N;
        cout << run_testcase(N) << endl;
    }
}



uint64_t    run_testcase(int n) {
    uint64_t    nb_sub;
    uint64_t    nb_ones;
    char        c;

    nb_sub = 0;
    nb_ones = 0;

    while (n--) {
        cin >> c;

        if (c == '1')   { nb_ones++; }
    }

    nb_sub = nb_ones;
    while(nb_ones-- > 0)    { nb_sub += nb_ones; }

    return(nb_sub);
}
