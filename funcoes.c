#include "header.h"

processo *inicializa (processo * p, int id, int surto, int prioridade) {
    processo *proc;
    proc = (processo*)malloc(sizeof(processo)); 
    proc->id = id;
    proc->surto = surto;
    proc->prioridade = prioridade;
    proc->execucao = 0;
    proc->espera = 0;
    proc->prox = p;
    return(proc);
};

processo*  inicializaArquivo(char* txt, processo *p){
  char s[200];

  FILE *arq;
  if((arq = fopen(txt,"r")) == NULL){
    printf("Erro ao abrir o arquivo texto\n"); //erro na abertura do arquivo
  }else{
    fseek(arq,0,SEEK_SET);                //posiciona o cursor no comeco do arquivo texto
      
    int i,k, id, surto, prioridade, zerar;
    char aux[10];

    while(fgets(s,100,arq) != 0){
      for(zerar=0;zerar<10;zerar++){
        aux[zerar] = '\0';
      }

      k = 0;
      i = 1;

      while(s[i] != ','){
        aux[k] = s[i];
        i++;
        k++;
      }

      id = atoi(aux);

      for(zerar=0;zerar<10;zerar++){
        aux[zerar] = '\0';
      }

      k = 0;
      i += 1;
        
      while(s[i] != ','){
        aux[k] = s[i];
        i++;
        k++;
      }

      surto = atoi(aux);

      for(zerar=0;zerar<10;zerar++){
        aux[zerar] = '\0';
      }

      k = 0;
      i += 1;
        
      while(s[i] != ']'){
        aux[k] = s[i];
        i++;
        k++;
      }

      prioridade = atoi(aux);

      p = inicializa(p,id,surto,prioridade);
    }
  }
  return p;
}

void listprocs (processo *proc) {
    processo *tmp = proc;
    printf("\tListagem de Processos\n");
    printf("\n");
    while (tmp != NULL) {
    printf("Processo: %d\tPrioridade: %d\tSurto: %d\n", tmp->id, tmp->prioridade, tmp->surto);
    tmp = tmp->prox;
    };
    printf("\n\n");
};

void fcfs (processo *proc) {
    int tempo = 0, inicio, fim;
  processo *tmp = proc;
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

void prioridade (processo *proc) {
  int tempo, inicio, fim, maior;
  processo *copia, *tmpsrc, *tmp, *maiorprimeiro;
  printf("\tEscalonamento por Prioridade\n");

  tmpsrc = proc;
  copia = tmp = NULL;

  while (tmpsrc != NULL) {
    if (copia == NULL) {

    copia = inicializa(tmpsrc, tmpsrc->id, tmpsrc->surto, tmpsrc->prioridade);
    tmp = copia;
    } else {
    tmp->prox = inicializa(tmpsrc, tmpsrc->id, tmpsrc->surto, tmpsrc->prioridade);
    tmp = tmp->prox;
    };
    tmpsrc = tmpsrc->prox;
  };

  tempo = 0;
  while (copia != NULL) {
    
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

    if (maiorprimeiro == NULL) {
	    inicio = tempo;
	    tempo += copia->surto;
	    fim = tempo;
	    printf("Processo: %d\tSurto: %d\tEspera: %d\tRetorno: %d\n", copia->id, tempo, inicio, fim);
	    tmpsrc = copia->prox;
	    free(copia);
	    copia = tmpsrc;
    }else{
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