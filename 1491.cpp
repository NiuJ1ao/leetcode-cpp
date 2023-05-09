#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.
*/

class Solution {
public:
    double average(vector<int>& salary) {
        int minSalary = INT_MAX, maxSalary = INT_MIN;
        double res = 0;

        for (int s: salary) {
            res += double(s);
            minSalary = min(minSalary, s);
            maxSalary = max(maxSalary, s);
        }

        res = (res - minSalary - maxSalary) / (salary.size() - 2);

        return res;
    }

    double average(vector<int>& salary) {
        return (reduce(salary.begin(), salary.end(), 0.) - *min_element(salary.begin(), salary.end()) - *max_element(salary.begin(), salary.end())) / (salary.size() - 2);
    }
};