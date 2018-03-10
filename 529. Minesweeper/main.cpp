#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        board_row = board.size();
        board_col = board[0].size();

        vector<vector<char>> ret(board_row, vector<char>(board_col, 'N')); // N for not visited;

        int click_row = click[0];
        int click_col = click[1];

        if (board[click_row][click_col] == 'M')
        {
            board[click_row][click_col] = 'X';
            return board;
        }

        int count = find_adj(board, click_row, click_col, ret);
        if (count != 0)
        {
            board[click_row][click_col] = '0' + count;
            return board;            
        }
        ret[click_row][click_col] = 'B';
        for (int i = 0; i < direction.size(); ++i)
        {
            DFS(ret, click_row + direction[i][0], click_col + direction[i][1], board);
        }

        for (int i = 0; i < board_row; ++i)
        {
            for (int j = 0; j < board_col; ++j)
            {
                if (ret[i][j] == 'N')
                {
                    ret[i][j] = board[i][j];
                }

            }
        }

        return ret;
    }

private:
    void DFS(vector<vector<char>> &ret, int row, int col, vector<vector<char>> &board)
    {
        if (in_board(row, col) == false)
            return;
        if (board[row][col] == 'M')
        {
            ret[row][col] = 'M';
            return;
        }
        if (ret[row][col] != 'N')
        {
            return;
        }
        int count = find_adj(board, row, col, ret);
        if (count != 0)
        {
            ret[row][col] = '0' + count;
            return;        
        }
        ret[row][col] = 'B';
        for (int i = 0; i < direction.size(); ++i)
        {
            DFS(ret, row + direction[i][0], col + direction[i][1], board);
        }
    }

    int find_adj(vector<vector<char>>& board, int current_row, int current_col,vector<vector<char>>& ret )
    {
        int count = 0;
        for (int i = 0; i < direction.size(); ++i)
        {
            int temp_row = current_row + direction[i][0];
            int temp_col = current_col + direction[i][1];
            if (in_board(temp_row, temp_col))
            {
                if (board[temp_row][temp_col] == 'M')
                {
                    ++count;
                    ret[temp_row][temp_col] = 'M';
                }
                /*else if (board[temp_row][temp_col] == 'E' && ret[temp_row][temp_col] == 'N')
                {
                    ret[temp_row][temp_col] = 'W';
                }*/
            }
        }
        return count;
    }

    bool in_board(int row, int col)
    {
        return (row >= 0 && col >= 0 && row < board_row && col < board_col);
    }

    vector<vector<int>> direction = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},  {0, 1},
        {1, -1}, {1, 0}, {1, 1} };

    int board_row;
    int board_col;
};