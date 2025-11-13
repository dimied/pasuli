
#include "splines.h"
#include "../pasuli_macros.h"
/*
 1. Suche <math>i\in\{0,\ldots,n-p-2\}</math>, 
 so dass <math>u\in[\tau_i,\tau_{i+1}[</math> gilt.
    Gibt es keinen solchen Index <math>i</math>, 
    so liegt <math>u</math> außerhalb des Definitionsbereiches 
    der Splinekurve <math>C</math>
    und es muss extrapoliert oder eine Fehlermeldung ausgegeben werden.
 2. Initialisiere Hilfsgrößen <math>q_{0,j}:=P_{i+j}</math> für <math>j=0,\ldots,d</math>
 3. Führe für <math>l=1,\ldots,d</math> und <math>j=0,\ldots,d-l</math> folgende Teilschritte 3.1 bis 3.3 iterativ aus:
 3.1. Im Ausnahmefall gleicher Knoten <math>\tau_{i+j}=\tau_{i+j+l}</math> setze <math>q_{l,j}:=q_{l-1,j}</math> und fahre mit dem nächsten Iterationsschritt <math>j:=j+1</math> bei 3.1. fort.
 3.2. Gilt dagegen <math>\tau_{i+j}<\tau_{i+j+l}</math>, so berechne <math>\alpha_{l,j}:=\frac{u-\tau_{i+j}}{\tau_{i+j+l}-\tau_{i+j}}</math>.
 3.3. Berechne damit <math>q_{l,j}:=q_{l-1,j}\cdot(1-\alpha_{l,j}) + q_{l-1,j+1}\cdot\alpha_{l,j}</math>.
 4. Als Endergebnis der Iteration erhält man <math>C(u):=q_{d,0}</math>.

Sind mehrere Splines, die sich nur durch die Koeffizienten <math>P_i</math> unterscheiden, an derselben Stelle <math>u</math> auszuwerten, so kann die in der Definition der B-Spline-Kurve aufgeführte Berechnungsvorschrift <math> C(u) = \sum_{i=0}^{n-p-2} P_i N_{i,p,\tau}(u)</math> effizienter als der Algorithmus von De Boor sein.
*/
/*
Point deBoor(int k,int degree, int i, double x, double* knots, Point *ctrlPoints)
{   // Please see wikipedia page for detail
    // note that the algorithm here kind of traverses in reverse order
    // comapred to that in the wikipedia page
    if( k == 0)
        return ctrlPoints[i];
    else
    {
        double alpha = (x-knots[i])/(knots[i+degree+1-k]-knots[i]);
        return (deBoor(k-1,degree, i-1, x, knots, ctrlPoints)*(1-alpha )+deBoor(k-1,degree, i, x, knots, ctrlPoints)*alpha );
    }
}
*/
#include <stdlib.h>
#include <stdio.h>

void evaluate_BSpline(double u,
                      double *pKnots,
                      int nKnots,
                      int degree,
                      double *pControlPoints3D,
                      double *pResult)
{
    int end = nKnots - degree - 2;
    int i = -1;

    // Find index
    for (int toFind = 0; toFind < end; toFind++)
    {
        if (pKnots[toFind] <= u && u < pKnots[toFind + 1])
        {
            i = toFind;
            break;
        }
    }

    if (i < 0)
    {
        printf("Not found index for %.2lf. (Range: 0-%x)\n", u, end);
        return;
    }
    printf("Allocate memory\n");
    double *pTempPoints = malloc(sizeof(double) * (degree + 1) * 3);
    printf("Copy points\n");
    // Copy required knot vector slice
    for (int idx = 0; idx <= degree; idx++)
    {
        int sourceIdx = idx + i - degree;
        pTempPoints[idx * 3] = pControlPoints3D[sourceIdx * 3];
        pTempPoints[idx * 3 + 1] = pControlPoints3D[sourceIdx * 3 + 1];
        pTempPoints[idx * 3 + 2] = pControlPoints3D[sourceIdx * 3 + 2];
    }

    printf("Points copied\n");
    double alpha, divisor, prev, diff;

    for (int r = 1; r <= degree; r++)
    {
        int curIdx = degree * 3;
        int prevIdx = curIdx - 3;

        for (int j = degree; j >= r; j--, curIdx -= 3, prevIdx -= 3)
        {
            prev = pKnots[j + i - degree];

            divisor = pKnots[j + i + 1 - r] - prev;

            if (divisor > 0)
            {
                alpha = (u - prev) / divisor;
                diff = (1 - alpha);
                pTempPoints[curIdx] = diff * pTempPoints[prevIdx] + alpha * pTempPoints[curIdx];
                pTempPoints[curIdx + 1] = diff * pTempPoints[prevIdx + 1] + alpha * pTempPoints[curIdx + 1];
                pTempPoints[curIdx + 2] = diff * pTempPoints[prevIdx + 2] + alpha * pTempPoints[curIdx + 2];
            }
            else
            {
                pTempPoints[curIdx] = pTempPoints[prevIdx];
                pTempPoints[curIdx + 1] = pTempPoints[prevIdx + 1];
                pTempPoints[curIdx + 2] = pTempPoints[prevIdx + 2];
            }
        }
    }
    // Algorithm
    /*
    for r in range(1, p + 1):
        for j in range(p, r - 1, -1):
            alpha = (x - t[j + k - p]) / (t[j + 1 + k - r] - t[j + k - p])
            d[j] = (1.0 - alpha) * d[j - 1] + alpha * d[j]

    return d[p]
    */

    pResult[0] = pTempPoints[degree * 3];
    pResult[1] = pTempPoints[degree * 3 + 1];
    pResult[2] = pTempPoints[degree * 3 + 2];

    free(pTempPoints);
}

double knots[] = {0, 1, 2, 2, 3, 3.5, 4, 4,5,6,7};
double points[] = {
    1, 0, 0,
    2, 0, 0,
    2, 0, 0,
    2, 0, 0};

/**
 * x: u
 * y: v
 * z: f(u)
 */
void eval_BSpline(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{

    double result[] = {0.0, 0.0, 0.0};
    int knotsSize = 9;

    int degree = 3;

    evaluate_BSpline(u, knots, knotsSize, degree, points, result);

    P_X(u);
    P_Y(v);
    P_Z(result[0]);
}

/*
def deBoor(k: int, x: int, t, c, p: int):
    k: Index of knot interval that contains x.
    x: Position.
    t: Array of knot positions, needs to be padded as described above.
    c: Array of control points.
    p: Degree of B-spline.
    
    d = [c[j + k - p] for j in range(0, p + 1)]

    for r in range(1, p + 1):
        for j in range(p, r - 1, -1):
            alpha = (x - t[j + k - p]) / (t[j + 1 + k - r] - t[j + k - p])
            d[j] = (1.0 - alpha) * d[j - 1] + alpha * d[j]

    return d[p]
    */