/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** archive
*/

#include "nm.h"


// #define  ARFMAG   "`\n"         /* header trailer string */

// struct  ar_hdr                  /* file member header */
// {
//     char    ar_name[16];        /* '/' terminated file member name */
//     char    ar_date[12];        /* file member date */
//     char    ar_uid[6]           /* file member user identification */
//     char    ar_gid[6]           /* file member group identification */
//     char    ar_mode[8]          /* file member mode (octal) */
//     char    ar_size[10];        /* file member size */
//     char    ar_fmag[2];         /* header trailer string */
// };
typedef struct ar_hdr ar_header_t;

static void disp(ar_header_t *hdr)
{
    fprintf(stderr, "ar name : (%.16s) \n", hdr->ar_name);
    fprintf(stderr, "ar date : (%.12s) \n", hdr->ar_date);
    fprintf(stderr, "ar uid : (%.6s) \n", hdr->ar_uid);
    fprintf(stderr, "ar gid : (%.6s) \n", hdr->ar_gid);
    fprintf(stderr, "ar mode : (%.8s) \n", hdr->ar_mode);
    fprintf(stderr, "ar size : (%.10s) \n", hdr->ar_size);
    fprintf(stderr, "ar fmag : (%.2s) \n", hdr->ar_fmag);
}

int archive(elf_file_t *file)
{
    ar_header_t *hdr = (ar_header_t *)((char *)file->content + SARMAG);

    if (strncmp((char *)file->content, ARMAG, SARMAG) != 0) {
        fprintf(stderr, "No magic string");
        return EXIT_SUCCESS;
    }
    hdr = ((char *)hdr) + 2074 + sizeof(ar_header_t) * 2;
    char *ptr = (char *)hdr;
    for (size_t i = 0; i < 5; i++) {
        disp((ar_header_t *)ptr);
        while (ptr[0] != ARFMAG) {
            ptr++;
        }
        ptr++;
        fprintf(stderr, "------------\n");
    }
    return EXIT_SUCCESS;
}