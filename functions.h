/* See LICENSE.txt for license and copyright information. */
#pragma once

extern void trim_whitespace(char *a_result, char *a_string, size_t a_buffersize);
extern void timestamp(char *a_result, const char *a_dtformat, size_t a_buffersize);
extern void print_if_verbose(uint32_t *a_verbose, char *format, ...);
