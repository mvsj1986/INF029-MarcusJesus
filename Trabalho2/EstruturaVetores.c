#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

c vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;
    int aux = posicao - 1;
    
    if(validarPosicao(posicao)==0){
        // se posição é um valor válido {entre 1 e 10}
        retorno = POSICAO_INVALIDA;
    }else if(vetorPrincipal[aux].p != NULL){
        // Na posicao já existe estrutura auxiliar
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }else if(tamanho < 1){
        // o tamanho nao pode ser menor que 1
        retorno = TAMANHO_INVALIDO;
    }else{
        int *a = (int*) malloc(tamanho * sizeof(int));
        if(a == NULL){
            // o tamanho ser muito grande
            retorno = SEM_ESPACO_DE_MEMORIA;
        }else{
            // deu tudo certo, crie
            retorno = SUCESSO;
            vetorPrincipal[aux].p = a;
            vetorPrincipal[aux].tamanho = tamanho;
            inicializarEstruturaAux(posicao, tamanho);
        }
    }

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int aux = posicao - 1;
    int tamanho = vetorPrincipal[aux].tamanho;
    int existeEstruturaAuxiliar = procurarEstruturaAux(posicao);
    int temEspaco = posicaoAuxiliarVazia(posicao, tamanho);
    int posicao_valida = validarPosicao(posicao);

    if (!posicao_valida)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar)
        {
            if (temEspaco)
            {
                //insere
                retorno = SUCESSO;
                inserirValor(valor, aux);
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = 0;
    int aux = posicao - 1;
    int posicao_valida = validarPosicao(posicao);
    int existeEstruturaAuxiliar = procurarEstruturaAux(posicao);

    if (!posicao_valida){
        retorno = POSICAO_INVALIDA;
    }else{
        if(existeEstruturaAuxiliar){
            if (vetorPrincipal[aux].p[0] != 0){
                //exclui
                retorno = SUCESSO;
                excluirUltimo(aux);
            }else{
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }
        }else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int fim;
    int aux = posicao - 1;
    int posicao_valida = validarPosicao(posicao);
    int existeEstruturaAuxiliar = procurarEstruturaAux(posicao);

    if (!posicao_valida){
        retorno = POSICAO_INVALIDA;
    }else{
        if(existeEstruturaAuxiliar){
            if (vetorPrincipal[aux].p[0] != 0){
                //exclui
                fim = exclusaoEspecifica(aux, valor);
                
                if (fim == 1) retorno = SUCESSO;
                else retorno = NUMERO_INEXISTENTE;
            }else{
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }
        }else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int retorno = 0;
    int aux = posicao - 1;
    int existeEstruturaAuxiliar = procurarEstruturaAux(posicao);
    int tamanho = sizeof(&vetorAux) / sizeof(vetorAux[0]);
    
    if(ehPosicaoValida(posicao)==-5){
        retorno = POSICAO_INVALIDA;
    }else{
        if(existeEstruturaAuxiliar){
            for(int i = 0; i < tamanho; i++){
                vetorAux[i] = vetorPrincipal[aux].p[i];
                if(vetorAux[i] == -997) vetorAux[i] = 0;
            }
            retorno = SUCESSO;
        }else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int retorno = 0;
    int aux = posicao - 1;
    int existeEstruturaAuxiliar = procurarEstruturaAux(posicao);
    int tamanho = sizeof(&vetorAux) / sizeof(vetorAux[0]);

    if(ehPosicaoValida(posicao)==-5){
        retorno = POSICAO_INVALIDA;
    }else{
        if(existeEstruturaAuxiliar){
            for(int i = 0; i < tamanho; i++){
                vetorAux[i] = vetorPrincipal[aux].p[i];
                if(vetorAux[i] == -997) vetorAux[i] = 0;
            }
            insertionSort(tamanho, vetorAux);
            retorno = SUCESSO;
        }else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    return retorno;
}

/*FUNÇÕES CONCLUIDAS ACIMA*/

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int retorno = 0;
    int estrutVazias = estruturasVazias();
    int k = 0;

    if(estrutVazias){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }else{
        for(int i = 0; i < TAM; i++){
            if(vetorPrincipal[i].p != NULL && vetorPrincipal[i].p[0] != 0){
                for(int j = 0; j < vetorPrincipal[i].tamanho; j++){
                    if(vetorPrincipal[i].p[j] != 0){
                        vetorAux[k] = vetorPrincipal[i].p[j];
                        k++;
                    }
                }
            }
        }
        for(int i = 0; i < k; i++){
            if(vetorAux[i] == -997) vetorAux[i] = 0;
        }
        retorno = SUCESSO;
    }
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int retorno = 0;
    int estrutVazias = estruturasVazias();
    int k = 0;
    int tamanho = sizeof(&vetorAux) / sizeof(vetorAux[0]);

    if(estrutVazias){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }else{
        for(int i = 0; i < TAM; i++){
            if(vetorPrincipal[i].p != NULL){
                for(int j = 0; j < vetorPrincipal[i].tamanho; j++){
                    if(vetorPrincipal[i].p[j] != 0){
                        vetorAux[k] = vetorPrincipal[i].p[j];
                        k++;
                    }
                }
            }
        }
        for(int i = 0; i < k; i++){
            if(vetorAux[i] == -997) vetorAux[i] = 0;
        }
        insertionSort(tamanho, vetorAux);
        retorno = SUCESSO;
    }
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    int retorno = 0;
    int* p;
    int aux = posicao - 1;
    int antigoTamanho = vetorPrincipal[aux].tamanho;
    int posicao_valida = validarPosicao(posicao);
    int existeEstruturaAuxiliar = procurarEstruturaAux(posicao);

    if(novoTamanho < 0){
        retorno = NOVO_TAMANHO_INVALIDO;
    }else{
        if(!posicao_valida){
            retorno = POSICAO_INVALIDA;
        }else{
            if(existeEstruturaAuxiliar){
                novoTamanho += antigoTamanho;
                p = (int*) realloc(vetorPrincipal[aux].p, novoTamanho * sizeof(int));

                if(p != NULL){
                    vetorPrincipal[aux].p = p;
                    retorno = SUCESSO;
                }else{
                    retorno = SEM_ESPACO_DE_MEMORIA;
                }
            }else{
                retorno = SEM_ESTRUTURA_AUXILIAR;
            }
        }
    }
    
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
    int retorno = 0;
    int aux = posicao - 1;
    int posicao_valida = validarPosicao(posicao);
    int existeEstruturaAuxiliar = procurarEstruturaAux(posicao);

    if(posicao_valida){
        if(existeEstruturaAuxiliar){
            for(int i = 0; i < vetorPrincipal[aux].tamanho; i++){
                if(vetorPrincipal[aux].p[i] != 0 && vetorPrincipal[aux].p[i] != -997){
                    retorno++;
                }
            }
        }else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }else{
        retorno = POSICAO_INVALIDA;
    }
    
    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote(){
    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

int validarPosicao(int num){
    if(num < 1 || num >10) return 0;
    else return 1;
}

int procurarEstruturaAux(int posicao){
    int i = posicao - 1;
    if(vetorPrincipal[i].p == NULL) return 0;
    else return 1;
}

void inicializarEstruturaAux(int posicao, int tamanho){
    int j = posicao - 1;
    for(int i = 0; i < tamanho; i++){
        vetorPrincipal[j].p[i] = 0;
    }
}

int posicaoAuxiliarVazia(int posicao, int tamanho){
    int j = posicao - 1;
    int retorno = 0;
    
    for(int i = 0; i < tamanho; i++){
        if(vetorPrincipal[j].p[i] == 0) retorno = 1;
    }
    return retorno;
}

void inserirValor(int valor, int aux){
    int tamanho = vetorPrincipal[aux].tamanho;
    int feito = 0;
    int i = 0;
    
    if(valor==0) valor = -997;
    
    do{
        if(vetorPrincipal[aux].p[i] == 0){
            vetorPrincipal[aux].p[i] = valor;
            feito = 1;
        }
        i++;
    } while(feito == 0);
}

void excluirUltimo(int posicao){
    int j;
    int i = 1;
    int feito = 0;

    do{
        j = i - 1;
        if(vetorPrincipal[posicao].p[i]==0){
            vetorPrincipal[posicao].p[j]=0;
            feito = 1;
        }else{
            i++;
        }
    } while(feito == 0);
}

int exclusaoEspecifica(int posicao, int valor){
    int fim = 0;
    int pos = -1;
    int i = 0;
    int tamanho = vetorPrincipal[posicao].tamanho;

    do{
        if(vetorPrincipal[posicao].p[i] == valor){
            pos = i;
        }else{
            i++;
        }
    }while(pos == -1 && i < tamanho);

    if(pos != -1){
        for(i = pos; i < tamanho - 1; i++){
            vetorPrincipal[posicao].p[i] = vetorPrincipal[posicao].p[i+1];
        }
        vetorPrincipal[posicao].p[tamanho-1] = 0;
        fim = 1;
    }
    
    return fim;
}

void insertionSort(int tamanho, int vetor[]){
    int chave, i, j;
    
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;
        
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        
        vetor[j + 1] = chave;
    }
}

int estruturasVazias(){
    for(int i = 0; i < 10; i++){
        if(vetorPrincipal[i].p != NULL) return 0;
    }
    return 1;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/
void inicializar(){
    for(int i = 0; i < TAM; i++) {
        vetorPrincipal[i].p = NULL;
        vetorPrincipal[i].tamanho = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/
void finalizar(){
    for(int i = 0; i < TAM; i++){
        vetorPrincipal[i].tamanho = 0;
        free(vetorPrincipal[i].p);
    };
}