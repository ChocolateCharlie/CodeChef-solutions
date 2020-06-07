#include <iostream>
#include <string>

using namespace std;

bool    run_testcase();



int main() {
    int T;

    cin >> T;

    while (T--) {
        cout << (run_testcase() ? "YES" : "NO") << endl;
    }
}



bool    run_testcase() {
    string  s;
    int     l;

    int     table[26];
    for (int i = 0; i < 26; i++)    { table[i] = 0; }

    cin >> s;
    l = s.length();

    for (int i = 0; i < l / 2; i++)     { table[s[i] - 'a']++; }
    for (int i = l - 1; i > l / 2; i--) { table[s[i] - 'a']--; }
    if (l % 2 == 0) { table[s[l / 2] - 'a']--; }

    for (int i = 0; i < 26; i++) {
        if (table[i] != 0)  return(false);
    }

    return(true);
}
