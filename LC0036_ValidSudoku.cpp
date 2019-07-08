//
// Created by hfq on 19-7-8.
//

#include <iostream>
#include <vector>
#include <unordered_set>
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        if(board.size() != 9) {
            return false;
        }

        for(int i = 0; i < board.size(); i++) {
            if(board[i].size() != 9) {
                return false;
            }
        }

        std::vector< std::unordered_set<char> > col_sets(9);
        std::vector< std::unordered_set<char> > row_sets(9);
        std::vector< std::unordered_set<char> > block_sets(9);
        int block = 0;

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                block = j / 3 + (i / 3) * 3;

                if(board[i][j] == '.') {
                    continue;
                }

                auto it_row = row_sets[i].find(board[i][j]);
                if(it_row != row_sets[i].end()) {
                    return false;
                }
                else {
                    row_sets[i].insert(board[i][j]);
                }

                auto it_col = col_sets[j].find(board[i][j]);
                if(it_col != col_sets[j].end()) {
                    return false;
                }
                else {
                    col_sets[j].insert(board[i][j]);
                }

                auto it_block = block_sets[block].find(board[i][j]);
                if(it_block != block_sets[block].end()) {
                    return false;
                }
                else {
                    block_sets[block].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector< std::vector<char> > input1({{'5','3','.','.','7','.','.','.','.'},
                                                 {'5','3','.','.','7','.','.','.','.'},
                                                 {'5','3','.','.','7','.','.','.','.'},
                                                 {'5','3','.','.','7','.','.','.','.'},
                                                 {'5','3','.','.','7','.','.','.','.'},
                                                 {'5','3','.','.','7','.','.','.','.'},
                                                 {'5','3','.','.','7','.','.','.','.'},
                                                 {'5','3','.','.','7','.','.','.','.'},
                                                 {'5','3','.','.','7','.','.','.','.'}});
        bool expects(false);
        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::vector< std::vector<char> >& input1, const bool& expects) {
        bool tst_pass = true;
        auto&& result = sol.isValidSudoku(input1);
        if(result != expects) {
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
    return 0;
}