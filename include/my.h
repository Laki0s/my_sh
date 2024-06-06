/*
** EPITECH PROJECT, 2023
** OwO
** File description:
** UwU
*/

#ifndef MY_H
    #define MY_H
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include "mylist.h"
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
void my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
int my_show_word_array(char *const *str);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_strlen_alpha(char *s);
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
char *my_strdup(char const *src);
int flag_c(va_list list);
int flag_d(va_list list);
int flag_i(va_list list);
int flag_s(va_list list);
int flag_pourcent(va_list list);
int flag_o(va_list list);
int my_printf(const char *format, ...);
int flag_f(va_list list);
char **my_str_to_array(char *str, char sep);
int set_boudin(global_t *set_boudin);
env_42_copy_t *copy_boudin(char **env);
int unset_boudin(global_t *set_boudin, char *str);
void agrument(global_t *radiateur);
int print_env(env_42_copy_t *archi_jtm);
int set_boudin(global_t *set_boudin);
int ckaaka(global_t *radiateur);
int execution(global_t *radiateur);
int dir_442(global_t *radiateur);
void arguments(global_t *radiateur, char *str);
int caca(char **tab, global_t *radiateur, int *index);
bool cmd(global_t *radiateur);
#endif
