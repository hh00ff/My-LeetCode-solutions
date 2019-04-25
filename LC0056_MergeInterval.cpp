//
// Created by hfq on 19-4-12.
//
#include <algorithm>
#include <iostream>
#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    static bool cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }

    std::vector<Interval> merge(std::vector<Interval>& intervals) {
        if(intervals.empty()) {
            return intervals;
        }
        std::vector<Interval> result;
        sort(intervals.begin(), intervals.end(), cmp);
        std::vector<Interval>::iterator iter = intervals.begin();
        Interval cur_interval(iter->start, iter->end);
        iter++;
        for(; iter != intervals.end(); iter++) {
            if(iter->start <= cur_interval.end) {
                cur_interval.end = iter->end > cur_interval.end ? iter->end : cur_interval.end;
            }
            else {
                result.push_back(cur_interval);
                cur_interval = *iter;
            }
        }
        result.push_back(cur_interval);
        return result;
    }
};


class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<Interval> inputs;
        std::vector<Interval> expects;
        int input_list[] = {1, 4, 2, 3};
        int exp_list[] = {1, 4};
        for(int i = 0; i < 2; i++) {
            inputs.emplace_back(Interval(input_list[i], input_list[i+1]));
        }
        for(int i = 0; i < 1; i++) {
            expects.emplace_back(Interval(exp_list[i], exp_list[i+1]));
        }
        check("Test 1", inputs, expects);
    }

private:
    void check(const char* testname, std::vector<Interval>& input, const std::vector<Interval>& expected) {
        bool tst_pass = true;
        auto&& result = sol.merge(input);
        if(result.size() != expected.size()) {
            tst_pass = false;
        }
        else {
            auto iter_input = result.begin();
            auto iter_exp = expected.begin();
            while(iter_input != result.end()) {
                if ((iter_input->start != iter_exp->start) || (iter_input->end != iter_exp->end)) {
                    tst_pass = false;
                    break;
                }
                iter_exp++;
                iter_input++;
            }
        }
        if(tst_pass){
            std::cout << testname << ": " << "pass" << std::endl;
        }
        else {
            std::cout << testname << ": " << "fail" << std::endl;
        }
    }

    Solution sol;
};

int main(int argc, char** argv) {
    Test tst = Test();
    tst.test1();
    return 0;
}
