/* encodeErgeDNAseI.h was originally generated by the autoSql program, which also 
 * generated encodeErgeDNAseI.c and encodeErgeDNAseI.sql.  This header links the database and
 * the RAM representation of objects. */

#ifndef ENCODEERGEDNASEI_H
#define ENCODEERGEDNASEI_H

#define ENCODEERGEDNASEI_NUM_COLS 14

struct encodeErgeDNAseI
/* ENCODE experimental data from dbERGEII */
    {
    struct encodeErgeDNAseI *next;  /* Next in singly linked list. */
    char *chrom;	/* Human chromosome */
    unsigned chromStart;	/* Start position in chromosome */
    unsigned chromEnd;	/* End position in chromosome */
    char *name;	/* Name of read - up to 255 characters */
    unsigned score;	/* Score from 0-1000.  1000 is best */
    char strand[2];	/* Value should be + or - */
    unsigned thickStart;	/* Start of where display should be thick (start codon) */
    unsigned thickEnd;	/* End of where display should be thick (stop codon) */
    unsigned reserved;	/* Always zero for now */
    unsigned blockCount;	/* Number of separate blocks (regions without gaps) */
    unsigned *blockSizes;	/* Comma separated list of block sizes */
    unsigned *chromStarts;	/* Start position of each block in relative to chromStart */
    char *Id;	/* dbERGEII Id */
    char *color;	/* RGB color values */
    };

struct encodeErgeDNAseI *encodeErgeDNAseILoad(char **row);
/* Load a encodeErgeDNAseI from row fetched with select * from encodeErgeDNAseI
 * from database.  Dispose of this with encodeErgeDNAseIFree(). */

struct encodeErgeDNAseI *encodeErgeDNAseILoadAll(char *fileName);
/* Load all encodeErgeDNAseI from whitespace-separated file.
 * Dispose of this with encodeErgeDNAseIFreeList(). */

struct encodeErgeDNAseI *encodeErgeDNAseILoadAllByChar(char *fileName, char chopper);
/* Load all encodeErgeDNAseI from chopper separated file.
 * Dispose of this with encodeErgeDNAseIFreeList(). */

#define encodeErgeDNAseILoadAllByTab(a) encodeErgeDNAseILoadAllByChar(a, '\t');
/* Load all encodeErgeDNAseI from tab separated file.
 * Dispose of this with encodeErgeDNAseIFreeList(). */

struct encodeErgeDNAseI *encodeErgeDNAseICommaIn(char **pS, struct encodeErgeDNAseI *ret);
/* Create a encodeErgeDNAseI out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new encodeErgeDNAseI */

void encodeErgeDNAseIFree(struct encodeErgeDNAseI **pEl);
/* Free a single dynamically allocated encodeErgeDNAseI such as created
 * with encodeErgeDNAseILoad(). */

void encodeErgeDNAseIFreeList(struct encodeErgeDNAseI **pList);
/* Free a list of dynamically allocated encodeErgeDNAseI's */

void encodeErgeDNAseIOutput(struct encodeErgeDNAseI *el, FILE *f, char sep, char lastSep);
/* Print out encodeErgeDNAseI.  Separate fields with sep. Follow last field with lastSep. */

#define encodeErgeDNAseITabOut(el,f) encodeErgeDNAseIOutput(el,f,'\t','\n');
/* Print out encodeErgeDNAseI as a line in a tab-separated file. */

#define encodeErgeDNAseICommaOut(el,f) encodeErgeDNAseIOutput(el,f,',',',');
/* Print out encodeErgeDNAseI as a comma separated list including final comma. */

/* -------------------------------- End autoSql Generated Code -------------------------------- */

#endif /* ENCODEERGEDNASEI_H */
