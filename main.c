#include "funcoes.c"

int main (void) {

    processo *lista, *temp = NULL;
    
    //lista = inicializaArquivo("entrada.txt", lista);
    lista = inicializa(lista, 1,2,3);
    lista = inicializa(lista, 2,2,3);
    lista = inicializa(lista, 4,2,3);
    lista = inicializa(lista, 10,2,3);

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