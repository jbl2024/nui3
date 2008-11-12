/*
 NUI3 - C++ cross-platform GUI framework for OpenGL based applications
 Copyright (C) 2002-2003 Sebastien Metrot
 
 licence: see nui3/LICENCE.TXT
 */

#include "nui.h"
#include "nuiPanose.h"

nuiPanose::nuiPanose()
{
  mFamily = eFamily_Any;
  mSerif = eSerif_Any;
  mWeight = eWeight_Any;
  mProportion = eProportion_Any;
  mContrast = eContrast_Any;
  mStrokeVariation = eStrokeVariation_Any;
  mArmStyle = eArmStyle_Any;
  mLetterForm = eLetterForm_Any;
  mMidLine = eMidLine_Any;
  mXHeight = eXHeight_Any;
}

nuiPanose::nuiPanose(const nuiFontPanoseBytes& rPanoseBytes)
{
  SetBytes(rPanoseBytes);
}

nuiPanose::nuiPanose(uint8 pPanoseBytes[10])
{
  SetBytes(pPanoseBytes);
}

nuiPanose::nuiPanose(const nuiPanose& rPanose)
{
  mFamily = rPanose.mFamily;
  mSerif = rPanose.mSerif;
  mWeight = rPanose.mWeight;
  mProportion = rPanose.mProportion;
  mContrast = rPanose.mContrast;
  mStrokeVariation= rPanose.mStrokeVariation;
  mArmStyle = rPanose.mArmStyle;
  mLetterForm = rPanose.mLetterForm;
  mMidLine = rPanose.mMidLine;
  mXHeight = rPanose.mXHeight;
}

void nuiPanose::GetBytes(nuiFontPanoseBytes& rBytes) const
{
  rBytes.mFamily = mFamily;
  rBytes.mSerif = mSerif;
  rBytes.mWeight = mWeight;
  rBytes.mProportion = mProportion;
  rBytes.mContrast = mContrast;
  rBytes.mStrokeVariation = mStrokeVariation;
  rBytes.mArmStyle = mArmStyle;
  rBytes.mLetterForm = mLetterForm;
  rBytes.mMidLine = mMidLine;
  rBytes.mXHeight = mXHeight;
}

void nuiPanose::SetBytes(const nuiFontPanoseBytes& rBytes)
{
  mFamily = (nuiFontFamily) rBytes.mFamily;
  mSerif = (nuiFontSerif) rBytes.mSerif;
  mWeight = (nuiFontWeight) rBytes.mWeight;
  mProportion = (nuiFontProportion) rBytes.mProportion;
  mContrast = (nuiFontContrast) rBytes.mContrast;
  mStrokeVariation= (nuiFontStrokeVariation) rBytes.mStrokeVariation;
  mArmStyle = (nuiFontArmStyle) rBytes.mArmStyle;
  mLetterForm = (nuiFontLetterForm) rBytes.mLetterForm;
  mMidLine = (nuiFontMidLine) rBytes.mMidLine;
  mXHeight = (nuiFontXHeight) rBytes.mXHeight;
}

void nuiPanose::SetBytes(uint8 pPanoseBytes[10])
{
  mFamily = (nuiFontFamily) pPanoseBytes[0];
  mSerif = (nuiFontSerif) pPanoseBytes[1];
  mWeight = (nuiFontWeight) pPanoseBytes[2];
  mProportion = (nuiFontProportion) pPanoseBytes[3];
  mContrast = (nuiFontContrast) pPanoseBytes[4];
  mStrokeVariation = (nuiFontStrokeVariation) pPanoseBytes[5];
  mArmStyle = (nuiFontArmStyle) pPanoseBytes[6];
  mLetterForm = (nuiFontLetterForm) pPanoseBytes[7];
  mMidLine = (nuiFontMidLine) pPanoseBytes[8];
  mXHeight = (nuiFontXHeight) pPanoseBytes[9];
}


