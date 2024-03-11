/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * 
 * FILA com alocacao estatica
 */

#include<stdio.h>
#include<stdlib.h>

#define N 10    // Definicao de constante que determina a capacidade da fila

//Definicao do tipo abstrato de dado que representa a estrutura FILA
struct est_fila {
    int fila[N];    //Vetor que representa a fila (estatico)
    int contador;   //Contador para controle da estrutura
};
typedef struct est_fila tipo_fila;

//Prototipo das funcoes
void insereFila(tipo_fila*, int);
int removeFila(tipo_fila*);
void imprimeFila(tipo_fila);

/***
 * Funcao que insere um novo valor na fila.
 * Parametros: *tipo_fila fl
 *		int valor
 * Retorno: void
 */
void insereFila(tipo_fila *fl, int valor) {
    int posicao;
    if ( fl->contador < N ) {
        //fl->fila[ fl->contador++ ] = valor;
        posicao = fl->contador;
        fl->fila[posicao] = valor;
        fl->contador += 1;
    } else {
        printf("[ERRO] Fila cheia. Valor nao inserido.\n");
    }
}

/***
 * Funcao que remove o primeiro valor da fila. Se a fila
 * estah vazia, retorna -1 como valor de erro.
 * Parametros:  tipo_fila *fl
 * Retorno: (int) valor removido da vila
*/
int removeFila(tipo_fila *fl) {
    int valor, i;
    //Verifica se a fila estah vazia
    if ( fl->contador == 0) {
        printf("[ERRO] Fila vazia, nao eh possivel remover valor.\n");
        return -1; //Retorna -1 como código de erro, nao foi possivel remover valor
    } else { //Contexto em que ocorre a remocao do primeiro valor
        valor = fl->fila[0]; //Guarda o valor primeiro da fila
        //Reposiciona os valores da fila
        for (i=0; i < fl->contador - 1; i++) //vai ateh a penultima posicao
            fl->fila[i] = fl->fila[i+1];
        fl->contador--; //decrementa o contador
        return valor; //retorna o valor removido 
    }

}


/***
 * FUncao que imprime a fila.
 * Parametro: tipo_fila fl
 * Retorno: void
 */
void imprimeFila(tipo_fila fl) {
    int i;
    printf("FILA: <- [ ");
    
    for (i=0; i<fl.contador; i++) {
        printf("%d ", fl.fila[i]);
    }
    printf("] <-\n");
}



int main() {
    tipo_fila minha_fila;
    int valor;

    //Inicializa o contador da fila
    minha_fila.contador = 0;

    insereFila(&minha_fila, 7); //Insere o valor 7 na fila
    insereFila(&minha_fila, 1); //Insere o valor 1 na fila
    insereFila(&minha_fila, 3); //Insere o valor 3 na fila
    insereFila(&minha_fila, 9); //Insere o valor 9 na fila

    imprimeFila(minha_fila);

    valor = removeFila(&minha_fila);
    printf("Valor removido da fila = %d\n", valor);
    valor = removeFila(&minha_fila);
    printf("Valor removido da fila = %d\n", valor);

    imprimeFila(minha_fila);
    
    return EXIT_SUCCESS;
}






