#include <stdio.h>

char tabuleiro[3][4];
char jogador_inicial;
char adversario;

int checa_vitoria(char p) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == p && tabuleiro[i][1] == p && tabuleiro[i][2] == p) return 1;
        if (tabuleiro[0][i] == p && tabuleiro[1][i] == p && tabuleiro[2][i] == p) return 1;
    }
    if (tabuleiro[0][0] == p && tabuleiro[1][1] == p && tabuleiro[2][2] == p) return 1;
    if (tabuleiro[0][2] == p && tabuleiro[1][1] == p && tabuleiro[2][0] == p) return 1;
    
    return 0;
}

int checa_empate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == '.') return 0;
        }
    }
    return 1;
}

int minimax(int is_maximizing) {
    if (checa_vitoria(jogador_inicial)) return 1;
    if (checa_vitoria(adversario)) return -1;
    if (checa_empate()) return 0;

    if (is_maximizing) {
        int melhor_pontuacao = -9999;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tabuleiro[i][j] == '.') {
                    tabuleiro[i][j] = jogador_inicial;
                    int pontuacao = minimax(0);
                    tabuleiro[i][j] = '.';
                    
                    if (pontuacao > melhor_pontuacao) {
                        melhor_pontuacao = pontuacao;
                    }
                }
            }
        }
        return melhor_pontuacao;
        
    } else {
        int melhor_pontuacao = 9999;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tabuleiro[i][j] == '.') {
                    tabuleiro[i][j] = adversario;
                    int pontuacao = minimax(1);
                    tabuleiro[i][j] = '.';
                    
                    if (pontuacao < melhor_pontuacao) {
                        melhor_pontuacao = pontuacao;
                    }
                }
            }
        }
        return melhor_pontuacao;
    }
}

int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%s", tabuleiro[i]);
    }
    
    char str_vez[2];
    scanf("%s", str_vez);
    jogador_inicial = str_vez[0];
    
    if (jogador_inicial == 'X') {
        adversario = 'O';
    } else {
        adversario = 'X';
    }

    int resultado = minimax(1);

    if (resultado == 1) {
        printf("VITORIA\n");
    } else if (resultado == -1) {
        printf("DERROTA\n");
    } else {
        printf("EMPATE\n");
    }

    return 0;
}