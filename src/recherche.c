/*
** EPITECH PROJECT, 2024
** minirar2rendu
** File description:
** main
*/

#include "../include/my.h"
#include "../include/mylist.h"
#include <string.h>

static char *cfortenchocolat(global_t *rar)
{
    env_42_copy_t *same_code = rar->chaise;

    if (rar->chaise == NULL)
        return NULL;
    while (same_code) {
        if (my_strcmp(same_code->name, "PATH") == 0) {
            return same_code->data;
        } else
            same_code = same_code->next;
    }
    return NULL;
}

static int print_error(char *str)
{
    my_putstr(str);
    my_putstr(": Command not found.\n");
    return 1;
}

static int split_dir_442(char *t, char *to, global_t *rar)
{
    my_strcpy(t, to);
    my_strcat(t, "/");
    my_strcat(t, rar->cmd);
    if (access(t, X_OK) == 0) {
        rar->lol = my_strdup(t);
        free(t);
        return 0;
    }
    return 1;
}

int dir_442(global_t *rar)
{
    char *str = cfortenchocolat(rar);
    char *to;
    char *t;

    if (str == NULL)
        return (print_error(rar->cmd));
    to = strtok(str, ":");
    t = malloc(sizeof(char) * (my_strlen(to) + my_strlen(rar->cmd) + 2));
    while (to != NULL) {
        if (split_dir_442(t, to, rar) == 0)
            return 0;
        to = strtok(NULL, ":");
        free(t);
        if (to != NULL)
            t = malloc(sizeof(char) * (my_strlen(to) +
                my_strlen(rar->cmd) + 2));
    }
    return print_error(rar->cmd);
}

static char *girou(global_t *rar)
{
    char *str = NULL;
    char buffer[1024];

    if (rar->programme == true) {
        rar->cmd = malloc(sizeof(char) *
        (my_strlen(getcwd(buffer, ((size_t)1024))) + my_strlen(rar->cmd) + 1));
        my_strcpy(rar->cmd, getcwd(buffer, ((size_t)1024)));
        str = malloc(sizeof(char) * (my_strlen(rar->cmd) + 1));
        for (int i = 1; rar->cmd[i]; i++)
            str[i - 1] = rar->cmd[i];
        my_strcat(rar->cmd, str);
    }
    return rar->cmd;
}

static bool gestion_error(char *cmd)
{
    if (access(cmd, F_OK) != 0) {
        my_printf("%s: Command not found.\n", cmd);
        return 1;
    }
    if (access(cmd, X_OK) != 0) {
        my_printf("%s: Permission denied.\n", cmd);
        return 1;
    }
    return 0;
}

int execution(global_t *rar)
{
    if (access(rar->cmd, X_OK) == 0)
        if (execve(rar->cmd, rar->arg, rar->env) == -1)
            exit(1);
    if (rar->programme == true) {
        rar->cmd = girou(rar);
        if (gestion_error(rar->cmd) != true)
            exit(1);
        if (execve(rar->cmd, rar->arg, rar->env) == -1)
            exit(1);
    }
    if (execve(rar->lol, rar->arg, rar->env) == -1)
        exit(1);
    return 0;
}
