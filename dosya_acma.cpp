#include <stdio.h>
#include <stdlib.h>

int main () {
   FILE * fp;

   fp = fopen ("file.txt", "w+");
   if ((fp=fopen("file.txt","w+"))==NULL)
	{
		printf("bir dosyay� acamadin :'(");

	}
	else
	{
		printf("sonunda dosyayi actin :) ");
		
	}
   
   fprintf(fp, "%s %s %s %d", "tebrikler", "dosya", "act�n", 2021);
   
   fclose(fp);

   return(0);
}
