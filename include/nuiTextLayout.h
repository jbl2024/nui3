/*
 NUI3 - C++ cross-platform GUI framework for OpenGL based applications
 Copyright (C) 2002-2003 Sebastien Metrot
 
 licence: see nui3/LICENCE.TXT
 */

#pragma once

class nuiFontBase;
class nuiDrawContext;
class nuiTextRun;
class nuiTextGlyph;
class nuiTextLine;
class nuiGlyphInfo;

class nuiTextLayout : public nuiRefCount
{
public:
  nuiTextLayout(const nuiTextStyle& rStyle, nuiOrientation Orientation = nuiHorizontal);
  nuiTextLayout(nuiFontBase* pFont, nuiOrientation Orientation = nuiHorizontal);
  virtual ~nuiTextLayout();

  bool Layout(const nglString& rString);
  void Print(nuiDrawContext* pContext, float X, float Y, bool AlignGlyphPixels) const;
  
  int32 GetParagraphCount() const;
  int32 GetLineCount(int32 Paragraph) const;
  int32 GetRunCount(int32 Paragraph, int32 Line) const;
  
  nuiTextLine* GetLine(int32 Paragraph, int32 Line) const;
  nuiTextRun*  GetRun(int32 Paragraph, int32 Line, int32 Run) const;
  
  void GetLines(std::vector<uint>& rLines) const;

  
  const nglUChar* GetUnicodeChars() const;

  /** @name Metrics */
  //@{
  int32  GetMetrics (nuiGlyphInfo& rInfo) const;
  /*!< Returns whole layout metrics (as a composite glyph)
   \param rInfo metrics info holder
   \return number of glyphs in the layout
   */
  float GetAscender() const;
  float GetDescender() const;
  //@}
  
  int32 GetGlyphCount() const;
  const nuiTextGlyph* GetGlyph   (int32 Offset) const;
  const nuiTextGlyph* GetGlyphAt (float X, float Y) const;
  /*!< Identify a glyph at given coordinates
   \param X abscissa in layout coordinate space
   \param Y ordinate in layout coordinate space
   \return located glyph instance, NULL if none match
   
   This method searches if a glyph's bounding box in the layout encloses the
   given coordinates. If such a glyph is found, its localized instance is
   returned.
   */
  nuiRect GetRect() const;
  void SetDensity(nuiSize X, nuiSize Y);
  nuiSize GetDensityX() const;
  nuiSize GetDensityY() const;
  //@}
  
  void SetSpacesPerTab(int count);
  int32 GetSpacesPerTab();
  
  void SetUnderline(bool set);
  bool GetUnderline() const;
  void SetStrikeThrough(bool set);
  bool GetStrikeThrough() const;
  
  void SetWrapX(nuiSize WrapX);
  nuiSize GetWrapX() const;
  
private:
  bool PrintGlyphs(nuiDrawContext *pContext, float X, float Y, const std::map<nuiTexture*, std::vector<nuiTextGlyph*> >& rGlyphs, bool AlignGlyphPixels) const;
  nuiTextStyle mStyle;
  std::map<nuiUnicodeScript, std::set<nglUChar> > mCharsets;
  
  nuiOrientation mOrientation;
  
  float mAscender;
  float mDescender;
  
  float mXMin, mXMax;
  float mYMin, mYMax;
  
  bool LayoutParagraph(int32 start, int32 length);
  
  typedef std::vector<nuiTextLine*> Paragraph;
  std::vector<Paragraph*> mpParagraphs;
  
  std::vector<nglUChar> mUnicode;
  std::vector<int32> mOffsetInString;
  std::vector<int32> mOffsetInUnicode;
};

