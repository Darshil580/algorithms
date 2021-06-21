#include <stdio.h>
#include<stdlib.h>
//printing the matrix.........
#define pfm(a,n) for (int i = 0; i < n; ++i){printf("\nrow %d:",i);for (int j = 0; j < n; ++j)printf("%d,",a[i][j]);}
//scaning the matrix...........
#define sfm(a,n) for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)scanf("%d",&a[i][j]);
#define debug(x) printf("debugging x = %d",x);

//matrix addition ** is used for matrix reference........
int **matrix_add(int n, int **mat1, int **mat2) {
	int **x;
	x = malloc(sizeof(int *)*n);
	//dynamic memory allocation........ but why  not direct knowing that what will be the size
	//because in order to return the matrix to the function where it called from.
	for (int i = 0; i < n; ++i)
	{
		x[i] = malloc(sizeof(int *) * n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	return x;
}
//matrix multiplication
int  **matrix_mul(int n, int matrix1[n][n] , int matrix2[n][n]) {

	int a[n / 2][n / 2], b[n / 2][n / 2], c[n / 2][n / 2], d[n / 2][n / 2];
	int e[n / 2][n / 2], f[n / 2][n / 2], g[n / 2][n / 2], h[n / 2][n / 2];
	int **new;
	int **s, **o, **p, **q;



	//divide matrix into 4 matrix for both matrix total 8 matrix a to h
	// printf("Assigning memory.....\n");

	new = malloc(sizeof(int *)*n);
	s = malloc(sizeof(int *) * (n / 2));
	o = malloc(sizeof(int *) * (n / 2));
	p = malloc(sizeof(int *) * (n / 2));
	q = malloc(sizeof(int *) * (n / 2));

	for (int i = 0; i < n; ++i)
	{
		new[i] = malloc(sizeof(int *) * n);
	}
	for (int i = 0; i < n / 2; ++i)
	{
		s[i] = malloc(sizeof(int *) * (n / 2));
		o[i] = malloc(sizeof(int *) * (n / 2));
		p[i] = malloc(sizeof(int *) * (n / 2));
		q[i] = malloc(sizeof(int *) * (n / 2));
	}

	//assiging values to small matrix from the original matrix.....
	for (int i = 0; i < n / 2; ++i)
	{
		for (int j = 0; j < n / 2; ++j)
		{
			//matrix1
			a[i][j] = matrix1[i][j];
			b[i][j] = matrix1[i][j + n / 2];
			c[i][j] = matrix1[i + n / 2][j];
			d[i][j] = matrix1[i + n / 2][j + n / 2];

			//matrix2
			e[i][j] = matrix2[i][j];
			f[i][j] = matrix2[i][j + n / 2];
			g[i][j] = matrix2[i + n / 2][j];
			h[i][j] = matrix2[i + n / 2][j + n / 2];
		}
	}

	//Base Condition.................
	if (n == 2) {
		new[0][0] = a[0][0] * e[0][0] + b[0][0] * g[0][0];
		new[0][1] = a[0][0] * f[0][0] + b[0][0] * h[0][0];
		new[1][0] = c[0][0] * e[0][0] + d[0][0] * g[0][0];
		new[1][1] = c[0][0] * f[0][0] + d[0][0] * h[0][0];
		return new;
	}

	//Getting a result of  addition of those matrix that are sent...........
	//we can actually modify the s,o,p,q's matrix multiplication equation in some different way to reduce the one recursion call that is strassen's matrix multiplication
	s = matrix_add(n / 2, matrix_mul(n / 2, a, e), matrix_mul(n / 2, b, g));
	o = matrix_add(n / 2, matrix_mul(n / 2, a, f), matrix_mul(n / 2, b, h));
	p = matrix_add(n / 2, matrix_mul(n / 2, c, e), matrix_mul(n / 2, d, g));
	q = matrix_add(n / 2, matrix_mul(n / 2, c, f), matrix_mul(n / 2, d, h));


	//subroutine for combining all the matrix...........
	for (int i = 0; i < n / 2; ++i)
	{
		printf("\ntransfering info to new combining the results of s,o,p,q");
		for (int j = 0; j < n / 2; ++j)
		{
			new[i][j] = s[i][j];
			new[i][j + n / 2] = o[i][j];
			new[i + n / 2][j] = p[i][j];
			new[i + n / 2][j + n / 2] = q[i][j];
		}
	}
	return new;
}
int main(int argc, char const *argv[])
{
	int n, **result;
	printf("Enter the matrix size:");
	scanf("%d", &n);
	int matrix1[n][n], matrix2[n][n];
	sfm(matrix1, n);
	sfm(matrix2, n);
	result = matrix_mul(n, matrix1, matrix2);
	pfm(result, n);
	free(result);
	return 0;
}