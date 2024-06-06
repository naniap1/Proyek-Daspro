#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main()
{
    int system(const char *command);
    FILE *fa;
    int pilih, k, ascii, i, j, n;
    char str[100];
    int jlh = 0;
    int teks[100];
    int key[100];
    int tampung = 0;
    int enk;
    char c;

    fa = fopen("receiver.txt", "ab+");
    if (fa == NULL)
    {
        printf("file can't Opened");
    }
    else
    {
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
                fprintf(fa, "Ciphertext : \t Key :\n");

                printf("\nThis is Encryption \n");
                scanf("%c", &c);
                printf("Enter String :");
                scanf("%[^\n]", &str);

                printf("\n");
                printf("Operator Kunci :");
                scanf("%d", &enk);
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
                            // printf("Convert teks ASCII to desimal : ");

                            // for (k = 0; k < 100; k++)
                            // {
                            //     if (str[k] != '\0')
                            //     {
                            //         ascii = str[k];
                            //         printf("%d  ", ascii);
                            //     }
                            //     else
                            //     {
                            //         break;
                            //     }
                            // }

                            // printf("\n");
                            for (k = 0; k < 100; k++)
                            {
                                if (str[k] != '\0')
                                {
                                    ascii = str[k];

                                    fprintf(fa, "%d \t\t\t\t %d\n", ascii / enk, ascii % enk);
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
                        }
                        break;
                    }
                    break;
                    return 0;

                case 2:
                    puts("This is menu to Descryption \n");
                    int hsl1, hsl2, tian;
                    printf("jumlah Chiper dan Key :");
                    scanf("%d", &jlh);
                    printf("Operator Kunci :");
                    scanf("%d", &enk);
                    system("cls");

                    for (i = 0; i < jlh; i++)
                    {
                        for (j = 0; j < jlh; j++)
                        {
                            for (n = 0; n < jlh; n++)
                            {

                                printf("Input chiper :");
                                scanf("%d", &teks[i]);
                                printf("Input Key :");
                                scanf("%d", &key[j]);
                                hsl1 = teks[i];
                                hsl2 = key[j];

                                fprintf(fa, "%c ", tampung = hsl1 * enk + hsl2);
                            }

                            fprintf(fa, "\n");
                            break;
                        }
                        break;
                    }
                    break;

                    return 0;

                    printf("\n");

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
            fflush(fa);

            system("code receiver.txt");

        } while (pilih != 3);
        system("cls");
    }
}
