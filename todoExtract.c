#include "stdio.h"
main()
{
    FILE *fp1,*fp2;
    fp2 = fopen("../todoListFile.txt", "w"); //dosya acildi.
    char c;
    fp1 = fopen("../someFile.c","r");
    int str=1;
    while (c != EOF) //bastan son karaktere kadar arama
    {
        c = getc(fp1);
        if(c =='\n')
            str++;  //satir sayisini arttirdim.
        if(c == '/')
        {
            c = getc(fp1);
            if(c == '/'){  //TODO satirlarini ikinci slash 'indan sonrasini satir boyunca kontrol ediyor.
                fprintf(fp2,"%5d satir: ", str);  //dosyada goruntulenmesi
                printf("%5d satir ", str);  //exe'de de gozukmesi
                printf("/someFile.c");
                printf("/todoListFile.c");

                while(c != '\n')
                {
                c = getc(fp1);
                putc(c,fp2);
                }
                str++;
            }
        }
    }
    fclose(fp1); //dosya kapatilir.
}
