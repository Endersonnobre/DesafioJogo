#include <stdio.h>

char board[3][3]; // Matriz para armazenar o estado atual do jogo

// Função para inicializar o tabuleiro
void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Função para exibir o tabuleiro
void display_board() {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

// Função para verificar se alguém ganhou ou o jogo empatou
char check_win() {
    int i;
    // Verifica linhas e colunas
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    // Verifica diagonais
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];
    // Verifica se houve empate
    for (i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return ' ';
        }
    }
    return 'D'; // Empate
}

int main() {
    int row, col;
    char player = 'X';
    char winner;

    initialize_board();

    printf("Bem-vindo ao Jogo da Velha!\n");
    printf("Jogador 1: X\n");
    printf("Jogador 2: O\n\n");

    while (1) {
        display_board();

        // Alternando entre jogadores
        if (player == 'X')
            printf("Jogador 1 (X), digite a linha e coluna que deseja jogar: ");
        else
            printf("Jogador 2 (O), digite a linha e coluna que deseja jogar: ");

        scanf("%d %d", &row, &col);

        // Verificando se a entrada está dentro dos limites do tabuleiro
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Entrada inválida. Tente novamente.\n");
            continue;
        }

        // Verificando se a posição escolhida está vazia
        if (board[row-1][col-1] != ' ') {
            printf("Esta posição já está ocupada. Tente novamente.\n");
            continue;
        }

        // Atualizando o tabuleiro com a jogada
        board[row-1][col-1] = player;

        // Verificando se há um vencedor ou empate
        winner = check_win();
        if (winner != ' ') {
            display_board();
            if (winner == 'D')
                printf("O jogo terminou em empate!\n");
            else
                printf("Parabéns, Jogador %c! Você venceu!\n", winner);
            break;
        }

        // Alternando o jogador
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}