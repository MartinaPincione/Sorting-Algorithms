#include "hamming.h"

int main()
{
    int hd;
    char* s1 = readString();
    char* s2 = readString();

    hd = computeHD(s1, s2);
    printf("hd:%d\n",hd);

    free(s1);
    free(s2);
   return 0;
}
