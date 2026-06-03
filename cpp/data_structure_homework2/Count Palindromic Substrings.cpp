#include <iostream>
#include <string>
using namespace std;

int getCnt(string s) {
        int n = s.size();
        int ans = 0;
        // 奇中心i
        for (int i = 0; i < n; ++i) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                ans++; l--; r++;
            }
        }
        // 偶
        for (int i = 0; i < n - 1; ++i) {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                ans++; l--; r++;
            }
        }
        return ans;
    }

int main() {
    string str;
    while (cin >> str) {
        cout << getCnt(str) << endl;
    }
    return 0;
}