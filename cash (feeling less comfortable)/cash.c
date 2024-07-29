#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int money;
    do
    {
        money = get_int("Change owed: ");
    } while (money < 0);

    int quarters=money/25;
    money%=25;
    int dimes=money/10;
    money%=10;
    int nickels=money/5;
    money%=5;
    int pennies=money;
    int total_coins=quarters+dimes+nickels+pennies;
    printf("%d\n", total_coins);
}
