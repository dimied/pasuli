#include <stdio.h>
#include <math.h>

typedef double (*funcSingleParam)(double x);

typedef double (*func2Params)(double x, double y);

void testSingleParameter(int limit, funcSingleParam pFunc, char *pszType);

void testNested2Parameters(int limitX, int limitY, func2Params pFunc, char *pszType);

void testCosSquaredPlusSinSquared(int limit);

void testAndSubtractXY(int limitX, int limitY);

int main()
{
    printf("Started ...\n");

    testCosSquaredPlusSinSquared(200 * 1000);

    //testAndSubtractXY(4 * 1000, 4 * 1000);

    printf("Finished\n");
    return 0;
}

double cosXsquaredPlusSinXsquared(double x)
{
    double cos_x = cos(x);
    double sin_x = sin(x);
    return 1 - (cos_x * cos_x + sin_x * sin_x);
}

double sin2X(double x)
{
    double sin_2x = sin(2 * x);
    return sin_2x - 2 * sin(x) * cos(x);
}

double cos2X(double x)
{
    double cos_x = cos(x);
    double sin_x = sin(x);
    double cos_2x = cos(2 * x);
    return cos_2x - (cos_x * cos_x - sin_x * sin_x);
}

double cos2X_2(double x)
{
    double cos_x = cos(x);
    double cos_2x = cos(2 * x);
    return cos_2x - (2 * cos_x * cos_x - 1);
}

void testCosSquaredPlusSinSquared(int limit)
{
    char *pszSquareSum = "1=cos(x)^2 + sin(x)^2";
    testSingleParameter(limit, cosXsquaredPlusSinXsquared, pszSquareSum);

    char *pszSin2X = "sin(2*x) = 2*sin(x)*cos(x)";
    testSingleParameter(limit, sin2X, pszSin2X);

    char *pszCos2X = "cos(2*x) = cos(x)^2 - sin(x)^2";
    testSingleParameter(limit, cos2X, pszCos2X);

    char *pszCos2X_2 = "cos(2*x) = 2*cos(x)^2 - 1";
    testSingleParameter(limit, cos2X_2, pszCos2X_2);
}

double sinXplusY(double x, double y)
{
    double result = sin(x + y);
    double resultByMultiply = sin(x) * cos(y) + cos(x) * sin(y);
    return result - resultByMultiply;
}

double sinXminusY(double x, double y)
{
    double result = sin(x - y);
    double resultByMultiply = sin(x) * cos(y) - cos(x) * sin(y);
    return result - resultByMultiply;
}

double cosXplusY(double x, double y)
{
    double result = cos(x + y);
    double resultByMultiply = cos(x) * cos(y) - sin(x) * sin(y);
    return result - resultByMultiply;
}

double cosXminusY(double x, double y)
{
    double result = cos(x - y);
    double resultByMultiply = cos(x) * cos(y) + sin(x) * sin(y);
    return result - resultByMultiply;
}

void testAndSubtractXY(int limitX, int limitY)
{
    //sin( x ± y ) = sin x · cos y ± cos x · sin y
    char *pszSinXplusY = "sin(x+y) = sin(x)*cos(y)+cos(x)*sin(y)";
    testNested2Parameters(limitX, limitY, &sinXplusY, pszSinXplusY);

    char *pszSinXminusY = "sin(x-y) = sin(x)*cos(y)-cos(x)*sin(y)";
    testNested2Parameters(limitX, limitY, &sinXminusY, pszSinXminusY);
    //cos( x+y ) = cos x · cos y - sin x · sin y
    char *pszCosXplusY = "cos(x+y) = cos(x)*cos(y)-sin(x)*sin(y)";
    testNested2Parameters(limitX, limitY, &cosXplusY, pszCosXplusY);
    //cos( x-y ) = cos x · cos y + sin x · sin y
    char *pszCosXminusY = "cos(x-y) = cos(x)*cos(y)+sin(x)*sin(y)";
    testNested2Parameters(limitX, limitY, &cosXminusY, pszCosXminusY);
}

void testSingleParameter(int limit, funcSingleParam pFunc, char *pszType)
{
    double start = 0;
    double end = 2 * M_PI;
    int numDifferences = 0;
    double maxPositiveDeviation = 0;
    double maxNegativeDeviation = 0;

    if (limit <= 0)
    {
        printf("Invalid parameter for the limit\n");
    }

    for (int i = 0; i <= limit; i++)
    {
        double value;
        if (i == 0)
        {
            value = 0;
        }
        else if (i == limit)
        {
            value = 2 * M_PI;
        }
        else
        {
            value = 2 * M_PI * i / (double)limit;
        }

        double difference = pFunc(value);

        if (difference != 0)
        {
            //printf("Difference: %e\n", difference);

            numDifferences++;
            if (maxPositiveDeviation < difference)
            {
                maxPositiveDeviation = difference;
            }
            if (maxNegativeDeviation > difference)
            {
                maxNegativeDeviation = difference;
            }
        }
    }

    printf("-------------------------------------\n");
    printf("Type: %s\n", pszType);
    printf("Range 0-2*PI:subdivisions:%d\n", limit);
    printf("#differences(number): %d\n", numDifferences);
    printf("#differences(percent): %.2lf\n", numDifferences * 100.0 / limit);
    printf("#max pos. dev. %e\n", maxPositiveDeviation);
    printf("#max neg. dev. %e\n", maxNegativeDeviation);
    printf("-------------------------------------\n");
}

void testNested2Parameters(int limitX, int limitY, func2Params pFunc, char *pszType)
{
    double start = 0;
    double end = 2 * M_PI;
    int numDifferences = 0;
    double maxPositiveDeviation = 0;
    double maxNegativeDeviation = 0;

    if (limitX <= 0 || limitY <= 0)
    {
        printf("Invalid parameter for the limit\n");
    }

    for (int i = 0; i <= limitX; i++)
    {
        double x;
        if (i == 0)
        {
            x = 0;
        }
        else if (i == limitX)
        {
            x = 2 * M_PI;
        }
        else
        {
            x = 2 * M_PI * i / (double)limitX;
        }

        for (int j = 0; j <= limitY; j++)
        {
            double y;
            if (j == 0)
            {
                y = 0;
            }
            else if (y == limitY)
            {
                y = 2 * M_PI;
            }
            else
            {
                y = 2 * M_PI * j / (double)limitY;
            }

            double difference = pFunc(x, y);

            if (difference != 0)
            {
                //printf("Difference: %e\n", difference);

                numDifferences++;
                if (maxPositiveDeviation < difference)
                {
                    maxPositiveDeviation = difference;
                }
                if (maxNegativeDeviation > difference)
                {
                    maxNegativeDeviation = difference;
                }
            }
        }
    }

    printf("-------------------------------------\n");
    printf("Type: %s\n", pszType);
    printf("Range 0-2*PI:subdivisions:X:%d\n", limitX);
    printf("Range 0-2*PI:subdivisions:Y:%d\n", limitY);
    printf("#differences(number): %d\n", numDifferences);
    printf("#differences(percent): %.2lf\n", numDifferences * 100.0 / (limitX * limitY));
    printf("#max pos. dev. %e\n", maxPositiveDeviation);
    printf("#max neg. dev. %e\n", maxNegativeDeviation);
    printf("-------------------------------------\n");
}