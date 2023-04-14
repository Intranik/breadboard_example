#include <stdio.h>

// Own includes
#include "board.h"

// Initialize the board
void init_board(int board[LENGTH][WIDTH]){

    for(int i = 0 ; i < LENGTH; i++){
         for(int j = 0 ; j < WIDTH; j++){
             board[i][j] = 0;
        }
    }
}

// Print the board
void print_board(int board[LENGTH][WIDTH]){

    for(int i = 0 ; i < LENGTH; i++){
         for(int j = 0 ; j < WIDTH; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_if_resistor_exists(int x1, 
                             int x2, 
                             int y, 
                             int board[LENGTH][WIDTH]){

    for (int i = x1 ; i <= x2; i++){
        if(board[y][i] == START_RESISTOR ||
           board[y][i] == IN_RESISTOR ||
           board[y][i] == END_RESISTOR
           ){
               return 1;
           }
    }

    return 0;
}

int resistor_points_checks(int x1, 
                           int y1, 
                           int x2, 
                           int y2, 
                           int board[LENGTH][WIDTH]){

    // Check all points to be inside the board
    if( (x1 >= WIDTH || x1 < 0) ||
        (x2 >= WIDTH || x2 < 0 ) ||
        (y1 >= LENGTH || y1 < 0 ) ||
        (y2 >= LENGTH || y2 < 0)
    ){
        printf("out of bound points, x1: %d  x2: %d  y1: %d  y2: %d\n", x1, x2, y1, y2);
        return 1;
    }

    // Check if we are trying to add resistor in same horisontell point
    if( x1 == x2 || x1 > x2){
        printf("check x1 and x2, x1: %d  x2: %d  y1: %d  y2: %d\n", x1, x2, y1, y2);
        return 1;
    }

    // Check if we are trying to add resistor in the same line
    if(y1 != y2){
        printf("y1 must be equals y2, x1: %d  x2: %d  y1: %d  y2: %d\n", x1, x2, y1, y2);
        return 1;
    }

    return 0;
}

// Adds resistor to the board
// Takes in two points
int add_resistor(int x1, 
                 int y1, 
                 int x2, 
                 int y2, 
                 int board[LENGTH][WIDTH]){
    
    if(resistor_points_checks(x1, y1, x2,y2, board)){
        printf("Failed to add resistor\n");
        return 1;
    }

    if(check_if_resistor_exists(x1, x2, y1, board)){
        printf("Failed to add resistor, resitor already exsits in points, x1: %d  x2: %d  y1: %d  y2: %d\n", x1, x2, y1, y2);
        return 1;
    }

    // Add resistor start and end
    board[y1][x1] = START_RESISTOR;
    board[y1][x2] = END_RESISTOR;

    // Fill mid resistor if needed
    for (int i = x1 + 1; i < x2; i++){
        board[y1][i] = IN_RESISTOR;
    }

    return 0;
}

int remove_resistor(int x1, 
                    int y1, 
                    int x2, 
                    int y2, 
                    int board[LENGTH][WIDTH]){
    
    if(resistor_points_checks(x1, y1, x2, y2, board)){
        printf("Failed to remove resistor\n");
        return 1;
    }

    if(board[y1][x1] != START_RESISTOR ||
       board[y1][x2] != END_RESISTOR){
        
        printf("Failed to remove resistor, no resistor exsits in x1: %d  x2: %d  y1: %d  y2: %d\n", x1, x2, y1, y2);
    }

    for (int i = x1 ; i <= x2; i++){
        board[y1][i] = 0;
    }

    return 0;
}

void show_resistor(int board[LENGTH][WIDTH]){

    int resistor_count = 0;
    int combined_length = 0;

    for(int i = 0 ; i < LENGTH; i++){
         for(int j = 0 ; j < WIDTH; j++){
            if(board[i][j] == START_RESISTOR){
                resistor_count++;
                combined_length++;
            }
            else if(board[i][j] == IN_RESISTOR ||
               board[i][j] == END_RESISTOR){
                combined_length++;
            }
        }
    }

    printf("There are %d resistors on the board. Their combined length is %d\n", resistor_count, combined_length);
}

/*int main(){

    int board[LENGTH][WIDTH];
    //char board[WIDTH][LENGTH];
    init_board(board);
    print_board(board);

    add_resistor(0, 1, 5, 1, board);    
    add_resistor(0, 9, 5, 9, board);
    
    remove_resistor(0, 1, 5, 1, board); 

    print_board(board);
    show_resistor(board);
    return 0;
}*/