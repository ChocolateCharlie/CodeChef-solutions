#include <iostream>

using namespace std;

int run_testcase(int n);



int main() {
    int T;
    int N;

    cin >> T;

    while (T--) {
        cin >> N;
        cout << run_testcase(N) << endl;
    }
}



int run_testcase(int n) {
    int nb_op;
    int w, min_salary, temp;

    nb_op = 0;

    cin >> min_salary;

    for (int i = 1; i < n; i++) {
        cin >> w;
        if(w < min_salary)  {
            temp = w;
            w = min_salary;
            min_salary = temp;
            nb_op += (i - 1) * (w - min_salary);
        }
        nb_op += w - min_salary;
    }

    return(nb_op);
}
