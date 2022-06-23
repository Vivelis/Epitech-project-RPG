/*
** EPITECH PROJECT, 2021
** pile-file
** File description:
** c_list_unit_tests.c
*/

#include <criterion/criterion.h>
#include "c_list.h"

Test(c_list, initialise)
{
    c_list_t *list = NULL;

    list = init_list();
    cr_assert_neq(list, NULL);
    free_list(list);
}

Test(c_listi, insert_index_0)
{
    c_list_t *list = NULL;

    list = init_list();
    insert_listi(list, 0, "cc");
    cr_assert_neq(list, NULL);
    cr_assert_eq(put_out_list(list), "cc");
    free_list(list);
}

Test(c_listi, insert_modif_index0)
{
    c_list_t *list = NULL;

    list = init_list();
    insert_listi(list, 0, "cc");
    insert_listi(list, 0, "aa");
    cr_assert_neq(list, NULL);
    cr_assert_eq(put_out_list(list), "aa");
    free_list(list);
}

Test(c_listi, insert_index1)
{
    c_list_t *list = NULL;

    list = init_list();
    insert_listi(list, 0, "cc");
    insert_listi(list, 1, "aa");
    cr_assert_neq(list, NULL);
    cr_assert_eq(put_out_list(list), "cc");
    cr_assert_eq(put_out_list(list), "aa");
    free_list(list);
}

Test(c_listi, insert_modif_index1)
{
    c_list_t *list = NULL;

    list = init_list();
    insert_listi(list, 0, "cc");
    insert_listi(list, 1, "aa");
    insert_listi(list, 1, "ll");
    cr_assert_neq(list, NULL);
    cr_assert_eq(put_out_list(list), "cc");
    cr_assert_eq(put_out_list(list), "ll");
    free_list(list);
}

Test(c_listi, insert_out_of_range)
{
    c_list_t *list = NULL;

    list = init_list();
    insert_listi(list, 0, "cc");
    insert_listi(list, 1, "aa");
    insert_listi(list, 4, "ll");
    cr_assert_neq(list, NULL);
    free_list(list);
}

Test(c_listi, insert_empty_list)
{
    c_list_t *list = NULL;

    list = init_list();
    insert_listi(list, 3, "cc");
    cr_assert_neq(list, NULL);
    cr_assert_eq(put_out_list(list), "cc");
    free_list(list);
}

Test(c_listi, delete_index0)
{
    c_list_t *list = NULL;

    list = init_list();
    insert_listi(list, 0, "cc");
    delete_listi(list, 0);
    cr_assert_neq(list, NULL);
    cr_assert_neq(put_out_list(list), "cc");
    free_list(list);
}

Test(c_listi, delete_index1)
{
    c_list_t *list = NULL;

    list = init_list();
    insert_listi(list, 0, "0");
    insert_listi(list, 1, "1");
    delete_listi(list, 1);
    cr_assert_neq(list, NULL);
    cr_assert_eq(put_out_list(list), "0");
    cr_assert_neq(put_out_list(list), "1");
    free_list(list);
}

Test(c_listi, delete_index1_two_len)
{
    c_list_t *list = NULL;

    list = init_list();
    insert_listi(list, 0, "0");
    insert_listi(list, 1, "1");
    insert_listi(list, 2, "2");
    delete_listi(list, 1);
    cr_assert_neq(list, NULL);
    cr_assert_eq(put_out_list(list), "0");
    cr_assert_eq(put_out_list(list), "2");
    free_list(list);
}

Test(c_listi, delete_index2_two_len)
{
    c_list_t *list = NULL;

    list = init_list();
    insert_listi(list, 0, "0");
    insert_listi(list, 1, "1");
    insert_listi(list, 2, "2");
    delete_listi(list, 2);
    cr_assert_neq(list, NULL);
    cr_assert_eq(put_out_list(list), "0");
    cr_assert_eq(put_out_list(list), "1");
    cr_assert_neq(put_out_list(list), "2");
    free_list(list);
}

Test(c_listi, delete_empty_list)
{
    c_list_t *list = NULL;

    list = init_list();
    delete_listi(list, 2);
    cr_assert_neq(list, NULL);
    free_list(list);
}

Test(c_listi, get_index0)
{
    c_list_t *list = NULL;
    list_element_t *result;

    list = init_list();
    insert_listi(list, 0, "0");
    result = get_listi(list, 0);
    cr_assert_neq(list, NULL);
    cr_assert_eq(result, "0");
    free_list(list);
}

Test(c_listi, get_index1)
{
    c_list_t *list = NULL;
    list_element_t *result;

    list = init_list();
    insert_listi(list, 0, "0");
    insert_listi(list, 1, "1");
    result = get_listi(list, 1);
    cr_assert_neq(list, NULL);
    cr_assert_eq(result, "1");
    free_list(list);
}

Test(c_listi, get_index2)
{
    c_list_t *list = NULL;
    list_element_t *result;

    list = init_list();
    insert_listi(list, 0, "0");
    insert_listi(list, 1, "1");
    insert_listi(list, 2, "2");
    result = get_listi(list, 2);
    cr_assert_neq(list, NULL);
    cr_assert_eq(result, "2");
    free_list(list);
}

Test(c_listi, get_index1_len2)
{
    c_list_t *list = NULL;
    list_element_t *result;

    list = init_list();
    insert_listi(list, 0, "0");
    insert_listi(list, 1, "1");
    insert_listi(list, 2, "2");
    result = get_listi(list, 1);
    cr_assert_neq(list, NULL);
    cr_assert_eq(result, "1");
    free_list(list);
}

Test(c_listi, get_index_out_of_range)
{
    c_list_t *list = NULL;
    list_element_t *result;

    list = init_list();
    insert_listi(list, 0, "0");
    insert_listi(list, 1, "1");
    result = get_listi(list, 10);
    cr_assert_neq(list, NULL);
    cr_assert_neq(result, "1");
    free_list(list);
}

Test(c_listi, get_index_empty_list)
{
    c_list_t *list = NULL;
    list_element_t *result;

    list = init_list();
    result = get_listi(list, 1);
    cr_assert_neq(list, NULL);
    cr_assert_neq(result, "1");
    free_list(list);
}
