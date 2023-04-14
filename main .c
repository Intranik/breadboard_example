#include <stdio.h>

// Own includes
#include "board.h"

// Print menu
void print_menu(){
    printf("****MENU FOR BOARD****\n");
    printf("1. Add resistor\n");
    printf("2. Remove resistor\n");
    printf("3. Show resistors\n");
    printf("4. Print board\n");
    printf("5. Exit\n");
    printf("Pick a choice: ");
}

int main(){

    int board[LENGTH][WIDTH] = {0}; // {0} inits array with 0 values equalts to init_board()
    int input = 0;
    int running = 1;
    int x1, x2, y1, y2 = 0;

    //init_board(board);

    // while(1) = while(true)
    while(running){
        print_menu();
        scanf("%d", &input);

        switch(input){
            case 1:
                printf("Give x1 y1 x2 y2\n");
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                printf("Adding resistor\n");
                add_resistor(x1, y1, x2, y2, board);
                print_board(board);
            break;
            case 2:
                printf("Give x1 y1 x2 y2\n");
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                printf("Removing resistor\n");
                remove_resistor(x1, y1, x2, y2, board);
                print_board(board);
            break;
            case 3:
                show_resistor(board);
            break;
            case 4:
                print_board(board);
            break;
            case 5:
                running = 0;
            break;
            default:
                printf("Wrong input");
        }
    }

    return 0;
}