#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct processos {
    int id;                      
    int surto;          
    int prioridade;       
    int execucao;         
    int espera;    
    struct processos *prox;
};

struct processos *init_processos (int id, int surto, int prioridade) {
    struct processos *proc;
    proc = (struct processos*)malloc(sizeof(struct processos)); 
    proc->id = id;
    proc->surto = surto;
    proc->prioridade = prioridade;
    proc->execucao = 0;
    proc->espera = 0;
    proc->prox = NULL;
    return(proc);
};

struct processos *init_processos (int id, int surto, int prioridade);
void fcfs (struct processos *proc);
void listprocs (struct processos *proc);
void prioridade (struct processos *proc);