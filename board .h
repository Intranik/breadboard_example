#define LENGTH 10
#define WIDTH 6

#define START_RESISTOR 1
#define IN_RESISTOR 2
#define END_RESISTOR 3


void init_board(int board[LENGTH][WIDTH]);
void print_board(int board[LENGTH][WIDTH]);

int add_resistor(int x1, 
                 int y1, 
                 int x2, 
                 int y2, 
                 int board[LENGTH][WIDTH]);

int remove_resistor(int x1, 
                    int y1, 
                    int x2, 
                    int y2, 
                    int board[LENGTH][WIDTH]);

void show_resistor(int board[LENGTH][WIDTH]);

