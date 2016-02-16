
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl KILLING
// ------------------------------
#ifndef KILLING_EXPORT_H
#define KILLING_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (KILLING_HAS_DLL)
#  define KILLING_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && KILLING_HAS_DLL */

#if !defined (KILLING_HAS_DLL)
#  define KILLING_HAS_DLL 1
#endif /* ! KILLING_HAS_DLL */

#if defined (KILLING_HAS_DLL) && (KILLING_HAS_DLL == 1)
#  if defined (KILLING_BUILD_DLL)
#    define KILLING_Export ACE_Proper_Export_Flag
#    define KILLING_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define KILLING_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* KILLING_BUILD_DLL */
#    define KILLING_Export ACE_Proper_Import_Flag
#    define KILLING_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define KILLING_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* KILLING_BUILD_DLL */
#else /* KILLING_HAS_DLL == 1 */
#  define KILLING_Export
#  define KILLING_SINGLETON_DECLARATION(T)
#  define KILLING_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* KILLING_HAS_DLL == 1 */

// Set KILLING_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (KILLING_NTRACE)
#  if (ACE_NTRACE == 1)
#    define KILLING_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define KILLING_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !KILLING_NTRACE */

#if (KILLING_NTRACE == 1)
#  define KILLING_TRACE(X)
#else /* (KILLING_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define KILLING_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (KILLING_NTRACE == 1) */

#endif /* KILLING_EXPORT_H */

// End of auto generated file.
