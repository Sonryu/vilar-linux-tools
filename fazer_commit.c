#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char *argv[] ){
	
if(argc < 3){
	fprintf(stderr, "Erro: Argumentos insuficientes.\n");
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


printf("--- INICIANDO: vilar-git (C Version) ---\n");
for (int i = 0; i < 3; i++) {
        
        if (i == 0) {
            strcpy(comando, formatos[i]); // git add .
        } else if (i == 1) {
            sprintf(comando, formatos[i], mensagem); // git commit -m "mensagem"
        } else if (i == 2) {
            sprintf(comando, formatos[i], branch); // git push origin branch
        }

        
        printf("Executando: %s\n", comando);
        int status = system(comando);

        if (status != 0) {
            fprintf(stderr, "Erro ao executar comando. Status: %d\n", status);
            return 1; // Para o programa se um comando falhar
        }
    }


printf("--- SUCESSOR! ---\n");
return 0;

}
