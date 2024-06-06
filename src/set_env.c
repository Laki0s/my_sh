/*
** EPITECH PROJECT, 2024
** minishell2rendu
** File description:
** set_boudin
*/

#include "../include/my.h"
#include "../include/mylist.h"

static int split_error(char *caca)
{
    for (int i = 1; caca[i]; i++) {
        if ((caca[i] >= 'a' && caca[i] <= 'z') || (caca[i] >= 'A' &&
            caca[i] <= 'Z') || (caca[i] <= '9' && caca[i] >= '0'));
        else {
            my_printf("setenv: Variable name must ");
            my_printf("contain alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}

static int error_boudin(char *caca, global_t *set_boudin)
{
    if (set_boudin->arg[3] != NULL) {
        my_printf("setenv: Too many arguments.\n");
        return 1;
    }
    if ((caca[0] < 'a' || caca[0] > 'z') &&
        (caca[0] < 'A' || caca[0] > 'Z')) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    return (split_error(caca));
}

env_42_copy_t *add_node(global_t *set_boudin)
{
    env_42_copy_t *new_node = malloc(sizeof(env_42_copy_t));

    new_node->name = my_strdup(set_boudin->arg[1]);
    if (set_boudin->arg[2] != NULL)
        new_node->data = my_strdup(set_boudin->arg[2]);
    else
        new_node->data = NULL;
    new_node->next = NULL;
    return new_node;
}

int print_env(env_42_copy_t *archi_jtm)
{
    env_42_copy_t *tmp = archi_jtm;

    while (tmp) {
        my_printf("%s=%s\n", tmp->name, tmp->data);
        tmp = tmp->next;
    }
    return 0;
}

env_42_copy_t *error_case(env_42_copy_t *same_code, global_t *set_boudin)
{
    if (set_boudin->arg[2] != NULL)
        same_code->data = my_strdup(set_boudin->arg[2]);
    return same_code;
}

static void inpit(global_t *set_boudin, env_42_copy_t *tmp,
    env_42_copy_t *new_node)
{
    if (set_boudin->chaise == NULL) {
        set_boudin->chaise = new_node;
    } else {
        tmp = set_boudin->chaise;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}

int set_boudin(global_t *set_boudin)
{
    env_42_copy_t *tmp = set_boudin->chaise;
    env_42_copy_t *new_node = add_node(set_boudin);

    if (error_boudin(set_boudin->arg[1], set_boudin) != 0)
        return 1;
    while (tmp) {
        if (my_strcmp(tmp->name, set_boudin->arg[1]) == 0) {
            tmp = error_case(tmp, set_boudin);
            return 0;
        }
        tmp = tmp->next;
    }
    inpit(set_boudin, tmp, new_node);
    return 0;
}
