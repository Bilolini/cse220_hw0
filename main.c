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
    int open;
    open = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(board[i][j] == ' ') open++;
            printf("%c", board[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("This is open\n");
    printf("%d\n", open);
    while(open != 0){
        // Getting the values from the user
        char val;
        int row, col;
        bool ok = true;
        printf("Choose a piece (x or o) or q to quit: ");
        while(ok){
            scanf("%c", &val);
            if(val == 'q'){
                break;
            }
            else if(val == 'x' || val == 'o'){
                ok = false;
                break;
            }else{
                printf("Invalid choice. Choose a piece (x or o) or q to quit: ");
            }
        }
        

        printf("Choose a row (0-4): ");
        scanf("%d", &row);
        while(!(row >=0 && row < 5)){
            printf("Invalid choice. Choose a row (0-4): ");
        };

        printf("Choose a column (0-4): ");
        scanf("%d", &col);
        while(!(col >=0 && col < 5)){
            printf("Invalid choice. Choose a column (0-4): ");
        };

        if(board[row][col] != " "){
            printf("Invalid choice. That space is already occupied.\n");

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    printf("%c", board[i][j]);
                    printf(" ");
                }
                printf("\n");
            }
        }else{
            board[row][col] = val;
            open--;
            if(open == 0){
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
