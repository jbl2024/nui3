/*
  NUI3 - C++ cross-platform GUI framework for OpenGL based applications
  Copyright (C) 2002-2003 Sebastien Metrot & Vincent Caron

  licence: see nui3/LICENCE.TXT
*/

#include "nui.h"
#include "nglLog.h"
#include "nglKernel.h"
#include "nglTime.h"
#include "nglOStream.h"

const nglLog::StampFlags nglLog::NoStamp     = 0;
const nglLog::StampFlags nglLog::TimeStamp   = 1 << 0;
const nglLog::StampFlags nglLog::DateStamp   = 1 << 1;
const nglLog::StampFlags nglLog::DomainStamp = 1 << 2;


/*
 * Life cycle
 */

nglLog::nglLog (bool UseConsole)
{
  printf("Check %s %d\n", __FILE__, __LINE__);
  mDefaultLevel = NGL_LOG_DEFAULT;
  mStampFlags = DomainStamp;
  mUseConsole = UseConsole;
  mDomainFormat = _T("%s: ");
  mDomainFormatLen = 0;
  printf("Check %s %d\n", __FILE__, __LINE__);
}

nglLog::~nglLog ()
{
  mLock.LockWrite();
  mOutputList.clear();
  mDomainList.clear();
  mLock.UnlockWrite();
}

/*
 * Formatting flags
 */

void nglLog::SetFlags (nglLog::StampFlags Flags)
{
  mStampFlags = Flags;
}

nglLog::StampFlags nglLog::GetFlags()
{
  return mStampFlags;
}


/*
 * Output management
 */

void nglLog::UseConsole(bool Use)
{
  mUseConsole = Use;
}

bool nglLog::AddOutput (nglOStream* pStream)
{
  if (!pStream)
    return false;

  mLock.LockWrite();
  mOutputList.push_back(pStream);
  mLock.UnlockWrite();
  return true;
}

bool nglLog::DelOutput (nglOStream* pStream)
{
  if (!pStream)
    return false;

  OutputList::iterator output;

  mLock.LockWrite();
  for (output = mOutputList.begin(); output != mOutputList.end(); ++output)
  {
    if (*output == pStream)
    {
      mOutputList.erase(output);
      mLock.UnlockWrite();
      return true;
    }
  }
  mLock.UnlockWrite();
  return false;
}


/*
 * Domain management
 */

uint nglLog::GetLevel (const nglChar* pDomain)
{
  Domain* slot = LookupDomain(pDomain);

  return slot ? slot->Level : 0;
}

void nglLog::SetLevel (const nglChar* pDomain, uint Level)
{
  if (!pDomain)
    return;

  if (strcmp(pDomain, _T("all")) == 0)
  {
    mLock.LockRead();
    DomainList::iterator dom = mDomainList.begin();
    DomainList::iterator end = mDomainList.end();

    for (; dom != end; ++dom)
    {
      ngl_atomic_set(dom->Level, Level);
    }
    mLock.UnlockRead();

    mDefaultLevel = Level;
    return;
  }

  Domain* slot = LookupDomain(pDomain);

  if (slot)
  {
    ngl_atomic_set(slot->Level, Level);
  }
}


/*
 * Output functions
 */

void nglLog::Log (const nglChar* pDomain, uint Level, const nglChar* pText, ...)
{
  printf("Check %s %d\n", __FILE__, __LINE__);
  if (pText == NULL)
    return;

  printf("Check %s %d\n", __FILE__, __LINE__);
  va_list args;
  va_start (args, pText);

  printf("Check %s %d\n", __FILE__, __LINE__);
  Logv (pDomain, Level, pText, args);

  printf("Check %s %d\n", __FILE__, __LINE__);
  va_end (args);
  printf("Check %s %d\n", __FILE__, __LINE__);
}

