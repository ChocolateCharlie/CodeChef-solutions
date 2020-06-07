#include <iostream>

using namespace std;

bool    run_testcase(int n);



int main() {
    int T;
    int N;

    cin >> T;

    while (T--) {
        cin >> N;
        cout << (run_testcase(N) ? "yes" : "no") << endl;
    }
}



bool    run_testcase(int n) {
    bool    is_rainbow;
    int     nb_elements[7];
    int     a, prev_a;
    bool    asc;

    is_rainbow = true;
    asc = true;
    for (int i = 0; i < 7; i++) { nb_elements[i] = 0; }

    cin >> prev_a;
    nb_elements[prev_a - 1]++;

    for (int i = 1; i < n; i++) {
        cin >> a;

        if (a > 7)  { is_rainbow = false; }
        else {
            if (asc && prev_a > a) {
                if (prev_a != 7)    { is_rainbow = false; }
                asc = false;
            }
            if (asc) {
                nb_elements[a - 1]++;
                if (a - 2 > -1 && nb_elements[a - 2] == 0)  { is_rainbow = false; }
            }
            else    { nb_elements[a - 1]--; }
        }
        prev_a = a;
    }

    for (int i = 0; i < 6; i++) {
        if (nb_elements[i] != 0)    { is_rainbow = false; }
    }

    return(is_rainbow);
}
