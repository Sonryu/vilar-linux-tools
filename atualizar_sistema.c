#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char *argv[] ){
	
    char comando[512];

    const char *formatos[] = {
	"dnf upgrade --refresh",
	"flatpak update -y"
};


printf("\n\033[1;3m--- INICIANDO: vilar-upgrade-system (C Version) ---\033[1;3m\n");
        
for (int i = 0; i < 2; i++) {
        
        if (i == 0) {
            strcpy(comando, formatos[i]); // dnf upgrade --refresh
        } else if (i == 1) {
            strcpy(comando, formatos[i]); // flatpak update
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

