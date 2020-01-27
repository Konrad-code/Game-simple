//---------------------------------------------------------------------------

#ifndef UnitH
#define UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TLabel *Label1;
        TButton *Button3;
        TButton *Button4;
        TImage *w;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TButton *Button9;
        TButton *Button10;
        TButton *Button11;
        TButton *Button12;
        TButton *Button13;
        TButton *Button14;
        TButton *Button15;
        TButton *Button16;
        TButton *Button17;
        TButton *Button18;
        TButton *Button19;
        TImage *l;
        TImage *s;
        TButton *Button20;
        TButton *Button21;
        TButton *Button22;
        TButton *Button23;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TButton *Button24;
        TButton *Button26;
        TButton *Button27;
        TButton *Button25;
        TButton *Button28;
        TButton *Button29;
        TButton *Button30;
        TButton *Button31;
        TButton *Button32;
        TButton *Button33;
        TButton *Button34;
        TButton *Button35;
        TButton *Button36;
        TButton *Button37;
        TButton *Button38;
        TButton *Button39;
        TButton *Button40;
        TButton *Button41;
        TButton *Button42;
        TButton *Button43;
        TLabel *Label5;
        TButton *Button44;
        TButton *Button45;
        TButton *Button46;
        TButton *Button47;
        TButton *Button48;
        TButton *Button49;
        TButton *Button50;
        TButton *Button51;
        TButton *Button52;
        TButton *Button53;
        TButton *Button54;
        TButton *Button55;
        TImage *tlo;
        TTimer *Timer_do_koloseum;
        TTimer *Timer1_z_koloseum;
        TTimer *Timer1_do_kowala;
        TTimer *Timer1_od_kowala;
        TTimer *Timer1_na_arene;
        TTimer *Timer1_z_areny;
        TTimer *Timer1_do_arka;
        TTimer *Timer1_od_arka;
        TTimer *Timer1_do_handlarki;
        TTimer *Timer1_od_handlarki;
        TTimer *Timer1_do_tawerny;
        TTimer *Timer1_z_tawerny;
        TTimer *Timer1_do_zamku;
        TTimer *Timer1_z_zamku;
        TTimer *Timer1_na_pustynie;
        TTimer *Timer1_z_pustyni;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button20Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
        void __fastcall Button17Click(TObject *Sender);
        void __fastcall Button18Click(TObject *Sender);
        void __fastcall Button19Click(TObject *Sender);
        void __fastcall Button21Click(TObject *Sender);
        void __fastcall Button22Click(TObject *Sender);
        void __fastcall Button23Click(TObject *Sender);
        void __fastcall Button24Click(TObject *Sender);
        void __fastcall Button26Click(TObject *Sender);
        void __fastcall Button27Click(TObject *Sender);
        void __fastcall Button25Click(TObject *Sender);
        void __fastcall Button28Click(TObject *Sender);
        void __fastcall Button29Click(TObject *Sender);
        void __fastcall Button30Click(TObject *Sender);
        void __fastcall Button31Click(TObject *Sender);
        void __fastcall Button32Click(TObject *Sender);
        void __fastcall Button33Click(TObject *Sender);
        void __fastcall Button34Click(TObject *Sender);
        void __fastcall Button35Click(TObject *Sender);
        void __fastcall Button36Click(TObject *Sender);
        void __fastcall Button37Click(TObject *Sender);
        void __fastcall Button38Click(TObject *Sender);
        void __fastcall Button39Click(TObject *Sender);
        void __fastcall Button40Click(TObject *Sender);
        void __fastcall Button41Click(TObject *Sender);
        void __fastcall Button42Click(TObject *Sender);
        void __fastcall Button43Click(TObject *Sender);
        void __fastcall Button44Click(TObject *Sender);
        void __fastcall Button45Click(TObject *Sender);
        void __fastcall Button46Click(TObject *Sender);
        void __fastcall Button47Click(TObject *Sender);
        void __fastcall Button48Click(TObject *Sender);
        void __fastcall Button49Click(TObject *Sender);
        void __fastcall Button50Click(TObject *Sender);
        void __fastcall Button51Click(TObject *Sender);
        void __fastcall Button52Click(TObject *Sender);
        void __fastcall Button53Click(TObject *Sender);
        void __fastcall Button54Click(TObject *Sender);
        void __fastcall Button55Click(TObject *Sender);
        void __fastcall Timer_do_koloseumTimer(TObject *Sender);
        void __fastcall Timer1_z_koloseumTimer(TObject *Sender);
        void __fastcall Timer1_do_kowalaTimer(TObject *Sender);
        void __fastcall Timer1_od_kowalaTimer(TObject *Sender);
        void __fastcall Timer1_na_areneTimer(TObject *Sender);
        void __fastcall Timer1_z_arenyTimer(TObject *Sender);
        void __fastcall Timer1_do_arkaTimer(TObject *Sender);
        void __fastcall Timer1_od_arkaTimer(TObject *Sender);
        void __fastcall Timer1_do_handlarkiTimer(TObject *Sender);
        void __fastcall Timer1_od_handlarkiTimer(TObject *Sender);
        void __fastcall Timer1_do_tawernyTimer(TObject *Sender);
        void __fastcall Timer1_z_tawernyTimer(TObject *Sender);
        void __fastcall Timer1_do_zamkuTimer(TObject *Sender);
        void __fastcall Timer1_z_zamkuTimer(TObject *Sender);
        void __fastcall Timer1_na_pustynieTimer(TObject *Sender);
        void __fastcall Timer1_z_pustyniTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
