#include <stdio.h>
#include "3-functions.h"
#include "2-structs.h"

#define TAM_MAX 3

pessoa listaAluno[TAM_MAX];
pessoa listaProfessor[TAM_MAX];
disciplina listaDisciplina[TAM_MAX];
turma listaTurma[TAM_MAX];

int main() {
  int opcao;

  // tela inicial.
  printf("Bem vindo ao sistema Escolar - Projeto Escola\n\nEscolha Uma "
         "Opção:\n\n");
  printf("[1] - Cadastrar\n[2] - Relatórios\n[3] - Atualizar\n\nOPCAO: ");
  scanf("%d", &opcao);
  // fgets();

  if (opcao == 1) {
    cadastros();
  } else if (opcao == 2) {
    listar();
  } else if (opcao == 3) {
    atualizarCadastros();
  }

  return 0;
}

// Criar:

int cadastros() {
  int aux;

  printf("Projeto Escola - CADASTROS\nCadastrar:\n\n");
  printf("[1] - Alunos\n[2] - Professores");
  printf("\n[3] - Disciplinas\n[4] - Turma\n\nOPCAO: ");
  scanf("%d", &aux);

  if (aux == 1) {
    cadastrarAluno();
  } else if (aux == 2) {
    cadastrarProfessor();
  } else if (aux == 3) {
    cadastrarDisciplina();
  } else if (aux == 4) {
    matricularEmTurma();
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

  for (int i = 0; i < TAM_MAX; i++) {
    printf("%d\n", listaProfessor[i].matricula);
  }
  printf("\n\nCadastro de professor");
  printf("\nDigite o nome do professor");

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

  return 0;
}

int listarTotal() { return 0; }
int ordenarPorSexo() { return 0; }
int ordenarPorNome() { return 0; }
int ordenarPorDataNascimento() { return 0; }
int listarDisciplina() { return 0; }
int listarTurma() { return 0; }

// Atualizar:

int atualizarCadastros() { return 0; }

// Deletar:
