#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int R;
    int G;
    int B;
} RGB;

void converterParaCinza(RGB **matriz, int linha, int coluna, int valor) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            int cinza = (int)(matriz[i][j].R * 0.30 + matriz[i][j].G * 0.59 + matriz[i][j].B * 0.11);

            matriz[i][j].R = cinza;
            matriz[i][j].G = cinza;
            matriz[i][j].B= cinza;
        }
    }

    FILE* fp_novo = fopen("Cinza.ppm", "w");
    if (fp_novo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }

    int i, j;

    fprintf(fp_novo, "P3\n");
    fprintf(fp_novo, "%d %d\n", coluna, linha);
    fprintf(fp_novo, "%d\n", valor);

    for (i = 0; i < linha; i++) 
    {
        for (j = 0; j < coluna; j++) 
        {
            fprintf(fp_novo, "%d %d %d ", matriz[i][j].R, matriz[i][j].G, matriz[i][j].B);
        }
        fprintf(fp_novo, "\n");
    }
}

void converterTonsCinzaESaturado(RGB **matriz, int linha, int coluna, int valor) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            int cinza = (int)(matriz[i][j].R * 0.30 + matriz[i][j].G * 0.59 + matriz[i][j].B * 0.11);

            matriz[i][j].R = cinza;
            matriz[i][j].G = cinza;
            matriz[i][j].B= cinza;
        }
    }

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            int r = (int)matriz[i][j].R * 1.3;
            int g = (int)matriz[i][j].G * 1.3;
            int b = (int)matriz[i][j].B * 1.3;

            if(r > 255) {
                matriz[i][j].R = 255;
            } else {
                matriz[i][j].R = r;
            }

            if(g > 255) {
                matriz[i][j].G = 255;
            } else {
                matriz[i][j].G = g;
            }

            if(b > 255) {
                matriz[i][j].B = 255;
            } else {
                matriz[i][j].B = b;
            }
        }
    }

    FILE* fp_novo = fopen("cinzaComSaturado.ppm", "w");
    if (fp_novo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }

    int i, j;

    fprintf(fp_novo, "P3\n");
    fprintf(fp_novo, "%d %d\n", coluna, linha);
    fprintf(fp_novo, "%d\n", valor);

    for (i = 0; i < linha; i++) 
    {
        for (j = 0; j < coluna; j++) 
        {
            fprintf(fp_novo, "%d %d %d ", matriz[i][j].R, matriz[i][j].G, matriz[i][j].B);
        }
        fprintf(fp_novo, "\n");
    }
}

void converterImagemNegativa(RGB **matriz, int linha, int coluna, int valor) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            int cinza = (int)(matriz[i][j].R * 0.30 + matriz[i][j].G * 0.59 + matriz[i][j].B * 0.11);

            matriz[i][j].R = cinza;
            matriz[i][j].G = cinza;
            matriz[i][j].B= cinza;
        }
    }

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            matriz[i][j].R = 255 - (int)matriz[i][j].R;
            matriz[i][j].G = 255 - (int)matriz[i][j].G;
            matriz[i][j].B = 255 -(int)matriz[i][j].B;

            
        }
    }

    FILE* fp_novo = fopen("imagemNegativa.ppm", "w");
    if (fp_novo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }

    int i, j;

    fprintf(fp_novo, "P3\n");
    fprintf(fp_novo, "%d %d\n", coluna, linha);
    fprintf(fp_novo, "%d\n", valor);

    for (i = 0; i < linha; i++) 
    {
        for (j = 0; j < coluna; j++) 
        {
            fprintf(fp_novo, "%d %d %d ", matriz[i][j].R, matriz[i][j].G, matriz[i][j].B);
        }
        fprintf(fp_novo, "\n");
    }
}

void converterImagemEnvelhecida(RGB **matriz, int linha, int coluna, int valor) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            int r = matriz[i][j].R - 20;
            int g = matriz[i][j].G - 20;
            int b = matriz[i][j].B - 20;

            matriz[i][j].R = r;
            matriz[i][j].G = g;
            matriz[i][j].B= b;
            
        }
    }

    FILE* fp_novo = fopen("imagemEnvelhecida.ppm", "w");
    if (fp_novo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }

    int i, j;

    fprintf(fp_novo, "P3\n");
    fprintf(fp_novo, "%d %d\n", coluna, linha);
    fprintf(fp_novo, "%d\n", valor);

    for (i = 0; i < linha; i++) 
    {
        for (j = 0; j < coluna; j++) 
        {
            fprintf(fp_novo, "%d %d %d ", matriz[i][j].R, matriz[i][j].G, matriz[i][j].B);
        }
        fprintf(fp_novo, "\n");
    }
}

