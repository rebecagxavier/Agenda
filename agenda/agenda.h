typedef struct tipoData tipoData;
typedef struct tipoDado tipoDado;
typedef struct tipoAgenda agenda;

tipoDado* ler_dado();
tipoData* ler_data();
void imprimir_dado(tipoDado* dado);
agenda* criar_agenda();
int compara_datas(tipoDado* d1, tipoDado* d2);
void agendar_evento(agenda *ag, tipoDado *dado);
int quantificar_evento(agenda* ag);
void* proximo_evento(agenda *ag);
void* cancelar_evento(agenda *ag, void* chave);
void alterar_evento(agenda* ag, tipoData* chave1, tipoDado* chave2);
void* concluir_evento(agenda *ag);
