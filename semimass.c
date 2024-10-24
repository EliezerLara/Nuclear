//Program that gets the semiempirical mass formula for a number A in terms of Z

#include<stdio.h>
#include<math.h>

#define mp 938.272
#define mn 939.565
#define av 15.75 
#define as 17.8
#define ac 0.711
#define asym 23.7


int main (){

    int A=43, Z , l;
    double m, B, def;

    //B = av*A-as*pow(A,(2.0/3.0))-ac*(Z*(Z-1)/pow(A,(1.0/3.0)))-asym*(pow((A-2*Z),2)/A);

    FILE*arch=fopen("semi.txt", "w");

        for(l=14;l<24;l++){

            Z=l+1;
            //printf("%d\n", Z);

            B = av*A-as*pow(A,(2.0/3.0))-ac*(Z*(Z-1)/pow(A,(1.0/3.0)))-asym*(pow((A-2*Z),2)/A);

            m = mp*Z+mn*(A-Z)-B;

            def = (mp*Z+mn*(A-Z))-m;

            fprintf(arch, "%d %lf %d %lf\n", Z, m, Z, def);
        }
    

    fclose(arch);


    return 0;

}



