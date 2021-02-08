//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <comobj.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TOpenDialog *od;
	TPageControl *PageControl;
	TTabSheet *MajorMenu;
	TTabSheet *TabSheet1;
	TPanel *Panel3;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TCheckBox *CheckBox1;
	TMaskEdit *RowMaskEdit;
	TMaskEdit *ColMaskEdit;
	TMaskEdit *SelectColMaskEdit;
	TUpDown *UpDown1;
	TUpDown *UpDown2;
	TUpDown *UpDown3;
	TPanel *Panel1;
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button2;
	TButton *Button1;
	TDrawGrid *DrawGrid1;
	TButton *Button3;
	TPanel *Panel2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall CheckCells(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
