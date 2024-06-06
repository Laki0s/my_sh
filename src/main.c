/*
** EPITECH PROJECT, 2024
** minishell2rendu
** File description:
** main
*/

#include "../include/my.h"
#include "../include/mylist.h"

static int caca_tty(void)
{
    return (isatty(STDIN_FILENO));
}

void init_struct(global_t *radiateur, char **env)
{
    int i = 0;
    int j = 0;

    if (env[0] != NULL) {
        for (j = 0; env[j]; j++);
        radiateur->env = malloc(sizeof(char *) * (j + 1));
        for (; env[i]; i++)
            radiateur->env[i] = my_strdup(env[i]);
        radiateur->env[i] = NULL;
    } else
        radiateur->env = NULL;
    radiateur->arg = NULL;
    radiateur->cmd = NULL;
    radiateur->lol = NULL;
    radiateur->path = NULL;
    radiateur->programme = false;
    radiateur->i = 0;
    radiateur->my_pid = getpid();
    radiateur->chaise = malloc(sizeof(env_42_copy_t));
    radiateur->chaise = copy_boudin(env);
}

static int invisible(char c)
{
    if (caca_tty() == 0 && c == '\n')
        exit(1);
    if (c == '\n')
        return 1;
    return 0;
}

int main(int argc, char **argv, char **env)
{
    global_t *radiateur = malloc(sizeof(global_t));
    char *line = NULL;
    size_t size = 0;

    init_struct(radiateur, env);
    if (caca_tty() != 0)
        my_printf("$> ");
    while (getline(&line, &size, stdin) != -1) {
        if (invisible(line[0]) == 1) {
            my_printf("$> ");
            continue;
        }
        if (line[my_strlen(line) - 1] == '\n')
            line[my_strlen(line) - 1] = '\0';
        radiateur->arg = my_str_to_array(line, ';');
        agrument(radiateur);
        if (caca_tty() != 0)
            my_printf("$> ");
    }
    return 0;
}
