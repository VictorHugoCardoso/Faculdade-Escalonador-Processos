#include "funcoes.c"

int main (void) {
    
    struct processos *plist, *ptmp;
    plist       = init_processos(1, 10, 3);
    plist->prox = init_processos(2,  1, 1); ptmp = plist->prox;
    ptmp->prox  = init_processos(3,  2, 3); ptmp = ptmp->prox;
    ptmp->prox  = init_processos(4,  1, 4); ptmp = ptmp->prox;
    ptmp->prox  = init_processos(5,  5, 2);
    
    listprocs(plist);
    fcfs(plist);   
    prioridade(plist);
    
    while (plist != NULL) {
        ptmp = plist;
        plist = plist->prox;
        free(ptmp);
    };
    return(0);
};