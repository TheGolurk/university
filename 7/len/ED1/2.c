#include <stdio.h>

int main(int argc, char const *argv[])
{
    int limit;
    scanf("%d", &limit);

    int t1 = 0, t2 = 1;
    int nextTerm = t1 + t2;

    for (size_t i = 3; i <= 10000; ++i)
    {
        if (nextTerm > limit) {
            return 0;
        }

        printf("%d ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }

    return 0;
}
