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

    FILE* fp_novo = fopen("./imgs_transformadas/Cinza.ppm", "w");
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

    fclose(fp_novo);
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

    FILE* fp_novo = fopen("./imgs_transformadas/cinzaComSaturado.ppm", "w");
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

    fclose(fp_novo);
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

    FILE* fp_novo = fopen("./imgs_transformadas/imagemNegativa.ppm", "w");
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

    fclose(fp_novo);
}

void converterImagemEnvelhecida(RGB **matriz, int linha, int coluna, int valor) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {

            int r = (int)matriz[i][j].R * 0.63;
            int g = (int)matriz[i][j].G * 0.38;
            int b = (int)matriz[i][j].B;

            matriz[i][j].R = r + 40;
            matriz[i][j].G = g + 40;
            matriz[i][j].B = 0;
        }
    }

    FILE* fp_novo = fopen("./imgs_transformadas/imagemEnvelhecida.ppm", "w");
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

    fclose(fp_novo);
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

    FILE* fp_novo = fopen("./imgs_transformadas/aumentoBrilho.ppm", "w");
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

    fclose(fp_novo);
}

void diminuirBrilhoImagem(RGB **matriz, int linha, int coluna, int valor, int diminuir) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            int cinza = (int)(matriz[i][j].R * 0.30 + matriz[i][j].G * 0.59 + matriz[i][j].B * 0.11);

            matriz[i][j].R = cinza;
            matriz[i][j].G = cinza;
            matriz[i][j].B = cinza;
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

    FILE* fp_novo = fopen("./imgs_transformadas/diminuiBrilho.ppm", "w");
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

    fclose(fp_novo);
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

    FILE* fp_novo = fopen("./imgs_transformadas/rotacionarImagem.ppm", "w");
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

    fclose(fp_novo);
}

int main() {
    FILE *fp;
    char nomeArquivo[100];
    char formato[3];
    int coluna, linha;

    while(1) {
        printf("Digite o nome do arquivo .ppm (com a extensão): ");
        scanf("%s", nomeArquivo);

  	    fp = fopen(nomeArquivo,"r");
        if (fp == NULL) {
                printf("Erro ao abrir o arquivo. Tente novamente.\n");
            } 
  	    fscanf(fp, "%s", formato); 
    
	    fscanf(fp, "%d %d", &coluna, &linha); 	// lê o tamanho da matriz  
    
        if(linha < 400 || coluna < 400) {
           printf("Número mínimo de linhas ou colunas inválido.\n");
        } else {
          break;
        }
    }
    

    RGB **matriz = (RGB **)malloc(linha * sizeof(RGB *));
    for (int i = 0; i < linha; i++) {
        matriz[i] = (RGB *)malloc(coluna * sizeof(RGB));
    }   

    int valor;
	fscanf(fp, "%d", &valor); 	// lê o valor máximo. 

    int i, j;

	for(j=0; j<linha; j++)
	{
		for(i=0; i<coluna; i++)
		{  	
  			fscanf(fp, "%d %d %d", &matriz[j][i].R, &matriz[j][i].G, &matriz[j][i].B);
		}
	}

    int opcao, brilho;

    do {
        printf("\nMenu:\n");
        printf("1. Converter para Cinza\n");
        printf("2. Converter para Tons de Cinza e Saturado\n");
        printf("3. Converter para Imagem Negativa\n");
        printf("4. Converter para Imagem Envelhecida\n");
        printf("5. Aumentar Brilho da Imagem\n");
        printf("6. Diminuir Brilho da Imagem\n");
        printf("7. Rotacionar Imagem\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                converterParaCinza(matriz, linha, coluna, valor); 
                break; 
            case 2:
                converterTonsCinzaESaturado(matriz, linha, coluna, valor);
                break;
            case 3:
                converterImagemNegativa(matriz, linha, coluna, valor);
                break;
            case 4:
                converterImagemEnvelhecida(matriz, linha, coluna, valor);
                break;
            case 5:
                printf("Digite o valor de aumento de brilho: ");
                scanf("%d", &brilho);
                aumentarBrilhoImagem(matriz, linha, coluna, valor, brilho);
                break;
            case 6:
                printf("Digite o valor de diminuição de brilho: ");
                scanf("%d", &brilho);
                diminuirBrilhoImagem(matriz, linha, coluna, valor, brilho);
                break;
            case 7:
                rotacionarImagem(matriz, linha, coluna, valor);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 8);

    for (int i = 0; i < linha; i++) {
        free(matriz[i]);
    }
    free(matriz);

    fclose(fp);
 	return 0;
    
}