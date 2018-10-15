#include "funcoes.c"

int main (int argc, char*argv[]) {

    processo *lista, *temp = NULL;
    
    lista = inicializaArquivo(argv[1], lista);

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