/*
  NUI3 - C++ cross-platform GUI framework for OpenGL based applications
  Copyright (C) 2002-2003 Sebastien Metrot

  licence: see nui3/LICENCE.TXT
*/

#ifndef __nuiPainter_h__
#define __nuiPainter_h__

/* nuiDrawContext design

  Rendering context divided in two parts:
  - Front End = nui high level rendering API. Backward compatible with the former nui API.
  - Back End = nui low level rendering API.

  Back End:
  Accepts two kind of requests:
  - Change the rendering state.
  - Draw something.

  Rendering state changes are accumulated until a Drawing operation is requested. The state is then applied before we carry the rendering operation.

*/

//#include "nui.h"
#include "nuiRect.h"

#include <stack>

#include "nuiRenderArray.h"
#include "nuiRenderState.h"
#include "nuiSurface.h"

class NUI_API nuiClipper : public nuiRect
{
public:
  nuiClipper(const nuiRect& rRect, bool enable = true)
    : nuiRect(rRect)
  {
    mEnabled = enable;
  }

  nuiClipper(bool enable = false)
  {
    mEnabled = enable;
  }

  nuiClipper(const nuiClipper& rClipper)
    : nuiRect(rClipper)
  {
    mEnabled = rClipper.mEnabled;
  }

  nuiClipper& operator= (const nuiClipper& rClipper)
  {
    mLeft  = rClipper.mLeft;
    mRight = rClipper.mRight;
    mTop = rClipper.mTop;
    mBottom = rClipper.mBottom;
    mEnabled = rClipper.mEnabled;
#ifdef USE_NUIVALUETYPES  
    Changed();
#endif
    return *this;
  }

  bool mEnabled;
};

class NUI_API nuiPainter : public nuiTextureCache, public nuiSurfaceCache
{
public:
  nuiPainter(const nuiRect& rRect, nglContext* pContext = NULL);
  virtual ~nuiPainter();

  virtual void SetSize(uint32 sizex, uint32 sizey) = 0;
  virtual void StartRendering(nuiSize ClipOffsetX, nuiSize ClipOffsetY);
  virtual void BeginSession() = 0;
  virtual void EndSession() = 0;

  virtual void SetState(const nuiRenderState& rState, bool ForceApply = false) = 0;
  virtual void DrawArray(const nuiRenderArray& rArray) = 0;
  virtual void ClearColor() = 0;
  virtual void ClearStencil(uint8 value) = 0;

  virtual void LoadMatrix(const nuiMatrix& rMatrix);
  virtual void MultMatrix(const nuiMatrix& rMatrix);
  virtual void PushMatrix();
  virtual void PopMatrix();
  virtual const nuiMatrix& GetMatrix() const;

  virtual void PushClipping();
  virtual void PopClipping();
  virtual void Clip(const nuiRect& rRect);
  virtual void ResetClipRect();
  virtual void EnableClipping(bool set);
  virtual bool GetClipRect(nuiRect& rRect, bool LocalRect) const;

  virtual uint32 GetClipStackSize() const;

  virtual uint32 GetRectangleTextureSupport() const;

  void GetClipOffset(nuiSize& rX, nuiSize& rY) const { rX = mClipOffsetX; rY = mClipOffsetY; }
  void GetSize(uint32& rX, uint32& rY) const { rX = mWidth; rY = mHeight; }
  const nuiRenderState& GetState() const { return mState; }

  void SetDummyMode(bool set) { mDummyMode = set; }
  bool GetDummyMode() const { return mDummyMode; }

  // Stats:
  void ResetStats();
  uint32 GetRenderOperations() const;
  uint32 GetVertices() const;
  uint32 GetBatches() const;

  // Display rotation
  void SetAngle(uint32 Angle) { mAngle = Angle; }
  uint32 GetAngle() { return mAngle; }
  

  // Debug:
  virtual void AddBreakPoint()
  {
    // do nothing by default, this is only used to debug defered rendering (i.e. nuiMetaPainter).
  }
  
  void DEBUG_EnableDrawArray(bool set) const;
  bool DEBUG_GetEnableDrawArray() const;
  
protected:
  nuiRenderState mState;
  std::stack <nuiClipper*> mpClippingStack;
  nuiSize mClipOffsetX;
  nuiSize mClipOffsetY;
  uint32 mWidth;
  uint32 mHeight;
  uint32 mAngle;

  nuiClipper mClip;
  std::stack<nuiMatrix> mMatrixStack;

  uint32 mRenderOperations;
  uint32 mVertices;
  uint32 mBatches;

  bool mDummyMode;

  mutable bool mEnableDrawArray;
  static uint32 mNeedTextureBackingStore;
  void AddNeedTextureBackingStore();
  void DelNeedTextureBackingStore();
};

#endif
