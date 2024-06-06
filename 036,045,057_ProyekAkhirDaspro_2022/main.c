#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

int main(void)
{
    int system(const char *command);
    int pilih, k, ascii, i, j, n;
    char str[100];
    int jlh = 0;
    int key = 0;
    int tampung = 0;
    char file[20];
    int enk;
    char nf[10];
    char nn[10];
    char c;
    FILE *fa;
    FILE *fn;
    FILE *data;
    char z[144];

    printf("Input your file name for sender ! : ");
    scanf("%s", nf);
    strcat(nf, "sender");
    strcat(nf, ".txt");
    fa = fopen(nf, "a+");

    printf("\nInput your file name for receiver ! : ");
    scanf("%s", nn);
    strcat(nn, "receiver");
    strcat(nn, ".txt");
    fn = fopen(nn, "a+");

    system("cls");
    do
    {

        puts("\n\n\t Choose What do you want: \t \n");
        puts("1.Encryption");
        puts("2.Descryption");
        puts("3.Exit \n");
        printf("Choose : ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:

            printf("\nThis is Encryption \n");
            printf("Enter String :");
            scanf("%c", &c);
            scanf("%[^\n]s", &str);
            fprintf(fa, "Ciphertext : \t Key :\n");

            printf("\n");
            printf("Operator Kunci :");
            scanf(" %d", &enk);
            printf("\n");

            char a = 177, b = 219;
            printf("\t\t");
            for (int i = 0; i < 80; i++)
                printf("%c", a);
            printf("\r");
            printf("\t\t");
            for (int i = 0; i < 80; i++)
            {
                printf("%c", b);
                Sleep(10);
            }
            system("CLS");
            printf("\n");

            for (k = 0; k < 100; k++)
            {
                if (str[k] != '\0')
                {
                    ascii = str[k];

                    if ((ascii >= 0 && ascii < 48) | (ascii >= 58 && ascii < 65) | (ascii >= 91 && ascii <= 96) | ascii > 122 && ascii < 184)
                    {
                        puts("You cannot input Symbols");
                        break;
                    }

                    else
                    {

                        for (k = 0; k < 100; k++)
                        {
                            if (str[k] != '\0')
                            {
                                ascii = str[k];
                                tampung = ascii % enk;
                                key = ascii / enk;

                                fprintf(fa, "%d \t\t\t\t %d\n", ascii / enk, ascii % enk);
                                fprintf(fn, "%c ", (key * enk) + tampung);
                            }
                            else
                            {
                                break;
                            }
                        }
                        fprintf(fa, "\t\t\t\t %d", enk);
                        fprintf(fa, "\n");
                        fprintf(fa, "Total : %d", k);
                        fprintf(fa, "\n");
                        fflush(fa);
                        fflush(fn);
                    }
                    break;
                }
                fflush(fa);
                fflush(fn);

                return 0;

            case 2:

                printf("Enter a filename:\n");
                fscanf(stdin, "%s", z);
                data = fopen(z, "r");

                char readfile[100];
                printf("\n");

                while (!feof(data))
                {
                    fgets(readfile, 1024, data);
                    printf("%s", readfile);
                    break;
                }
                printf("\n");
                getch();
                break;

            case 3:;
                printf("\n\t\t\t\t\t\t\tGoodbye\n\n");

                char a = 177, b = 219;
                printf("\t\t");
                for (int i = 0; i < 88; i++)
                    printf("%c", a);
                printf("\r");
                printf("\t\t");
                for (int i = 0; i < 88; i++)
                {
                    printf("%c", b);
                    Sleep(10);
                }
                break;
            default:
                printf("Wrong Choice. Enter again\n");
                break;
            }
        }
        fprintf(fa, "\n");

        printf("\e[1;1H\e[2J");
        fflush(fa);

    } while (pilih != 3);
}