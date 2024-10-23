typedef struct lse t_lse;
typedef int(*t_comparar_lse)(void* p1, void* p2);
typedef void(*t_imprimir_lse)(void* p1);

t_lse* criar_lse(t_imprimir_lse imprimir, t_comparar_lse comparar);
void inserir_lse(t_lse* lse, void* carga_util);
void inserir_final_lse(t_lse* lse, void* carga_util);
void* acessar_lse(t_lse* lse, int pos);
void* remover_lse(t_lse* lse);
void* remover_final_lse(t_lse* lse);
void* buscar_lse(t_lse *lse, void* chave);
void imprimir_lse(t_lse* lse);
void inserir_conteudo_lse(t_lse* lse, void* carga);
void* remover_conteudo_lse(t_lse* lse, void* chave);