#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char *argv[] ){
	
if(argc < 3){
	fprintf(stderr, "\033[1;31mErro: Argumentos insuficientes.\033[1;31m\n");
	fprintf(stderr, "Uso: %s [branch] [\"mensagem do commit\"]\n", argv[0]);
	return 1;
}

char *branch = argv[1];
char *mensagem = argv[2];

char comando[512];
// %s sera substituido por branch ou mensagem
const char *formatos[] = {
	"git add .",
	"git commit -m \"%s\"",
	"git push origin %s"
};


printf("\n\033[1;3m--- INICIANDO: vilar-git (C Version) ---\033[1;3m\n");
for (int i = 0; i < 3; i++) {
        
        if (i == 0) {
            strcpy(comando, formatos[i]); // git add .
        } else if (i == 1) {
            sprintf(comando, formatos[i], mensagem); // git commit -m "mensagem"
        } else if (i == 2) {
            sprintf(comando, formatos[i], branch); // git push origin branch
        }

        
        printf("\033[1mExecutando: %s\033[1m\n", comando);
        int status = system(comando);

        if (status != 0) {
            fprintf(stderr, "\n\033[1;31m[!] Erro ao executar comando. Status: %d\033[0m\n", status);
            return 1; // Para o programa se um comando falhar
        }
    }


printf("\n\033[1;3;32m--- SUCESSO! ---\033[0m\n\n");
return 0;

}
