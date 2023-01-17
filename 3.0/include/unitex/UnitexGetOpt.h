/*
 * Copyright (c) 1987, 1993, 1994, 1996
 *  The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *  This product includes software developed by the University of
 *  California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/**
 * This library has been modified by S. Paumier in order to make the getopt... functions
 * thread safe, because Unitex main_XXX programs parse their options with them, and
 * as Unitex must now be also compiled as a library, multiple calls to getopt...
 * could cause problems.
 */

#ifndef UnitexGetOptH
#define UnitexGetOptH

#ifdef __cplusplus

#ifndef HAS_UNITEX_NAMESPACE
#define HAS_UNITEX_NAMESPACE 1
#endif

namespace unitex {
#endif
    
/**
 * struct option, no_argument, required_argument and optional_argument may already
 * have been defined if someone use both libunitex.so and the original getopt.
 */

#define no_argument_TS             0
#define required_argument_TS       1
#define optional_argument_TS       2

struct option_TS {
   const char *name;
   int  has_arg;
   int *flag;
   int val;
};



/**
 * This structure defines all the things getopt needs to work in a thread safe way.
 */
struct OptVars {
   int   opterr;       /* if error message should be printed */
   int   optind;       /* index into parent argv vector */
   int   optopt;       /* character checked for validity */
   int   optreset;     /* reset getopt */
   const char  *optarg;      /* argument associated with option */
   int   nonopt_start; /* first non option argument (for permute) */
   int   nonopt_end;  /* first option after non options (for permute) */
   const char* place ;
};


struct OptVars* new_OptVars();
void free_OptVars(struct OptVars*);
int getopt_TS(int, char * const *, const char *,struct OptVars*);
int getopt_long_TS(int, char *const *, const char *, const struct option_TS *, int *,struct OptVars*);
int getopt_long_only_TS(int, char *const *, const char *, const struct option_TS *, int *,struct OptVars*);

#ifdef __cplusplus
} // namespace unitex
#endif

#endif
