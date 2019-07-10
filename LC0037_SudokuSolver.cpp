//
// Created by hfq on 19-7-1

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        if(board.empty()) {
            return;
        }

        std::vector<std::unordered_set<char>> tab_col(9);
        std::vector<std::unordered_set<char>> tab_row(9);
        std::vector<std::unordered_set<char>> tab_block(9);

        int block = 0;
        for(int i = 0; i < 9; i ++) {
            for(int j = 0; j < 9; j++) {
                block = (i / 3) * 3 + j / 3;
                if(board[i][j] == '.') {
                    continue;
                }
                else {
                    tab_row[i].insert(board[i][j]);
                    tab_col[j].insert(board[i][j]);
                    tab_block[block].insert(board[i][j]);
                }
            }
        }

        solveSudokuCore(board, tab_col, tab_row, tab_block, 0, 0);
    }

    bool solveSudokuCore(std::vector<std::vector<char>>& board,
                         std::vector<std::unordered_set<char>>& tab_col, std::vector<std::unordered_set<char>>& tab_row,
                         std::vector<std::unordered_set<char>>& tab_block, int i, int j) {
        int i_next = i;
        int j_next = j;
        bool tmp_res = false;
        if(j == 8 && i != 8) {
            i_next++;
            j_next = 0;
        }
        else if(j == 8 && i == 8 && board[i][j] != '.') {
            return true;
        }
        else {
            j_next++;
        }

        if(board[i][j] != '.') {

            return solveSudokuCore(board, tab_col, tab_row, tab_block, i_next, j_next);
        }

        int block = (i / 3) * 3 + j / 3;

        for(int num = 1; num <= 9; num++) {
            if(tab_row[i].find(num+'0') != tab_row[i].end() || tab_col[j].find(num+'0') != tab_col[j].end() ||
            tab_block[block].find(num+'0') != tab_block[block].end()) {
                continue;
            }
            else {
                board[i][j] = num + '0';
                tab_row[i].insert(num+'0');
                tab_col[j].insert(num+'0');
                tab_block[block].insert(num+'0');
                if(i == 8 && j == 8) {
                    tmp_res = true;
                }
                else {
                    tmp_res = solveSudokuCore(board, tab_col, tab_row, tab_block, i_next, j_next);
                }

                if(tmp_res) {
                    return true;
                }
                else {
                    board[i][j] = '.';
                    tab_row[i].erase(num+'0');
                    tab_col[j].erase(num+'0');
                    tab_block[block].erase(num+'0');
                    continue;
                }
            }
        }

        board[i][j] = '.';
        return false;
    }
};

class Test {
public:
    Test() {
        sol = Solution();
    }

    void test1() {
        std::vector< std::vector<char> > input1({{'5','3','.','.','7','.','.','.','.'},
                                                 {'6','.','.','1','9','5','.','.','.'},
                                                 {'.','9','8','.','.','.','.','6','.'},
                                                 {'8','.','.','.','6','.','.','.','3'},
                                                 {'4','.','.','8','.','3','.','.','1'},
                                                 {'7','.','.','.','2','.','.','.','6'},
                                                 {'.','6','.','.','.','.','2','8','.'},
                                                 {'.','.','.','4','1','9','.','.','5'},
                                                 {'.','.','.','.','8','.','.','7','9'}});

        std::vector< std::vector<char> > expects({{'5','3','4','6','7','8','9','1','2'},
                                                 {'6','7','2','1','9','5','3','4','8'},
                                                 {'1','9','8','3','4','2','5','6','7'},
                                                 {'8','5','9','7','6','1','4','2','3'},
                                                 {'4','2','6','8','5','3','7','9','1'},
                                                 {'7','1','3','9','2','4','8','5','6'},
                                                 {'9','6','1','5','3','7','2','8','4'},
                                                 {'2','8','7','4','1','9','6','3','5'},
                                                 {'3','4','5','2','8','6','1','7','9'}});

        check("Test 1", input1, expects);
    }

private:
    void check(const char* testname, std::vector< std::vector<char> >& input1, const std::vector< std::vector<char> >& expects) {
        bool tst_pass = true;
        sol.solveSudoku(input1);

        if(input1 != expects) {
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