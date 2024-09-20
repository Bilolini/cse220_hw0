#include <stdio.h>
#include <stdbool.h>

int main(){
    // printf("Hello world\n");

    char board[5][5] = {
                {'x', 'x', 'x', ' ', 'o'},
                {'o', 'x', 'x', 'o', 'o'},
                {'o', 'x', ' ', 'x', 'x'},
                {'o', ' ', 'x', 'x', ' '},
                {'x', 'o', 'x', 'x', 'o'},
            };
    
    // Printing the state of the game
    bool done;
    done = false;
    int open = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if(board[i][j] == ' '){
                open++;
            }
        }
    }
    printf("%d", open);
    while(!done){
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++)
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

            if(!(row >=0 && row < 5)){
                printf("Invalid choice. ");
            }else{
                break;
            }
        }
        
        // COLUMN
        while(true){
            printf("Choose a column (0-4): ");
            scanf(" %d", &col);
            if(!(col >=0 && col < 5)){
                printf("Invalid choice. ");
            }else{
                break;
            }
        }
        

        if(&board[row][col] == "x" || &board[row][col] == "0"){
            printf("Invalid choice. That space is already occupied.\n");
        }
        else if(four_inrow(val, row, col)){
            printf("Invalid choice. You have created 4-in-a-row.\n");
        }   else{
            board[row][col] = val;
            open--;
            if(open == 0){
                done = true;
                printf("Congratulations, you have filled the board!\n");
                for (int i = 0; i < 5; i++)
                    {
                        for (int j = 0; j < 5; j++)
                        {
                            printf("%c", board[i][j]);
                            printf(" ");
                        }
                        printf("\n");
                    }
            }
        }
    }
}


bool four_inrow(char val, int row, int col){
    int ways[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    for(int j = 0; j< 4; j++){
        int c = 1;
        // for positive
        for(int i = 1; i < 4; i++){
            int x = row + ways[j][0] * i;
            int y = col + ways[j][1] * i;

            if(x >= 0 && x < rows && 
            y >= 0 && y < cols && board[row][col] == val){
                c++;
            }else{ break; }
        }

        if(c >= 4) return true;
        // for negative
        for(int i = 1; i < 4; i++){
            int x = row - ways[j][0] * i;
            int y = col - ways[j][1] * i;

            if(x >= 0 && x < rows && 
            y >= 0 && y < cols && board[row][col] == val){
                c++;
            }else{ break; }
        }

        if(c >= 4) return true;
    }
    return false;
}