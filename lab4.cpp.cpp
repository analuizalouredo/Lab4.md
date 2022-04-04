#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int quant,i;
    float medida;
    char unidade;
    int farenheit,libra,jarda,pes,milha,polegadas;
    int quant_massa,quant_distancia,quant_temperatura;
    int x,y,z;


    FILE*entrada;
    FILE*saida;
    entrada=fopen ("entrada3.txt","r");
    saida=fopen ("saida3.txt","w");


    fscanf (entrada, "%d",&quant);
    quant_massa=0;
    quant_distancia=0;
    quant_temperatura=0;
    i=1;
    while (i<=quant)
    {
        fscanf (entrada, "%f  %c", &medida,&unidade);
        if (unidade== 'k' || unidade== 'K')
        {
            libra=medida*(0.453592);
            fprintf (saida, "%.2f kilogramas equivale a %d libras\n",medida,libra);
            quant_massa=quant_massa+1;


        }

        else if (unidade== 'c'||unidade=='C')
            {
            farenheit= (9/5)*medida +32;
            fprintf (saida, "%.2f graus Celsius equivale a %d graus Farenheit\n",medida,farenheit);
            quant_temperatura=quant_temperatura+1;

            }

        else if (unidade=='m'||unidade=='M')
            {
            milha=(0.000621371)*medida;
            jarda=(0.000621371)*medida*1760-milha*1760;
            pes=3*(0.000621371)*medida*1760-milha*1760*3-jarda*3;
            polegadas=3*(0.000621371)*medida*1760*12-milha*1760*3*12-jarda*3*12-12*pes;
            fprintf (saida, "%.2f metros equivale a %d milhas,%d jardas, %d pes e %d polegadas\n",medida,milha, jarda,pes,polegadas);
            quant_distancia=quant_distancia+1;
            }


        i=i+1;




    }
    fprintf (saida, "\n-----------------------------------------\na)Qual a quantidade de casos de cada tipo\n");
    fprintf (saida,"Massa:%d\n",quant_massa);
    fprintf (saida,"Temperatura:%d\n",quant_temperatura);
    fprintf (saida,"Distancia:%d\n",quant_distancia);

    fprintf (saida,"\nb)Qual a maior massa?\n");

    fscanf (entrada,"%f",&medida);
    i=1;


    fclose (entrada);
    fclose (saida);
    system ("pause");
    return 0;


}
