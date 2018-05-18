object Form1: TForm1
  Left = 398
  Top = 575
  Width = 848
  Height = 469
  Caption = 'PingPong by Monika'
  Color = clBtnFace
  UseDockManager = True
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  DesignSize = (
    832
    430)
  PixelsPerInch = 96
  TextHeight = 13
  object tlo: TShape
    Left = 0
    Top = 0
    Width = 832
    Height = 430
    Align = alClient
    Brush.Color = clGreen
  end
  object line: TShape
    Left = 401
    Top = 0
    Width = 6
    Height = 433
  end
  object paddleLeft: TShape
    Left = 64
    Top = 160
    Width = 30
    Height = 150
    Brush.Color = clRed
    Pen.Width = 2
  end
  object paddleRight: TShape
    Left = 664
    Top = 160
    Width = 30
    Height = 150
    Brush.Color = clRed
    Pen.Width = 2
  end
  object ball: TShape
    Left = 88
    Top = 80
    Width = 30
    Height = 30
    Brush.Color = clYellow
    Shape = stCircle
  end
  object Label2: TLabel
    Left = 296
    Top = 192
    Width = 217
    Height = 35
    Anchors = [akLeft, akTop, akBottom]
    Caption = 'Ilosc odbic:'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Serif'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label1: TLabel
    Left = 296
    Top = 128
    Width = 193
    Height = 33
    Anchors = [akLeft, akTop, akRight, akBottom]
    Caption = 'Wynik: '
    Color = clSkyBlue
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clBlue
    Font.Height = -31
    Font.Name = 'MS Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Visible = False
  end
  object points: TLabel
    Left = 208
    Top = 40
    Width = 385
    Height = 42
    Caption = 'Punkt dla gracza prawego -->'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Papyrus'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Button1: TButton
    Left = 256
    Top = 320
    Width = 300
    Height = 60
    Cursor = crHandPoint
    Caption = 'Nowa gra'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -31
    Font.Name = 'MS Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 256
    Top = 248
    Width = 300
    Height = 60
    Caption = 'Nast'#281'pna rudna'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clLime
    Font.Height = -23
    Font.Name = 'MS Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Visible = False
  end
  object TimerLeftPaddleTop: TTimer
    Enabled = False
    Interval = 10
    OnTimer = TimerLeftPaddleTopTimer
    Left = 24
    Top = 160
  end
  object TimerLeftPaddleBoth: TTimer
    Enabled = False
    Interval = 10
    OnTimer = TimerLeftPaddleBothTimer
    Left = 24
    Top = 192
  end
  object TimerRightPaddleTop: TTimer
    Enabled = False
    Interval = 10
    OnTimer = TimerRightPaddleTopTimer
    Left = 712
    Top = 160
  end
  object TimerRightPaddleBoth: TTimer
    Enabled = False
    Interval = 10
    OnTimer = TimerRightPaddleBothTimer
    Left = 712
    Top = 192
  end
  object TimerBall: TTimer
    Enabled = False
    Interval = 20
    OnTimer = TimerBallTimer
    Left = 88
    Top = 48
  end
end
