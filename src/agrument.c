/*
** EPITECH PROJECT, 2024
** miniradiateur2rendu
** File description:
** main
*/

#include "../include/my.h"
#include "../include/mylist.h"
#include <sys/wait.h>

bool exit_statut(global_t *radiateur)
{
    if (radiateur->path == NULL)
        exit(0);
    for (int i = 0; radiateur->path[i]; i++)
        if (radiateur->path[i] > '9' || radiateur->path[i] < '0') {
            my_printf("exit: Expression Syntax.\n");
            return true;
        }
    exit(my_getnbr(radiateur->path));
}

static bool others(global_t *radiateur)
{
    if (my_strcmp(radiateur->cmd, "setenv") == 0) {
        if (radiateur->path == NULL)
            print_env(radiateur->chaise);
        else
            set_boudin(radiateur);
        return true;
    } else if (my_strcmp(radiateur->cmd, "unsetenv") == 0){
        unset_boudin(radiateur, radiateur->path);
        return true;
    }
    return false;
}

bool cmd(global_t *radiateur)
{
    if (my_strcmp(radiateur->cmd, "exit") == 0)
        exit_statut(radiateur);
    if (my_strcmp(radiateur->cmd, "cd") == 0) {
        ckaaka(radiateur);
        return true;
    }
    if (my_strcmp(radiateur->cmd, "env") == 0) {
        print_env(radiateur->chaise);
        return true;
    }
    return others(radiateur);
}

int exec_cmd(global_t *radiateur)
{
    if (cmd(radiateur) == true)
        return 1;
    radiateur->my_pid = fork();
    if (radiateur->my_pid == 0) {
        if (radiateur->programme == true)
            execution(radiateur);
        if (dir_442(radiateur) == 0)
            execution(radiateur);
    }
    return 0;
}

static void path(global_t *radiateur, int i)
{
    if (radiateur->arg[i] == NULL)
        return;
    if (radiateur->path == NULL && my_strcmp(radiateur->arg[i], "-") == 0)
        radiateur->path = my_strdup(radiateur->arg[i]);
    else if (radiateur->path == NULL)
        radiateur->path = my_strdup(radiateur->arg[i]);
}

void arguments(global_t *radiateur, char *str)
{
    radiateur->arg = my_str_to_array(str, ' ');
    radiateur->cmd = my_strdup(radiateur->arg[0]);
    for (int i = 0; radiateur->cmd[i]; i++)
        if (radiateur->cmd[i] == '/')
            radiateur->programme = true;
    for (int i = 1; radiateur->arg[i]; i++)
        path(radiateur, i);
}

void agrument(global_t *radiateur)
{
    char **tmp = radiateur->arg;
    int status;

    for (int i = 0; tmp[i]; i++) {
        if (caca(tmp, radiateur, &i) == 0) {
            arguments(radiateur, tmp[i]);
            exec_cmd(radiateur);
        }
        waitpid(radiateur->my_pid, &status, 0);
        radiateur->cmd = NULL;
        radiateur->path = NULL;
        radiateur->i = 0;
    }
    for (int i = 0; tmp[i]; i++)
        free(tmp[i]);
}
