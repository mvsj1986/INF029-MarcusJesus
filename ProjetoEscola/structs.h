typedef struct{
  int dia;
  int mes;
  int ano;
}dnas;

typedef struct{
  int matricula;
  char nome[50];
  char sexo[2];
  dnas datanascimento;
  char cpf[15];
}pessoa;

typedef struct{
  int codigo;
  char nome[30];
}disciplina;

typedef struct{
  int codigo;
  int matricula;
}turma;
