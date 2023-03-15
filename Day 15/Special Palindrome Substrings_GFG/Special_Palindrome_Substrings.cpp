#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int specialPalindrome(string a, string b) {
        int l1 = a.length(), l2 = b.length();
        if (l1 < l2)
            return -1;
        int ans = INT_MAX;
        char s1[l1+1], s2[l2+1];
        strcpy(s1, a.c_str());
        strcpy(s2, b.c_str());
        for (int i = 0; i < l1-l2+1; i++) {
            char temp[l1+1];
            strcpy(temp, (a.substr(0, i) + b + a.substr(i+l2)).c_str());
            int cost = 0;
            for (int j = i; j < i+l2; j++) {
                if (s1[j] != temp[j])
                    cost++;
            }
            int is_palin = 1;
            for (int j = 0; j < ceil(l1/2.0); j++) {
                if ((j < i || j >= i+l2) && temp[j] != temp[l1-j-1])
                    cost++;
                else if (l1-i-1 < j || l1-i-l2-1 >= j && temp[j] != temp[l1-j-1])
                    cost++;
                else if (temp[j] != temp[l1-j-1]) {
                    is_palin = 0;
                    break;
                }
            }
            if (is_palin == 1)
                ans = min(ans, cost);
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
