#include "../aoc.h"

// --------------- FIRST PART -------------------------

int is_decreasing(char **arr)
{
    printf("decreasing\n");
    int i = -1;
    int val;
    int val_next;

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

// --------------- SECOND PART -------------------------

int is_increasing_skip(char **arr, int leave_out)
{
    int val;
    int val_next;
    int next_index;
    int size = get_arr_size(arr);
    int i = 0;
    while (i < size - 1)
    {
        if (i == leave_out)
        {
            if (i + 1 == leave_out)
                next_index = i + 2;
            else
                next_index = i + 1;
        }
        if (next_index >= size)
            break ;
        val = atoi(arr[i]);
        val_next = atoi(arr[next_index]);
        if (val_next <= val || val_next > val + 3)
            return (0);
        i++;
    }
    return (1);
}

int is_decreasing_skip(char **arr, int leave_out)
{
    int val;
    int val_next;
    int next_index;
    int size = get_arr_size(arr);
    int i = 0;
    while (i < size - 1)
    {
        if (i == leave_out)
        {
            if (i + 1 == leave_out)
                next_index = i + 2;
            else
                next_index = i + 1;
        }
        if (next_index >= size)
            break ;
        val = atoi(arr[i]);
        val_next = atoi(arr[next_index]);
        if (val_next >= val || val_next < val - 3)
            return (0);
        i++;
    }
    return (1);
}

int check_safety_incr(char **arr)
{
    int i = 0;
    int res;

    while (arr[i])
    {
        res = is_increasing_skip(arr, i);
       // printf("incr safety without %s: %d\n", arr[i], res);
        if (res)
            return (1);
        i++;
    }
    return (0);
}

int check_safety_decr(char **arr)
{
    int i = 0;
    int res;

    while (arr[i])
    {
        res = is_decreasing_skip(arr, i);
        //printf("decr safety without %s: %d\n", arr[i], res);
        if (res)
            return (1);
        i++;
    }
    return (0);
}

// --------------- MAIN -------------------------

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
        safe = safe + check_safety_incr(temp) + check_safety_decr(temp);
        //printf("safety %d: %d\n", i, safe);
        free_arr(temp);
        i++;
    }
    free_arr(arr);
    //printf("safe: %d\n", safe);
    return (safe);
}
