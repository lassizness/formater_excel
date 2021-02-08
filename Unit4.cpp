// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
float box = 0;
float sht = 0;
float fas = 0;
bool CheckCreatGrid = false;
TStringGrid *StringGrid;
TCheckBox *check;
Variant App, Bks, Bk, Sht, Shts, Cll;

// ---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender) {
	if (od->Execute()) {
		Edit1->Text = od->FileName;
		Button2->Enabled = true;
	}
	else {
		ShowMessage("���� �� ������.");
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender) {
	Button1->Enabled = false;
	Button2->Enabled = false;
	Label1->Caption = "������ ����.";
	// App- ����������, , Bk-�����,  Sht- ����, Cll - ������
	App = CreateOleObject("Excel.Application");
	App.OlePropertySet("Visible", false);
	// ������������� ��������� ���� � true ��� false.
	Bk = App.OlePropertyGet("Workbooks").OlePropertyGet("Open",
		WideString(od->FileName));
	// ���������  ����� � ������� ������.  |,0,FALSE,1,"","1488",FALSE|
	Sht = Bk.OlePropertyGet("Worksheets", 1);
	// ��������� ������ �������� �����. � ������ ������ 1.
	if (CheckCreatGrid == false) {
		StringGrid = new TStringGrid(Form4);
		// ����������� ������� ��������� �� �����.
		StringGrid->Parent = Panel2;
		StringGrid->FixedCols = 0;
		StringGrid->FixedRows = 1;
		StringGrid->Height = 360;
		StringGrid->Name = "StringGrid";
		StringGrid->ScrollBars = ssVertical;
		Panel2->Height = Panel2->Height + StringGrid->Height;
		Form4->Height = Form4->Height + StringGrid->Height;
		CheckCreatGrid = true;
	}

	int CountRow = 0, CountCol = 0, WriteCountCol = 0, WriteCountRow = 1;

	if (CheckBox1->Checked == true)
	{ // �������� �� ��������� ����� ��������������
		CountCol = Sht.OlePropertyGet("UsedRange").OlePropertyGet("Columns")
			.OlePropertyGet("Count");
		// ���������� ��������� �������� ������� ������� EXEL.
		CountRow = Sht.OlePropertyGet("UsedRange").OlePropertyGet("Rows")
			.OlePropertyGet("Count");
	}
	else {
		CountCol = StrToInt(ColMaskEdit->Text);
		CountRow = StrToInt(RowMaskEdit->Text);
	}
	// ���������� ��������� �������� ������ ������� EXEL.
	// � ��������������� ����������� �������� ������� ���� �����, ������
	// �������� ���� ����� ���� ������ ������� � �������.

	for (int i = 1; i <= CountRow; i++) {
		for (int j = 1; j <= CountCol; j++) {
			if (j == 1) {
				WriteCountCol = 1;
				// ��������� ����������, ������� ���� ���������� ����� � ��������.
				// ������������ ��� ������ ����� �������� �� ��������.
				if (VarToStr(Sht.OlePropertyGet("Cells", i,
					StrToInt(SelectColMaskEdit->Text))).Length() > 1) {
					StringGrid->RowCount = WriteCountRow++;
				}
			}
			if (VarToStr(Sht.OlePropertyGet("Cells", 2, j)).Length() != 0)
			{ // ��� �� �� ������� ����� ����������, ��������� �������������� VarToStr (Variant to String), �������� �� ����� ������. ���� ����� ����� 0, ������ ������ ������.
				if (i == 1)
				{ // ��������, �� ���� �� �������� ��� ������� ���������� �������. ��������� ����� ������, ���� 1, ����� ����������� ��� ����� �� ����� �������.
					check = new TCheckBox(Panel2);
					check->Parent = Panel2;
					check->Name = "check" + IntToStr(WriteCountCol);
					check->Width = 10;

					if (WriteCountCol > 1) {
						check->Left = 30 + (65 * (WriteCountCol - 1));
					}
					else {
						check->Left = 30;
					}
					check->Top = 5;
					check->Tag = WriteCountCol;
					check->OnClick = CheckCells;
					StringGrid->Objects[WriteCountCol][i] =
						dynamic_cast<TCheckBox*>
						(FindComponent("check" + IntToStr(WriteCountCol)));

					StringGrid->ColCount = WriteCountCol;
					StringGrid->Width = StringGrid->ColCount * 78;
					Panel2->Width = StringGrid->Width;
					Form4->Width = Panel2->Width + 50;
				}

				if ((VarToStr(Sht.OlePropertyGet("Cells", i,
					StrToInt(SelectColMaskEdit->Text))).Length() > 1)) {

					StringGrid->Cells[WriteCountCol - 1][WriteCountRow - 1] =
						VarToStr(Sht.OlePropertyGet("Cells", i, j));
					// �������� �������� ������ EXEl � ������, ��� �� �� ���� ������ ��� ������. ��������� �� try catch.
				}
				WriteCountCol++;
			}
		}
		Application->ProcessMessages();
	}
	StringGrid->RowCount++;
	App.OleProcedure("Quit");
	Label1->Caption = "��������� ������. ������ �������.";
	Button3->Enabled = true;
}

