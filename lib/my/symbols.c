/*
** EPITECH PROJECT, 2023
** symbols
** File description:
** flags before width specifier
*/

int symbols(const char *format, int i)
{
    int temp = 0;
    int count;

    for (temp; format[i] == '-' || format[i] == '+' || format[i] == ' '
    || format[i] == '0' || format[i] == '#'; temp++) {
        i++;
    }
    count = temp;
    for (temp; temp != 0; temp--) {
        if (format[i] == ' ' || format[i] == '+') {
            continue;
        }
        if (format[i] == '0') {
            continue;
        }
        if (format[i] == '#') {
            continue;
        }
    }
    return count;
}