uint32 nuiPanose::GetDistance(const nuiPanose& rPanose) const
{
  uint32 score = 0;
  score += CompareFamily(rPanose.mFamily);
  score += CompareSerif(rPanose.mSerif);
  score += CompareWeight(rPanose.mWeight);
  score += CompareProportion(rPanose.mProportion);
  score += CompareContrast(rPanose.mContrast);
  score += CompareStrokeVariation(rPanose.mStrokeVariation);
  score += CompareArmStyle(rPanose.mArmStyle);
  score += CompareLetterForm(rPanose.mLetterForm);
  score += CompareMidLine(rPanose.mMidLine);
  score += CompareXHeight(rPanose.mXHeight);
  return score;
}

float nuiPanose::GetNormalizedDistance(const nuiPanose& rPanose) const
{
  float distance = GetDistance(rPanose);
  return (distance > 0) ? 1.0f / (float)GetDistance(rPanose) : 1.0f;
}

nuiFontFamily nuiPanose::GetFamily() const
{
  return mFamily;
}

nuiFontSerif nuiPanose::GetSerif() const
{
  return mSerif;
}

nuiFontWeight nuiPanose::GetWeight() const
{
  return mWeight;
}

nuiFontProportion nuiPanose::GetProportion() const
{
  return mProportion;
}

nuiFontContrast nuiPanose::GetContrast() const
{
  return mContrast;
}

nuiFontStrokeVariation nuiPanose::GetStrokeVariation() const
{
  return mStrokeVariation;
}

nuiFontArmStyle nuiPanose::GetArmStyle() const
{
  return mArmStyle;
}

nuiFontLetterForm nuiPanose::GetLetterForm() const
{
  return mLetterForm;
}

nuiFontMidLine nuiPanose::GetMidLine() const
{
  return mMidLine;
}

nuiFontXHeight nuiPanose::GetXHeight() const
{
  return mXHeight;
}


void nuiPanose::SetFamily(nuiFontFamily set)
{
  mFamily = set;
}

void nuiPanose::SetSerif(nuiFontSerif set)
{
  mSerif = set;
}

void nuiPanose::SetWeight(nuiFontWeight set)
{
  mWeight = set;
}

void nuiPanose::SetProportion(nuiFontProportion set)
{
  mProportion = set;
}

void nuiPanose::SetContrast(nuiFontContrast set)
{
  mContrast = set;
}

void nuiPanose::SetStrokeVariation(nuiFontStrokeVariation set)
{
  mStrokeVariation = set;
}

void nuiPanose::SetArmStyle(nuiFontArmStyle set)
{
  mArmStyle = set;
}

void nuiPanose::SetLetterForm(nuiFontLetterForm set)
{
  mLetterForm = set;
}

void nuiPanose::SetMidLine(nuiFontMidLine set)
{
  mMidLine = set;
}

void nuiPanose::SetXHeight(nuiFontXHeight set)
{
  mXHeight = set;
}


nglString nuiPanose::Dump() const
{
  return nglString::Empty;
}


// Distance functions:
const static uint32 FamilyMetric[6][6] = 
{
  {0x00010000, 0x00100000, 0x00001000, 0x00001000, 0x00001000, 0x00001000},
  {0x00100000, 0x10000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000},
  {0x00001000, 0x01000000, 0x00000000, 0x000000ff, 0x000000ff, 0x000000ff},
  {0x00001000, 0x01000000, 0x000000ff, 0x00000000, 0x000000ff, 0x000000ff},
  {0x00001000, 0x01000000, 0x000000ff, 0x000000ff, 0x00000000, 0x000000ff},
  {0x00001000, 0x01000000, 0x000000ff, 0x000000ff, 0x000000ff, 0x00000000}
};