// ---------------------------------------------------------------------------
void __fastcall TForm4::FormResize(TObject * Sender) {
	// this->Width = 425;
	// this->Height = 159;
}

// ---------------------------------------------------------------------------
void __fastcall TForm4::N3Click(TObject * Sender) {
	Application->Terminate();
}
// ---------------------------------------------------------------------------

void __fastcall TForm4::N5Click(TObject * Sender) {
	ShowMessage("���� ������ �� ��������.");
}
// ---------------------------------------------------------------------------

void __fastcall TForm4::CheckCells(TObject * Sender) {
	// ShowMessage(((TCheckBox*)Sender)->Name);
}

// ---------------------------------------------------------------------------

void __fastcall TForm4::CheckBox1Click(TObject * Sender) {
	if (CheckBox1->Checked == true) {
		ColMaskEdit->Enabled = false;
		RowMaskEdit->Enabled = false;
	}
	else {
		ColMaskEdit->Enabled = true;
		RowMaskEdit->Enabled = true;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm4::Button3Click(TObject *Sender) {
	int CountCol = 1; // ���������� ��� ��������� ��������.
	App = CreateOleObject("Excel.Application");
	App.OlePropertySet("Visible", false);
	// ������������� ��������� ���� � true ��� false.
	Bks = App.OlePropertyGet("Workbooks"); // ���������  �����.
	App.OlePropertySet("SheetsInNewWorkbook", 1);
	Bks.OleProcedure("Add");
	Bk = Bks.OlePropertyGet("Item", 1);
	Shts = Bk.OlePropertyGet("Worksheets");
	Sht = Shts.OlePropertyGet("Item", 1);
	Label1->Caption = "����� � ����� ����.";

	for (int i = 1; i <= StringGrid->RowCount; i++) {
		for (int j = 1; j <= StringGrid->ColCount; j++) {

			if (j == 1) {
				CountCol = 1;
			}
			// ���� ����� ���������� �� ����� � ������ �����������.
			// �����, ������ ����� � �������� � �������.
			// ����� �������� �� ������������� ����
			if (dynamic_cast<TCheckBox*>(Panel2->FindComponent("check" +
				IntToStr(j)))->Checked == true) {
				Cll = Sht.OlePropertyGet("Cells").OlePropertyGet("Item", i,
					CountCol++);
				Cll.OlePropertySet("RowHeight", 20); //������ ������
				Cll.OlePropertySet("ColumnWidth", 15);// ������ ������
				Cll.OlePropertySet("WrapText", true); // ������� �� ������
				Cll.OlePropertySet("Value",
					WideString(StringGrid->Cells[j - 1][i - 1]));
			}
		}
	}
	/* Cll = Sht.OlePropertyGet("Cells").OlePropertyGet("Item", 1, 5);
	 Cll.OlePropertySet("Value", WideString("����� ������: " + table[2][16]));
	 Cll = Sht.OlePropertyGet("Cells").OlePropertyGet("Item", 1, allcol);
	 Cll.OlePropertyGet("Cells", 1, allcol).OlePropertySet("NumberFormat",
	 (L"_-* #,##0 [$?-ru-RU]_-;-* #,##0 [$?-ru-RU]_-;_-* " "-"
	 " [$?-ru-RU]_-;_-@_-")); */

	// Cll.OlePropertySet("Value", WideString("�����" + table[1][jj]));
	App.OlePropertySet("Visible", false);
	App.OlePropertyGet("Workbooks").OlePropertyGet("Item", 1).OleProcedure
		("SaveAs", WideString(ExtractFilePath(od->FileName) + "reform_" +
		ExtractFileName(od->FileName))); //��������� ���� EXEL � ��������� + �������� ���.
	App.OleProcedure("Quit"); //��������� EXEL �� ���������.
	Label1->Caption = "������.";
	Button1->Enabled = true;
	Button2->Enabled = false;
}
// ---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender)
{
Form4->ChangeScale(1000,1000);
}
//---------------------------------------------------------------------------

