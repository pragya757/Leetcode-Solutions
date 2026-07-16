class Solution {
public:

    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int index){

        // Word completely found
        if(index == word.size()){
            return true;
        }

        // Invalid cell
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()){
            return false;
        }

        // Character doesn't match
        if(board[i][j] != word[index]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';      // Mark visited

        bool found =
            dfs(board, word, i+1, j, index+1) ||
            dfs(board, word, i-1, j, index+1) ||
            dfs(board, word, i, j+1, index+1) ||
            dfs(board, word, i, j-1, index+1);

        board[i][j] = temp;     // Backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};
