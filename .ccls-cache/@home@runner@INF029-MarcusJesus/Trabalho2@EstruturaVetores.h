#ifndef TRABALHO2_ESTRUTURAVETORES_H
#define TRABALHO2_ESTRUTURAVETORES_H

/* enumeracoes (enum) ajudam a deixar o codigo mais legivel, possibilitando que
 * voce de significado as suas constantes, para mais informacoes
 * https://en.cppreference.com/w/c/language/enum as constantes do enum em sua
 * inicialização vao representar o numero resultante da soma do valor da
 * constante anterior mais 1, caso nao haja valor algum na primeira constante
 * ela vai ser inicializada com 0 */
enum {
  TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11,
  NOVO_TAMANHO_INVALIDO,
  NUMERO_INEXISTENTE,
  ESTRUTURA_AUXILIAR_VAZIA,
  TAMANHO_INVALIDO,
  SEM_ESPACO_DE_MEMORIA,
  POSICAO_INVALIDA,
  JA_TEM_ESTRUTURA_AUXILIAR,
  SEM_ESTRUTURA_AUXILIAR,
  SEM_ESPACO,
  SUCESSO
};

typedef struct reg {
  int conteudo;
  struct reg *prox;
} No;

typedef struct core {
  int tamanho;
  int *p;
} c;

int criarEstruturaAuxiliar(int posicao, int tamanho);
int inserirNumeroEmEstrutura(int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
No *montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No **inicio);

// funções que eu estou testando...
int validarPosicao(int num);
int procurarEstruturaAux(int posicao);
void inicializarEstruturaAux(int posicao, int tamanho);
int posicaoAuxiliarVazia(int posicao, int tamanho);
void inserirValor(int valor, int aux);
void excluirUltimo(int posicao);
int exclusaoEspecifica(int posicao, int valor);
void insertionSort(int tamanho, int vetor[]);
int estruturasVazias();

void inicializar();
void finalizar();
void dobrar(int *x);

#endif // TRABALHO2_ESTRUTURAVETORES_H