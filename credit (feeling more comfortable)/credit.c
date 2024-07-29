#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    long card;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int temp = 0;
    int sum_temp = 0;
    char sum3_str[15];
    char temp_str[15];
    char str[21];

    while (1)
    {
        card = get_long("Write the card you want to check for validity: ");
        sprintf(str, "%ld", card);
        int i = 0;
        int isValid = 1;
        while (str[i] != '\0')
        {
            if (!isdigit((unsigned char)str[i]))
            {
                isValid = 0;
                break;
            }
            i++;
        }

        if (isValid)
        {
            for (int b = strlen(str) - 1; b >= 0; b--)
            {
                if ((strlen(str) - b) % 2 == 0)
                {
                    int temp_int = str[b] - '0';
                    temp = temp_int * 2;
                    sprintf(temp_str, "%i", temp);

                    if (strlen(temp_str) >= 2)
                    {
                        for (int j = 0; j < strlen(temp_str); j++)
                        {
                            sum_temp += temp_str[j] - '0';
                        }
                        sum1 += sum_temp;
                        sum_temp = 0;
                    }
                    else
                    {
                        sum1 += temp;
                    }
                }
                else
                {
                    int temp_int = str[b] - '0';
                    sum2 += temp_int;
                }
            }

            sum3 = sum2 + sum1;
            if (sum3 % 10 == 0)
            {
                if ((strlen(str) == 13 || strlen(str) == 16) && str[0] == '4')
                {
                    printf("VISA\n");
                }
                else if (strlen(str) == 15 && str[0] == '3' && (str[1] == '4' || str[1] == '7'))
                {
                    printf("AMEX\n");
                }
                else if (strlen(str) == 16 && str[0] == '5' && (str[1] >= '1' && str[1] <= '5'))
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
            break;
        }
    }
    return 0;
}
