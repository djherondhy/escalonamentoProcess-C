#include <stdio.h>

int main(){

    typedef struct{
        int x; // chegada do processo
        int y; //duração do processo
        int fp; //fim do processo
        int tt; //turnaround
        int te; //tempo de espera
        int ordem; //ordem de execução

    }Proc;

     typedef struct{
        int numTeste;
        float TMT;
        float TME;
        int nProcessos;
        int ordem[30];
    }Saida;

    int n;
    int cAux = 0; 
    int ctt = 0, cte = 0; //contadores turnaround e espera
    int j = 0, ct =0; //auxiliares dos dados de saída
    Saida saida[30];
    int x = 10;
    

        while(x!=0){
     //Leitura dos Valores de Entrada
        scanf("%d", &n);
        if(n==0){
            printf("Fim da Execucao! \n \n");
            x = 0;
        }else{

        Proc fila[n];

        for(int i=0; i<n; i++){
            scanf("%d", &fila[i].x);
            scanf("%d", &fila[i].y);
            fila[i].ordem = i+1;
        }


        //Variáveis auxiliares na ordenação dos processos
        int aux;
        int auy;
        int auO;
        //ordenação dos processos
        for(int i =0; i<n;i++){
            if(fila[i].x == fila[i+1].x){
                if(fila[i].y>fila[i+1].y){

                     auy = fila[i+1].y;
                     fila[i+1].y = fila[i].y;
                     fila[i].y = auy;

                     aux = fila[i+1].x;
                     fila[i+1].x = fila[i].x;
                     fila[i].x = aux;   
                    
                     auO = fila[i+1].ordem;
                     fila[i+1].ordem = fila[i].ordem;
                     fila[i].ordem = auO;

                }
            }else{
                 if(fila[i].y>fila[i+1].y){

                     auy = fila[i+1].y;
                     fila[i+1].y = fila[i].y;
                     fila[i].y = auy;

                     aux = fila[i+1].x;
                     fila[i+1].x = fila[i].x;
                     fila[i].x = aux;   

                     auO = fila[i+1].ordem;
                     fila[i+1].ordem = fila[i].ordem;
                     fila[i].ordem = auO;
                }
            }
        }

        //Define o Tempo de fim do proceso;
        fila[0].fp = fila[0].y;
        for(int i = 0;i<n-1;i++){
            if(fila[i+1].x<fila[i].fp){
            cAux += fila[i].y;
            fila[i+1].fp = cAux + fila[i+1].y;
            }else{
                 fila[i+1].fp = cAux + fila[i+1].y + fila[i+1].x;
            }
        }

        //Define o turnaround;
        for(int i=0;i<n;i++){
            fila[i].tt = fila[i].fp - fila[i].x;
            ctt += fila[i].tt;
        }

        //Define de espera
        for(int i=0;i<n;i++){
            fila[i].te = fila[i].fp - fila[i].x - fila[i].y; 
            cte += fila[i].te;
        }

        for(int i=0;i<n;i++){
            printf("P%d : %d  ", fila[i].ordem, fila[i].fp);
        }
        printf("\n");
        for(int i=0;i<n;i++){
            printf("P%d : %d  ", fila[i].ordem, fila[i].tt);
        }
        
        ct++;
        saida[j].numTeste = ct;
        saida[j].nProcessos = n;
        saida[j].TME = cte;
        saida[j].TMT = ctt;
            for(int i =0;i<n;i++){
                saida[j].ordem[i] = fila[i].ordem;
            }
        j++;

        cte = 0;
        ctt = 0;
        cAux = 0;

        }
    }

    for(int i = 0; i<j;i++){
        printf("Teste %d \n", saida[i].numTeste);
        printf("Tempo Medio de Execucao %.2f \n", saida[i].TMT/saida[i].nProcessos);
        printf("Tempo Medio de Espera %.2f \n", saida[i].TME/saida[i].nProcessos);

        for(int k = 0; k<saida[i].nProcessos;k++){
            printf("P%d  ", saida[i].ordem[k]);
        }
        printf("\n\n");
    }

   
    return 0;
}