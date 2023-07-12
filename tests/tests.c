/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** test
*/

#include "../include/mysh.h"
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (the_42sh, no_env_ls, .init = redirect_all_stdout){
    char* test_input = "ls\nexit\n";
    char *args[] = {"./42sh", NULL};
    FILE* fp = fopen("test_input.txt", "w");
    fwrite(test_input, strlen(test_input), 1, fp);
    fclose(fp);

    fp = freopen("test_input.txt", "r", stdin);

    mini_shell(1, args, NULL);

    fclose(fp);
    remove("test_input.txt");
    cr_assert_stdout_eq_str("ls: Command not found.\n");
}

Test (the_42sh, env_pwd, .init = redirect_all_stdout){
    char* test_input = "/bin/pwd\nexit\n";
    char *args[] = {"./42sh", NULL};
    char *env[] = {"PATH=/bin/", NULL};
    FILE* pipe = popen("/bin/pwd", "r");
    char output[1024];
    fgets(output, 1024, pipe);
    pclose(pipe);
    FILE* fp = fopen("test_input.txt", "w");
    fwrite(test_input, strlen(test_input), 1, fp);
    fclose(fp);
    fp = freopen("test_input.txt", "r", stdin);

    mini_shell(1, args, env);

    fclose(fp);
    remove("test_input.txt");
    cr_assert_stdout_eq_str(output);
}

Test (the_42sh, env_env, .init = redirect_all_stdout){
    char* test_input = "env\nexit\n";
    char *args[] = {"./42sh", NULL};
    char *env[] = {"PATH=/bin/", NULL};
    FILE* fp = fopen("test_input.txt", "w");
    fwrite(test_input, strlen(test_input), 1, fp);
    fclose(fp);

    fp = freopen("test_input.txt", "r", stdin);

    mini_shell(1, args, env);

    fclose(fp);
    remove("test_input.txt");
    cr_assert_stdout_eq_str("PATH=/bin/\n");
}
