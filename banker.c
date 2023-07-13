/*8. Design, develop and implement a C/C++/Java program to implement Banker’s
algorithm. Assume suitable input required to demonstrate the results.*/

#include <stdio.h>

void main()
{
    int alloc[7][5], need[7][5], max[7][5], rsrc[5], avail[5], safe[5], f[7];
    int i, j, k = 0, c = 0, loopc=1, np, nr, total;
    for (i = 1; i <= 7; i++)
    {
        f[i] = 0;
    }

    printf("Enter No of Processes(p):");
    scanf("%d", &np);
    printf("Enter No of resources(r)");
    scanf("%d", &nr);

    printf("Enter Allocation Matrix:\n");
    for (i = 1; i <= np; i++)
        for (j = 1; j <= nr; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for (i = 1; i <= np; i++)
        for (j = 1; j <= nr; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Total No. of each RSRSC:");
    for (j = 1; j <= nr; j++)
        scanf("%d", &rsrc[j]);

    for (i = 1; i <= np; i++)
        for (j = 1; j <= nr; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for (j = 1; j <= nr; j++)
    {
        total = 0;
        avail[j] = 0;
        for (i = 1; i <= np; i++)
            total += alloc[i][j];
        avail[j] = rsrc[j] - total;
    }

    printf("Avaiable:");
    for (j = 1; j <= nr; j++)
        printf("%d", avail[j]);

    printf("\n\nAlloc MATRIX:\tMax Matrix:\tNeed Marix:\n");
    for (i = 1; i <= np; i++)
    {
        for (j = 1; j <= nr; j++)
            printf("%d", alloc[i][j]);
        printf("\t\t");

        for (j = 1; j <= nr; j++)
            printf("%d", max[i][j]);
        printf("\t\t");

        for (j = 1; j <= nr; j++)
            printf("%d", need[i][j]);
        printf("\n");
    }

    while (loopc < np && c != np)
    {
        ++loopc;
        for (i = 1; i <= np; i++)
        {
            if (f[i] == 0)
            {
                for (j = 1; j <= nr; j++)
                {
                    if (need[i][j] > avail[j])
                        break;
                }
                if (j == nr + 1)
                {
                    for (j = 1; j <= nr; j++)
                        avail[j] += alloc[i][j];
                    f[i] = 1;
                    ++c;
                    safe[k++] = i;
                }
            }
        }
    }

    if (c == np)
    {
        printf("Safe State:\n");
        for (k = 0; k < np; k++)
            printf("%d->", safe[k]);
    }
    else
        printf("NO Safe State:");
}