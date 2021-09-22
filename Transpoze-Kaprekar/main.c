#include<math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

long int **dinamik(int sutun,int satir) {

    long **dizi;

    int i;
    dizi = malloc(sutun*sizeof( *dizi));

    for(i=0;i<sutun;i++)
        dizi[i] =malloc(satir*sizeof((*dizi[i])));

    return dizi;
}


void rastgele( long int** dizi,int sutun,int satir) {
    int i, j;
    srand(time(NULL));

    for(i=0;i<sutun;i++)
    {
        for(j=0;j<satir;j++)
        {
            dizi[i][j]= 5+ rand() %50;
        }

    }

}

int main()
{
    long int**p;
    int sa,su,temp;
    printf("sutun sayisini giriniz-->");
    scanf("%d",&su);
    printf("\nsatir sayisini giriniz-->");
    scanf("%d",&sa);printf("\n");

    p = dinamik(su,sa);
    rastgele(p,su,sa);
    siralama(p,su,sa);
    transpoze(p,su,sa);
    yazdirma(p,su,sa);
    kaprekar_yazdirma(p,su,sa);





    return 0;
}
int siralama( long int** dizi,int sutun,int satir)
{
    printf("SIRALANMIS HALI\n");
    printf("\n");
    long t,i,j;
    long temp;
    for(t=1; t<sutun*satir; t++)
    {
        for(i=0; i<sutun; i++)
        {
            for(j=0; j<satir-1; j++)
            {
                if (dizi[i][j]>dizi[i][j+1])
                {
                    temp=dizi[i][j];
                    dizi[i][j]=dizi[i][j+1];
                    dizi[i][j+1]=temp;
                }
            }
        }
        for(i=0; i<satir-1; i++)
        {
            if (dizi[i][satir-1]>dizi[i+1][0])
            {
                temp=dizi[i][satir-1];
                dizi[i][satir-1]=dizi[i+1][0];
                dizi[i+1][0]=temp;
            }
        }
    }
    for( i =0;i<sutun;i++){
        for( j =0;j<satir;j++){

    printf("% ld  ", dizi[i][j]);
        }
    printf("\n");
    }
    return 0;
}
void transpoze(long int** dizi,int sutun,int satir)
{
    int a[sutun][satir];
    printf("\nTRANSPOZESI ALINMIS HALI\n");
   int temp,i,j;

   for (i = 0; i<sutun; i++)
   {

      for (j =i+1; j<satir; j++)
      {

         a[i][j]=dizi[i][j];
         dizi[i][j]=dizi[j][i];
         dizi[j][i]=a[i][j];
      }
   }


   printf("\n") ;

   for ( i = 0; i<sutun; i++)
   {

      for (j = 0; j<satir; j++)
      {

         printf(" %ld ",dizi[i][j]);
      }
         printf("\n");
   }




}
void yazdirma(long int** dizi,int sutun,int satir)
{
    FILE*fp;
    int i,j,c;


    fp=fopen("transpoze.txt","w");
     c=getc(fp);
while(1)
{
    for(i=0; i<sutun; i++)
     {
        for(j=0; j<satir; j++)
         {
           fprintf(fp, "%ld ", *(*(dizi +j)+i));
         }
            fprintf(fp ,"\n");
     }
            fprintf(fp ,"\n");
     for( i=0; i<sutun; i++)
      {
        for( j=0; j<satir; j++)
         {
           fprintf(fp, "%ld ", *(*(dizi +i)+j));
         }
            fprintf(fp ,"\n");
      }
            fprintf(fp,"\n");

     if(c==EOF)
      {
         printf("\n  !!yazma islemi tamam!!\n");
         break;
      }

}
     fclose(fp);



}

bool kaprekar(int sayi)
{
    int i,j,sayi1=0,bas2=0,eleman_bas,bas1=0,karesi,basamak,temp;
    int dizi1[50];

    karesi=sayi*sayi;
		temp=sayi;
		while(temp>0)
		{
			temp=temp/10;
			bas1++;
		}
		eleman_bas=bas1-1;

		while(karesi>0 && bas2<bas1)
		{
			basamak=karesi%10;
			karesi=karesi/10;
			dizi1[eleman_bas]=basamak;
			eleman_bas--;
			bas2++;
		}


		for(j=0;j<bas1;j++)
		{
			sayi1=sayi1*10 + dizi1[j];
		}


         if((karesi+sayi1)==sayi)
         return true;
         else
            return false;


}
void kaprekar_yazdirma(long int**dizi,int sutun,int satir)
{
    FILE *fp1;
    fp1=fopen("kaprekar.txt","w");
    int i,j,temp=0;
    printf("\n");
    for(i=0;i<sutun;i++)
     {
       for(j=0;j<satir;j++)
       {
           if(kaprekar(dizi[i][j]))
           {

               printf("%3d kaprekar sayidir.\n",dizi[i][j]);
               fprintf(fp1," %3d kaprekar sayidir.\n",dizi[i][j]);
               temp++;
           }
       }
     }

        if(temp==0)
           {
                printf("\n  !!kaprekar sayi yok!!\n");
           }
    fclose(fp1);

}
