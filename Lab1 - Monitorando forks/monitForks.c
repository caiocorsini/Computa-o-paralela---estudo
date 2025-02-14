//Caio Vinicius Corsini Filho
//Exercicio 2

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num_processos = 0;
    int total_processos;
    int pid;
    int status;

    // Pega quantidade de processos a serem criados
    printf("Quantos processos: ");
    scanf("%d", &total_processos);  //Eh o meu "n"

    while(num_processos<total_processos){
        pid = fork();
        if(pid == 0){  //FILHO
            srand(time(NULL)+getpid());  // Gerando inteiro aleatorio
            int sleep_time = rand() % 15 + 1;  //Tempo para filho dormir randomizado. de 15 a 1
            sleep(sleep_time);
            exit(sleep_time); // O filho retorna seu tempo de sono como código de saída
        } else  //PAI
            num_processos++; 
    }

    // Espera todos os processos criados terminarem
    while ((pid = wait(&status)) > 0) {  // Se wait() retornar -1 eh porque nao tem mais filhos para esperar, entao o while para de repetir
        if (WIFEXITED(status)) {  //WIFEXITED pega o valor de saida desse filho, neste caso o "sleep_time" da funcao exit
            printf("No processo pai: Processo filho %d terminou com código de saída %d\n", pid, WEXITSTATUS(status));
        }
    }
    return 0;
}

//cp "/mnt/c/Users/caiof/Documentos disco local/aaaComputacao_faculdade/Computação paralela/Labs/Lab1 - Monitorando forks/monitForks.c" ~/CompParalel/
//clear & gcc monitForks.c -o monitForks & ./monitForks
//cp "/mnt/c/Users/caiof/Documentos disco local/aaaComputacao_faculdade/Computação paralela/Labs/Lab1 - Monitorando forks/monitForks.c" ~/CompParalel/ && clear && gcc monitForks.c -o monitForks && ./monitForks
