#include "../aoc.h"

int is_decreasing(char **arr)
{
    printf("decreasing\n");
    int i = -1;
    int val;
    int val_next;
    int prob_el = -1;
    int size = get_arr_size(arr);

    while (arr[++i])
    {
        val = atoi(arr[i]);
        if (arr[i + 1])
        {
            val_next = atoi(arr[i + 1]);
            if (val_next < val && val_next >= val - 3)
                continue;
            else
                return (0);
        }
    }
    return (1);
}

int is_increasing(char **arr)
{
    printf("increasing\n");
    int i = -1;
    int val;
    int val_next;
    int prob_el = -1;
    int size = get_arr_size(arr);

    while (arr[++i])
    {
        val = atoi(arr[i]);
        if (arr[i + 1])
        {
            val_next = atoi(arr[i + 1]);
            if (val_next > val && val_next <= val + 3)
                continue ;
            else
                return (0);
        }
    }
    return (1);
}

int check_safety(char **arr)
{
    if (!is_decreasing(arr) && !is_increasing(arr))
        return (0);
    return (1);
}
// 65 68 66 67 69 70 73 72
// 8 1 2 3
// 8 9 1 2 3

int main(int argc, char **argv)
{
    (void)argc;
    int i = 0;
    int j = 0;
    int safe = 0;
    char **temp;
    char **arr = ft_split(argv[1], '\n');
    while (arr[i])
    {
        temp = ft_split(arr[i], ' ');
        safe += check_safety(temp);
        free_arr(temp);
        i++;
    }
    free_arr(arr);
    printf("safe: %d\n", safe);
    return (safe);
}
