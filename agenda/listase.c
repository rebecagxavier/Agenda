#include "stdlib.h"
#include "listase.h"

typedef struct elem_se{
    void*  carga_util;
    struct elem_se* prox;
} t_elemento_lse;

struct lse{
    t_elemento_lse* inicio;
    t_elemento_lse* fim;
    int tamanho;
    t_comparar_lse comparar;
    t_imprimir_lse imprimir;
};

t_elemento_lse* criar_elemento_lse(void* carga_util){
    t_elemento_lse* novo = malloc(sizeof(t_elemento_lse));
    novo->carga_util = carga_util;
    novo->prox = NULL;
    return novo;
}

t_lse* criar_lse(t_imprimir_lse imprimir, t_comparar_lse comparar){
    t_lse *l = malloc(sizeof(t_lse));
    l->inicio = l->fim = NULL;
    l->tamanho = 0;
    l->comparar = comparar;
    l->imprimir = imprimir;
    return l;
}

void inserir_lse(t_lse* lse, void* carga_util){
    t_elemento_lse* novo = criar_elemento_lse(carga_util);

    if (lse->inicio == NULL){
        lse->inicio = lse->fim = novo;
    }else{
        novo->prox = lse->inicio;
        lse->inicio = novo;
    }
    lse->tamanho++;
}


void inserir_final_lse(t_lse* lse, void* carga_util){

    t_elemento_lse* novo = criar_elemento_lse(carga_util);

    if (lse->inicio == NULL){
        lse->inicio = lse->fim = novo;
    }else{
       lse->fim->prox = novo;
        lse->fim = novo;
    }
    lse->tamanho++;

}

void* acessar_lse(t_lse* lse, int pos){

    if((lse->inicio==NULL) || (pos == 0)){
        return NULL;
    }
    if (pos > 0){
        pos = (pos%lse->tamanho);
        pos = (pos == 0?lse->tamanho:pos);
    }else{
        pos = (pos % lse->tamanho) + lse->tamanho + 1;
        pos = (pos == (lse->tamanho + 1)?1:pos);
    }

    t_elemento_lse *cam = lse->inicio;
    for(int i=1;i<pos;i++){
        cam = cam->prox;
    }
    return cam->carga_util;
}

 void* remover_lse(t_lse* lse){
   void* carga = NULL;
    if(lse->inicio == NULL){
        return NULL;
    }
    t_elemento_lse* proximo = lse->inicio->prox;

    carga = lse->inicio->carga_util;
    free(lse->inicio);
    lse->tamanho--;
    lse->inicio = proximo;
    if (lse->inicio == NULL){ // único
        lse->fim = NULL;
    }
    return carga;
}

 void* remover_final_lse(t_lse* lse){
   void* carga = NULL;
    if(lse->inicio == NULL){
        return NULL;
    }
    t_elemento_lse* ant = NULL;
    t_elemento_lse* cam = lse->inicio;

    while(cam!=lse->fim){
        ant = cam;
        cam = cam->prox;
    }
    carga = cam->carga_util;

    if (ant == NULL){ // unico elemento
        lse->inicio = NULL;
        lse->fim = NULL;
    }else{ // mais de um elemento
        ant->prox = NULL;
        lse->fim = ant;
    }
    free(cam);
    lse->tamanho--;
    return carga;
}


void* buscar_lse(t_lse* lse, void* chave){
    t_elemento_lse *cam = lse->inicio;
    while( (cam!=NULL) && (lse->comparar(cam->carga_util, chave)!=0) ){
        cam = cam->prox;
    }
    if(cam==NULL){
        return NULL;
    }else{
        return cam->carga_util;
    }
}

void imprimir_lse(t_lse* lse){
    t_elemento_lse* cam = lse->inicio;
    while(cam!=NULL){
        lse->imprimir(cam->carga_util);
        cam = cam->prox;
    }
}

void inserir_conteudo_lse(t_lse* lse, void* carga){
    t_elemento_lse* novo = criar_elemento_lse(carga);

    t_elemento_lse* cam = lse->inicio;
    t_elemento_lse* ant = NULL;
    while( (cam != NULL) && lse->comparar(cam->carga_util, carga)<0){
        ant = cam;
        cam = cam->prox;
    }
    if (ant == NULL){ //inicio;
      novo->prox = cam;
      lse->inicio = novo;
    }else if (cam == NULL){ //fim
      ant->prox = novo;
      lse->fim = novo;
    }else{ // meio
      ant->prox = novo;
      novo->prox = cam;
    }
    lse->tamanho++;
}

void* remover_conteudo_lse(t_lse* lse, void* chave){
    void* carga=NULL;
    t_elemento_lse* cam = lse->inicio;
    t_elemento_lse* ant = NULL;

    while( (cam!=NULL) && (lse->comparar(cam->carga_util, chave)!=0) ){
      ant = cam;
      cam = cam->prox;
    }
    if (cam == NULL){
      return NULL;
    }else if(ant == NULL){ // inicio
      carga = cam->carga_util;
      lse->inicio = cam->prox;
      if (lse->inicio == NULL){
        lse->fim = NULL;
      }
    }else if(cam->prox == NULL){ // ultimo
      carga = cam->carga_util;
      lse->fim = ant;
    }else{ // meio
      carga = cam->carga_util;
      ant->prox = cam->prox;
    }
    lse->tamanho--;
    free(cam);
    return carga;
}
