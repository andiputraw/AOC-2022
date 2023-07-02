#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_MAX 1024
#define INPUT "./sample.txt"

int total_calory(int *top_3_calory)
{
    int total_calory = 0;
    for (int i = 0; i < 3; i++)
    {
        total_calory += *(top_3_calory + (sizeof(top_3_calory) * i));
    }
    return total_calory;
}
int get_lowest_calory(int *top_3_calory)
{
    int current_lowest = *top_3_calory;

    for (int i = 0; i < 3; i++)
    {
        if (*(top_3_calory + (sizeof(top_3_calory) * i)) <= current_lowest)
        {
            current_lowest = *(top_3_calory + (sizeof(top_3_calory) * i));
        }
    }

    return current_lowest;
}

void rearrange_calory(int *top_3_calory, int calory)
{
    int top_2 = *(top_3_calory + (sizeof(top_3_calory) * 1));
    int top_1 = *(top_3_calory + (sizeof(top_3_calory) * 2));

    if (calory >= top_1)
    {
        *(top_3_calory + (sizeof(top_3_calory) * 2)) = calory;
        *(top_3_calory + (sizeof(top_3_calory) * 1)) = top_1;
        *top_3_calory = top_2;
    }
    else if (calory >= top_2)
    {
        *(top_3_calory + (sizeof(top_3_calory) * 1)) = calory;
        *top_3_calory = top_2;
    }
    else
    {
        *top_3_calory = calory;
    }
    printf("%i %i %i\n", *top_3_calory, *(top_3_calory + (sizeof(top_3_calory) * 1)), *(top_3_calory + (sizeof(top_3_calory) * 2)));
}

int main()
{
#if 0
    char buffer[BUFFER_MAX];

    int current_elf = 1;
    int current_calory = 0;

    int highest_calory = 0;
    int highest_elf = 0;

    FILE *input_file = fopen(INPUT, "r");

    if (input_file == NULL)
    {

        printf("Error reading file");
        exit(1);
    }

    while (fgets(buffer, BUFFER_MAX, input_file))
    {
        current_calory += atoi(buffer);
        printf("current calory %i\n", current_calory);

        if (strlen(buffer) == 1)
        {
            current_elf++;
            current_calory = 0;
        }
        if (current_calory > highest_calory)
        {
            highest_elf = current_elf;
            highest_calory = current_calory;
        }

        printf("%s", buffer);
    }

    printf("\n");
    printf("the elf with highest calory is %i with %i calories\n", highest_elf, highest_calory);

    fclose(input_file);

    return 0;
#else
    char buffer[BUFFER_MAX];

    int top_3_calory[3] = {0, 0, 0};

    int current_calory = 0;

    FILE *input_file = fopen(INPUT, "r");

    if (input_file == NULL)
    {

        printf("Error reading file");
        exit(1);
    }

    while (fgets(buffer, BUFFER_MAX, input_file))
    {
        current_calory += atoi(buffer);
        printf("current calory %i\n", current_calory);

        if (strlen(buffer) == 1)
        {
            int lowest_calory = get_lowest_calory(top_3_calory);
            printf("lowest calorty in top 3 %i and current is %i \n", lowest_calory, current_calory);
            if (current_calory > lowest_calory)
            {
                rearrange_calory(top_3_calory, current_calory);
            }
            current_calory = 0;
        }

        printf("%s", buffer);
    }

    printf("\n");
    int lowest_calory = get_lowest_calory(top_3_calory);
    printf("lowest calorty in top 3 %i and current is %i \n", lowest_calory, current_calory);

    if (current_calory > get_lowest_calory(top_3_calory))
    {
        rearrange_calory(top_3_calory, current_calory);
    }

    printf("total calory of top 3 elf is %i calories\n", total_calory(top_3_calory));

    fclose(input_file);

    return 0;
#endif
}
