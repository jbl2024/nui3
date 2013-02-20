/*
 NUI3 - C++ cross-platform GUI framework for OpenGL based applications
 Copyright (C) 2002-2003 Sebastien Metrot
 
 licence: see nui3/LICENCE.TXT
 */

#pragma once

class nuiGrid;
class nuiText;

class nuiTextureInspector : public nuiSimpleContainer
{
public:
  nuiTextureInspector();
  virtual ~nuiTextureInspector();
  
protected:
  nuiEventSink<nuiTextureInspector> mSink;
  
  void OnTexturesChanged(const nuiEvent& rEvent);
  void OnTextureSelection(const nuiEvent& rEvent);
  void UpdateTextures();
  
  nuiImage* mpImage;
  nuiGrid* mpAttributeGrid;
  nuiSlotsSink mSlot;
};
