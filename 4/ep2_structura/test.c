#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct tm t1, t2;

    t1.tm_year = 2021;
    t1.tm_mon = 10;
    t1.tm_mday = 14;

    t2.tm_year = 2021;
    t2.tm_mon = 10;
    t2.tm_mday = 13;

    double diff = difftime(mktime(&t1), mktime(&t2));

    printf("%.f\n", diff);

    return 0;
}
