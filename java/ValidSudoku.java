import java.util.*;

class ValidSudoku {
    public boolean isValidSudoku(char[][] board) {
        Set<String> seen = new HashSet<>();

        

        for(int i=0; i<9; i++){

            for(int j=0; j<9; j++){

                int num = board[i][j];

                

                if(num != '.'){

                    if(seen.contains(num+"R"+i) || seen.contains(num+"C"+j) || 

                        seen.contains(num+"B"+i/3+"."+j/3)){

                        return false;

                    }else{

                        seen.add(num+"R"+i);

                        seen.add(num+"C"+j);

                        seen.add(num+"B"+i/3+"."+j/3);

                    }

                }

            }

        }

        

        return true;
    }

    public static void main(String[] args){
        char[][] board = {
            {'8','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };

        // Output: false
        // because there are two '8' in first column

        if(new ValidSudoku().isValidSudoku(board)) System.out.println("true");
        else System.out.println("false");
    }
}