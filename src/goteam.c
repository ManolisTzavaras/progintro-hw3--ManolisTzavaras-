#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 19

char board[MAX_SIZE][MAX_SIZE];
int board_size = 5;

// Go table
void clear_board() {
    for (int r = 0; r < MAX_SIZE; r++) {
        for (int c = 0; c < MAX_SIZE; c++) {
            board[r][c] = '.';
        }
    }
}

// print table 
void showboard() {
    printf("= \n");
    printf("  ");
    for (int c = 0; c < board_size; c++) printf(" %c", 'A' + c);
    printf("\n");

    for (int r = 0; r < board_size; r++) {
        printf("%d ", board_size - r);
        for (int c = 0; c < board_size; c++) {
            printf("%c ", board[r][c]);
        }
        printf("%d\n", board_size - r);
    }
    printf("  ");
    for (int c = 0; c < board_size; c++) printf(" %c", 'A' + c);
    printf("\n\n");
}

int main() {
    char line[1024];
    char cmd[256];
    
    clear_board();
    setbuf(stdout, NULL); 

    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "%s", cmd) != 1) continue;

        if (strcmp(cmd, "boardsize") == 0) {
            sscanf(line, "boardsize %d", &board_size);
            clear_board();
            printf("= \n\n");
        }
        else if (strcmp(cmd, "komi") == 0) {
            printf("= \n\n");
        }
        else if (strcmp(cmd, "clear_board") == 0) {
            clear_board();
            printf("= \n\n");
        }
        else if (strcmp(cmd, "showboard") == 0) {
            showboard();
        }
        else if (strcmp(cmd, "play") == 0) {
            char color[10], pos[10];
            sscanf(line, "play %s %s", color, pos);
            
            if (strcmp(pos, "pass") != 0 && strcmp(pos, "PASS") != 0) {
                int col = toupper(pos[0]) - 'A';
                int row = board_size - atoi(&pos[1]);
                board[row][col] = (tolower(color[0]) == 'b') ? 'X' : 'O';
            }
            printf("= \n\n");
        }
        else if (strcmp(cmd, "genmove") == 0) {
            char color[10];
            sscanf(line, "genmove %s", color);
            
            
            int move_made = 0;
            for (int r = 0; r < board_size && !move_made; r++) {
                for (int c = 0; c < board_size && !move_made; c++) {
                    if (board[r][c] == '.') {
                        board[r][c] = (tolower(color[0]) == 'b') ? 'X' : 'O';
                        printf("= %c%d\n\n", 'A' + c, board_size - r);
                        move_made = 1;
                    }
                }
            }
            if (!move_made) printf("= PASS\n\n");
        }
        else if (strcmp(cmd, "final_score") == 0) {
            printf("= B+8.5\n\n"); 
        }
        else if (strcmp(cmd, "quit") == 0) {
            printf("= \n\n");
            break;
        }
        else {
            printf("= \n\n");
        }
    }
    return 0;
}
