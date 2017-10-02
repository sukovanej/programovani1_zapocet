#include <stdio.h>
#include "src/test.h"
#include "src/cetnost.h"
#include "src/mincovka.h"

#define enable_output 1

void tests();

int main()
{
    tests();
}

void tests()
{
    /** string_size() */
    assert_unsigned_int(string_size("ahoj"), 4);
    assert_unsigned_int(string_size(""), 0);
    assert_unsigned_int(string_size("123456789"), 9);
    /** /string_size() */

    /** cetnost() */
    int *result1 = cetnost("abcd");
    assert_int(result1[0], 1);
    assert_int(result1[1], 1);
    assert_int(result1[2], 1);
    assert_int(result1[3], 1);

    int *result2 = cetnost("aabbbccccddddd");
    assert_int(result2[0], 2);
    assert_int(result2[1], 3);
    assert_int(result2[2], 4);
    assert_int(result2[3], 5);

    int *result3 = cetnost("a b c ");
    assert_int(result3[0], 1);
    assert_int(result3[1], 3);
    assert_int(result3[2], 1);
    assert_int(result3[3], 1);
    /** /cetnost() */

    /** mincovka */
    unsigned int *result4;
    assert_int(mincovka(1000, &result4), 1);
    assert_int(result4[0], 1000);

    unsigned int *result5;
    assert_int(mincovka(1234, &result5), 6);
    assert_int(result5[0], 1000);
    assert_int(result5[1], 200);
    assert_int(result5[2], 20);
    assert_int(result5[3], 10);
    assert_int(result5[4], 2);
    assert_int(result5[5], 2);

    unsigned int *result6;
    assert_int(mincovka(12345, &result6), 8);
    assert_int(result6[0], 5000);
    assert_int(result6[1], 5000);
    assert_int(result6[2], 2000);
    assert_int(result6[3], 200);
    assert_int(result6[4], 100);
    assert_int(result6[5], 20);
    assert_int(result6[6], 20);
    assert_int(result6[7], 5);

    /** /mincovka */

    /** uklid */
    free(result1);
    free(result2);
    free(result3);
    free(result4);
    free(result5);
    free(result6);
}