/*
 * Compile with
 *      gcc -o regtest main.c -lpcre2-8
 * and run with
 *      ./regtest
 * Check the return value with
 *      echo $?
 *
 * To use this program set subject STRING to string to be matched,
 * REGEX to regular expression that should match the subject string,
 * OPT_COMP to compilation options and OPT_MATCH to matching options.
 *
 * In case of a match 0 is returned, otherwise non-zero. In case of
 * error the program displays an error message and exits immediately
 * with non-zero value.
 */

#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STRING          "This is a paragraph."
#define REGEX           "^(?:[ \t\v\f]*(?:(?:\r\n|\r|\n)(?:(?:[ \t\v\f]*(?:\r\n|\r|\n))+|$)|$))|$"
#define OPT_COMP        0
#define OPT_MATCH       0

static bool regex_match(const char * const string, const char * const regex, const uint32_t opt_comp, const uint32_t opt_match)
{
        int errcode = 0;
        PCRE2_SIZE erroffset = 0;

        pcre2_code *code = pcre2_compile((PCRE2_SPTR) regex, PCRE2_ZERO_TERMINATED, opt_comp, &errcode, &erroffset, NULL);
        if (code == NULL)
        {
                fprintf(stderr, "Failed to compile regex.\n");
                fprintf(stderr, "Error code: %d.\n", errcode);
                fprintf(stderr, "Error at offset %d.\n", erroffset);
                exit(1);
        }

        pcre2_match_data *m = pcre2_match_data_create(2, NULL);;

        char buf[255];
        pcre2_get_error_message(pcre2_match(code, (PCRE2_SPTR) string, PCRE2_ZERO_TERMINATED, 0, opt_match, m, NULL), buf, 255);
        if (pcre2_match(code, (PCRE2_SPTR) string, PCRE2_ZERO_TERMINATED, 0, opt_match, m, NULL) < 0)
        {
                fprintf(stderr, "%s\n", buf);
                pcre2_code_free(code);
                return false;
        }

        pcre2_code_free(code);
        return true;
}

int main()
{
        if (regex_match(STRING, REGEX, OPT_COMP, OPT_MATCH)) {
                fprintf(stderr, "match\n");
                return 0;
                }

        fprintf(stderr, "S-H-I-T!\n");
        return 1;
}
