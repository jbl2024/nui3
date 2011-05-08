/*
  NUI3 - C++ cross-platform GUI framework for OpenGL based applications
  Copyright (C) 2002-2003 Sebastien Metrot

  licence: see nui3/LICENCE.TXT
*/

#include "nui.h"
#include "MainWindow.h"
#include "Application.h"
#include "nuiCSS.h"
#include "nuiVBox.h"

#include "nuiTextLayout.h"
#include "nuiFontManager.h"
#include "nuiFont.h"

/*
 * MainWindow
 */

MainWindow::MainWindow(const nglContextInfo& rContextInfo, const nglWindowInfo& rInfo, bool ShowFPS, const nglContext* pShared )
  : nuiMainWindow(rContextInfo, rInfo, pShared, nglPath(ePathCurrent)), mEventSink(this),
    mpLayout(NULL), mpFont(NULL)
{
  SetDebugMode(true);
  //mClearBackground = false;
}

MainWindow::~MainWindow()
{
  delete mpLayout;
  if (mpFont)
    mpFont->Release();
}


void MainWindow::OnCreation()
{
  nuiScrollView* pScrollView = new nuiScrollView;
  nuiEditText* pText = new nuiEditText(_T("Type something here\n\n"));
  
  nglIStream* pStream = nglPath("rsrc:/test.txt").OpenRead();
  if (pStream)
  {
    pStream->SetTextEncoding(eUTF8);
    nglString text;
    pStream->ReadText(text);

    nuiFontRequest request;
    request.MustHaveSize(25, 2);
    request.SetName("Times", 2);
    //request.SetName("Helvetica", 2);
    mpFont = nuiFontManager::GetManager().GetFont(request);
    printf("Requested font: %s\n", mpFont->GetFamilyName().GetChars());
    mpLayout = new nuiTextLayout(mpFont);
    mpLayout->LayoutText(text);
    
    pText->AddText(text);
    delete pStream;
  }
  
  pText->SetTextColor(nuiColor(128,128,128));
  AddChild(pScrollView);
  pScrollView->AddChild(pText);
  
  pScrollView->SetBorder(10, 10, 32, 32);
}

bool MainWindow::Draw(nuiDrawContext* pContext)
{
  nuiMainWindow::Draw(pContext);

  if (mpLayout)
  {
    pContext->SetTextColor(nuiColor(0, 0, 0));
    mpFont->Print(pContext, 100, 100, mpLayout, false);
  }
  
  return true;
}