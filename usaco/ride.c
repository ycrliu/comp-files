/*
ID: robertl8
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); (i)++)

char s1[7];
char s2[7];

int main()
{
    FILE *fin = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");
    fscanf(fin, "%s%s", s1, s2);
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int p1 = 1;
    int p2 = 1;
    FOR(i, 0, n1) p1 *= 1 + (s1[i] - 'A');
    FOR(i, 0, n2) p2 *= 1 + (s2[i] - 'A');
    fprintf(fout, "%s\n", p1 % 47 == p2 % 47 ? "GO" : "STAY");
    return 0;
}
