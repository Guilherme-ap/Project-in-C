
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct conta{
    int id;
    char nome[50];
    float saldo;
    int tipo_conta;
}CONTA;
CONTA coleta_dados(){// Função para pegar os dados do usuário
        CONTA func;//declarando a variavel x do tipo CONTA
        printf("Digite o id da conta: ");
        scanf("%d",&func.id);
        printf("\nDigite o nome do cliente: ");
        getchar();
        gets(func.nome);
        printf("\nDigite o saldo da conta: ");
        scanf("%f",&func.saldo);
        printf("\nDigite o tipo da conta: ");
        printf("\n1 - corrente\n");
        printf("\n2 - poupança\n");
        scanf("%d",&func.tipo_conta);
        printf("\n\n");
        system("pause");
        system("cls");
    return func;
};
void imprime(CONTA *func,int n){//Função para escrever na tela utilizando um for
    int i;
        for(i=0;i<n;i++){
        printf("\nID da conta:%d",func[i].id);
        printf("\nNome da conta:%s",func[i].nome);
        printf("\nO saldo é R$:%.2f",func[i].saldo);
        printf("\nO tipo da conta é: %d",func[i].tipo_conta);
        if(func[i].tipo_conta == 1){
            printf("\tCorrente\n");
        }else if(func[i].tipo_conta == 2){
            printf("\tPoupança");
        }
        printf("\n\n");
        }
}
void *libera(func){//Liberar a memória
    free(func);
    printf("Memória limpa com sucesso!");
}
CONTA *alocar(int n){//Alocar a memoria do tipo CONTA e do tamanho que usuário fornecer
    CONTA *dados;
    dados = (CONTA*) malloc(n * sizeof(CONTA));
    return dados;
}

CONTA escrever(func,coleta_dados,n){//Funcão do tipo CONTA para escrever no arquivo binário
    FILE *arquivo;
    arquivo = fopen("guardaDados.bin","w");
    if(arquivo == NULL){
        printf("Erro, arquivo não foi criado\n");
        system("pause");
        exit(1);
    }else{
    fwrite(func,sizeof(CONTA),n,arquivo);//escrever os dados de func do tamanho de CONTA, quantas vezes o usuário quiser no arquivo
    fclose(arquivo);
    }
}
main(){
    setlocale(LC_ALL,"portuguese");
    int n,i;
    printf("Digite a quantidade de contas que será gerenciadas:\n");
    scanf("%d", &n);
    CONTA *func = alocar(n);//variável func do tipo conta recebe a alocação dinâmica
    // uma ponte que func vai apontar pra alocar que esta apontando pro espaço na memoria disponivel ja reservada pela variavel dados
    for(i=0;i<n;i++){
        func[i] = coleta_dados();
    }
    escrever(func,n);
    imprime(func,n);
    libera(func);
};


