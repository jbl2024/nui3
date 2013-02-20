/*
  NUI3 - C++ cross-platform GUI framework for OpenGL based applications
  Copyright (C) 2002-2003 Sebastien Metrot

  licence: see nui3/LICENCE.TXT
*/

#ifndef __nuiTabView_h__
#define __nuiTabView_h__

class nuiGradient;
class nuiFont;
class nuiLabel;

class NUI_API TabEvent : public nuiEvent
{
public:
  TabEvent(const uint& index);
  uint mTabIndex;
};



class NUI_API nuiTabView : public nuiSimpleContainer
{
private:
  class Tab;
public:
  nuiTabView(nuiPosition tabPosition, bool decoratedBackground = true);
  virtual ~nuiTabView();

  virtual nuiRect CalcIdealSize();
  virtual bool SetRect(const nuiRect& rRect);
  virtual bool Draw(nuiDrawContext* pContext);
  
  virtual bool MouseClicked   (nuiSize X, nuiSize Y, nglMouseInfo::Flags Button);
  virtual bool MouseUnclicked (nuiSize X, nuiSize Y, nglMouseInfo::Flags Button);
    
  void OnIconClicked(const nuiEvent& rEvent);
  void OnTabEnterDrag(const nuiEvent& rEvent);

  virtual void AddTab(const nglString& rTitle, nuiWidget* pContents);
  virtual void AddTab(nuiWidget* pTitle, nuiWidget* pContents);
  virtual void InsertTab(nuiWidget* pTitle, nuiWidget* pContents, uint position);
  virtual void RemoveTab(nuiWidget* pTab);
  virtual void RemoveTab(const uint& tab_index);
   
  uint GetTabCount();

  nuiPosition GetTabPosition();
  
  nuiOrientation GetOrientation();
  void SetTabPosition(nuiPosition tabPosition);

  void SelectTab(const uint& index);
  uint GetSelectedTab() const { return mCurrentTabIndex; }
  void EnableChildrenRectUnion(bool set);
  bool GetChildrenRectUnion() const;

  void SetFoldable(bool Foldable);
  bool GetFoldable() const;

  void SetFolded(bool set, bool Animate = true);
  bool GetFolded() const;
  
  void SetChangeOnDrag(bool change);
  bool GetChangeOnDrag() const;

  nuiEventSink<nuiTabView> mTabViewEvents;
  nuiSimpleEventSource<0> TabSelect;
protected:
  uint mCurrentTabIndex;
  nuiPosition mTabPosition;

  std::vector<nuiWidget*> mTabs;
  std::vector<Tab*> mIcons;
  nuiRect mIdealIconsRect;
  nuiRect mIdealTabsRect;

  bool mChangeOnDrag;
  bool mChildrenRectUnion;
  bool mFoldable;
  bool mFolded;
  bool mSliding;
  bool mDecoratedBackground;
  float mFoldRatio;
  
private:
  class Tab : public nuiSimpleContainer
  {
  public:
    Tab(nuiWidget* pWidget);
    virtual nglDropEffect OnCanDrop(nglDragAndDrop* pDragObject, nuiSize X, nuiSize Y);
    nuiSimpleEventSource<0> EnterDrag;
  };
};

#endif//__nuiTabView_h__

