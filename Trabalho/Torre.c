#include <stdio.h>

int main()
{
    int alt, larg, torres, i;
    scanf("%d %d", &alt, &larg);
    char camp[alt][larg];
    char input[(int)1e3];

    for (i = 0; i < alt; i++)
    {
        scanf("%s", camp[i]);
        int j;
        for (j = 0; j < larg; j++)
        {
            if (camp[i][j] == 't')
                torres++;
        }
    }

    return 0;
}