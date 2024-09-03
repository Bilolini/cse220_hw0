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
        
        printf("Choose a piece (x or o) or q to quit: ");
        scanf("%c", &val);
        printf("%c\n", val);
        
        int c;
        while((c= getchar()) != '\n' && c != EOF); 
        if(val == 'q'){
            done = true;
            break;
        }
        if(val != 'x' && val != 'o'){
            while(!(val == 'x' || val == 'o')){
                printf("Invalid choice.Choose a piece (x or o) or q to quit: ");
                scanf("%c", &val);

                if(val == 'q'){
                    done = true;
                    break;
                }
            }
        }
        

        // ROW
        printf("Choose a row (0-4): ");
        scanf("%d", &row);
        while(!(row >=0 && row < 5)){
            printf("Invalid choice. Choose a row (0-4): ");
            scanf("%d", &row);
        };

        // COLUMN
        printf("Choose a column (0-4): ");
        scanf("%d", &col);
        while(!(col >=0 && col < 5)){
            printf("Invalid choice. Choose a column (0-4): ");
            scanf("%d", &row);
        };


        if(&board[row][col] == "x" || &board[row][col] == "0"){
            printf("Invalid choice. That space is already occupied.\n");
        }else{
            board[row][col] = val;
            if(done == true){
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