const static uint32 SerifMetric[16][16] =
{
  {0x00010000, 0x00100000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000},
  {0x00100000, 0x10000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000},
  {0x00001000, 0x01000000, 0x00000000, 0x00000004, 0x00000004, 0x00000004, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000010},
  {0x00001000, 0x01000000, 0x00000004, 0x00000000, 0x00000004, 0x00000004, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000010},
  {0x00001000, 0x01000000, 0x00000004, 0x00000004, 0x00000000, 0x00000004, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000010},
  {0x00001000, 0x01000000, 0x00000004, 0x00000004, 0x00000004, 0x00000000, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000010},
  {0x00001000, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000040, 0x00000040, 0x00000040, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000040, 0x00000040, 0x00000040, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000020, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000040, 0x00000040, 0x00000040, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000020, 0x00000040, 0x00000040, 0x00000040, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000040, 0x00000040, 0x00000040, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000000, 0x00000010, 0x00000010, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000000, 0x00000010, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000010, 0x00000000, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000040, 0x00000040, 0x00000040, 0x00000000, 0x00000020},
  {0x00001000, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 0x00000010, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000040, 0x00000040, 0x00000040, 0x00000020, 0x00000000}
};

const static uint32 WeightMetric[12][12] =
{
  {0x00010000, 0x00100000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000},
  {0x00100000, 0x10000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000},
  {0x00001000, 0x01000000, 0x00000000, 0x00000001, 0x00000004, 0x00000009, 0x00000010, 0x00000019, 0x00000024, 0x00000031, 0x00000040, 0x00000051},
  {0x00001000, 0x01000000, 0x00000001, 0x00000000, 0x00000001, 0x00000004, 0x00000009, 0x00000010, 0x00000019, 0x00000024, 0x00000031, 0x00000040},
  {0x00001000, 0x01000000, 0x00000004, 0x00000001, 0x00000000, 0x00000001, 0x00000004, 0x00000009, 0x00000010, 0x00000019, 0x00000024, 0x00000031},
  {0x00001000, 0x01000000, 0x00000009, 0x00000004, 0x00000001, 0x00000000, 0x00000001, 0x00000004, 0x00000009, 0x00000010, 0x00000019, 0x00000024},
  {0x00001000, 0x01000000, 0x00000010, 0x00000009, 0x00000004, 0x00000001, 0x00000000, 0x00000001, 0x00000004, 0x00000009, 0x00000010, 0x00000019},
  {0x00001000, 0x01000000, 0x00000019, 0x00000010, 0x00000009, 0x00000004, 0x00000001, 0x00000000, 0x00000001, 0x00000004, 0x00000009, 0x00000010},
  {0x00001000, 0x01000000, 0x00000024, 0x00000019, 0x00000010, 0x00000009, 0x00000004, 0x00000001, 0x00000000, 0x00000001, 0x00000004, 0x00000009},
  {0x00001000, 0x01000000, 0x00000031, 0x00000024, 0x00000019, 0x00000010, 0x00000009, 0x00000004, 0x00000001, 0x00000000, 0x00000001, 0x00000004},
  {0x00001000, 0x01000000, 0x00000040, 0x00000031, 0x00000024, 0x00000019, 0x00000010, 0x00000009, 0x00000004, 0x00000001, 0x00000000, 0x00000001},
  {0x00001000, 0x01000000, 0x00000051, 0x00000040, 0x00000031, 0x00000024, 0x00000019, 0x00000010, 0x00000009, 0x00000004, 0x00000001, 0x00000000}
};

const static uint32 ProportionMetric[10][10] =
{
  {0x00010000, 0x00100000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000},
  {0x00100000, 0x10000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000},
  {0x00001000, 0x01000000, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000040, 0x00000004, 0x00000080, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000020, 0x00000040, 0x00000000, 0x00000080, 0x00000004, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000020, 0x00000004, 0x00000080, 0x00000000, 0x000000c0, 0x00000080},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000020, 0x00000080, 0x00000004, 0x000000c0, 0x00000000, 0x00000080},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000020, 0x00000040, 0x00000040, 0x00000080, 0x00000080, 0x00000000}
};

