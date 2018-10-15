#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
	
typedef struct processos {
    int id;                      
    int surto;          
    int prioridade;       
    int execucao;         
    int espera;    
    struct processos *prox;
}processo ;

int vazia(processo *l);
processo* invertelista(processo* l);
processo *inicializaArquivo(char* txt, processo *p);
processo *inicializa (processo * p, int id, int surto, int prioridade);
void fcfs (processo *proc);
void listprocs (processo *proc);
void prioridade (processo *proc);