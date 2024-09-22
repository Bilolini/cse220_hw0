#include <stdio.h>
#include <stdbool.h>

int main(){
    // printf("Hello world\n");

    char board[4][4] = {
                {'x', 'o', 'x', 'o'},
                {'x', 'x', 'x', 'o'},
                {'o', 'o', 'o', '-'},
                {'o', 'o', 'o', 'x'},
            };
    
    // Printing the state of the game
    bool done;
    done = false;
    int open = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if(board[i][j] == ' '){
                open++;
            }
        }
    }
    // printf("%d", open);
    while(!done){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++)
                {
                    printf("%c", board[i][j]);
                    printf(" ");
                }
            printf("\n");
        }
        // Getting the values from the user
        char val;
        int row, col;
        
        while(true){
            printf("Choose a piece (x or o) or q to quit: ");
            scanf(" %c", &val);
            // printf("%c\n", val);

            if(val == 'q'){
                done = true;
                break;
            }

            if(val != 'x' && val != 'o'){
                printf("Invalid choice. ");
            }else{
                break;
            }
        }
        
        if(done) break;

        // ROW
        while(true){
            printf("Choose a row (0-4): ");
            scanf(" %d", &row);

            if(!(row >=0 && row < 4)){
                printf("Invalid choice. ");
            }else{
                break;
            }
        }
        
        // COLUMN
        while(true){
            printf("Choose a column (0-4): ");
            scanf(" %d", &col);
            if(!(col >=0 && col < 4)){
                printf("Invalid choice. ");
            }else{
                break;
            }
        }
        

        if(&board[row][col] == "x" || &board[row][col] == "o"){
            printf("Invalid choice. That space is already occupied.\n");
        }
       else{
            bool combo = false;
            // Check horizontal
            int count = 0;
            for (int i = col - 1; i >= 0 && board[row][i] == val; i--) {
                count++;
            }
            for (int i = col + 1; i < 4 && board[row][i] == val; i++) {
                count++;
            }
            if (count >= 3) {
                combo = true;
            }

            // Check vertical
            if(!combo){
                count = 0;
                for (int i = row - 1; i >= 0 && board[i][col] == val; i--) {
                    count++;
                }
                for (int i = row + 1; i < 4 && board[i][col] == val; i++) {
                    count++;
                }
                if (count >= 3) {
                    combo = true;
                }
            }
        
            if(!combo){
                // Check diagonal (top-left to bottom-right)
                count = 0;
                for (int i = row - 1, j = col - 1; i >= 0 && j >= 0 && board[i][j] == val; i--, j--) {
                    count++;
                }
                for (int i = row + 1, j = col + 1; i < 4 && j < 4 && board[i][j] == val; i++, j++) {
                    count++;
                }
                if (count >= 3) {
                    combo = true;
                }
            }
            
            if(!combo){
                // Check diagonal (top-right to bottom-left)
                count = 0;
                for (int i = row - 1, j = col + 1; i >= 0 && j < 4 && board[i][j] == val; i--, j++) {
                    count++;
                }
                for (int i = row + 1, j = col - 1; i < 4 && j >= 0 && board[i][j] == val; i++, j--) {
                    count++;
                }
                if (count >= 3) {
                    combo = true;
                }
            }

            if(!combo){
                board[row][col] = val;
                open--;
                if(open == 0){
                    done = true;
                    printf("Congratulations, you have filled the board!\n");
                    for (int i = 0; i < 4; i++)
                        {
                            for (int j = 0; j < 4; j++)
                            {
                                printf("%c", board[i][j]);
                                printf(" ");
                            }
                            printf("\n");
                        }
                }
            }else{
                printf("Invalid choice. You have created 4-in-a-row.\n");
            }
        }
    }
}
