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
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "MarcusJesus2019116031.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

DataQuebrada quebraData(char data[])
{
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i; 

  for (i = 0; data[i] != '/'; i++){
    sDia[i] = data[i];	
  }
  if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
    sDia[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }  


  int j = i + 1; //anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++){
    sMes[i] = data[j];
    i++;
  }

  if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
    sMes[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }


  j = j + 1; //anda 1 cada para pular a barra
  i = 0;

  for(; data[j] != '\0'; j++){
    sAno[i] = data[j];
    i++;
  }

  if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
    sAno[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

  dq.valido = 1;

  return dq;
}

int padronizarAno(int ano)
{
  int nAno;
  
  if (ano < 100) {
    nAno = ano + 2000;
  } else {
    nAno = ano;
  }

  return nAno;
}

int isBissexto(int ano)
{
  if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)){
    return 1;
  }
  else{
    return 0;
  }
}

int validadorData(DataQuebrada dq)
{
  if (dq.iDia < 29){
    return dq.valido;
  } else if (dq.iDia == 29 && dq.iMes == 2){
    if (isBissexto(dq.iAno) == 1) return dq.valido;
  } else if (dq.iDia < 31 && dq.iMes != 2){
    return dq.valido;
  } else if (dq.iDia == 31 && (dq.iMes == 1 || dq.iMes == 3 || dq.iMes == 5 || dq.iMes == 7 || dq.iMes == 8 || dq.iMes == 10 || dq.iMes == 12)){
    return dq.valido;
  }
  return 0;
}

int mesAnterior(DataQuebrada dq)
{
  int mesAnt;

  if (dq.iMes == 1){
    mesAnt = 12;
  } else {
    mesAnt = dq.iMes - 1;
  }

  if (mesAnt == 2 && isBissexto(dq.iAno) == 0){
    return 28;
  } else if (mesAnt == 2 && isBissexto(dq.iAno) == 1){
    return 29;
  } else if (mesAnt == 4 || mesAnt == 6 || mesAnt == 9 || mesAnt == 11){
    return 30;
  } else if (mesAnt == 1 || mesAnt == 3 || mesAnt == 5 || mesAnt == 7 || mesAnt == 8 || mesAnt == 10 || mesAnt == 12){
    return 31;
  }

  return -1;
}

char capitalizarChar(char letra)
{
  if (letra > 96 && letra < 123) return letra - 32;
  else return letra;
}

void capitalizarSting(char texto[])
{
  //97 e 122 - 32 (65 e 90)
  for (int i = 0; i != '\0'; i++){
    if (texto[i] > 96 && texto[i] < 123){
      texto[i] = capitalizarChar(texto[i]);
    }
  }
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd e mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  DataQuebrada dataFim;

  //quebrar a string data em strings sDia, sMes, sAno
  dataFim = quebraData(data);

  //verificar se dados passados estão num formato válidos.
  if (dataFim.valido == 0) return 0;

  //padronizando o ano (de apenas dois digitos) entre 2000 e 2099
  dataFim.iAno = padronizarAno(dataFim.iAno);

  //verificação da validade individual dos componentes da data já que os dados recebidos tem formato válido.
  if (dataFim.iDia > 31 || dataFim.iDia < 1) dataFim.valido = 0;
  if (dataFim.iMes > 12 || dataFim.iMes < 1) dataFim.valido = 0;

  //verificar válidade para o mês.
  dataFim.valido = validadorData(dataFim);
  
  return dataFim.valido;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    DataQuebrada dq1, dq2;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      dq1 = quebraData(datainicial);
      dq1.iAno = padronizarAno(dq1.iAno);
      dq2 = quebraData(datafinal);
      dq2.iAno = padronizarAno(dq2.iAno);

      if (dq1.iAno > dq2.iAno){
        dma.retorno = 4;
        return dma;
      } else if (dq1.iAno == dq2.iAno){
        if (dq1.iMes > dq2.iMes){
          dma.retorno = 4;
          return dma;
        } else if (dq1.iMes == dq2.iMes && dq1.iDia > dq2.iDia){
          dma.retorno = 4;
          return dma;
        }
      }
      
      dma.qtdAnos = dq2.iAno - dq1.iAno;
      
      if(dq1.iMes > dq2.iMes){
        dma.qtdAnos--;
        dma.qtdMeses = 12 - (dq1.iMes - dq2.iMes);
      } else {
        dma.qtdMeses = dq2.iMes - dq1.iMes;
      }

      if(dq1.iDia > dq2.iDia){
        if(dma.qtdMeses == 0){
          dma.qtdAnos--;
          dma.qtdMeses = 11;
          dma.qtdDias = mesAnterior(dq2) - (dq1.iDia - dq2.iDia);
        } else {
          dma.qtdMeses--;
          dma.qtdDias = mesAnterior(dq2) - (dq1.iDia - dq2.iDia);
        }
      } else {
        dma.qtdDias = dq2.iDia - dq1.iDia;
      }
      
      dma.retorno = 1;
      return dma;
    }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
  int qtdOcorrencias = 0;

  if (!isCaseSensitive){
    capitalizarSting(texto);
    c = capitalizarChar(c);
  }

  for (int i = 0; texto[i] != '\0' ; i++){
    if (texto[i] == c){
      qtdOcorrencias++;
    }
  }
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int qtdOcorrencias = 0;
  int j = 0;
  int registro = 0;
  int tam, inicio, k;

  while(strBusca[j] != '\0'){
    tam++;
    j++;
  }

  j = 0;

  for(int i = 0; i < 30; i++){
    if(strTexto[i] == strBusca[j]){
      inicio = i;
      k = i;
      if(strTexto[k] == strBusca[j] && strTexto[k] != '\0' && strBusca[j] != '\0'){
        k++;
        j++;
        if (j == tam - 1){
          posicoes[registro] = inicio;
          registro++;
          posicoes[registro] = k;
          registro++;
          qtdOcorrencias++;
        }
      }
    }
  }
  
  return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */
int q5(int num)
{

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */
int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}