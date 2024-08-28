#include <stdio.h>
#include <conio.h> // com essa função vamos ler as entradas do teclado
#include <windows.h> 

#define ROWS 20 // linhas
#define COLS 10 // colunas

//Essa é uma função construida de forma auxiliar, ela recebe uma matriz e printa no terminal
void printMatrix(char matrix[ROWS][COLS]) {
    //como essa matriz vai se impressa várias vezes, sempre tem que limpar a tela para que
    //a nova amtriz possa ser impressa "no mesmo lugar" da anterior e dar a sensação de 
    //movimento 
    system("cls");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

int movimentation(int x){
    if (_kbhit()) { //essa função verifica se alguma tecla foi pressionada
        char tecla = _getch(); //essa função capta qual foi a tecla

        if (tecla == 'a' && x > 0) {
            //Se a tecla pressionada foi o A, então move para a esquerda decrescendo o valor
            //de posição da coluna
            x--;
        }else if (tecla == 'd' && x < COLS - 1) {
            //Se a tecla pressionada foi o D, então move para a direita crescendo o valor
            //de posição da coluna
            x++;
        }
    }

    return x;
}

int main() {
    //criando uma matriz
    char matrix[ROWS][COLS];
    // Inicializa a matriz com espaços em branco
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = ' ';
        }
    }

    int pos_initial_COLS = 5; // A posicao inicial na coluna é 5
    int pos_initial_ROWS = 0; // Posição inicial na linha é 0

    //criação do laço de repetição onde o codigo vai realmente funcionar
    while (1) {
        // Verifica sempre se a bolinha está na primeira linha, caso não esteja ele limpa
        //  a linha anteior
        if (pos_initial_ROWS > 0) {
            matrix[pos_initial_ROWS-1][pos_initial_COLS] = ' ';
        }

        // Atualiza a posição do ponto
        //o ponto começa na posição [0][5]
        matrix[pos_initial_ROWS][pos_initial_COLS] = 'O';

        // Imprime a matriz
        printMatrix(matrix);

        // Aqui faz a incrementação da linha para que a bola possa pecorre a matriz para baixo
        pos_initial_ROWS++;

        //Se a posição ininicial da linha é igual a quantidade de linhas determinadas então
        //então chegou ao fundo, saindo do while
        if (pos_initial_ROWS == ROWS) {
            break;
        }

        //Aqui é onde a "Mágica" acontece para o movimento acontecer
        //O movimento basicamente se baseia em trocar a bolinha de coluna
        int result = movimentation(pos_initial_COLS);

        if(result != pos_initial_COLS){ 
            //no momento estou criando uma forma de apagar os "rastros"
            pos_initial_COLS = result;
            matrix[pos_initial_ROWS-1][pos_initial_COLS] = ' ';
        }

        // Pequena pausa para controlar a velocidade da queda
        _sleep(300);
    }

    printf("O ponto chegou ao fundo da matriz.\n");

    return 0;
}
