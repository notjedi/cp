#include<bits/stdc++.h>

#define endl '\n'
#define MAX (int)1e6

using namespace std;
using ll = long long;

string s, t;
char chars[MAX];
int n, len, pos = 0;

/* PROLLY LOOK AT THIS? */
/* https://stackoverflow.com/questions/56334492/c-create-fixed-size-queue */

bool checkStackForT(int position) {
    if (position < len)
        return false;

    int temp = 0;
    for (int i = position - len; i<position; i++)
        if (chars[i] != t[temp++])
            return false;
    return true;
}

/* http://www.usaco.org/index.php?page=viewproblem2&cpid=526 */
int main() {

    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    cin >> s >> t;
    n = s.length(), len = t.length();

    for (int i=0; i<n; i++) {
        chars[pos] = s[i];
        pos++;
        if (s[i] == t[len - 1] && checkStackForT(pos))
            pos -= len;
    }

    for (int i=0; i<pos; i++)
        cout << chars[i];
    cout << endl;
    return 0;
}