void nglLog::Logv (const nglChar* pDomain, uint Level, const nglChar* pText, va_list Args)
{
  printf("Check %s %d\n", __FILE__, __LINE__);
  if (pText == NULL)
    return;

  printf("Check %s %d\n", __FILE__, __LINE__);
  Domain* dom = LookupDomain(pDomain);
  if (!dom)
    return;

  printf("Check %s %d\n", __FILE__, __LINE__);
  if (Level > dom->Level)
    return;

  printf("Check %s %d\n", __FILE__, __LINE__);
  // Update log item counter
  ngl_atomic_inc(dom->Count);

  printf("Check %s %d\n", __FILE__, __LINE__);
  // Get time stamp (if necessary)
  nglTimeInfo stamp;

  printf("Check %s %d\n", __FILE__, __LINE__);
  if (mStampFlags & (TimeStamp | DateStamp))
  {
    nglTime now;
    now.GetLocalTime (stamp);
  }

  printf("Check %s %d\n", __FILE__, __LINE__);
  // Compose mPrefix
  mPrefix.Wipe();
  if (mStampFlags & DateStamp)
  {
    mBody.Format(_T("%.2d/%.2d/%.2d "), stamp.Year - 100, stamp.Month, stamp.Day);
    mPrefix += mBody;
  }
  printf("Check %s %d\n", __FILE__, __LINE__);
  if (mStampFlags & TimeStamp)
  {
    mBody.Format(_T("%.2d:%.2d:%.2d "), stamp.Hours, stamp.Minutes, stamp.Seconds);
    mPrefix += mBody;
  }
  printf("Check %s %d\n", __FILE__, __LINE__);
  if (mStampFlags & DomainStamp)
  {
    const nglChar* dom_name = dom->Name.GetChars();

    if (dom->Count == 1)
    {
      // On first display from this domain, adjust domain display width
      uint32 dom_len = strlen(dom_name);

      if (dom_len > mDomainFormatLen)
      {
        mDomainFormatLen = dom_len;
        mDomainFormat.Format(_T("%%-%ds: "), mDomainFormatLen);
      }
    }

    mBody.Format(mDomainFormat.GetChars(), dom_name);
    mPrefix += mBody;
  }

  printf("Check %s %d\n", __FILE__, __LINE__);
  mOutputBuffer.Formatv(pText, Args);
  mOutputBuffer.TrimRight(_T('\n'));

  printf("Check %s %d\n", __FILE__, __LINE__);
  if (mOutputBuffer.Find(_T('\n')) == -1)
  {
  printf("Check %s %d\n", __FILE__, __LINE__);
    // Single line, display immediatly
    mBody = mPrefix;
    mBody += mOutputBuffer;
    mBody += _T('\n');
    Output (mBody);
  }
  else
  {
  printf("Check %s %d\n", __FILE__, __LINE__);
    // Multiple lines, display individually
    std::vector<nglString> lines;
    std::vector<nglString>::iterator line;

  printf("Check %s %d\n", __FILE__, __LINE__);
    mOutputBuffer.Tokenize(lines, _T('\n'));
    for (line = lines.begin(); line != lines.end(); ++line)
    {
  printf("Check %s %d\n", __FILE__, __LINE__);
      mBody = mPrefix;
      mBody += *line;
      mBody.TrimRight(_T('\n'));
      mBody += _T('\n');
  printf("Check %s %d\n", __FILE__, __LINE__);
      Output (mBody);
  printf("Check %s %d\n", __FILE__, __LINE__);
    }
  }
  printf("Check %s %d\n", __FILE__, __LINE__);
}

void nglLog::Dump (uint Level) const
{
  printf("Check %s %d\n", __FILE__, __LINE__);
  mLock.LockRead();
  printf("Check %s %d\n", __FILE__, __LINE__);
  DomainList::const_iterator dom = mDomainList.begin();
  DomainList::const_iterator end = mDomainList.end();
  printf("Check %s %d\n", __FILE__, __LINE__);

  nglString text = _T("# Log domains usage statistics :\n");
  nglString format;
  printf("Check %s %d\n", __FILE__, __LINE__);
  Output(text);
  printf("Check %s %d\n", __FILE__, __LINE__);

  for (; dom != end; dom++)
  {
  printf("Check %s %d\n", __FILE__, __LINE__);
    format.Format(_T("#   %s %%d\n"), mDomainFormat.GetChars());
    text.Format(format.GetChars(), (*dom).Name.GetChars(), (*dom).Count);
    Output(text);
  printf("Check %s %d\n", __FILE__, __LINE__);
  }
  printf("Check %s %d\n", __FILE__, __LINE__);
  mLock.UnlockRead();
  printf("Check %s %d\n", __FILE__, __LINE__);
}


/*
 * Internal classes
 */

nglLog::Domain* nglLog::LookupDomain (const nglChar* pName)
{
  printf("Check %s %d\n", __FILE__, __LINE__);
  // Sanity check
  if (!pName)
    return NULL;

  printf("Check %s %d\n", __FILE__, __LINE__);
  mLock.LockRead();
  // Search in domain list
  DomainList::iterator dom = mDomainList.begin();
  DomainList::iterator end = mDomainList.end();

  printf("Check %s %d\n", __FILE__, __LINE__);
  for (; dom != end; dom++)
  {
  printf("Check %s %d\n", __FILE__, __LINE__);
    if (dom->Name == pName)
    {
  printf("Check %s %d\n", __FILE__, __LINE__);
      Domain* pDom = &(*dom);
      mLock.UnlockRead();
  printf("Check %s %d\n", __FILE__, __LINE__);
      return pDom;
    }
  }
  printf("Check %s %d\n", __FILE__, __LINE__);
  mLock.UnlockRead();

  // Not found ? Create it.
  printf("Check %s %d\n", __FILE__, __LINE__);
  mLock.LockWrite();
  printf("Check %s %d\n", __FILE__, __LINE__);
  mDomainList.push_back(Domain(pName, mDefaultLevel));
  Domain* pDom = &mDomainList.back();
  printf("Check %s %d\n", __FILE__, __LINE__);
  mLock.UnlockWrite();
  printf("Check %s %d\n", __FILE__, __LINE__);
  return pDom;
}

void nglLog::Output (const nglString& rText) const
{
  printf("Check %s %d\n", __FILE__, __LINE__);
  if (mUseConsole)
  {
  printf("Check %s %d\n", __FILE__, __LINE__);
    NGL_OUT(rText);
  printf("Check %s %d\n", __FILE__, __LINE__);
  }

  printf("Check %s %d\n", __FILE__, __LINE__);
  OutputList::const_iterator out;
  for (out = mOutputList.begin(); out != mOutputList.end(); out++)
    (*out)->WriteText (rText);
  printf("Check %s %d\n", __FILE__, __LINE__);
}
