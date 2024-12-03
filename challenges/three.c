#include "../aoc.h"

#define MAX_LINES 100
#define MAX_LINE_LENGTH 1024

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

int find_val(char *str) // (45,67) or (!5, 8]dskjn!)
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

int process_input(char *input)
{
    int res = 0;
    int start = 0;
    int len = 0;
    char *temp;
    int i = -1;
    int val = 0;
    while (input[++i])
    {
        len = 0;
        //printf("i: %d %c\n", i, input[i]);
        if (input[i] && input[i] == 'm')
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
                            if (input[i] == 'm')
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


// 170497160 too low
// 172921095 wrong
int main() {
    FILE *file = fopen("inputs/input3.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char *stored_lines[MAX_LINES];
    int line_count = 0;

    while (line_count < MAX_LINES) {
        char buffer[MAX_LINE_LENGTH];
        if (fgets(buffer, MAX_LINE_LENGTH, file) == NULL) {
            break; // End of file or error
        }

        // Store each line dynamically
        stored_lines[line_count] = strdup(buffer);
        if (stored_lines[line_count] == NULL) {
            perror("Memory allocation error");
            break;
        }
        line_count++;
    }

    fclose(file);
    long res = 0;
    int val = 0;
    // Reuse stored input
    //val = process_input(stored_lines[9]);

    printf("Stored input lines:\n");
    for (int i = 0; i < line_count; i++)
    {
        val = process_input(stored_lines[i]);
        res += val;
        printf("val: %d\n", val);
        free(stored_lines[i]); // Free allocated memory
    }
    printf("res: %ld\n", res);
    return (res);
}

