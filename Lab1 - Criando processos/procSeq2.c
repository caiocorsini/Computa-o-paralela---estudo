#include <stdio.h>  // Ja traz a variavel stderr declarada
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Essa versao forma arvore, ("possivelmente")
void main(){
    pid_t proc = 0;  //pid_t eh um tipo especializado para representar PIDs.
    int status,i,n;
    printf("Valor de n: "); scanf("%d", &n);

    for(i=1; i<n; i++){
        proc = fork();
        if(proc == 0) break;  // Se o processo nao for filho, pare de rodar.
        wait(&status);
    }

    // Tem que usar fprintf ao inves de printf para os processos nao usarem o mesmo buffer
    fprintf(stderr, "i: %d - Process ID:%ld - parent ID:%ld - child ID:%ld\n",
        i, (long)getpid(), (long)getppid(), (long)proc);  // Printa as informacoes se for filho
}

//cp "/mnt/c/Users/caiof/Documentos disco local/aaaComputacao_faculdade/Computação paralela/Labs/Lab1 - Criando processos/procSeq2.c" ~/CompParalel/
//clear & gcc procSeq2.c -o procSeq2 & ./procSeq2
//clear && cp "/mnt/c/Users/caiof/Documentos disco local/aaaComputacao_faculdade/Computação paralela/Labs/Lab1 - Criando processos/procSeq2.c" ~/CompParalel/ && clear && gcc procSeq2.c -o procSeq2 && ./procSeq2
