#include <stdio.h>
#include <math.h>

double a, b, c;
double from, to;

double calc ( double t )
{
    return sqrt(a*a-t*t) * sqrt(b*b-t*t) - c * ( sqrt(b*b-t*t) + sqrt(a*a-t*t) );
}

int main()
{
    scanf( "%lf %lf %lf", &a, &b, &c );
    
    from = 0;
    to = (a > b)?b:a;
    double mid, value, result = -999;
    
    mid = (from+to)/2;
    while( abs(result-mid) > 0.0001 )
    {
        value = calc( mid );
        if( value > 0 ) from = mid;
        else if( value < 0 ) to = mid;
        //printf( "%lf to %lf is %lf -> %lf\n", from, to, mid, value );
        result = mid;
        mid = (from+to)/2;
    }
    result = mid;
    
    printf( "%.3lf", result );
    
    return 0;
}