const static uint32 ContrastMetric[10][10] =
{
  {0x00010000, 0x00100000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000},
  {0x00100000, 0x10000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000},
  {0x00001000, 0x01000000, 0x00000000, 0x00000001, 0x00000004, 0x00000009, 0x00000010, 0x00000019, 0x00000024, 0x00000031},
  {0x00001000, 0x01000000, 0x00000001, 0x00000000, 0x00000001, 0x00000004, 0x00000009, 0x00000010, 0x00000019, 0x00000024},
  {0x00001000, 0x01000000, 0x00000004, 0x00000001, 0x00000000, 0x00000001, 0x00000004, 0x00000009, 0x00000010, 0x00000019},
  {0x00001000, 0x01000000, 0x00000009, 0x00000004, 0x00000001, 0x00000000, 0x00000001, 0x00000004, 0x00000009, 0x00000010},
  {0x00001000, 0x01000000, 0x00000010, 0x00000009, 0x00000004, 0x00000001, 0x00000000, 0x00000001, 0x00000004, 0x00000009},
  {0x00001000, 0x01000000, 0x00000019, 0x00000010, 0x00000009, 0x00000004, 0x00000001, 0x00000000, 0x00000001, 0x00000004},
  {0x00001000, 0x01000000, 0x00000024, 0x00000019, 0x00000010, 0x00000009, 0x00000004, 0x00000001, 0x00000000, 0x00000001},
  {0x00001000, 0x01000000, 0x00000031, 0x00000024, 0x00000019, 0x00000010, 0x00000009, 0x00000004, 0x00000001, 0x00000000}
};

const static uint32 StrokeVariationMetric[9][9] =
{
  {0x00010000, 0x00100000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000},
  {0x00100000, 0x10000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000},
  {0x00001000, 0x01000000, 0x00000000, 0x00000010, 0x00000010, 0x00000010, 0x00000020, 0x00000020, 0x00000040},
  {0x00001000, 0x01000000, 0x00000010, 0x00000000, 0x00000010, 0x00000010, 0x00000020, 0x00000020, 0x00000040},
  {0x00001000, 0x01000000, 0x00000010, 0x00000010, 0x00000000, 0x00000010, 0x00000020, 0x00000020, 0x00000040},
  {0x00001000, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 0x00000000, 0x00000020, 0x00000020, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000010, 0x00000020},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000010, 0x00000000, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000020, 0x00000020, 0x00000000}
};

const static uint32 ArmStyleMetric[12][12] =
{
  {0x00010000, 0x00100000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000},
  {0x00100000, 0x10000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000},
  {0x00001000, 0x01000000, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000040, 0x00000010, 0x00000040, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000040, 0x00000040, 0x00000010, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000020, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000010},
  {0x00001000, 0x01000000, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000010, 0x00000040, 0x00000040, 0x00000020, 0x00000020, 0x00000000, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000040, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000000}
};

const static uint32 LetterFormMetric[16][16] =
{
  {0x00010000, 0x00100000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000},
  {0x00100000, 0x10000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000},
  {0x00001000, 0x01000000, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000040, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000040, 0x00000040, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000040, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000020, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000010},
  {0x00001000, 0x01000000, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000020, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000040, 0x00000040, 0x00000040, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000020, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000040, 0x00000040, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000040, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000000, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000040, 0x00000010, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000020, 0x00000000}
};

const static uint32 MidLineMetric[14][14] =
{
  {0x00010000, 0x00100000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000},
  {0x00100000, 0x10000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000},
  {0x00001000, 0x01000000, 0x00000000, 0x00000010, 0x00000010, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000010, 0x00000000, 0x00000010, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040},
  {0x00001000, 0x01000000, 0x00000010, 0x00000010, 0x00000000, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020},
  {0x00001000, 0x01000000, 0x00000020, 0x00000040, 0x00000040, 0x00000000, 0x00000010, 0x00000010, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000040, 0x00000020, 0x00000040, 0x00000010, 0x00000000, 0x00000010, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000020, 0x00000010, 0x00000010, 0x00000000, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020},
  {0x00001000, 0x01000000, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000000, 0x00000010, 0x00000010, 0x00000020, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000010, 0x00000000, 0x00000010, 0x00000040, 0x00000020, 0x00000040},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000010, 0x00000010, 0x00000000, 0x00000040, 0x00000040, 0x00000020},
  {0x00001000, 0x01000000, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000000, 0x00000010, 0x00000010},
  {0x00001000, 0x01000000, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000010, 0x00000000, 0x00000010},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000040, 0x00000040, 0x00000020, 0x00000010, 0x00000010, 0x00000000}
};


