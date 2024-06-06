/*
** EPITECH PROJECT, 2024
** minishell2rendu
** File description:
** copy_env
*/

#include "../include/my.h"
#include "../include/mylist.h"

static env_42_copy_t *add_node(char *str)
{
    env_42_copy_t *new_node = malloc(sizeof(env_42_copy_t));
    char **tab_data = my_str_to_array(str, '=');

    new_node->name = my_strdup(tab_data[0]);
    if (tab_data[1] != NULL)
        new_node->data = my_strdup(tab_data[1]);
    else
        new_node->data = NULL;
    new_node->next = NULL;
    for (int i = 0; tab_data[i]; i++)
        free(tab_data[i]);
    free(tab_data);
    return new_node;
}

static env_42_copy_t *set_caca(env_42_copy_t *corp_de_mon_truc)
{
    env_42_copy_t *tmp = corp_de_mon_truc;
    env_42_copy_t *new_node = NULL;
    char buffer[1024];

    while (tmp) {
        if (my_strcmp(tmp->name, "OLDPWD") == 0) {
            free(tmp->data);
            tmp->data = my_strdup(getcwd(buffer, 1024));
            return corp_de_mon_truc;
        }
        tmp = tmp->next;
    }
    new_node = malloc(sizeof(env_42_copy_t));
    new_node->name = my_strdup("OLDPWD");
    new_node->data = my_strdup(getcwd(buffer, 1024));
    new_node->next = corp_de_mon_truc;
    corp_de_mon_truc = new_node;
    return corp_de_mon_truc;
}

env_42_copy_t *copy_boudin(char **env)
{
    env_42_copy_t *chocolatine;
    env_42_copy_t *tmp = NULL;
    env_42_copy_t *corp_de_mon_truc = NULL;

    for (int i = 0; env[i]; i++) {
        chocolatine = add_node(env[i]);
        if (corp_de_mon_truc == NULL) {
            corp_de_mon_truc = chocolatine;
            tmp = corp_de_mon_truc;
        } else {
            tmp->next = chocolatine;
            tmp = tmp->next;
        }
    }
    corp_de_mon_truc = set_caca(corp_de_mon_truc);
    return corp_de_mon_truc;
}
