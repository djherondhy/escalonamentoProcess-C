#include <stdio.h>

  typedef struct{
        int x; // chegada do processo
        int y; //duração do processo
        int fp; //fim do processo
        int tt; //turnaround
        int te; //tempo de espera
        int ordem; //ordem de execução

    }Proc;




int main(){

   

    typedef struct{
        int numTeste;
        float TMT;
        float TME;
        int nProcessos;
        int ordem[4];
    }Saida;

    int n;
    int cAux = 0;
    int ctt = 0, cte = 0;
     int j = 0, ct =0;
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

        //Define o Tempo de fim do proceso;
        fila[0].fp = fila[0].y+fila[0].x;
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
   
    
}