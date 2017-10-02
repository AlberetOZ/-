#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

const int InfRoots = -1;

int Solve_Square ( double a, double b, double c, double* x1, double* x2);

void unitest();

int main ()
{
	double  a = 0, b = 0, c =0;

    unitest();

	printf("Enter a,b,c\n");

	scanf("%lg %lg %lg" , &a, &b, &c);

	double x1 = 0, x2 = 0;
	int Nroots = Solve_Square ( a, b, c, &x1, &x2);

	switch (Nroots)
	{
		case 0: printf("No real roots\n");
			break;

		case 1: printf("One root: %g\n", x1);
			break;

		case 2: printf("Two roots: %f ; %f\n", x1 , x2 );
			break;

        case InfRoots: printf("Infinite Roots\n");
            break;

		default: printf("main(): ERROR: Nroots=%d\n" , Nroots);
			return 1;

	}

	return 0;
}

int Solve_Square ( double a, double b, double c, double* x1, double* x2)
{

	assert (isfinite (a));
	assert (isfinite (b));
	assert (isfinite (c));

	assert (x1 != NULL);
	assert (x2 != NULL);
	assert (x1 != x2);

	if ( a == 0)
	{
		if ( b == 0 )
			return ( c == 0 )? InfRoots : 0 ;
		else
		{
		*x1 = -c/b ;

		return 1;

		}


	}


	else
	{
		double D = b*b - 4*a*c;

		if ( D == 0)
		{
			*x1 = -b / (2*a) ;
			return 1;
		}
		else
            if (D > 0)
            {
                *x1 = (-b - sqrt(D) ) / (2*a);
                *x2 = (-b + sqrt(D) ) / (2*a);

                return 2;
            }
            else
            {
                return 0;



            }
	}



}


void unitest ()
{

    double test[5][6] {{0, 0, 0, 0, 0, InfRoots},
                       {1, 5, 6, -2, -3, 2},
                       {12, 4, 5, 0, 0, 0}
		       {6, -8, 13, 0, 0, 0}
		       {4, -7, 3, 0.75 , 1, 2}} ;

    double  temp1 = 0, temp2 = 0;

    int i = 0, N =0 ;

    for (i = 0 ; i < 5 ; i++ )
    {
        N = Solve_Square (test[i][0], test[i][1], test[i][2], &temp1, &temp2);
        if ( (  N != test[i][5] )  || (temp1 != test[i][3]) || (temp2 != test[i][4]) )
        {
            printf("unitest error: test[%d]\n a=%lg , b=%lg , c=%lg\n x1=%lg (expected %lg) , x2=%lg (expected %lg) , Nroots=%2lg",
            i+1, test[i][0], test[i][1], test[i][2], temp1, test[i][3], temp2, test[i][4], N);

            exit;


        }

    }

}

