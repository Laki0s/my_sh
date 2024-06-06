/*
** EPITECH PROJECT, 2024
** miniradiateur2rendu
** File description:
** main
*/

#include "../include/my.h"
#include "../include/mylist.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char *back_to_home(global_t *radiateur)
{
    env_42_copy_t *caca = radiateur->chaise;

    while (caca) {
        if (my_strcmp(caca->name, "HOME") == 0) {
            return (caca->data);
        } else
            caca = caca->next;
    }
    return NULL;
}

char *retour(global_t *radiateur)
{
    env_42_copy_t *caca = radiateur->chaise;

    while (caca) {
        if (my_strcmp(caca->name, "OLDPWD") == 0) {
            return (caca->data);
        } else
            caca = caca->next;
    }
    return NULL;
}

static char *avec_vaglette(global_t *radiateur)
{
    char *tmp;
    char caca[1024];
    char *home = back_to_home(radiateur);

    if (home == NULL)
        return NULL;
    tmp = malloc(sizeof(char) * (my_strlen(home + 1)));
    my_strcpy(tmp, home);
    my_strcat(tmp, "/");
    for (int i = 2; radiateur->path[i]; i++) {
        caca[i - 2] = radiateur->path[i];
        if (radiateur->path[i])
            caca[i - 1] = '\0';
    }
    return (my_strcat(tmp, caca));
}

static char *directorie(global_t *radiateur)
{
    if (radiateur->path == NULL)
        return (back_to_home(radiateur));
    if (radiateur->path[0] == '~' && radiateur->path[1] == '/')
        return (avec_vaglette(radiateur));
    if (my_strcmp(radiateur->path, "-") == 0)
        return (retour(radiateur));
    return (radiateur->path);
}

static char *new_path(char *str, char *full_path)
{
    if (str != NULL) {
        free(str);
        if (full_path != NULL)
            str = malloc(sizeof(char) * (my_strlen(full_path) + 2));
    }
    if (full_path != NULL && str != NULL)
        my_strcpy(str, full_path);
    else
        str = my_strdup(full_path);
    return str;
}

static char *check(global_t *radiateur)
{
    if (radiateur->env == NULL)
        return NULL;
    else
        return (directorie(radiateur));
}

static int gestion_error(char *dir, global_t *radiateur, int v)
{
    struct stat fd;

    if (lstat(dir, &fd) == -1)
        return 1;
    else if (radiateur->arg[3] != NULL) {
        my_putstr("cd: Too many arguments.\n");
        return 1;
    }
    if (S_ISDIR(fd.st_mode) == false) {
        my_printf("%s: Not a directory.\n", dir);
        return 1;
    } else if (access(dir, R_OK | X_OK) == 0) {
        my_printf("%s: Permission denied.\n", dir);
        return 1;
    }
    if (v == -1) {
        my_printf("%s: No such file or directory.\n", dir);
        return 1;
    }
    return 0;
}

int ckaaka(global_t *radiateur)
{
    char tmp[1024];
    char *dir = check(radiateur);
    char *old_dir = my_strdup(getcwd(tmp, 1024));
    env_42_copy_t *caca = radiateur->chaise;
    int value;

    if (dir == NULL)
        return 1;
    value = chdir(dir);
    if (value != 0 && gestion_error(dir, radiateur, value) != 0)
        return 1;
    while (caca) {
            if (my_strcmp(caca->name, "PWD") == 0)
            caca->data = new_path(caca->data, getcwd(tmp, 1024));
        if (my_strcmp(caca->name, "OLDPWD") == 0)
            caca->data = new_path(caca->data, old_dir);
        caca = caca->next;
    }
    free(old_dir);
    return 1;
}
