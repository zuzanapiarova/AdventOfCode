#include "../aoc.h"

// -------- FIRST PART ----------
int search_line(char *line)
{
    char *temp;
    char *new_temp;
    temp = line;
    int i = 0;
    int count = 0;
    while (*temp)
    {
        new_temp = strstr(temp, "XMAS");
        if (!new_temp)
            return (count);
        else
        {
            count++;
            temp = new_temp + 1;
        }
        temp++;
    }
    return (count);
}

int search_line_back(char *line)
{
    char *temp;
    char *new_temp;
    temp = line;
    int i = 0;
    int count = 0;
    //printf("line: %s\n", line);
    while (*temp)
    {
        new_temp = strstr(temp, "SAMX");
        if (!new_temp)
            return (count);
        else
        {
            count++;
            temp = new_temp + 1;
        }
        temp++;
    }
    return (count);
}

int search_column(char *one, char *two, char *three, char *four)
{
    int count = 0;
    int i = 0;
    while (one[i])
    {
        if (one[i] == 'X' && two[i] == 'M' && three[i] == 'A' && four[i] == 'S')
            count++;
        i++;
    }
    return (count);
}

int search_diagonal_TL_BR(char *one, char *two, char *three, char *four)
{
    int count = 0;
    int i = 0;
    while (one[i])
    {
        if (one[i] == 'X' && two[i + 1] == 'M' && three[i + 2] == 'A' && four[i + 3] == 'S')
            count++;
        i++;
    }
    return (count);
}

int search_diagonal_TR_BL(char *one, char *two, char *three, char *four)
{
    int count = 0;
    int i = 0;
    while (one[i])
    {
        if (one[i + 3] == 'X' && two[i + 2] == 'M' && three[i + 1] == 'A' && four[i] == 'S')
            count++;
        i++;
    }
    return (count);
}

int get_xmas_count(char **stored_lines, int line_count)
{
    int count = 0;
    int i = 0;
    int ln_count = 0;
    int col_count = 0;
    int diag_count = 0;
    while (i < line_count)
    {
        ln_count += search_line(stored_lines[i]) + search_line_back(stored_lines[i]);
        if (i < line_count - 3)
        {
            col_count += search_column(stored_lines[i], stored_lines[i + 1], stored_lines[i + 2], stored_lines[i + 3]) + search_column(stored_lines[i + 3], stored_lines[i + 2], stored_lines[i + 1], stored_lines[i]);
            diag_count += search_diagonal_TL_BR(stored_lines[i], stored_lines[i + 1], stored_lines[i + 2], stored_lines[i + 3])
                        + search_diagonal_TL_BR(stored_lines[i + 3], stored_lines[i + 2], stored_lines[i + 1], stored_lines[i])
                        + search_diagonal_TR_BL(stored_lines[i], stored_lines[i + 1], stored_lines[i + 2], stored_lines[i + 3])
                        + search_diagonal_TR_BL(stored_lines[i + 3], stored_lines[i + 2], stored_lines[i + 1], stored_lines[i]);
        }
        i++;
    }
    // printf("line count: %d\n", ln_count);
    // printf("col count: %d\n", col_count);
    // printf("diag count: %d\n", diag_count);
    count = ln_count + col_count + diag_count;
    // printf("count: %d\n", count);
    return (count);
}

// -------- SECOND PART ----------

// one ...
// two .A.
// thr ...

int search_row_by_row(char *one, char *two, char *three)
{
    int count = 0;
    int i = 1;
    int len = strlen(one);
    while (i < len - 1)
    {
        // printf("from top left: %c%c%c\n", one[i - 1], two[i], three[i + 1]);
        // printf("from bottom left: %c%c%c\n", three[i - 1], two[i], one[i + 1]);
        if (two[i] == 'A')
        {
            if ((one[i - 1] == 'M' && one[i + 1] == 'M' && three[i - 1] == 'S' && three[i + 1] == 'S')
                || (one[i - 1] == 'S' && one[i + 1] == 'S' && three[i - 1] == 'M' && three[i + 1] == 'M')
                || (one[i - 1] == 'S' && one[i + 1] == 'M' && three[i - 1] == 'S' && three[i + 1] == 'M')
                || (one[i - 1] == 'M' && one[i + 1] == 'S' && three[i - 1] == 'M' && three[i + 1] == 'S'))
                count++;
        }
        i++;
    }
    return (count);
}

int get_x_mas_count(char **stored_lines, int line_count)
{
    int count = 0;
    int i = 0;

    while (i < line_count - 2)
    {
        count += search_row_by_row(stored_lines[i], stored_lines[i + 1], stored_lines[i + 2]);
        i++;
    }
    return(count);
}

// -------- MAIN ----------

int main(void)
{
    char *stored_lines[MAX_LINES];
    int line_count = 0;

    FILE *file = fopen("inputs/input4.txt", "r");
    if (!file)
       return (perror("Error opening file"), 1);
    while (line_count < MAX_LINES)
    {
        char buffer[MAX_LINE_LENGTH];
        if (fgets(buffer, MAX_LINE_LENGTH, file) == NULL)  // end of file or error
            break;
        stored_lines[line_count] = strdup(buffer);
        if (stored_lines[line_count] == NULL)
        {
            perror("Memory allocation error");
            break;
        }
        line_count++;
    }
    fclose(file);

    // int xmas_count = get_xmas_count(stored_lines, line_count);
    // printf("XMAS count: %d\n", xmas_count);
    int x_mas_count = get_x_mas_count(stored_lines, line_count);
    printf("X_MAS count: %d\n", x_mas_count);
    int i = 0;
    while (i < line_count)
    {
        free(stored_lines[i]);
        i++;
    }
    return (0);
}
