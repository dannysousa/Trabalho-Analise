#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Memor_CB(int p[], int n);
int Memor_CBaux(int p[], int n, int r[]);

int Memor_CB(int p[], int n)
{
    int r[n];
    for (int i = 0; i < n; i++)
    {
        r[i] = 1;
	}
    return (Memor_CBaux(p, n, r));
}

int Memor_CBaux(int p[], int n, int r[])
{
	int q;
    if (n > 0 && r[n - 1] >= 0)
    {
    return r[n - 1];
	}
    if (n == 0)
	{
        q = 0;
    }
    else
	{
    	q = 1;
        for (int i = 1; i <= n; i++)
        {
            int aux = p[i - 1] + (Memor_CBaux(p, n - i, r));
            if (q < aux)
            {
            	q = aux;
            }
    	}
        r[n - 1] = q;
    }
	return q;
}

int main()
{
	FILE *arq;
	char str[100], Linha[100];
	int i=1, result, armTemp[100], k=0, j=0, escolha, dinheiro;
	
	printf("Por gentileza, digite o nome do arquivo mais a extensão do mesmo a ser aberto:\n");
	gets(str);
	
	arq = fopen(str, "rt");
	
	system("cls");
	
	if (arq == NULL)
	{
		printf("erro na abertura do arquivo ou arquivo inexistente!!!");
	}else{
		
		while (!feof(arq))
		{
			// Lê uma linha (inclusive com o '\n')
	    	result = fscanf(arq, "%s", Linha);  // o 'fgets' lê até 99 caracteres ou até o '\n'
    		if (result)		// Se foi possível ler
			{
//				printf("Linha %d : %s\n",i,Linha);
				armTemp[i] = atoi(Linha);
			}
			i++;
		}
		
		int tamanho[(i-1)/2], valor[(i-1)/2];
		
		for(int x = 1; x <= i; x++)
		{
			if(x % 2 == 0)
			{
				valor[k] = armTemp[x];
				k++;
			}else{
				tamanho[j] = armTemp[x];
				j++;
			}
		}
		
		printf("Tamanho da haste:\n");
		for(int z = 0; z < (i/2); z++)
		{
			printf("%icm\t", tamanho[z]);
		}
		printf("\nValor do tamanho do corte da haste:\n");
		for(int z = 0; z < (i/2); z++)
		{
			printf("R$ %i\t", valor[z]);
		}
		
		printf("\nQual o tamanho da haste que deseja?");
		scanf("%i", &escolha);
		while(escolha <=0 || escolha > (i/2))
		{
			printf("Por gentileza, apenas um dos tamanhos disponiveis!!!");
			printf("\nQual o tamanho da haste que deseja?");
			scanf("%i", &escolha);
		}
		
		system("cls");
		dinheiro = Memor_CB(valor, escolha);
		printf("O valor a ser pago pela haste %c R$ %i", 130, dinheiro);
		
  		fclose(arq);
	}
//	puts(str);
//	int mat[n][2];
	
}
