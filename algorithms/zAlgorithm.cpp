#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> getZArray(string str) {
    int n = str.length();
    int l = 0, r = 0;
    vector<int> z(n);
    for (int i = 1; i < n; i++) {
        if (i > r) {
            // no prefix substring that starts before i and ends after i
            // so, we reset l and r
            l = r = i;

            // computer new [l, r] by comparing str[0...] to str[i...]
            while (r < n && str[r - l] == str[r]) r++;
            z[i] = r - l;
            r--;
        } else {
            // z[i] >= min(z[k], r-i+1) since str[i...] matches with str[k...]
            // for at least r-i+1 characters
            int k = i - l;
            if (z[k] < r - i + 1)
                // no prefix substring starting at str[i]
                // interval [l, r] remains same
                z[i] = z[k];
            else {
                // possible to extend the interval [l, r] thus we will set l as i
                // and start matching from str[r] onwards and get new r
                // then we will update interval [l, r]
                l = i;
                while (r < n && str[r-l] == str[r]) r++;
                z[i] = r - l;
                r--;
            }
        }
    }

    return z;
}

int main() {
    auto res = getZArray("aabcaabxaaaz");
    for (int i: res) {
        cout << i << " ";
    }
    cout << endl;
}