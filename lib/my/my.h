/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** include library
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>

void my_putchar(char c);
int recursive(int n);
int sqroot(int nb, int test_index);
int test_special_cases(int nb);
char notaletter(char *str, int i);
char lwrcs(char *str, int i);
int haystack(char *str, char const *to_find, int CharAt);
int sub_strstr(char *str, char const *to_find, int i);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_put_ll(long long nb);
int my_put_ull(unsigned long long nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_put_nbr_unsigned(unsigned int nb);
int my_putnbr_base(long long nb, char const *base);
int my_putnbr_base_count(unsigned long nb, char const *base);
int symbols(const char *format, int i);
int addthiccness(int diff, char adjuster);
int conversionwidth(char flag, va_list Warg, int prec, int width);
int adjustwidth2(int width, char flag, int prec, va_list Warg);
int adjustwidth(int width, char flag, int prec, va_list Warg);
int thiccness(int width, char flag, va_list Warg, int prec);
int printchar(const char *format, int i);
int recursive_u(unsigned int n);
int putfloat_isneg(double *nb, long long *intnb, long double *decnb);
int my_unsigned_int_counter(unsigned int nb);
int my_ull_counter(unsigned long long nb);
int *precision(const char *format, int i, int *tab_prec);
int lookahead(const char *format, int i);
int my_count_float(double nb, int prec);
int my_sci_count(double num, int prec, int isneg);
double scinot_div_neg(double num);
double scinot_div(double num);
int exponent(double num, int addminus);
int my_put_sci(char flag, int nb, int exp, int addminus);
int my_int_counter(int nb);
int my_put_float(double nb, int prec);
int my_putstrn(char const *str, int prec);
int sci_notation(double num, int prec, char flag, int nb);
int flag_char(char flag, va_list arg, int *prec);
int flags_conversions(char flag, va_list arg, int *prec, int count);
int flagschecker4(char flag, va_list arg, int *prec, int count);
int flagschecker(char flag, va_list arg, int *prec, int count);
int my_print_pointer(void *ptr);
int my_printf(const char *format, ...);
void my_str_swap(char **a, char **b);
int my_strcmp_maj(char *s1, char *s2);
int alpha_sort(char **file_names, int name_count);

#endif /* !MY_H_ */
