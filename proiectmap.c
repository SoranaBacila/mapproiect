#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int n = 3, m = 3;
int **a;

void citire(void)
{
	int i, j, x;
	a = (int**)malloc(n * sizeof(int));
	if (!a)
	{
		printf("Eroare la alocarea dinamica a liniilor!");
		free(a);
		exit(EXIT_FAILURE);
	}
	for (j = 0; j < m; j++)
	{
		a[j] = (int*)malloc(m * sizeof(int));
		if (!a[j])
		{
			printf("Eroare la alocarea dinamica a coloanelor!");
			free(a);
			exit(EXIT_FAILURE);

		}
	}
    srand(time(NULL));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			printf("a[%d][%d]=", i, j);
			x = rand() % 100;
			a[i][j] = x;
			printf("%d\n", a[i][j]);
		}

}

void afisare(void)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void suma_diagP(void)
{
	int i, j;
	int s = 0;

	if (n == m)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)

				if (i == j)

					s = s + a[i][j];
		printf("Suma de pe diagonala principala este:%d\n", s);
	}
	else
		printf("Matricea nu este patratica si nu are diagonala principala\n");

}

void suma_diagS(void)
{
	int i, j;
	int ss = 0;

	if (n == m)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)


				if (i + j == n - 1)

					ss = ss + a[i][j];
		printf("Suma de pe diagonala secundara este:%d\n", ss);
	}
	else
		printf("Matricea nu este patratica si nu are diagonala secundara\n");
}

void minsimax_diagP(void)
{
	int i, j;
	int max = a[1][0];
	int min = a[1][0];

	if (n == m)
	{
		for (i = 2; i < n; i++)
			for (j = 0; j < m; j++)
			{
				if ((a[i][j] > max) && (i > j)) //sub diagonala principala
					max = a[i][j];

				else if ((a[i][j] < min) && (i > j))
					min = a[i][j];
			}
		printf("Maximul de sub diagonalei principale este: %d\n", max);
		printf("Minimul de sub diagonalei principale este: %d\n", min);


	}
	else
		printf("Matricea nu este patratica, deci nu are diagonala principala");

}

void minsimax_diagS(void)
{
	int i, j;
	int max = a[1][n - 1];
	int min = a[1][m - 1];

	if (n == m)
	{
		for (i = 2; i < n; i++)
			for (j = 0; j < m; j++)

			{
				if ((a[i][j] > max) && (i + j > n - 1)) //sub diagonala principala
					max = a[i][j];

				else if ((a[i][j] < min) && (i + j > n - 1))
					min = a[i][j];
			}
		printf("Maximul de sub diagonalei secundara este: %d\n", max);
		printf("Minimul de sub diagonalei secundara este: %d\n", min);


	}
	else
		printf("Matricea nu este patratica, deci nu are diagonala secundara");

}

int main()
{

	citire();
	afisare();
	suma_diagP();
	suma_diagS();
	minsimax_diagP();
	minsimax_diagS();


	return 0;
}