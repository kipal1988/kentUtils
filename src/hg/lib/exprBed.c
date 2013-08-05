/* exprBed.c was originally generated by the autoSql program, which also 
 * generated exprBed.h and exprBed.sql.  This module links the database and
 * the RAM representation of objects. */

#include "common.h"
#include "linefile.h"
#include "dystring.h"
#include "jksql.h"
#include "exprBed.h"


struct exprBed *exprBedLoad(char **row)
/* Load a exprBed from row fetched with select * from exprBed
 * from database.  Dispose of this with exprBedFree(). */
{
struct exprBed *ret;
int sizeOne;

AllocVar(ret);
ret->numExp = sqlUnsigned(row[8]);
ret->chrom = cloneString(row[0]);
ret->chromStart = sqlUnsigned(row[1]);
ret->chromEnd = sqlUnsigned(row[2]);
ret->name = cloneString(row[3]);
ret->size = sqlUnsigned(row[4]);
ret->uniqueAlign = sqlUnsigned(row[5]);
ret->score = sqlUnsigned(row[6]);
ret->hname = cloneString(row[7]);
sqlStringDynamicArray(row[9], &ret->hybes, &sizeOne);
assert(sizeOne == ret->numExp);
sqlFloatDynamicArray(row[10], &ret->scores, &sizeOne);
assert(sizeOne == ret->numExp);
return ret;
}

struct exprBed *exprBedLoadAll(char *fileName) 
/* Load all exprBed from a tab-separated file.
 * Dispose of this with exprBedFreeList(). */
{
struct exprBed *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[11];

while (lineFileRow(lf, row))
    {
    el = exprBedLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct exprBed *exprBedCommaIn(char **pS, struct exprBed *ret)
/* Create a exprBed out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new exprBed */
{
char *s = *pS;
int i;

if (ret == NULL)
    AllocVar(ret);
ret->chrom = sqlStringComma(&s);
ret->chromStart = sqlUnsignedComma(&s);
ret->chromEnd = sqlUnsignedComma(&s);
ret->name = sqlStringComma(&s);
ret->size = sqlUnsignedComma(&s);
ret->uniqueAlign = sqlUnsignedComma(&s);
ret->score = sqlUnsignedComma(&s);
ret->hname = sqlStringComma(&s);
ret->numExp = sqlUnsignedComma(&s);
s = sqlEatChar(s, '{');
AllocArray(ret->hybes, ret->numExp);
for (i=0; i<ret->numExp; ++i)
    {
    ret->hybes[i] = sqlStringComma(&s);
    }
s = sqlEatChar(s, '}');
s = sqlEatChar(s, ',');
s = sqlEatChar(s, '{');
AllocArray(ret->scores, ret->numExp);
for (i=0; i<ret->numExp; ++i)
    {
    ret->scores[i] = sqlFloatComma(&s);
    }
s = sqlEatChar(s, '}');
s = sqlEatChar(s, ',');
*pS = s;
return ret;
}

void exprBedFree(struct exprBed **pEl)
/* Free a single dynamically allocated exprBed such as created
 * with exprBedLoad(). */
{
struct exprBed *el;

if ((el = *pEl) == NULL) return;
freeMem(el->chrom);
freeMem(el->name);
freeMem(el->hname);
/* All strings in hybes are allocated at once, so only need to free first. */
if (el->hybes != NULL)
    freeMem(el->hybes[0]);
freeMem(el->hybes);
freeMem(el->scores);
freez(pEl);
}

void exprBedFreeList(struct exprBed **pList)
/* Free a list of dynamically allocated exprBed's */
{
struct exprBed *el, *next;

for (el = *pList; el != NULL; el = next)
    {
    next = el->next;
    exprBedFree(&el);
    }
*pList = NULL;
}

void exprBedOutput(struct exprBed *el, FILE *f, char sep, char lastSep) 
/* Print out exprBed.  Separate fields with sep. Follow last field with lastSep. */
{
int i;
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->chrom);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%u", el->chromStart);
fputc(sep,f);
fprintf(f, "%u", el->chromEnd);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->name);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%u", el->size);
fputc(sep,f);
fprintf(f, "%u", el->uniqueAlign);
fputc(sep,f);
fprintf(f, "%u", el->score);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->hname);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%u", el->numExp);
fputc(sep,f);
if (sep == ',') fputc('{',f);
for (i=0; i<el->numExp; ++i)
    {
    if (sep == ',') fputc('"',f);
    fprintf(f, "%s", el->hybes[i]);
    if (sep == ',') fputc('"',f);
    fputc(',', f);
    }
if (sep == ',') fputc('}',f);
fputc(sep,f);
if (sep == ',') fputc('{',f);
for (i=0; i<el->numExp; ++i)
    {
    fprintf(f, "%f", el->scores[i]);
    fputc(',', f);
    }
if (sep == ',') fputc('}',f);
fputc(lastSep,f);
}

/* -------------------------------- End autoSql Generated Code -------------------------------- */
