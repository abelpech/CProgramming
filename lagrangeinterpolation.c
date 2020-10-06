#include<stdio.h>
 
/*Function to evaluate Li(x)*/
 
double Li(int i, int n, double x[n+1], double X){
    int j;
    double prod=1;
    for(j=0;j<=n;j++){
        if(j!=i)
            prod=prod*(X-x[j])/(x[i]-x[j]);
    }
        return prod;
}
 
/*Function to evaluate Pn(x) where Pn is the Lagrange interpolating polynomial of degree n*/
 
double Pn(int n, double x[n+1], double y[n+1], double X){
    double sum=0;
    int i;
    for(i=0;i<=n;i++){
        sum=sum+Li(i,n,x,X)*y[i];
    }
    return sum;
}
int main(){
    int i,n;  //n is the degree
    printf("Enter the number of data-points:\n");
    scanf("%d",&n);  //no. of data-points is n+1
    n=n-1;
    //Arrays to store the (n+1) x and y data-points of size n+1
    double x[n+1];
    double y[n+1];
    printf("Enter the x data-points:\n");
    for(i=0;i<n+1;i++){
        scanf("%lf",&x[i]);
    }
     
    printf("Enter the y data-points:\n");
    for(i=0;i<n+1;i++){
        scanf("%lf",&y[i]);
    }
     
    double X;  //value of x for which interpolated value is required
    printf("Enter the value of x for which you want the interpolated value of y(x):\n");
    scanf("%lf",&X);
    printf("The interpolated value is %lf",Pn(n,x,y,X));

    return 0 ;
}
