object Form4: TForm4
  Left = 0
  Top = 0
  Caption = #1055#1088#1072#1081#1089
  ClientHeight = 485
  ClientWidth = 424
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Times New Roman'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 21
  object PageControl: TPageControl
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 418
    Height = 479
    ActivePage = MajorMenu
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 452
    object MajorMenu: TTabSheet
      AlignWithMargins = True
      Caption = #1043#1083#1072#1074#1085#1086#1077' '#1084#1077#1085#1102
      ExplicitLeft = 4
      ExplicitTop = 32
      ExplicitWidth = 281
      ExplicitHeight = 157
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 404
        Height = 89
        Align = alTop
        TabOrder = 0
        ExplicitTop = 22
        ExplicitWidth = 401
        object Label1: TLabel
          Left = 128
          Top = 69
          Width = 5
          Height = 21
        end
        object Edit1: TEdit
          Left = 0
          Top = 0
          Width = 393
          Height = 29
          AutoSelect = False
          AutoSize = False
          ReadOnly = True
          TabOrder = 0
        end
        object Button2: TButton
          Left = 128
          Top = 30
          Width = 129
          Height = 33
          Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
          Enabled = False
          TabOrder = 1
          OnClick = Button2Click
        end
        object Button1: TButton
          Left = 1
          Top = 30
          Width = 121
          Height = 33
          Caption = #1042#1099#1073#1088#1072#1090#1100
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = Button1Click
        end
        object DrawGrid1: TDrawGrid
          Left = 264
          Top = 88
          Width = 320
          Height = 120
          TabOrder = 3
        end
        object Button3: TButton
          Left = 263
          Top = 30
          Width = 129
          Height = 33
          Caption = #1054#1073#1088#1072#1073#1086#1090#1072#1090#1100
          Enabled = False
          TabOrder = 4
          OnClick = Button3Click
        end
      end
      object Panel2: TPanel
        Left = 0
        Top = 89
        Width = 404
        Height = 348
        Align = alClient
        TabOrder = 1
        ExplicitTop = 144
        ExplicitWidth = 393
        ExplicitHeight = 177
      end
    end
    object TabSheet1: TTabSheet
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      ImageIndex = 1
      ExplicitLeft = 108
      ExplicitTop = 48
      ExplicitWidth = 484
      ExplicitHeight = 321
      object Panel3: TPanel
        Left = 144
        Top = 7
        Width = 225
        Height = 169
        TabOrder = 0
        object Label2: TLabel
          Left = 16
          Top = 26
          Width = 60
          Height = 21
          Caption = #1057#1090#1088#1086#1082#1080
        end
        object Label3: TLabel
          Left = 120
          Top = 26
          Width = 73
          Height = 21
          Caption = #1057#1090#1086#1083#1073#1094#1099
        end
        object Label4: TLabel
          Left = 31
          Top = -1
          Width = 141
          Height = 21
          Caption = #1040#1074#1090#1086#1086#1087#1088#1077#1076#1077#1083#1077#1085#1080#1077
        end
        object Label5: TLabel
          Left = 0
          Top = 104
          Width = 216
          Height = 21
          Caption = #1053#1086#1084#1077#1088' '#1089#1090#1086#1083#1073#1094#1072' '#1076#1083#1103' '#1086#1090#1073#1086#1088#1072
        end
        object CheckBox1: TCheckBox
          Left = 8
          Top = 0
          Width = 20
          Height = 20
          Hint = '1'
          Margins.Left = 50
          Margins.Top = 50
          Margins.Right = 50
          Margins.Bottom = 50
          Constraints.MaxHeight = 20
          Constraints.MaxWidth = 20
          Constraints.MinHeight = 20
          Constraints.MinWidth = 20
          Ctl3D = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -40
          Font.Name = 'Times New Roman'
          Font.Style = []
          ParentCtl3D = False
          ParentFont = False
          TabOrder = 0
          OnClick = CheckBox1Click
        end
        object RowMaskEdit: TMaskEdit
          Left = 8
          Top = 53
          Width = 69
          Height = 29
          Alignment = taCenter
          EditMask = '!999;1;_'
          MaxLength = 3
          TabOrder = 1
          Text = '251'
        end
        object ColMaskEdit: TMaskEdit
          Left = 120
          Top = 53
          Width = 75
          Height = 29
          Alignment = taCenter
          EditMask = '!999;1;_'
          MaxLength = 3
          TabOrder = 2
          Text = ' 14'
        end
        object SelectColMaskEdit: TMaskEdit
          Left = 72
          Top = 131
          Width = 62
          Height = 29
          Alignment = taCenter
          EditMask = '!999;1;_'
          MaxLength = 3
          TabOrder = 3
          Text = ' 13'
        end
        object UpDown1: TUpDown
          Left = 195
          Top = 53
          Width = 16
          Height = 29
          Associate = ColMaskEdit
          Max = 999
          Position = 14
          TabOrder = 4
        end
        object UpDown2: TUpDown
          Left = 77
          Top = 53
          Width = 16
          Height = 29
          Associate = RowMaskEdit
          Max = 999
          Position = 251
          TabOrder = 5
        end
        object UpDown3: TUpDown
          Left = 134
          Top = 131
          Width = 16
          Height = 29
          Associate = SelectColMaskEdit
          Max = 999
          Position = 13
          TabOrder = 6
        end
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 640
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = '-'
      end
      object N3: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = N3Click
      end
    end
    object N4: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object N5: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = N5Click
      end
    end
  end
  object od: TOpenDialog
    Filter = #1050#1085#1080#1075#1072' EXEL|*.xlsx|'#1050#1085#1080#1075#1072' EXEL 97-2003|*.xls'
    Left = 648
    Top = 48
  end
end
