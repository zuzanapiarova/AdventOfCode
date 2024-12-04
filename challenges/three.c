#include "../aoc.h"

int is_valid(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int find_val(char *str)
{
    int i = 0;
    int res = 0;
    char *first;
    char *second;
    int second_start = 0;
    while (str[i] && str[i] != ',')
        i++;
    if (i > ft_strlen(str))
        return (0);
    first = ft_substr(str, 0, i);
    second_start = i + 1;
    while (str[i] && str[i] != ')')
        i++;
    second = ft_substr(str, second_start, i);
    // printf("first: %s\n", first);
    // printf("second: %s\n", second);
    if (!is_valid(first) || !is_valid(second))
        return (0);
    else
    {
        res = atoi(first) * atoi(second);
    }
    free(first);
    free(second);
    return (res);
}

int process_input(char *input, int *do_flag)
{
    int res = 0;
    int start = 0;
    int len = 0;
    char *temp;
    int i = -1;
    int val = 0;

// ---------------------------- second part addition below -----------------------------
    while (input[++i])
    {
        len = 0;
        if (input[i] && input[i] == 'd')
        {
            i++;
            if (input[i] && input[i] == 'o')
            {
                i++;
                if (input[i] && input[i] == '(')
                {
                    i++;
                    if (input[i] && input[i] == ')')
                    {
                        i++;
                        *do_flag = 1;
                        printf("--- DO ---\n");
                    }
                }
                else if (input[i] && input[i] == 'n')
                {
                    i++;
                    if (input[i] && input[i] == '\'')
                    {
                        i++;
                        if (input[i] && input[i] == 't')
                        {
                            i++;
                            if (input[i] && input[i] == '(')
                            {
                                i++;
                                if (input[i] && input[i] == ')')
                                {
                                    i++;
                                    *do_flag = 0;
                                    printf("--- DONT ---\n");
                                }
                            }
                        }
                    }
                }
            }
        }
// -------------------------- second part addition above --------------------------------
        if (input[i] && input[i] == 'm' && *do_flag == 1)
        {
            i++;
            if (input[i] && input[i] == 'u')
            {
                i++;
                if (input[i] && input[i] == 'l')
                {
                    i++;
                    if (input[i] && input[i] == '(')
                    {
                        if (input[i + 1] && !ft_isdigit(input[i + 1]))
                            continue ;
                        i++;
                        start = i;
                        while (input[i] && input[i] != ')')
                        {
                            if (input[i] == 'm' || input[i] == 'd')
                            {
                                i--;
                                break ;
                            }
                            len++;
                            i++;
                        }
                        if (len > 0)
                        {
                            temp = ft_substr(input, start, len);
                            printf("temp: %s\n", temp);
                            val = find_val(temp);
                            printf("val: %d\n", val);
                            res += val;
                            free(temp);
                        }
                    }
                }
            }
        }
    }
    return (res);
}

int main()
{
    char *stored_lines[MAX_LINES];
    int line_count = 0;
    int do_flag = 1;

    FILE *file = fopen("inputs/input", "r");
    if (!file)
        return (perror("Error opening file"), 1);
    while (line_count < MAX_LINES)
    {
        char buffer[MAX_LINE_LENGTH];
        if (fgets(buffer, MAX_LINE_LENGTH, file) == NULL) // end of file or error
            break ;
        stored_lines[line_count] = strdup(buffer);
        if (stored_lines[line_count] == NULL)
        {
            perror("Memory allocation error");
            break ;
        }
        line_count++;
    }
    fclose(file);
// ----------------------------
    long res = 0;
    int val = 0;
    for (int i = 0; i < line_count; i++)
    {
        val = process_input(stored_lines[i], &do_flag);
        res += val;
       // printf("val: %d\n", val);
        free(stored_lines[i]);
    }
    printf("res: %ld\n", res);
    return (res);
}

