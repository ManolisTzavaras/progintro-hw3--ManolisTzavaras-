#include <stdio.h>

int main() {
    char board[5][5];
    char userCol;
    int userRow, r, c;
    int turn = 0;

    
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            board[r][c] = '.';
        }
    }

    while (1) {
        
        printf("\n  A B C D E\n");
        for (r = 0; r < 5; r++) {
            printf("%d ", 5 - r); 
            for (c = 0; c < 5; c++) {
                printf("%c ", board[r][c]); 
            }
            printf("%d\n", 5 - r);
        }
        printf("  A B C D E\n");

        
        char marker = (turn % 2 == 0) ? 'X' : 'O';
        printf("\nPaiktis %c, dwse kinhsh (p.x. C 3): ", marker);
        scanf(" %c %d", &userCol, &userRow);

        
        int targetCol = userCol - 'A';
        int targetRow = 5 - userRow;

        
        if (targetCol >= 0 && targetCol < 5 && targetRow >= 0 && targetRow < 5) {
            board[targetRow][targetCol] = marker; 
            turn++;
        } else {
            printf("Lathos syntetagmenes! Dokimaste ksana.\n");
        }
    }

    return 0;
}
