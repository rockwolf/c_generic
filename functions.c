/* See LICENSE file for license and copyright info. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>


/*
 * This function returns a pointer to a substring of the original string.
 * If the given string was allocated dynamically, the caller must not overwrite
 * that pointer with the returned value, since the original pointer must be
 * deallocated using the same allocator with which it was allocated.  The return
 * value must NOT be deallocated using free() etc.
 */
void trim_whitespace(char *a_result, char *a_string, size_t a_buffersize)
{
    char *l_end;
    
    /* Trim leading space/newline. */
    while (isspace(*a_string) || (*a_string=='\n'))
        a_string++;

    if ((*a_string == 0) || (a_buffersize < 1))  // Exit when done.
        strncpy(a_result, a_string, a_buffersize - 1);

    /* Trim trailing space/newline. */
    l_end = a_string + strlen(a_string) - 1;
    while (
        (l_end > a_string)
        && (isspace(*l_end) || (*l_end == '\n'))
    )
    {
        l_end--;
    }

    /* Write new null terminator. */
    *(l_end + 1) = 0;
    strncpy(a_result, a_string, a_buffersize - 1);
}


/*
 * current_datetime_to_string
 * Gets the current datetime and
 * return it as a formatted string.
 */
void timestamp(char *a_result, const char *a_dtformat, size_t a_buffersize)
{
    time_t l_time = time(NULL);
    struct tm l_localtime = *localtime(&l_time);

    snprintf(
        a_result,
        a_buffersize - 1,
        a_dtformat,
        l_localtime.tm_year + 1900,
        l_localtime.tm_mon + 1,
        l_localtime.tm_mday,
        l_localtime.tm_hour,
        l_localtime.tm_min,
        l_localtime.tm_sec
    );
}

/*
 * print_if_verbose
 * Prints the given message, when
 * the verbose flag is true (1).
 */
void print_if_verbose(uint32_t *a_verbose, char *a_msg, ...)
{
    va_list l_args;
    if (*a_verbose != 1)
        return;

    va_start(l_args, a_msg);
    vprintf(a_msg, l_args);
    va_end(l_args);
}
