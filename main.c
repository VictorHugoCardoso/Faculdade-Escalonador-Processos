#include "funcoes.c"

int main (void) {

    processo *lista, *temp = NULL;
    
    lista = inicializaArquivo("entrada.txt", lista);

    listprocs(lista);
    fcfs(lista);   
    prioridade(lista);
    
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    };
    return(0);
};