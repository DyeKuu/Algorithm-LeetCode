
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited;
        for (int i = 0; i < board.size(); i++) {
            vector<bool> temp(board[i].size(), false);
            visited.push_back(temp);
        }
        return exist(board, word, visited);
    }

   private:
    bool exist(vector<vector<char>>& board, string word,
               vector<vector<bool>>& visited) {
        if (word.empty()) return true;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0] &&
                    findNext(board, word.substr(1), i, j, visited))
                    return true;
            }
        }
        return false;
    }

    bool findNext(vector<vector<char>>& board, string word, int x, int y,
                  vector<vector<bool>>& visited) {
        if (word.empty()) return true;
        visited[x][y] = true;
        if (y < board[x].size() - 1 && !visited[x][y + 1] &&
            board[x][y + 1] == word[0] &&
            findNext(board, word.substr(1), x, y + 1, visited))
            return true;
        if (y > 0 && !visited[x][y - 1] && board[x][y - 1] == word[0] &&
            findNext(board, word.substr(1), x, y - 1, visited))
            return true;
        if (x < board.size() - 1 && !visited[x + 1][y] &&
            board[x + 1][y] == word[0] &&
            findNext(board, word.substr(1), x + 1, y, visited))
            return true;
        if (x > 0 && !visited[x - 1][y] && board[x - 1][y] == word[0] &&
            findNext(board, word.substr(1), x - 1, y, visited))
            return true;
        visited[x][y] = false;
        return false;
    }
};
