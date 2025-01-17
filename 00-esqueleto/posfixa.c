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

  posfixa.c
  Pitao II

  Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
  de aula, caso você tenha utilizado alguma refência, liste-as abaixo
  para que o seu programa não seja considerada plágio.
  Exemplo:

  - função mallocc retirada de: 

  http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

/*
  NAO EDITE OU MODIFIQUE NADA QUE ESTA ESCRITO NESTE ESQUELETO
*/

/*------------------------------------------------------------*/
/* iterface para o uso da funcao deste módulo */
#include "posfixa.h"

/*------------------------------------------------------------*/
#include "categorias.h" /* Categoria, MAX_OPERADORES, INDEFINIDA, 
                           ABRE_PARENTESES, ... */
#include "objetos.h" /* tipo CelObjeto, freeObjeto(), freeListaObjetos() */
#include "stack.h"   /* stackInit(), stackFree(), stackPop() 
                        stackPush(), stackTop() */

/*-------------------------------------------------------------
 *  infixaParaPosfixa
 * 
 *  Recebe uma lista ligada com cabeca INIINFIXA representando uma
 *  fila de itens de uma expressao infixa e RETORNA uma lista ligada
 *  com cabeca contendo a fila com a representacao da correspondente
 *  expressao em notacao posfixa.
 */
 /*  As celulas da notacao infixa que nao forem utilizadas na notacao 
  *  posfixa (abre e fecha parenteses) devem ser liberadas 
  *  (freeObjeto()).
  */
CelObjeto * infixaParaPosfixa(CelObjeto *iniInfixa) {
    CelObjeto *aux, *ini, *fim, *proximo;
    Stack pilha = stackInit();
    ini = iniInfixa;
    fim = ini;
    aux = iniInfixa->prox;
    while (aux != NULL) {
        proximo = aux->prox;
        if (aux->categoria == FECHA_PARENTESES) {
            while (stackTop(pilha)->categoria != ABRE_PARENTESES) {
                fim->prox = stackPop(pilha);
                fim = fim->prox;
            }
            freeObjeto(aux);
            freeObjeto(stackPop(pilha));
        }
        else if (aux->categoria != FLOAT && aux->categoria != ID) {
            if (aux->categoria != ABRE_PARENTESES) {
                if (aux->categoria != OPER_MENOS_UNARIO && aux->categoria != OPER_EXPONENCIACAO && aux->categoria != OPER_INDEXACAO && aux->categoria != OPER_LOGICO_NOT && aux->categoria != OPER_ATRIBUICAO)      
                    while (!stackEmpty(pilha) && stackTop(pilha)->categoria != ABRE_PARENTESES && aux->valor.vInt <= stackTop(pilha)->valor.vInt) {
                        fim->prox = stackPop(pilha);
                        fim = fim->prox;
                    }
                else 
                    while (!stackEmpty(pilha) && stackTop(pilha)->categoria != ABRE_PARENTESES && aux->valor.vInt < stackTop(pilha)->valor.vInt) {
                        fim->prox = stackPop(pilha);
                        fim = fim->prox;
                    }
            }
            stackPush(pilha, aux);
        }
        else {
            fim->prox = aux;
            fim = fim->prox;
        }
        aux = proximo;
    }
    while (!stackEmpty(pilha)) {
        fim->prox = stackPop(pilha);
        fim = fim->prox;
    }

    fim->prox = NULL;
    stackFree(pilha);
    return ini;
}
