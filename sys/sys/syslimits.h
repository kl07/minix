/*	$NetBSD: syslimits.h,v 1.26 2011/09/27 01:51:42 christos Exp $	*/

/*
 * Copyright (c) 1988, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
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
 *
 *	@(#)syslimits.h	8.1 (Berkeley) 6/2/93
 */

#ifndef _SYS_SYSLIMITS_H_
#define _SYS_SYSLIMITS_H_

#if defined(__minix)
#define __MINIX_OPEN_MAX	255 /* a process may have 255 files open */
#define __MINIX_PATH_MAX	1024/* a pathname may contain 1023 chars (+ '\0')*/

#if defined(_STANDALONE)
/* LSC: In NetBSD this gets pulled in through libkern.h */
#include <sys/null.h>
#endif /* defined(_STANDALONE) */
#endif /* defined(__minix) */

#include <sys/featuretest.h>

#if defined(_POSIX_C_SOURCE) || defined(_XOPEN_SOURCE) || \
    defined(_NETBSD_SOURCE)
#define	ARG_MAX		 (256 * 1024)	/* max bytes for an exec function */
#ifndef CHILD_MAX
#define	CHILD_MAX		  160	/* max simultaneous processes */
#endif
#define	GID_MAX		   USHRT_MAX	/* max value for a gid_t (2^31-2) */
#define	LINK_MAX		32767	/* max file link count */
#define	MAX_CANON		  255	/* max bytes in term canon input line */
#define	MAX_INPUT		  255	/* max bytes in terminal input */
#define	NAME_MAX		  255	/* max bytes in a file name, must be */
					/* kept in sync with MAXPATHLEN */
#define	NGROUPS_MAX		   8	/* max supplemental group id's */
#define UID_MAX       USHRT_MAX  /* max value for a uid_t */
#ifndef OPEN_MAX
#define	OPEN_MAX __MINIX_OPEN_MAX	/* max open files per process */
#endif
#define	PATH_MAX     __MINIX_PATH_MAX	/* max bytes in pathname */
#define	PIPE_BUF		32768	/* max bytes for atomic pipe writes */

#define	BC_BASE_MAX	      INT_MAX	/* max ibase/obase values in bc(1) */
#define	BC_DIM_MAX		65535	/* max array elements in bc(1) */
#define	BC_SCALE_MAX	      INT_MAX	/* max scale value in bc(1) */
#define	BC_STRING_MAX	      INT_MAX	/* max const string length in bc(1) */
#define	COLL_WEIGHTS_MAX	    2	/* max weights for order keyword */
#define	EXPR_NEST_MAX		   32	/* max expressions nested in expr(1) */
#define	LINE_MAX		 2048	/* max bytes in an input line */
#define	RE_DUP_MAX		  255	/* max RE's in interval notation */

/*
 * IEEE Std 1003.1c-95, adopted in X/Open CAE Specification Issue 5 Version 2
 */
#if (_POSIX_C_SOURCE - 0) >= 199506L || (_XOPEN_SOURCE - 0) >= 500 || \
    defined(_NETBSD_SOURCE)
#define	LOGIN_NAME_MAX		   17	/* max login name length incl. NUL */
#endif

/*
 * X/Open CAE Specification Issue 5 Version 2
 */
#if defined(_XOPEN_SOURCE) || defined(_NETBSD_SOURCE)
#define	IOV_MAX			 1024	/* max # of iovec's for readv(2) etc. */
#define	NZERO			   20	/* default "nice" */
#endif /* _XOPEN_SOURCE || _NETBSD_SOURCE */

#endif /* !_ANSI_SOURCE */

#ifdef __minix
#define STREAM_MAX 8 /* == _POSIX_STREAM_MAX */
#define TZNAME_MAX 6 /* == _POSIX_TZNAME_MAX */
#define TIME_MAX  LONG_MAX
#endif

#endif /* !_SYS_SYSLIMITS_H_ */

