// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Marcus Vinicius Sousa de Jesus
//  email: mvsj1986@gmail.com
//  Matrícula: 2019116031
//  Semestre: 2º / 2024.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include "MarcusJesus-2019116031.h"

 void limparVetor(int * vetor, int tamanho){
   for(int i = 0; i < tamanho; i++){
     vetor[i] = 0;
   }
 }

Data separarData(char data[]){
  Data d;
  int z = 0;
  int parte[10];

  limparVetor(parte, 10);
  
  for(int i = 0; i < 10; i++){
    if(data[i] != '/'){
      parte[i] = data[i] - '0';
    }
  }

  d.dia = 0;
  d.mes = 0;
  d.ano = 0;

  do{
    d.dia = d.dia *10 + parte[z];
    z++;
  }while(parte[z] != -1);
  z++;

  do{
    d.mes = d.mes *10 + parte[z];
    z++;
  }while(parte[z] != -1);
  z++;

  do{
    d.ano = d.ano *10 + parte[z];
    z++;
  }while(z < 11 && d.ano < 10000);
  
  return d;
}

int q1(char data[]){
  Data original;

  original = separarData(data);

  printf("Dia %d, mes %d, ano %d", original.dia, original.mes, original.ano);
  return 0;
}

//questões 2 a 6 não feitas.