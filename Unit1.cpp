//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
     paddleLeft->Left = 80;
     paddleLeft->Top = tlo->Height/2 - paddleLeft->Height/2;
     paddleRight->Left = tlo->Width - 80 - paddleRight->Width;
     paddleRight->Top = tlo->Height/2 - paddleRight->Height/2;
     Button1->Visible = false;
     line->Left = tlo->Width/2 - line->Width/2;
     line->Height = tlo->Height;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerLeftPaddleTopTimer(TObject *Sender)
{
        if( paddleLeft->Top > 5)   paddleLeft->Top-=5;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerLeftPaddleBothTimer(TObject *Sender)
{
        if( paddleLeft->Top + paddleLeft->Height < tlo->Height-5)
        paddleLeft->Top+=5;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_UP)  TimerRightPaddleTop->Enabled = true;
        if (Key == VK_DOWN) TimerRightPaddleBoth->Enabled = true;
        if (Key == 0x41)  TimerLeftPaddleTop->Enabled = true;   //0x41 A
        if (Key == 0x5A)   TimerLeftPaddleBoth->Enabled = true; //0x5A Z

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_UP)  TimerRightPaddleTop->Enabled = false;
        if (Key == VK_DOWN) TimerRightPaddleBoth->Enabled = false;
        if (Key == 0x41)  TimerLeftPaddleTop->Enabled = false;   //0x41 A
        if (Key == 0x5A)   TimerLeftPaddleBoth->Enabled = false; //0x5A Z
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerRightPaddleTopTimer(TObject *Sender)
{
        if( paddleRight->Top > 5)   paddleRight->Top-=5;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerRightPaddleBothTimer(TObject *Sender)
{
        if( paddleRight->Top + paddleRight->Height < tlo->Height-5)
        paddleRight->Top+=5;
}
//---------------------------------------------------------------------------
