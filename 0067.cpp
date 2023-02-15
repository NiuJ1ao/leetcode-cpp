#include <string>
#include <algorithm>
using namespace std;

/*
Given two binary strings a and b, return their sum as a binary string.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;
        while (!a.empty() && !b.empty()) {
            int i = a.back() - '0';
            int j = b.back() - '0';
            a.pop_back();
            b.pop_back();

            int sum = i + j + carry;
            carry = (sum >> 1) & 0x1;
            char c = (sum & 0x1) + '0';
            res.insert(0, 1, c);
        }

        while (!a.empty()) {
            int i = a.back() - '0';
            a.pop_back();
            int sum = i + carry;
            carry = (sum >> 1) & 0x1;
            char c = (sum & 0x1) + '0';
            res.insert(0, 1, c);
        } 
        while (!b.empty()) {
            int j = b.back() - '0';
            b.pop_back();
            int sum = j + carry;
            carry = (sum >> 1) & 0x1;
            char c = (sum & 0x1) + '0';
            res.insert(0, 1, c);
        } 
        
        if (carry != 0) {
            res.insert(0, 1, '1');
        }
        return res;
    }

    string addBinary(string a, string b) {
        string res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;
            res += to_string(sum % 2);
        }
        if (carry) 
            res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};