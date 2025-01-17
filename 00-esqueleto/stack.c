/*
  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__

  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP, 
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA. 
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM 
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES DESSE EP
  E QUE PORTANTO NÃO CONSTITUEM PLÁGIO. DECLARO TAMBÉM QUE SOU RESPONSÁVEL
  POR TODAS AS CÓPIAS DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO SÃO PUNIDOS COM 
  REPROVAÇÃO DIRETA NA DISCIPLINA.

  Nome:

  stack.c
  Pitao II

  Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
  de aula, caso você tenha utilizado alguma refência, liste-as abaixo
  para que o seu programa não seja considerada plágio.

  Exemplo:
  - função mallocc retirada de: 
 
  http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

/* interface para o uso de uma pilha */
#include "stack.h" 
#include <stdlib.h>
/* 
 * 
 * STACK.c: IMPLEMENTACAO DE UMA PILHA 
 *
 * TAREFA EP3
 *
 * Faca aqui a implementacao de uma pilha atraves de uma 
 * __lista encadeada com cabeca__. 
 * 
 * A implementacao deve respeitar a interface que voce declarar em 
 * stack.h. 
 *
 * TAREFA EP4: copiar a implementacao feira para o EP3.
 *     E possivel que sua implementacao para o EP3 deve ser 
 *     adaptada, ja que agora a pilha de execucao pode conter
 *     nomes de variaveis e nao apenas valores double.
 *
 */

Stack stackInit() {
    Stack pilha = mallocSafe(sizeof(CelObjeto));
    pilha->categoria = INDEFINIDA;
    pilha->valor.pStr = NULL;
    pilha->prox = NULL;
    return pilha;
}

int stackEmpty(Stack pilha) {
    return (pilha->prox == NULL);
}

void stackPush(Stack pilha, CelObjeto *celula){
    CelObjeto *aux;

    aux = pilha->prox;
    celula-> prox = aux;
    pilha->prox = celula;
}

CelObjeto* stackPop(Stack pilha) {
    CelObjeto *objeto;

    objeto = pilha->prox;
    pilha->prox = objeto->prox;
    objeto->prox = NULL;
    return objeto;
}

CelObjeto* stackTop(Stack pilha) {
    return pilha->prox;
}

void stackFree(Stack pilha) {
    Stack aux;
    while (pilha != NULL) {
        aux = pilha->prox;
        freeObjeto(pilha);
        pilha = aux;
    }

}

void stackDump(Stack pilha) {
    Stack aux;
    for (aux = pilha->prox; aux != NULL; aux = aux->prox)
        if (aux->categoria == FLOAT)
            printf("  %.6f\n", aux->valor.vFloat);
        else 
            printf("  %s\n", aux->valor.pStr);
}