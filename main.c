#include <stdio.h>
#include <stdlib.h>

/* Matriz do jogo */
char game[3][3];
/* Inicializa a matriz */
void init();
/* Mostra a matriz na tela */
void display();
/* Obtem uma jogada do usuário */
void player_move();
/* Obtem uma jogada do computador */
void computer_move();
/* Checa se tem um vencedor */
int win(char xo);


int main(void) {
    char stop = 'n';
    printf("Jogo da velha\n");
    /* primeiro inicia a matriz
    entra no loop e mostra a matriz
    obtem uma jogada do usuário
    se alguém ganhar, mostra a matriz e para o loop */
    init();
    do {
        display();
        player_move();
        computer_move();
        if(win('X')) {
            display();
            printf("Você ganhou!\n");
            stop = 'y';
        } else if(win('O')) {
            display();
            printf("Você perdeu!\n");
            stop = 'y';
        }
    } while(stop == 'n');
    return 0;
}

void init() {
    /* preenche a matriz com espaços */
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) game[i][j] = ' ';
}

void display() {
    /* mostra a matriz na tela, inicialmente mostra os espaços, a cada jogada
    o espaço é ocupado */
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", game[i][0], game[i][1], game[i][2]);
        if(i != 2) printf("---|---|---\n");
    }
    printf("\n");
}

void player_move() {
    int coordx, coordy;
    printf("Entre com as coordenadas do X (0 0, 1 0, 2 1): ");
    scanf("%d%d", &coordx, &coordy);
    game[coordx][coordy] = 'X';
}

void computer_move() {
    /* TODO: refazer, código retirado do livro */
    int i, j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++)
		    if(game[i][j] == ' ') break;
		if(game[i][j] == ' ') break;
	}
	if(i * j == 9) {
		printf("empate\n");
		exit(0);
	}
	else game[i][j] = 'O';
}

int win(char xo) {
    /* TODO: arrumar essa gambita usando laços */
    /* checa as combinações verticais */
    if(game[0][0] == xo && game[1][0] == xo && game[2][0] == xo) return 1;
    else if(game[0][1] == xo && game[1][1] == xo && game[2][1] == xo) return 1;
    else if(game[0][2] == xo && game[1][2] == xo && game[2][2] == xo) return 1;
    /* checa as combinações horizontais */
    else if(game[0][0] == xo && game[0][1] == xo && game[0][2] == xo) return 1;
    else if(game[1][0] == xo && game[1][1] == xo && game[1][2] == xo) return 1;
    else if(game[2][0] == xo && game[2][1] == xo && game[2][2] == xo) return 1;
    /* testa as diagonais */
    else if(game[0][0] == xo && game[1][1] == xo && game[2][2] == xo) return 1;
    else if(game[0][2] == xo && game[1][1] == xo && game[2][0] == xo) return 1;
    return 0;
}