const static uint32 XHeightMetric[8][8] =
{
  {0x00010000, 0x00100000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000, 0x00001000},
  {0x00100000, 0x10000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000, 0x01000000},
  {0x00001000, 0x01000000, 0x00000000, 0x00000020, 0x00000020, 0x00000010, 0x00000040, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000000, 0x00000020, 0x00000040, 0x00000010, 0x00000040},
  {0x00001000, 0x01000000, 0x00000020, 0x00000020, 0x00000000, 0x00000040, 0x00000040, 0x00000010},
  {0x00001000, 0x01000000, 0x00000010, 0x00000040, 0x00000040, 0x00000000, 0x00000020, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000010, 0x00000040, 0x00000020, 0x00000000, 0x00000020},
  {0x00001000, 0x01000000, 0x00000040, 0x00000040, 0x00000010, 0x00000020, 0x00000020, 0x00000000}
};


uint32 nuiPanose::CompareFamily(nuiFontFamily set) const
{
  return FamilyMetric[mFamily][set];
}

uint32 nuiPanose::CompareSerif(nuiFontSerif set) const
{
  return SerifMetric[mSerif][set];
}

uint32 nuiPanose::CompareWeight(nuiFontWeight set) const
{
  return WeightMetric[mWeight][set];
}

uint32 nuiPanose::CompareProportion(nuiFontProportion set) const
{
  return ProportionMetric[mProportion][set];
}

uint32 nuiPanose::CompareContrast(nuiFontContrast set) const
{
  return ContrastMetric[mContrast][set];
}

uint32 nuiPanose::CompareStrokeVariation(nuiFontStrokeVariation set) const
{
  return StrokeVariationMetric[mStrokeVariation][set];
}

uint32 nuiPanose::CompareArmStyle(nuiFontArmStyle set) const
{
  return ArmStyleMetric[mArmStyle][set];
}

uint32 nuiPanose::CompareLetterForm(nuiFontLetterForm set) const
{
  return LetterFormMetric[mLetterForm][set];
}

uint32 nuiPanose::CompareMidLine(nuiFontMidLine set) const
{
  return MidLineMetric[mMidLine][set];
}

uint32 nuiPanose::CompareXHeight(nuiFontXHeight set) const
{
  return XHeightMetric[mXHeight][set];
}

void nuiPanose::SetBold(bool set)
{
  if (mFamily != eFamily_Pictorial)
	{
		// only do this if we're not a symbol font    
		if (!set)
		{
			// regular font
			if (mWeight == eWeight_Any || mWeight == eWeight_NoFit || mWeight > eWeight_Medium)
			{
				mWeight = eWeight_Medium;
			}
		}
		else
		{
			// bold font
			if (mWeight == eWeight_Any || mWeight == eWeight_NoFit || mWeight < eWeight_Bold)
			{
				mWeight = eWeight_Bold;
			}
		}
  }  
}

void nuiPanose::SetItalic(bool set)
{
  if (mFamily != eFamily_Pictorial)
  {
    // only do this if we're not a symbol font    
    if (!set)
    {
      // upright font
      if (mLetterForm == eLetterForm_Any || mLetterForm == eLetterForm_NoFit)
      {
        mLetterForm = eLetterForm_NormalCompact;
      }
      else if (mLetterForm >= eLetterForm_ObliqueCompact && mLetterForm <= eLetterForm_ObliqueSquare)
      {
        mLetterForm = (nuiFontLetterForm)(mLetterForm - 7); //#HACK
      }
    }
    else
    {
      // italic font
      if (mLetterForm == eLetterForm_Any || mLetterForm == eLetterForm_NoFit)
      {
        mLetterForm = eLetterForm_ObliqueCompact;
      }
      else if (mLetterForm >= eLetterForm_NormalCompact && mLetterForm <= eLetterForm_NormalSquare)
      {
        mLetterForm = (nuiFontLetterForm)(mLetterForm + 7); //#HACK
      }
    }
  }
}
