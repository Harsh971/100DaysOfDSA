// Java Solution

class Solution
{
    boolean adjacentSearch(char[][] board, String word, int i, int j, int len)
    {
        if(len == word.length())
            return true;
        if(i < 0 || j < 0 || i >= board.length || j >= board[0].length)
            return false;
        if(board[i][j] != word.charAt(len))
            return false;
            //character mactches, mark it and recur for all 4 dir for next ch.
        board[i][j] = '*';
        boolean ans = 
            adjacentSearch(board, word, i-1, j, len+1) || //up
            adjacentSearch(board, word, i+1, j, len+1) || //down
            adjacentSearch(board, word, i, j-1, len+1) || //left
            adjacentSearch(board, word, i, j+1, len+1);   // right
        // board[i][j] = word.charAt(len);// i cannot find complete word in this path, reset the path and return to parent call.
        return ans;
    }
    
    public boolean isWordExist(char[][] board, String word)
    {
        for(int i = 0; i < board.length; i++)
        {
            for(int j = 0; j < board[0].length; j++)
            {
                if(board[i][j] == word.charAt(0) && adjacentSearch(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
	}
}