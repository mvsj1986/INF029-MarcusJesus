#include <stdio.h>
#include "functions.h"

#define TAM_MAX 3

pessoa listaAluno[TAM_MAX];
pessoa listaProfessor[TAM_MAX];
disciplina listaDisciplina[TAM_MAX];
turma listaTurma[TAM_MAX];

int main() {
  int contAluno = 0;
  int contProfessor = 0;
  int contDisciplina = 0;
  int contTurma = 0;
  int opcao;

  iniciarListas(listaAluno, listaProfessor, listaDisciplina, listaTurma);
  
  printf("Bem vindo ao sistema Escolar - Projeto Escola\n\nEscolha Uma "
         "Opção:\n\n");
  printf("[1] - Cadastrar\n[2] - Relatórios\n[3] - Atualizar\n\nOPCAO: ");
  scanf("%d", &opcao);

  switch (opcao) {
    case 1: cadastros(); break;
    case 2: listar(); break;
    case 3: atualizarCadastros(); break;
    default: printf("opção invalida");
  }

  return 0;
}

void iniciarListas(pessoa *listaAluno, pessoa *listaProfessor, disciplina *listaDisciplina, turma *listaTurma){
  int i;

  for (i = 0; i < TAM_MAX; i++){
    listaAluno[i].matricula = -1;
    listaProfessor[i].matricula = -1;
    listaDisciplina[i].codigo = -1;
    listaTurma[i].codigo = -1;
  }
}

// Criar:

int cadastros() {
  int aux;

  printf("Projeto Escola - CADASTROS\nCadastrar:\n\n");
  printf("[1] - Alunos\n[2] - Professores");
  printf("\n[3] - Disciplinas\n[4] - Turma\n\nOPCAO: ");
  scanf("%d", &aux);

  switch (aux) {
    case 1: cadastrarAluno(); break;
    case 2: cadastrarProfessor(); break;
    case 3: cadastrarDisciplina(); break;
    case 4: matricularEmTurma(); break;
    default: printf("opção invalida");
  }
  
  return 0;
}

int cadastrarAluno() {

  for (int i = 0; i < TAM_MAX; i++) {
    printf("%d\n", listaAluno[i].matricula);
  }
  printf("\n\n Cadastro de aluno");
  printf("\nDigite o nome do aluno");

  return 0;
}

int cadastrarProfessor(void) {
  char professorNome[50];

  for (int i = 0; i < TAM_MAX; i++) {
    printf("%d\n", listaProfessor[i].matricula);
  }
  printf("\n\nCadastro de professor");
  printf("\nDigite o nome do professor");
  fgets(professorNome, 50, stdin);

  

  return 0;
}

int cadastrarDisciplina() {

  for (int i = 0; i < TAM_MAX; i++) {
    printf("%d\n", listaDisciplina[i].codigo);
  }
  printf("\n\n Cadastro de disciplina");
  printf("\nDigite o nome da discplina");

  return 0;
}

int matricularEmTurma() {
  int codigo;
  int matricula;

  printf("CADASTRO DE ALUNO EM TURMA\n\n Informe o codigo da turma: ");
  scanf("%d", &codigo);

  // criar função para listar os alunos ja matriculados na turma do código
  // recebido

  // Se o aluno não estiver na lista acima
  printf("digite a matricula do aluno a matricular: ");
  scanf("%d", &matricula);

  // ação de registro em vetor listaTurma...

  return 0;
}

// Ler:

int listar() {
  int aux;

  printf("Projeto Escola - RELATORIO\nListar:\n\n");
  printf("[1] - Alunos\n[2] - Professores\n");
  printf("[3] - Disciplinas\n[4] - Turmas\n\nOPCAO: ");
  scanf("%d", &aux);

  switch (aux) {
    case 1: menuRelatoriosAlunos(listaAluno); break;
    case 2: menuRelatoriosProfessor(listaProfessor); break;
    case 3: listarDisciplina(listaDisciplina); break;
    case 4: listarTurma(listaTurma); break;
    default: printf("opção invalida");
  }

  return 0;
}

int menuRelatoriosAlunos(pessoa *listaAluno){ return 0; }
int menuRelatoriosProfessor(pessoa *listaProfessor){ return 0; }
int listarTotal(pessoa *lista) { return 0; }
int ordenarPorSexo(pessoa *lista) { return 0; }
int ordenarPorNome(pessoa *lista) { return 0; }
int ordenarPorDataNascimento(pessoa *lista) { return 0; }
int listarDisciplina(disciplina *listaDisciplina) { return 0; }
int listarTurma(turma *listaTurma) { return 0; }

// Atualizar:

int atualizarCadastros() { return 0; }

// Deletar:
