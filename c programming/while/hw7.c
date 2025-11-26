//hw7: Check whether the given 3 digit number is Armstrong
/* 
153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
1634 = 1^4 + 6^4 + 3^4 + 4^4 = 1 + 1296 + 81 + 256 = 1634
*/
#include <stdio.h>

int main() {
    int num, original, temp, count = 0, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;
    temp = num;

    // Step 1: Count digits
    while (temp != 0) {
        count++;
        temp = temp / 10;
    }

    // Step 2: Compute Armstrong sum
    temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        int power = 1; // to store digit^count

        // simulate digit^count without using *
        int i = 0;
        while (i < count) {
            // simulate multiplication: power = power * digit;
            int mul = 0, j = 0;
            while (j < digit) { // add 'power' to itself 'digit' times
                mul = mul + power;
                j++;
            }
            power = mul;
            i++;
        }

        sum = sum + power; // add the cube/power of each digit
        temp = temp / 10;
    }

    // Step 3: Compare and print
    if (sum == original)
        printf("\n%d is an Armstrong number.", original);
    else
        printf("\n%d is NOT an Armstrong number.", original);

    return 0;
}
