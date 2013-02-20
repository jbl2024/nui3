/*
 NUI3 - C++ cross-platform GUI framework for OpenGL based applications
 Copyright (C) 2002-2003 Sebastien Metrot & Vincent Caron
 
 licence: see nui3/LICENCE.TXT
 */



#ifndef __nglInputDeviceInstance_h__
#define __nglInputDeviceInstance_h__

class nglInputDevice;

class nglInputDeviceInstance
{
public:
  static nglInputDevice* CreateDevice(nglInputDeviceInstance* mpDevice);

  nglInputDeviceInstance();
  virtual ~nglInputDeviceInstance();

  virtual bool Update();
  nglString    GetPort();
  nglString    GetName();
  uint         GetButtonCount();
  bool         GetButtonState (uint Index);
  uint         GetAxeCount();
  float        GetAxeValue (uint Index);
  void         IncRef();
  void         DecRef();

protected:
  nglString          mPort;
  nglString          mName;
  std::vector<float> mAxes;
  std::vector<bool>  mButtons;

private:
  uint               mRefCnt;
};

#endif // __nglInputDeviceInstance_h__
