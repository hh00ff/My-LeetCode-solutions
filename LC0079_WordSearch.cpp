//
// Created by hfq on 2019/8/22.
//
#include <iostream>
#include <vector>
#include <string>
class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        if(word.empty()) {
            return true;
        }
        if(board.empty() || board[0].empty()) {
            return false;
        }
        std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if(existCore(board, visited, word, i, j, 0)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    bool existCore(std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited, std::string& word,
            int i, int j, int k) {
        if(k == word.size() - 1) {
            return true;
        }
        std::vector<int> offsets = {-1, 0, 1};
        int newi, newj;
        bool exist = false;
        for(auto offsetX: offsets) {
            for(auto offsetY: offsets) {
                if(abs(offsetX) + abs(offsetY) != 1) {
                    continue;
                }
                newi = offsetX + i;
                newj = offsetY + j;
                if(newi < board.size() && newi >= 0 && newj < board[0].size() && newj >= 0 && !visited[newi][newj] &&
                board[newi][newj] == word[k + 1]) {
                    visited[newi][newj] = true;
                    exist = exist || existCore(board, visited, word, newi, newj, k + 1);
                    visited[newi][newj] = false;
                }
            }
        }
        return exist;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector<std::vector<char>> input1({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}});
        std::string input2("ABCCED");
        bool expects(true);

        check("Test 1", input1, input2, expects);
    }

    void test2() {
        std::vector<std::vector<char>> input1({{'A', 'B'}, {'C', 'D'}});
        std::string input2("ABCD");
        bool expects(false);

        check("Test 2", input1, input2, expects);
    }

private:
    void check(const char* testname, std::vector<std::vector<char>>& input1, std::string& input2, const bool& expects) {
        bool tst_pass = true;
        auto res = sol.exist(input1, input2);

        if(res != expects) {
            tst_pass = false;
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
    tst.test2();
    return 0;
}

