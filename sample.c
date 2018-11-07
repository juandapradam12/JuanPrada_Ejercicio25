#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* COMPILO CON gcc sample.c -o sample -lm Y ./sample */


double randn (double mu, double sigma)
{
	double U1, U2, W, mult;
	static double X1, X2;
	static int call = 0;
	double X_mu_sigma; 

	if (call == 1)
	{
	call = !call;
	return (mu + sigma * (double) X2);
	}

	do
	{
	U1 = -1 + ((double) rand () / RAND_MAX) * 2;
	U2 = -1 + ((double) rand () / RAND_MAX) * 2;
	W = pow (U1, 2) + pow (U2, 2);
	}
	while (W >= 1 || W == 0);

	mult = sqrt ((-2 * log (W)) / W);
	X1 = U1 * mult;
	X2 = U2 * mult;

	call = !call;

	X_mu_sigma = mu + sigma * (double) X1;

	return (X_mu_sigma);
}

void* generator (double N, double mu, double sigma)
{
	double* values; 
	values = malloc(sizeof(double *)*N);

	int i; 
	for ( i = 0; i < N; i++)
	{
		values[i] = randn(mu, sigma);
	}

	FILE *sample = fopen("sample.dat", "w");
		
	for(int i = 0; i < N; i++)
	{
            	fprintf(sample, "%f", values[i]);
        	fprintf(sample, "\n");
    	}
	fclose(sample);
}

void main(int argc, double *argv)
{
	double N; 
	double mu; 
	double sigma; 

	N = 1000; /*argv[1];*/
	mu = 2.5; /*argv[2];*/
	sigma = 3.5; /*argv[3];*/

	generator(N, mu, sigma);

}






