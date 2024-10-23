#include "stdio.h"
#include "stdlib.h"
#include "agenda.h"
#include "listase.h"
#include "string.h"

struct tipoAgenda{
    int quant;
    struct tipoAgenda *prox; 
    t_lse* elementos;
};
typedef struct tipoData {
  int dia;
  int mes;
  int ano;
  int hora;
  int minuto;
} tipoData;

typedef struct tipoDado{
  tipoData data;
  char evento[140];
  char prioridade[10];
} tipoDado;

tipoDado* ler_dado() {
  tipoDado *dado = malloc(sizeof(tipoDado));
  int dia, mes, ano, hora, minuto;
  char evento[140], prioridade[10];
  scanf("%d/%d/%d %d:%d %s %s", &dia, &mes, &ano, &hora, &minuto, evento, prioridade);
  dado->data.dia = dia;
  dado->data.mes = mes;
  dado->data.ano = ano;
  dado->data.hora = hora;
  dado->data.minuto = minuto;
  strcpy(dado->evento, evento);
  strcpy(dado->prioridade, prioridade);
  return dado;
}

tipoData* ler_data() {
  tipoData *data = malloc(sizeof(tipoData));
  int dia, mes, ano, hora, minuto;
  scanf("%d/%d/%d %d:%d", &dia, &mes, &ano, &hora, &minuto);
  data->dia = dia;
  data->mes = mes;
  data->ano = ano;
  data->hora = hora;
  data->minuto = minuto;
  return data;
}

void imprimir_dado(tipoDado* dado){
    printf("%02d/%02d/%02d %02d:%02d %s %s\n", dado->data.dia, dado->data.mes, dado->data.ano, dado->data.hora, dado->data.minuto, dado->evento, dado->prioridade);
} 
    
int compara_datas(tipoDado* dd1, tipoDado* dd2) {
  tipoData d1 = dd1->data;
  tipoData d2 = dd2->data;
  int alta = 3;
  int media = 2;
  int baixa = 1;
    if(d1.ano != d2.ano)
    {
        return d1.ano - d2.ano; 
    }
    else if(d1.mes != d2.mes)
    {
        return d1.mes - d2.mes;
    }else if(d1.dia != d2.dia)
    {
        return d1.dia - d2.dia;
    }
    else if(d1.hora != d2.hora)
    {
        return d1.hora - d2.hora;
    }else if(d1.minuto != d2.minuto)
    {
        return d1.minuto - d2.minuto;
    }
    return 0;
}

agenda* criar_agenda(){
    agenda* ag = malloc(sizeof(agenda));
    ag->quant = 0;
    ag->elementos = criar_lse(NULL, compara_datas);
    return ag;
}


void agendar_evento(agenda *ag, tipoDado* dado){
    ag->quant++;
    inserir_conteudo_lse(ag->elementos, dado);  
}

tipoDado* cria_evento(tipoData data, char evento[], char prioridade[]){
    tipoDado *dado = malloc(sizeof(tipoDado));
    dado->data = data;
    strcpy(dado->evento, evento);
    strcpy(dado->prioridade, prioridade);
    return dado;
}

int quantificar_evento(agenda* ag){
    if(ag!=NULL){
        return ag->quant;
    }
    return 0;
}

void* proximo_evento(agenda *ag){
     return acessar_lse(ag->elementos, 1);
}

void* cancelar_evento(agenda *ag, void* chave){
    ag->quant--;
    return remover_conteudo_lse(ag->elementos, chave);
}

void alterar_evento(agenda* ag, tipoData* chave1, tipoDado* chave2){
    cancelar_evento(ag, chave1);
    agendar_evento(ag, chave2);
}

void* concluir_evento(agenda *ag){
    ag->quant--;
    return remover_lse(ag->elementos);
}