#include "header.h"

/* Listando Processos */
void listprocs (struct processos *proc) {
    struct processos *tmp = proc;
    printf("\tListagem de Processos\n");
    printf("\n");
    while (tmp != NULL) {
    printf("Processo: %d\tPrioridade: %d\tSurto: %d\n", tmp->id, tmp->prioridade, tmp->surto);
    tmp = tmp->prox;
    };
    printf("\n\n");
};

void fcfs (struct processos *proc) {
    int tempo = 0, inicio, fim;
  struct processos *tmp = proc;
  printf("\tEscalonamento FCFS\n");
    printf("\n");
  while (tmp != NULL) {
    inicio = tempo;
    tempo += tmp->surto;
    fim = tempo;
    printf("Processo: %d\tSurto: %d\tEspera: %d\tRetorno: %d\n", tmp->id, tempo, inicio, fim);
    tmp = tmp->prox;
  };
    printf("\n\n");
};

void prioridade (struct processos *proc) {
  int tempo, inicio, fim, maior;
  struct processos *copia, *tmpsrc, *tmp, *maiorprimeiro;
  printf("\tEscalonamento por Prioridade\n");
   printf("\n");
  
     /* Replicando Lista de Processos */
  tmpsrc = proc;
  copia = tmp = NULL;
  while (tmpsrc != NULL) {
    if (copia == NULL) {
    copia = init_processos(tmpsrc->id, tmpsrc->surto, tmpsrc->prioridade);
    tmp = copia;
    } else {
    tmp->prox = init_processos(tmpsrc->id, tmpsrc->surto, tmpsrc->prioridade);
    tmp = tmp->prox;
    };
    tmpsrc = tmpsrc->prox;
  };
  /* Programa Principal */
  tempo = 0;
  while (copia != NULL) {
    
    /* Localiza o proximo processo */
    maiorprimeiro = NULL;
    maior = copia->prioridade;
    tmp = copia->prox;
    tmpsrc = copia;
    while (tmp != NULL) {
    if (tmp->prioridade < maior) {
      maior = tmp->prioridade;
      maiorprimeiro = tmpsrc;
    };
    tmpsrc = tmp;
    tmp = tmp->prox;
    };
    
    // primeiro processo maior prioridade 
    if (maiorprimeiro == NULL) {
	    inicio = tempo;
	    tempo += copia->surto;
	    fim = tempo;
	    printf("Processo: %d\tSurto: %d\tEspera: %d\tRetorno: %d\n", copia->id, tempo, inicio, fim);
	    tmpsrc = copia->prox;
	    free(copia);
	    copia = tmpsrc;
    } else {
	    tmp = maiorprimeiro->prox;
	    inicio = tempo;
	    tempo += tmp->surto;
	    fim = tempo;
	    printf("Processo: %d\tSurto: %d\tEspera: %d\tRetorno: %d\n", tmp->id, tempo, inicio, fim);
	    maiorprimeiro->prox = tmp->prox;
	    free(tmp);
    };
  };
};