void aumentarBrilhoImagem(RGB **matriz, int linha, int coluna, int valor, int aumento) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            int cinza = (int)(matriz[i][j].R * 0.30 + matriz[i][j].G * 0.59 + matriz[i][j].B * 0.11);

            matriz[i][j].R = cinza;
            matriz[i][j].G = cinza;
            matriz[i][j].B= cinza;
        }
    }

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            
            int r = ((int)matriz[i][j].R + aumento);
            int g = ((int)matriz[i][j].G + aumento);
            int b = ((int)matriz[i][j].B + aumento);

            if(r > 255) {
                matriz[i][j].R = 255;
            } else {
                matriz[i][j].R = r;
            }

            if(g > 255) {
                matriz[i][j].G = 255;
            } else {
                matriz[i][j].G = g;
            }

            if(b > 255) {
                matriz[i][j].B = 255;
            } else {
                matriz[i][j].B = b;
            }
            
        }
    }

    FILE* fp_novo = fopen("aumentoBrilho.ppm", "w");
    if (fp_novo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }

    int i, j;

    fprintf(fp_novo, "P3\n");
    fprintf(fp_novo, "%d %d\n", coluna, linha);
    fprintf(fp_novo, "%d\n", valor);

    for (i = 0; i < linha; i++) 
    {
        for (j = 0; j < coluna; j++) 
        {
            fprintf(fp_novo, "%d %d %d ", matriz[i][j].R, matriz[i][j].G, matriz[i][j].B);
        }
        fprintf(fp_novo, "\n");
    }
}

void diminuirBrilhoImagem(RGB **matriz, int linha, int coluna, int valor, int diminuir) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            int cinza = (int)(matriz[i][j].R * 0.30 + matriz[i][j].G * 0.59 + matriz[i][j].B * 0.11);

            matriz[i][j].R = cinza;
            matriz[i][j].G = cinza;
            matriz[i][j].B= cinza;
        }
    }

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            
            int r = ((int)matriz[i][j].R - diminuir);
            int g = ((int)matriz[i][j].G - diminuir);
            int b = ((int)matriz[i][j].B - diminuir);

            if(r < 0) {
                matriz[i][j].R = 0;
            } else {
                matriz[i][j].R = r;
            }

            if(g < 0) {
                matriz[i][j].G = 0;
            } else {
                matriz[i][j].G = g;
            }

            if(b < 0) {
                matriz[i][j].B = 0;
            } else {
                matriz[i][j].B = b;
            }
            
        }
    }

    FILE* fp_novo = fopen("diminuiBrilho.ppm", "w");
    if (fp_novo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }

    int i, j;

    fprintf(fp_novo, "P3\n");
    fprintf(fp_novo, "%d %d\n", coluna, linha);
    fprintf(fp_novo, "%d\n", valor);

    for (i = 0; i < linha; i++) 
    {
        for (j = 0; j < coluna; j++) 
        {
            fprintf(fp_novo, "%d %d %d ", matriz[i][j].R, matriz[i][j].G, matriz[i][j].B);
        }
        fprintf(fp_novo, "\n");
    }
}

void rotacionarImagem(RGB **matriz, int linha, int coluna, int valor) {

    RGB **matrizRotacionada = (RGB **)malloc(coluna * sizeof(RGB*));
    for (int i = 0; i < coluna; i++) {
        matrizRotacionada[i] = (RGB *)malloc(linha * sizeof(RGB));
    }

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            matrizRotacionada[j][linha - 1 - i] = matriz[i][j];
        }
    }

    FILE* fp_novo = fopen("rotacionarImagem.ppm", "w");
    if (fp_novo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }

    int i, j;

    fprintf(fp_novo, "P3\n");
    fprintf(fp_novo, "%d %d\n", coluna, linha);
    fprintf(fp_novo, "%d\n", valor);

    for (i = 0; i < linha; i++) 
    {
        for (j = 0; j < coluna; j++) 
        {
            fprintf(fp_novo, "%d %d %d ", matrizRotacionada[i][j].R, matrizRotacionada[i][j].G, matrizRotacionada[i][j].B);
        }
        fprintf(fp_novo, "\n");
    }
}

int main() {
    FILE *fp;
  	fp = fopen("samuca.ppm","r");

    char formato[3];
  	fscanf(fp, "%s", formato); 

    
  	printf("FORMATO: %s\n", formato);

    int coluna, linha;
	fscanf(fp, "%d %d", &coluna, &linha); 	// lê o tamanho da matriz  
  	printf("COLUNA E LINHA: %d %d\n", coluna, linha);

    RGB **matriz = (RGB **)malloc(linha * sizeof(RGB *));
    for (int i = 0; i < linha; i++) {
        matriz[i] = (RGB *)malloc(coluna * sizeof(RGB));
    }   

    int valor;
	fscanf(fp, "%d", &valor); 	// lê o valor máximo. 
  	printf("VALOR MAXIMO: %d\n", valor);

    int i, j;

	for(j=0; j<linha; j++)
	{
		for(i=0; i<coluna; i++)
		{  	
  			fscanf(fp, "%d %d %d", &matriz[j][i].R, &matriz[j][i].G, &matriz[j][i].B);
		}
	}

       
    //converterParaCinza(matriz, linha, coluna, valor);
    //converterTonsCinzaESaturado(matriz, linha, coluna, valor);
    //converterImagemNegativa(matriz, linha, coluna, valor);
    converterImagemEnvelhecida(matriz, linha, coluna, valor);
    //aumentarBrilhoImagem(matriz, linha, coluna, valor, 70);
    //diminuirBrilhoImagem(matriz, linha, coluna, valor, 100);
    //rotacionarImagem(matriz, linha, coluna, valor);

    fclose(fp);
 	return 0;

}



