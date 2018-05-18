//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x = 7, y = 7;
int result = 0;
int numberOfBounces = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
     points->Visible = false;
     Label1->Visible = false;
     Label2->Visible = false;
     Button2->Visible = false;
     paddleLeft->Left = 80;
     paddleLeft->Top = tlo->Height/2 - paddleLeft->Height/2;
     paddleRight->Left = tlo->Width - 80 - paddleRight->Width;
     paddleRight->Top = tlo->Height/2 - paddleRight->Height/2;


     //wspolrzedne poczatkowe pilki    ostatecznie myslalam o dwoch opcjach
     ball->Left = 115;
     ball->Top = 10;
     x = 7, y = 7;
     TimerBall->Enabled = true;
     ball->Visible = true;

     line->Left = tlo->Width/2 - line->Width/2;
     line->Height = tlo->Height;

     Button1->Visible = false;
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

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
   //ruch pocz¹tkowy pi³ki
   ball->Left += x;
   ball->Top += y;

   //odbijaj od górnej sciany
   if (ball->Top - 5 <= tlo->Top) y = -y ;

   //odbijaj od dolnej sciany
   if (ball->Top + ball->Height + 1 >= tlo->Height) y = -y;

   //skucha!
    if ((( ball->Left < paddleLeft->Left  &&
        (ball->Top + ball->Height / 2 < paddleLeft->Top ||
        ball->Top + ball->Height / 2 > paddleLeft->Top + paddleLeft->Height)) ||
        (ball->Left + ball->Width > paddleRight->Left + paddleRight->Width &&
        (ball->Top + ball->Height / 2 < paddleRight->Top ||
        ball->Top + ball->Height / 2 > paddleRight->Top + paddleRight->Height))))
    {
        result++;
        TimerBall->Enabled = false;
        ball->Visible = false;
        points->Visible = true;
        Label1->Visible = true;
        Label2->Visible = true;
        Button2->Visible = true;
        Button1->Visible = true;

      }

   //odbicie pilki od paletki lewej najprostsza
   else if ((ball->Left < paddleLeft->Left + paddleLeft->Width &&
           ball->Top + ball->Height/2 <= paddleLeft->Top + paddleLeft->Height &&
           ball->Top + ball->Height/2 >= paddleLeft->Top))
       {
                x = - x;
                numberOfBounces++;
       }
       
        //odbicie pilki od paletki prawej najprostsza    dzia³a
else if ((ball->Left + ball->Width >= paddleRight->Left  &&
           ball->Top + ball->Height/2 <= paddleRight->Top + paddleRight->Height &&
           ball->Top + ball->Height/2 >= paddleRight->Top))
       {
                x = - x;
       }


}
//---------------------------------------------------------------------------




