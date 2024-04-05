#include "2-structs.h"

// Chamada das funções principais

void iniciarListas(pessoa *listaAluno, pessoa *listaProfessor, disciplina *listaDisciplina, turma *listaTurma);

//Criar:
int cadastros(void);
int cadastrarAluno(void);
int cadastrarProfessor(void);
int cadastrarDisciplina(void);
int matricularEmTurma(void);

//Ler:

int listar(void);
int menuRelatoriosAlunos(pessoa *listaAluno);
int menuRelatoriosProfessor(pessoa *listaProfessor);
int listarTotal(pessoa *lista);
int ordenarPorSexo(pessoa *lista);
int ordenarPorNome(pessoa *lista);
int ordenarPorDataNascimento(pessoa *lista);
int listarDisciplina(disciplina *lista);
int listarTurma(turma *lista);

//Atualizar:

int atualizarCadastros(void);

//Deletar:

int deletarCadastros(void);
