#include <vector>
#include <algorithm>
using namespace std;

/*
The array-form of an integer num is an array representing its digits in left to right order.
For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.
*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int idx = num.size() - 1;
        int carry = 0;
        while (k != 0 || idx >= 0) {
            int sum = carry;
            if (idx >= 0) sum += num[idx];
            if (k != 0) sum += k % 10;

            res.push_back(sum % 10);
            carry = (sum / 10) % 10;
            k /= 10;
            idx--;
        }
        if (carry) 
            res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }

    // take K itself as a carry
    vector<int> addToArrayForm(vector<int> A, int K) {
        for (int i = A.size() - 1; i >= 0 && K > 0; --i) {
            A[i] += K;
            K = A[i] / 10;
            A[i] %= 10;
        }
        while (K > 0) {
            A.insert(A.begin(), K % 10);
            K /= 10;
        }
        return A;
    }
};
