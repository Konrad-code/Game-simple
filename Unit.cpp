//---------------------------------------------------------------------------
#include <iostream>
#include <vcl.h>
#pragma hdrstop
#include <string>
#include <windows.h>
#pragma hdrstop
#include <time.h>
#include <ctime>
#include "Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int coatak;
int tmp = 0;


class Skin
{
public:
        void wczytaj_skin(){};
};

class Wojownik:
public Skin
{
public:
        Wojownik(){};
        virtual void wczytaj_skin(TImage* z);
};

void Wojownik::wczytaj_skin(TImage* z)
{
        z -> Visible = true;
}
class Leonidas:
public Skin
{
public:
        Leonidas(){};
        virtual void wczytaj_skin(TImage* z);
};

void Leonidas::wczytaj_skin(TImage* z)
{
        z -> Visible = true;
}
class Spiderman:
public Skin
{
public:
        Spiderman(){};
        virtual void wczytaj_skin(TImage* z);
};

void Spiderman::wczytaj_skin(TImage* z)
{
        z -> Visible = true;
}




class Mob
{
public:
        friend class Postac;
        string nazwa;
        int hp, sila, obrona, expgain, goldgain;

        Mob(string n, int h);
        Mob(string n, int h, int przeciazacz1);
        Mob(string n, int h, int przeciazacz1, int przeciazacz2);
        Mob(string n, int h, int przeciazacz1, int przeciazacz2, int przeciazacz3);
        ~Mob();
};

Mob::~Mob()
{

}

Mob::Mob(string n, int h)
{
nazwa = n;
hp = h;
sila = (rand() % (int)(20*(hp/100)*1.2 - 20*(hp/100)*0.8)) + (int)(20*(hp/100)*0.8);
obrona = (rand() % (int)(5*(hp/100)*1.2 - 5*(hp/100)*0.8)) + (int)(5*(hp/100)*0.8);
expgain = 50*(hp/100);
goldgain = 100*(hp/100);
}

Mob::Mob(string n, int h, int przeciazacz1)
{
nazwa = n;
hp = h;
sila = (rand() % (int)(30*(hp/100)*1.2 - 30*(hp/100)*0.8)) + (int)(30*(hp/100)*0.8);
obrona = (rand() % (int)(5*(hp/100)*1.2 - 5*(hp/100)*0.8)) + (int)(5*(hp/100)*0.8);
expgain = 75*(hp/100);
goldgain = 150*(hp/100);
}

Mob::Mob(string n, int h, int przeciazacz1, int przeciazacz2)
{
nazwa = n;
hp = h;
sila = (rand() % (int)(40*(hp/100)*1.2 - 40*(hp/100)*0.8)) + (int)(40*(hp/100)*0.8);
obrona = (rand() % (int)(10*(hp/100)*1.2 - 10*(hp/100)*0.8)) + (int)(10*(hp/100)*0.8);
expgain = 100*(hp/100);
goldgain = 200*(hp/100);
}

Mob::Mob(string n, int h, int przeciazacz1, int przeciazacz2, int przeciazacz3)
{
nazwa = n;
hp = h;
sila = (rand() % (int)(50*(hp/100)*1.2 - 50*(hp/100)*0.8)) + (int)(50*(hp/100)*0.8);
obrona = (rand() % (int)(15*(hp/100)*1.2 - 15*(hp/100)*0.8)) + (int)(15*(hp/100)*0.8);
expgain = 150*(hp/100);
goldgain = 200*(hp/100);
}

Mob wilk("Wilk", 100);
Mob niedzwiedz("Niedzwiedz", 200);
Mob goblin("Goblin", 300);
Mob ork("Ork", 400);
Mob gryf("Gryf", 500);
Mob hydra("Hydra", 600);

Mob krzyzowiec("Krzyzowiec", 700, 1);
Mob paladyn("Paladyn", 800, 1);
Mob arcymag("Arcymag", 900, 1);
Mob archaniol("Archaniol", 1000, 1);

Mob herszt("Herszt ogrow", 1100, 1, 2);
Mob zawadiaka("Pustynny zawadiaka", 1200, 1, 2);
Mob zywiolak("Zywiolak wiatru", 1300, 1, 2);
Mob ent("Ent", 1400, 1, 2);
Mob tysieczny("Tysieczny wojownik", 1500, 1, 2);

Mob behemot("Behemot", 1600, 1, 2, 3);
Mob dementor("Dementor", 1700, 1, 2, 3);
Mob czart("Czart", 1800, 1, 2, 3);
Mob smok("Czarny smok", 1900, 1, 2, 3);
Mob krol("Krol", 2000, 1, 2, 3);



class Postac
{
int hp, hp_max, exp, lvl, atak, obrona, gold;
string nazwa;
public:
        friend class Handlarka;
        friend class Tawerna;
        friend class Kowal;
        friend class Zul;
        void atakuj(Mob m, TLabel*);
        void status(TLabel*, TImage* w, TImage* l, TImage* s);
        void awans();
        Postac();
        ~Postac();
};

Postac::Postac()
{
        nazwa = "mHm_MaXi";
        lvl = 1;
        hp_max = 75*lvl;
        hp = hp_max;
	exp = 0;
        atak = 30;
        obrona = 10;
	gold = 10000;
}

Postac::~Postac()
{
}

void Postac::awans()
{
	int temp;
	if (exp < 0)
	{
		while (exp < 0)
		{
			temp = exp;
			lvl--;
                        obrona--;
                        atak--;
                        hp_max = 75*lvl;
                        hp = hp_max;
			if (hp < 0) hp = 1;
			exp = lvl*150 + temp;
			if (lvl == 1) {exp = 0; hp = 1; hp_max = 75*lvl;}
			if (lvl < 1)
                        {
				lvl = 1;
				exp = 0;
                                hp = 1;
                                hp_max = 75*lvl;
			}
		}
	}
	else if (exp >= lvl*150)
	{
		exp = exp - (lvl*150);
		lvl++;
		hp_max = 75*lvl + 100;
                hp = hp_max;
		gold += 100;
                atak++;
                obrona++;
	}
}

void Postac::atakuj(Mob m, TLabel*)
{
        //Sleep(2000);
        int walka = 1, dmg, przewaga;
	srand((unsigned int)time(NULL));

        AnsiString b, c, d, e, g;

        b = IntToStr(hp);
        c = IntToStr(hp_max);
	d = IntToStr(m.expgain);
        e = IntToStr(m.goldgain);
        g = IntToStr(3*m.expgain);

	//cout << "WALKA Z MOBEM: " << mob->nazwa << endl;
	while (walka != 0)
	{

		przewaga = (atak - m.obrona);
		dmg = (rand() % (przewaga - (int)(przewaga*0.6))) + (int)(przewaga*0.6);
		if (dmg < 0) dmg = 0;
		m.hp -= dmg;
		if (m.hp <= 0)
		{
			walka = 0;
			exp += m.expgain;
			gold +=  m.goldgain;
                        b = IntToStr(hp);

                       Form1 -> Label4 -> Caption = "WYGRANA\nHP: "+b+"/"+c+"\nEXP: +"+d+"\nGOLD: +"+e;
                       Form1 -> Label4 -> Visible = true;
                       Form1 -> Button26 -> Visible = true;
                       Form1 -> Button27 -> Visible = true;
			//cout << "WYGRALES!!!" << endl;
		}
		else
		{
			przewaga = m.sila - obrona;
			dmg = (rand() % (przewaga-(int)(przewaga*0.6))) + (int)(przewaga*0.6);
			if (dmg<0) dmg = 0;
			hp -= dmg;
			if (hp <= 0)
			{
				hp = 1;
				walka = 0;
				exp -= (3 * m.expgain);
                                b = IntToStr(hp);

	                Form1 -> Label4 -> Caption = "PRZEGRANA\nHP: "+b+"/"+c+"\nEXP: -"+g;
                        Form1 -> Label4 -> Visible = true;
                        Form1 -> Button26 -> Visible = true;
				//cout << "PRZEGRALES!!!" << endl;
			}
		}
	}
        awans();
}

TImage* porownanie(TImage* w, TImage* l, TImage* s)
{
        TImage *wsk;
        if(w -> Visible == true)
        {
                wsk = w;
        }
        else if(l -> Visible == true)
                {
                        wsk = l;
                }
                else if(s -> Visible == true)
                        {
                                wsk = s;
                        }
        return wsk;
}
void Postac::status(TLabel*, TImage* w, TImage* l, TImage* s)
{
        TImage *abc;
        abc = porownanie(w, l, s);

        AnsiString b, c, d, e, f, g, h;
        string a(nazwa);
        AnsiString j = AnsiString (a.c_str());
        b = IntToStr(hp);
        c = IntToStr(hp_max);
	d = IntToStr(exp);
        e = IntToStr(atak);
        f = IntToStr(obrona);
	g = IntToStr(lvl);
	h = IntToStr(gold);
        AnsiString i(abc->Name);
        if(i == "w") i = "Wojownik";
        if(i == "l") i = "Leonidas";
        if(i == "s") i = "Spiderman";
        //AnsiString k = AnsiString (i.c_str()));
        //i = abc -> Name;

        /*String c;
        int b = 500;
        c = IntToStr(b); */

        Form1 -> Label3 -> Caption = "NICK POSTACI: "+j+"\nKlasa postaci: "+i+
                                        "\nHP: "+b+"\nHP Max: "+c+"\nEXP: "+d+
                                        "\nLEVEL: "+g+"\nATAK: "+e+"\nOBRONA: "+f+
                                        "\nGOLD: "+h;
        Form1 -> Label3 -> Visible = true;
}

class Handlarka
{
public:
        int wsp;
        void lecz(int x, Postac *pos, TLabel*);
        Handlarka(Postac *pos);
};

Handlarka::Handlarka(Postac *pos)
{
wsp = 0;
}

void Handlarka::lecz(int x, Postac *pos, TLabel*)
{
        wsp = x;
        int z = 0;
        if(wsp == 25)
        {
                z=0;
        }
        else
                {
                z = wsp * 10;
                }
        if (pos -> hp < pos -> hp_max && pos -> gold >= (500 + z))
        {
                pos -> hp = (pos -> hp) + (wsp*(pos -> hp_max)/100);
                if(pos -> hp > pos -> hp_max) pos -> hp = pos -> hp_max;
                pos -> gold -= (500 + z);
                Form1 -> Label5 -> Caption = "Zostales uleczony!";
                Form1 -> Label5 -> Visible = true;
        }
        else
        {
                Form1 -> Label5 -> Caption = "Jestes zdrow lub zbyt biedny!";
                Form1 -> Label5 -> Visible = true;
        }
}

class Tawerna
{
public:
        int wsp;
        void graj_karty(int x, int y, Postac *pos, TLabel*);
        Tawerna(Postac *pos);
};

Tawerna::Tawerna(Postac *pos)
{
wsp = 0;
}

void Tawerna::graj_karty(int x, int y, Postac *pos, TLabel*)
{
        Sleep(5500);
        srand((unsigned int)time(NULL));
        int hajs = x;
        wsp = y;
        if (pos -> gold < hajs)
        {
                Form1 -> Label5 -> Caption = "Nie stac cie na gre";
                Form1 -> Label5 -> Visible = true;
        }
        if (pos -> gold >= hajs)
        {
                 int z = (int)(rand() % 10) + (int)(pos -> exp);
                 int h = (pos -> gold - z) % 10;
                 if(h < wsp)
                {
                        Form1 -> Label5 -> Caption = "WYGRANA! Zgarniasz monety wiesniakow";
                        Form1 -> Label5 -> Visible = true;
                        pos -> gold += hajs;
                }
                 else
                {
                        Form1 -> Label5 -> Caption = "PRZEGRANA! Tracisz swoje pieniadze";
                        Form1 -> Label5 -> Visible = true;
                        pos -> gold -= hajs;
                }
        }
}

class Kowal
{
public:
        void ulepsz(int x, Postac *pos, TLabel*);
        Kowal(Postac *pos);
};

Kowal::Kowal(Postac *pos)
{
}

void Kowal::ulepsz(int x, Postac *pos, TLabel*)
{
        int tmp = x;
        int hajs;
        if (((tmp == 1 || tmp == 2) && (pos -> gold < 5000)) || (tmp == 3 || tmp == 4) && (pos -> gold < 1000000))
        {
                Form1 -> Label5 -> Caption = "Nie stac cie na ulepszanie";
                Form1 -> Label5 -> Visible = true;
        }
        else
        {
                Sleep(3000);
                Form1 -> Label5 -> Caption = "Ulepszanie zakonczone powodzeniem";
                Form1 -> Label5 -> Visible = true;
                if(tmp == 1) {pos -> atak++; hajs = (int)(((pos -> gold) + 5000) / 10) * (pos -> lvl);}
                if(tmp == 2) {pos -> obrona++; hajs = (int)(((pos -> gold) + 5000) / 10) * (pos -> lvl);}
                if(tmp == 3) {(int)(pos -> atak *= 1.15); hajs = 1000000;}
                if(tmp == 4) {(int)(pos -> obrona *= 1.15); hajs = 1000000;}
                pos -> gold -= hajs;
        }
}

class Zul
{
public:
        void baluj(int x, Postac *pos, TLabel*);
        Zul(Postac *pos);
};

Zul::Zul(Postac *pos)
{
}

void Zul::baluj(int x, Postac *pos, TLabel*)
{
        int a = x;
        if(a == 1)
        {
                Form1 -> Label5 -> Caption = "Ostatnio na baletach z lysym...";
                Form1 -> Label5 -> Visible = true;
        }
        if(a == 2)
        {
                if(pos->gold < 2)
        {
                Form1 -> Label5 -> Caption = "Jestes biedniejszy od zula...";
                Form1 -> Label5 -> Visible = true;
        }
        else
        {
                pos -> gold -= 2;
                Form1 -> Label5 -> Caption = "Pomogles ksieciuniowi w potrzebie";
                Form1 -> Label5 -> Visible = true;
        }
        }
        if(a == 3)
        {
        if(pos -> gold < 1000)
        {
                Form1 -> Label5 -> Caption = "Nie stac cie na noc pelna przygod";
                Form1 -> Label5 -> Visible = true;
        }
        else
        {
                Form1 -> Label5 -> Caption = "Co sie stalo? Gdzie jestem ja i moje pieniadze?";
                Form1 -> Label5 -> Visible = true;
                pos -> gold -= 1000;
                Sleep(30000);
        }
        }
}

class Pole
{
public:
        Pole();
        char p;
};

Pole::Pole()
{
        p='n';
}

class Plansza
{
public:
        Plansza();
        ~Plansza();
        TImage * plansza[1];
        Pole * pozycja[1];
        void Stworz();
};

Plansza::Plansza()
{
}

Plansza::~Plansza()
{
        for (int i=0;i<2;i+=3)
        {
                plansza[i]=NULL;
                pozycja[i]=NULL;
        }
delete plansza;
delete pozycja;
}

void Plansza::Stworz()
{
                        plansza[1]=new TImage(Form1);
                        plansza[1]->Parent=Form1;
                        plansza[1]->Picture->LoadFromFile("img/mapa_1100.bmp");
                        plansza[1]->Height=687;  //437   1600   687
                        plansza[1]->Width=1100;  //700  2560    1100
                        plansza[1]->Left=10;
                        plansza[1]->Top=10;
                        plansza[1]->Visible=true;
                        plansza[1] -> Transparent = true;
                        pozycja[1]=new Pole;
}

class Graj
{
public:
        int x;
        int y;
        Graj();
        void Run(Plansza*);
};

Graj::Graj()
{
}

void Graj::Run(Plansza* p)
{
    // p->Idz(x,y);
}

Plansza plansz;
Graj gra;
Wojownik woj;
Leonidas leo;
Spiderman spi;
Postac pos;
Handlarka hand(&pos);
Tawerna krupier(&pos);
Kowal kow(&pos);
Zul arek(&pos);

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Button3Click(Button1);
        Sleep(1000);
        Label1 -> Visible = false;
        Button2 -> Caption = "Zaczynajmy!";

        Button1 -> Caption = "Do dziela!";
        Button1 -> Visible = false;
        Button2 -> Visible = false;
        Button3 -> Visible = false;
        Button4 -> Visible = false;
        Label2 -> Visible = true;
        Button21 -> Visible = true;
        Button22 -> Visible = true;
        Button23 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Button4Click(Button2);
        Sleep(1000);
        Label1 -> Visible = false;
        Button2 -> Caption = "Do dziela!";
        Button1 -> Caption = "Zaczynajmy!";
        Button1 -> Visible = false;
        Button2 -> Visible = false;
        Button3 -> Visible = false;
        Button4 -> Visible = false;
        Label2 -> Visible = true;
        Button21 -> Visible = true;
        Button22 -> Visible = true;
        Button23 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Button3 -> Visible = true;
        Sleep(1000);
        Button3 -> Caption = "3";
        Sleep(1000);
        Button3 -> Caption = "2";
        Sleep(1000);
        Button3 -> Caption = "1";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        Button4 -> Visible = true;
        Sleep(1000);
        Button4 -> Caption = "1";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        //    >>>>  KOLOSEUM   <<<<
        Timer1_z_koloseum->Enabled=false;
        Timer1_od_kowala->Enabled=false;
        Timer1_z_areny->Enabled=false;
        Timer1_od_arka->Enabled=false;
        Timer1_od_handlarki->Enabled=false;
        Timer1_z_tawerny->Enabled=false;
        Timer1_z_zamku->Enabled=false;
        Timer1_z_pustyni->Enabled=false;
        tmp = 0;
        Timer_do_koloseum->Enabled=true;
        Button5 -> Visible = false;
        Button6 -> Visible = false;
        Button7 -> Visible = false;
        Button8 -> Visible = false;
        Button9 -> Visible = false;
        Button10 -> Visible = false;
        Button11 -> Visible = false;
        Button12 -> Visible = false;
        Button13 -> Visible = true;
        Button14 -> Visible = true;
        Button15 -> Visible = true;
        Button16 -> Visible = true;
        Button17 -> Visible = true;
        Button18 -> Visible = true;
        Button19 -> Visible = true;
        Button24 -> Visible = false;
        Button26 -> Visible = false;
        Button27 -> Visible = false;
        Label3 -> Visible = false;
        Label4 -> Visible = false;
        Button25 -> Visible = false;
        Button28 -> Visible = false;
        Button29 -> Visible = false;
        Button30 -> Visible = false;
        Button31 -> Visible = false;
        Button32 -> Visible = false;
        Button33 -> Visible = false;
        Button34 -> Visible = false;
        Button35 -> Visible = false;
        Button36 -> Visible = false;
        Button37 -> Visible = false;
        Button38 -> Visible = false;
        Button39 -> Visible = false;
        Button40 -> Visible = false;
        Button44 -> Visible = false;
        Button45 -> Visible = false;
        Button46 -> Visible = false;
        Button47 -> Visible = false;
        Button48 -> Visible = false;
        Label5 -> Visible = false;
        Button49 -> Visible = false;
        Button50 -> Visible = false;
        Button51 -> Visible = false;
        Button52 -> Visible = false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
        //    >>>>  ARENA   <<<<
        Timer1_z_koloseum->Enabled=false;
        Timer1_od_kowala->Enabled=false;
        Timer1_z_areny->Enabled=false;
        Timer1_od_arka->Enabled=false;
        Timer1_od_handlarki->Enabled=false;
        Timer1_z_tawerny->Enabled=false;
        Timer1_z_zamku->Enabled=false;
        Timer1_z_pustyni->Enabled=false;
        tmp = 0;
        Timer1_na_arene->Enabled=true;
        Button5 -> Visible = false;
        Button6 -> Visible = false;
        Button7 -> Visible = false;
        Button8 -> Visible = false;
        Button9 -> Visible = false;
        Button10 -> Visible = false;
        Button11 -> Visible = false;
        Button12 -> Visible = false;
        Button13 -> Visible = false;
        Button14 -> Visible = false;
        Button15 -> Visible = false;
        Button16 -> Visible = false;
        Button17 -> Visible = false;
        Button18 -> Visible = false;
        Button19 -> Visible = true;
        Button24 -> Visible = false;
        Button26 -> Visible = false;
        Button27 -> Visible = false;
        Label3 -> Visible = false;
        Label4 -> Visible = false;
        Button25 -> Visible = false;
        Button28 -> Visible = false;
        Button29 -> Visible = false;
        Button30 -> Visible = false;
        Button36 -> Visible = true;
        Button37 -> Visible = true;
        Button38 -> Visible = true;
        Button39 -> Visible = true;
        Button40 -> Visible = true;
        Button44 -> Visible = false;
        Button45 -> Visible = false;
        Button46 -> Visible = false;
        Button47 -> Visible = false;
        Button49 -> Visible = false;
        Button50 -> Visible = false;
        Button51 -> Visible = false;
        Button52 -> Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
        //    >>>>  PUSTYNIA   <<<<
        Timer1_z_koloseum->Enabled=false;
        Timer1_od_kowala->Enabled=false;
        Timer1_z_areny->Enabled=false;
        Timer1_od_arka->Enabled=false;
        Timer1_od_handlarki->Enabled=false;
        Timer1_z_tawerny->Enabled=false;
        Timer1_z_zamku->Enabled=false;
        Timer1_z_pustyni->Enabled=false;
        tmp = 0;
        Timer1_na_pustynie->Enabled=true;
        Button5 -> Visible = false;
        Button6 -> Visible = false;
        Button7 -> Visible = false;
        Button8 -> Visible = false;
        Button9 -> Visible = false;
        Button10 -> Visible = false;
        Button11 -> Visible = false;
        Button12 -> Visible = false;
        Button25 -> Visible = false;
        Button28 -> Visible = false;
        Button29 -> Visible = false;
        Button30 -> Visible = false;
        Button19 -> Visible = true;
        Button24 -> Visible = false;
        Button26 -> Visible = false;
        Button27 -> Visible = false;
        Label3 -> Visible = false;
        Label4 -> Visible = false;
        Button31 -> Visible = true;
        Button32 -> Visible = true;
        Button33 -> Visible = true;
        Button34 -> Visible = true;
        Button35 -> Visible = true;
        Button36 -> Visible = false;
        Button37 -> Visible = false;
        Button38 -> Visible = false;
        Button39 -> Visible = false;
        Button40 -> Visible = false;
        Button44 -> Visible = false;
        Button45 -> Visible = false;
        Button46 -> Visible = false;
        Button47 -> Visible = false;
        Button49 -> Visible = false;
        Button50 -> Visible = false;
        Button51 -> Visible = false;
        Button52 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
        //    >>>>  TAWERNA   <<<<
        Timer1_z_koloseum->Enabled=false;
        Timer1_od_kowala->Enabled=false;
        Timer1_z_areny->Enabled=false;
        Timer1_od_arka->Enabled=false;
        Timer1_od_handlarki->Enabled=false;
        Timer1_z_tawerny->Enabled=false;
        Timer1_z_zamku->Enabled=false;
        Timer1_z_pustyni->Enabled=false;
        tmp = 0;
        Timer1_do_tawerny->Enabled=true;
        Button5 -> Visible = false;
        Button6 -> Visible = false;
        Button7 -> Visible = false;
        Button8 -> Visible = false;
        Button9 -> Visible = false;
        Button10 -> Visible = false;
        Button11 -> Visible = false;
        Button12 -> Visible = false;
        Button24 -> Visible = false;
        Button44 -> Visible = true;
        Button45 -> Visible = true;
        Button46 -> Visible = true;
        Button47 -> Visible = true;
        Button19 -> Visible = true;
        Button49 -> Visible = false;
        Button50 -> Visible = false;
        Button51 -> Visible = false;
        Button52 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
        //    >>>>  ZAMEK   <<<<
        Timer1_z_koloseum->Enabled=false;
        Timer1_od_kowala->Enabled=false;
        Timer1_z_areny->Enabled=false;
        Timer1_od_arka->Enabled=false;
        Timer1_od_handlarki->Enabled=false;
        Timer1_z_tawerny->Enabled=false;
        Timer1_z_zamku->Enabled=false;
        Timer1_z_pustyni->Enabled=false;
        tmp = 0;
        Timer1_do_zamku->Enabled=true;
        Button5 -> Visible = false;
        Button6 -> Visible = false;
        Button7 -> Visible = false;
        Button8 -> Visible = false;
        Button9 -> Visible = false;
        Button10 -> Visible = false;
        Button11 -> Visible = false;
        Button12 -> Visible = false;
        Button12 -> Visible = false;
        Button13 -> Visible = false;
        Button14 -> Visible = false;
        Button15 -> Visible = false;
        Button16 -> Visible = false;
        Button17 -> Visible = false;
        Button18 -> Visible = false;
        Button25 -> Visible = true;
        Button28 -> Visible = true;
        Button29 -> Visible = true;
        Button30 -> Visible = true;
        Button19 -> Visible = true;
        Button24 -> Visible = false;
        Button26 -> Visible = false;
        Button27 -> Visible = false;
        Label3 -> Visible = false;
        Label4 -> Visible = false;
        Button31 -> Visible = false;
        Button32 -> Visible = false;
        Button33 -> Visible = false;
        Button34 -> Visible = false;
        Button35 -> Visible = false;
        Button36 -> Visible = false;
        Button37 -> Visible = false;
        Button38 -> Visible = false;
        Button39 -> Visible = false;
        Button40 -> Visible = false;
        Button44 -> Visible = false;
        Button45 -> Visible = false;
        Button46 -> Visible = false;
        Button47 -> Visible = false;
        Button49 -> Visible = false;
        Button50 -> Visible = false;
        Button51 -> Visible = false;
        Button52 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
        //    >>>>  KOWAL   <<<<
        Timer1_z_koloseum->Enabled=false;
        Timer1_od_kowala->Enabled=false;
        Timer1_z_areny->Enabled=false;
        Timer1_od_arka->Enabled=false;
        Timer1_od_handlarki->Enabled=false;
        Timer1_z_tawerny->Enabled=false;
        Timer1_z_zamku->Enabled=false;
        Timer1_z_pustyni->Enabled=false;
        tmp = 0;
        Timer1_do_kowala->Enabled=true;
        Button5 -> Visible = false;
        Button6 -> Visible = false;
        Button7 -> Visible = false;
        Button8 -> Visible = false;
        Button9 -> Visible = false;
        Button10 -> Visible = false;
        Button11 -> Visible = false;
        Button12 -> Visible = false;
        Button24 -> Visible = false;
        Button49 -> Visible = true;
        Button50 -> Visible = true;
        Button51 -> Visible = true;
        Button52 -> Visible = true;
        Button19 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
        //    >>>>  HANDLARKA   <<<<
        Timer1_z_koloseum->Enabled=false;
        Timer1_od_kowala->Enabled=false;
        Timer1_z_areny->Enabled=false;
        Timer1_od_arka->Enabled=false;
        Timer1_od_handlarki->Enabled=false;
        Timer1_z_tawerny->Enabled=false;
        Timer1_z_zamku->Enabled=false;
        Timer1_z_pustyni->Enabled=false;
        tmp = 0;
        Timer1_do_handlarki->Enabled=true;
        Button5 -> Visible = false;
        Button6 -> Visible = false;
        Button7 -> Visible = false;
        Button8 -> Visible = false;
        Button9 -> Visible = false;
        Button10 -> Visible = false;
        Button11 -> Visible = false;
        Button12 -> Visible = false;
        Button12 -> Visible = false;
        Button13 -> Visible = false;
        Button14 -> Visible = false;
        Button15 -> Visible = false;
        Button16 -> Visible = false;
        Button17 -> Visible = false;
        Button18 -> Visible = false;
        Button25 -> Visible = false;
        Button28 -> Visible = false;
        Button29 -> Visible = false;
        Button30 -> Visible = false;
        Button19 -> Visible = true;
        Button24 -> Visible = false;
        Button26 -> Visible = false;
        Button27 -> Visible = false;
        Label3 -> Visible = false;
        Label4 -> Visible = false;
        Button31 -> Visible = false;
        Button32 -> Visible = false;
        Button33 -> Visible = false;
        Button34 -> Visible = false;
        Button35 -> Visible = false;
        Button36 -> Visible = false;
        Button37 -> Visible = false;
        Button38 -> Visible = false;
        Button39 -> Visible = false;
        Button40 -> Visible = false;
        Button41 -> Visible = true;
        Button42 -> Visible = true;
        Button43 -> Visible = true;
        Button44 -> Visible = false;
        Button45 -> Visible = false;
        Button46 -> Visible = false;
        Button47 -> Visible = false;
        Button49 -> Visible = false;
        Button50 -> Visible = false;
        Button51 -> Visible = false;
        Button52 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
        //    >>>>  AREK   <<<<
        Timer1_z_koloseum->Enabled=false;
        Timer1_od_kowala->Enabled=false;
        Timer1_z_areny->Enabled=false;
        Timer1_od_arka->Enabled=false;
        Timer1_od_handlarki->Enabled=false;
        Timer1_z_tawerny->Enabled=false;
        Timer1_z_zamku->Enabled=false;
        Timer1_z_pustyni->Enabled=false;
        tmp = 0;
        Timer1_do_arka->Enabled=true;
        Button5 -> Visible = false;
        Button6 -> Visible = false;
        Button7 -> Visible = false;
        Button8 -> Visible = false;
        Button9 -> Visible = false;
        Button10 -> Visible = false;
        Button11 -> Visible = false;
        Button12 -> Visible = false;
        Button24 -> Visible = false;
        Button49 -> Visible = false;
        Button50 -> Visible = false;
        Button51 -> Visible = false;
        Button52 -> Visible = false;
        Button53 -> Visible = true;
        Button54 -> Visible = true;
        Button55 -> Visible = true;
        Button19 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
        //mob.wilk5(wilk, 100)
        coatak = 1;
        pos.atakuj(wilk, Label4);
        //pos -> atakuj(wilk);
        Button13 -> Visible = false;
        Button14 -> Visible = false;
        Button15 -> Visible = false;
        Button16 -> Visible = false;
        Button17 -> Visible = false;
        Button18 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
        coatak = 2;
        pos.atakuj(niedzwiedz, Label4);
        Button13 -> Visible = false;
        Button14 -> Visible = false;
        Button15 -> Visible = false;
        Button16 -> Visible = false;
        Button17 -> Visible = false;
        Button18 -> Visible = false;
        Button19 -> Visible = false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
        coatak = 3;
        pos.atakuj(goblin, Label4);
        Button13 -> Visible = false;
        Button14 -> Visible = false;
        Button15 -> Visible = false;
        Button16 -> Visible = false;
        Button17 -> Visible = false;
        Button18 -> Visible = false;
        Button19 -> Visible = false;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
        coatak = 4;
        pos.atakuj(ork, Label4);
        Button13 -> Visible = false;
        Button14 -> Visible = false;
        Button15 -> Visible = false;
        Button16 -> Visible = false;
        Button17 -> Visible = false;
        Button18 -> Visible = false;
        Button19 -> Visible = false;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
        coatak = 5;
        pos.atakuj(gryf, Label4);
        Button13 -> Visible = false;
        Button14 -> Visible = false;
        Button15 -> Visible = false;
        Button16 -> Visible = false;
        Button17 -> Visible = false;
        Button18 -> Visible = false;
        Button19 -> Visible = false;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
        coatak = 6;
        pos.atakuj(hydra, Label4);
        Button13 -> Visible = false;
        Button14 -> Visible = false;
        Button15 -> Visible = false;
        Button16 -> Visible = false;
        Button17 -> Visible = false;
        Button18 -> Visible = false;
        Button19 -> Visible = false;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
        Button20Click(Button19);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
        Label2 -> Visible = false;
        Button21 -> Visible = false;
        Button22 -> Visible = false;
        Button23 -> Visible = false;
        woj.wczytaj_skin(w);
        tlo -> Visible = true;
        //plansz.Stworz();
        Button24 -> Visible = true;
        Button5 -> Visible = true;
        Button6 -> Visible = true;
        Button7 -> Visible = true;
        Button8 -> Visible = true;
        Button9 -> Visible = true;
        Button10 -> Visible = true;
        Button11 -> Visible = true;
        Button12 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
        Label2 -> Visible = false;
        Button21 -> Visible = false;
        Button22 -> Visible = false;
        Button23 -> Visible = false;
        tlo -> Visible = true;
        //plansz.Stworz();
        leo.wczytaj_skin(l);
        Button24 -> Visible = true;
        Button5 -> Visible = true;
        Button6 -> Visible = true;
        Button7 -> Visible = true;
        Button8 -> Visible = true;
        Button9 -> Visible = true;
        Button10 -> Visible = true;
        Button11 -> Visible = true;
        Button12 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
        Label2 -> Visible = false;
        Button21 -> Visible = false;
        Button22 -> Visible = false;
        Button23 -> Visible = false;
        tlo -> Visible = true;
        //plansz.Stworz();
        spi.wczytaj_skin(s);
        Button24 -> Visible = true;
        Button5 -> Visible = true;
        Button6 -> Visible = true;
        Button7 -> Visible = true;
        Button8 -> Visible = true;
        Button9 -> Visible = true;
        Button10 -> Visible = true;
        Button11 -> Visible = true;
        Button12 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button24Click(TObject *Sender)
{
        //    >>>>  STATUS   <<<<
        tmp=0;
        Timer1_z_koloseum->Enabled=false;
        Timer1_od_kowala->Enabled=false;
        Timer1_z_areny->Enabled=false;
        Timer1_od_arka->Enabled=false;
        Timer1_od_handlarki->Enabled=false;
        Timer1_z_tawerny->Enabled=false;
        Timer1_z_zamku->Enabled=false;
        Timer1_z_pustyni->Enabled=false;
        tmp = 0;
        Timer1_na_pustynie->Enabled=false;
        Timer1_do_kowala->Enabled=false;
        Timer1_na_arene->Enabled=false;
        Timer1_do_arka->Enabled=false;
        Timer1_do_handlarki->Enabled=false;
        Timer1_do_tawerny->Enabled=false;
        Timer1_do_zamku->Enabled=false;
        Timer_do_koloseum->Enabled=false;
        tmp = 0;
        TImage *abc;
        abc = porownanie(w, l, s);
        abc -> Left = 576;
        abc -> Top = 424;
        Button5 -> Visible = false;
        Button6 -> Visible = false;
        Button7 -> Visible = false;
        Button8 -> Visible = false;
        Button9 -> Visible = false;
        Button10 -> Visible = false;
        Button11 -> Visible = false;
        Button12 -> Visible = false;
        Button24 -> Visible = false;
        pos.status(Label1, w, s, l);
        Button19 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button26Click(TObject *Sender)
{
        //    >>>>  WYJSCIE   <<<<
        tmp = 0;
        Button20Click(Button26);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
        //    >>>>  WYJSCIE   <<<<
        TImage *abc;
        abc = porownanie(w, l, s);
        Button5 -> Visible = true;
        Button6 -> Visible = true;
        Button7 -> Visible = true;
        Button8 -> Visible = true;
        Button9 -> Visible = true;
        Button10 -> Visible = true;
        Button11 -> Visible = true;
        Button12 -> Visible = true;
        Button13 -> Visible = false;
        Button14 -> Visible = false;
        Button15 -> Visible = false;
        Button16 -> Visible = false;
        Button17 -> Visible = false;
        Button18 -> Visible = false;
        Button19 -> Visible = false;
        Button24 -> Visible = true;
        Button26 -> Visible = false;
        Button27 -> Visible = false;
        Label3 -> Visible = false;
        Label4 -> Visible = false;
        Button25 -> Visible = false;
        Button28 -> Visible = false;
        Button29 -> Visible = false;
        Button30 -> Visible = false;
        Button31 -> Visible = false;
        Button32 -> Visible = false;
        Button33 -> Visible = false;
        Button34 -> Visible = false;
        Button35 -> Visible = false;
        Button36 -> Visible = false;
        Button37 -> Visible = false;
        Button38 -> Visible = false;
        Button39 -> Visible = false;
        Button40 -> Visible = false;
        Button41 -> Visible = false;
        Button42 -> Visible = false;
        Button43 -> Visible = false;
        Label5 -> Visible = false;
        Button44 -> Visible = false;
        Button45 -> Visible = false;
        Button46 -> Visible = false;
        Button47 -> Visible = false;
        Button48 -> Visible = false;
        Button49 -> Visible = false;
        Button50 -> Visible = false;
        Button51 -> Visible = false;
        Button52 -> Visible = false;
        Button53 -> Visible = false;
        Button54 -> Visible = false;
        Button55 -> Visible = false;
        tmp = 0;
        Timer1_na_pustynie->Enabled=false;
        Timer1_do_kowala->Enabled=false;
        Timer1_na_arene->Enabled=false;
        Timer1_do_arka->Enabled=false;
        Timer1_do_handlarki->Enabled=false;
        Timer1_do_tawerny->Enabled=false;
        Timer1_do_zamku->Enabled=false;
        Timer_do_koloseum->Enabled=false;
        tmp = 0;
        if(abc->Left == 888 && abc->Top == 472)Timer1_z_pustyni->Enabled=true;
        if(abc->Left == 576 && abc->Top == 264)Timer1_z_koloseum->Enabled=true;
        if(abc->Left == 416 && abc->Top == 224)Timer1_od_kowala->Enabled=true;
        if(abc->Left == 376 && abc->Top == 364)Timer1_z_areny->Enabled=true;
        if(abc->Left == 96 && abc->Top == 244)Timer1_od_arka->Enabled=true;
        if(abc->Left == 186 && abc->Top == 454)Timer1_od_handlarki->Enabled=true;
        if(abc->Left == 316 && abc->Top == 604)Timer1_z_tawerny->Enabled=true;
        if(abc->Left == 816 && abc->Top == 280)Timer1_z_zamku->Enabled=true;
}
//---------------------------------------------------------------------------
        //    >>>>  PONOWNA WALKA   <<<<
void __fastcall TForm1::Button27Click(TObject *Sender)
{
if(coatak == 1)
        {
        pos.atakuj(wilk, Label4);
        }
        else if (coatak == 2)
                {
                pos.atakuj(niedzwiedz, Label4);
                }
                else if (coatak == 3)
                        {
                        pos.atakuj(goblin, Label4);
                        }
                        else if (coatak == 4)
                                {
                                pos.atakuj(ork, Label4);
                                }
                                else if (coatak == 5)
                                        {
                                        pos.atakuj(gryf, Label4);
                                        }
                                        else if (coatak == 6)
                                                {
                                                pos.atakuj(hydra, Label4);
                                                }
if(coatak == 7)
        {
        pos.atakuj(krzyzowiec, Label4);
        }
        else if (coatak == 8)
                {
                pos.atakuj(paladyn, Label4);
                }
                else if (coatak == 9)
                        {
                        pos.atakuj(arcymag, Label4);
                        }
                        else if (coatak == 10)
                                {
                                pos.atakuj(archaniol, Label4);
                                }
if(coatak == 11)
        {
        pos.atakuj(herszt, Label4);
        }
        else if (coatak == 12)
                {
                pos.atakuj(zawadiaka, Label4);
                }
                else if (coatak == 13)
                        {
                        pos.atakuj(zywiolak, Label4);
                        }
                        else if (coatak == 14)
                                {
                                pos.atakuj(ent, Label4);
                                }
                                else if (coatak == 15)
                                        {
                                        pos.atakuj(tysieczny, Label4);
                                        }
if (coatak == 16)
        {
        pos.atakuj(behemot, Label4);
        }
        else if(coatak == 17)
                {
                pos.atakuj(dementor, Label4);
                }
                else if (coatak == 18)
                         {
                         pos.atakuj(czart, Label4);
                         }
                         else if (coatak == 19)
                                  {
                                  pos.atakuj(smok, Label4);
                                  }
                                  else if (coatak == 20)
                                           {
                                           pos.atakuj(krol, Label4);
                                           }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button25Click(TObject *Sender)
{
        coatak = 7;
        pos.atakuj(krzyzowiec, Label4);
        Button25 -> Visible = false;
        Button28 -> Visible = false;
        Button29 -> Visible = false;
        Button30 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button28Click(TObject *Sender)
{
        coatak = 8;
        pos.atakuj(paladyn, Label4);
        Button25 -> Visible = false;
        Button28 -> Visible = false;
        Button29 -> Visible = false;
        Button30 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button29Click(TObject *Sender)
{
        coatak = 9;
        pos.atakuj(arcymag, Label4);
        Button25 -> Visible = false;
        Button28 -> Visible = false;
        Button29 -> Visible = false;
        Button30 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button30Click(TObject *Sender)
{
        coatak = 10;
        pos.atakuj(archaniol, Label4);
        Button25 -> Visible = false;
        Button28 -> Visible = false;
        Button29 -> Visible = false;
        Button30 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button31Click(TObject *Sender)
{
        coatak = 11;
        pos.atakuj(herszt, Label4);
        Button31 -> Visible = false;
        Button32 -> Visible = false;
        Button33 -> Visible = false;
        Button34 -> Visible = false;
        Button35 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button32Click(TObject *Sender)
{
        coatak = 12;
        pos.atakuj(zawadiaka, Label4);
        Button31 -> Visible = false;
        Button32 -> Visible = false;
        Button33 -> Visible = false;
        Button34 -> Visible = false;
        Button35 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button33Click(TObject *Sender)
{
        coatak = 13;
        pos.atakuj(zywiolak, Label4);
        Button31 -> Visible = false;
        Button32 -> Visible = false;
        Button33 -> Visible = false;
        Button34 -> Visible = false;
        Button35 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button34Click(TObject *Sender)
{
        coatak = 14;
        pos.atakuj(ent, Label4);
        Button31 -> Visible = false;
        Button32 -> Visible = false;
        Button33 -> Visible = false;
        Button34 -> Visible = false;
        Button35 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button35Click(TObject *Sender)
{
        coatak = 15;
        pos.atakuj(tysieczny, Label4);
        Button31 -> Visible = false;
        Button32 -> Visible = false;
        Button33 -> Visible = false;
        Button34 -> Visible = false;
        Button35 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button36Click(TObject *Sender)
{
        coatak = 16;
        pos.atakuj(behemot, Label4);
        Button36 -> Visible = false;
        Button37 -> Visible = false;
        Button38 -> Visible = false;
        Button39 -> Visible = false;
        Button40 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button37Click(TObject *Sender)
{
        coatak = 17;
        pos.atakuj(dementor, Label4);
        Button36 -> Visible = false;
        Button37 -> Visible = false;
        Button38 -> Visible = false;
        Button39 -> Visible = false;
        Button40 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button38Click(TObject *Sender)
{
        coatak = 18;
        pos.atakuj(czart, Label4);
        Button36 -> Visible = false;
        Button37 -> Visible = false;
        Button38 -> Visible = false;
        Button39 -> Visible = false;
        Button40 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button39Click(TObject *Sender)
{
        coatak = 19;
        pos.atakuj(smok, Label4);
        Button36 -> Visible = false;
        Button37 -> Visible = false;
        Button38 -> Visible = false;
        Button39 -> Visible = false;
        Button40 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button40Click(TObject *Sender)
{
        coatak = 20;
        pos.atakuj(krol, Label4);
        Button36 -> Visible = false;
        Button37 -> Visible = false;
        Button38 -> Visible = false;
        Button39 -> Visible = false;
        Button40 -> Visible = false;
        Button19 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button41Click(TObject *Sender)
{
        hand.lecz(25, &pos, Label5);
        Button41 -> Visible = false;
        Button42 -> Visible = false;
        Button43 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button42Click(TObject *Sender)
{
        hand.lecz(50, &pos, Label5);
        Button41 -> Visible = false;
        Button42 -> Visible = false;
        Button43 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button43Click(TObject *Sender)
{
        hand.lecz(100, &pos, Label5);
        Button41 -> Visible = false;
        Button42 -> Visible = false;
        Button43 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button44Click(TObject *Sender)
{
        krupier.graj_karty(100, 7, &pos, Label5);
        Button48 -> Visible = true;
        Button19 -> Visible = true;
        Button44 -> Visible = false;
        Button45 -> Visible = false;
        Button46 -> Visible = false;
        Button47 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button45Click(TObject *Sender)
{
        krupier.graj_karty(1000, 6, &pos, Label5);
        Button48 -> Visible = true;
        Button19 -> Visible = true;
        Button44 -> Visible = false;
        Button45 -> Visible = false;
        Button46 -> Visible = false;
        Button47 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button46Click(TObject *Sender)
{
        krupier.graj_karty(10000, 4, &pos, Label5);
        Button48 -> Visible = true;
        Button19 -> Visible = true;
        Button44 -> Visible = false;
        Button45 -> Visible = false;
        Button46 -> Visible = false;
        Button47 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button47Click(TObject *Sender)
{
        krupier.graj_karty(100000, 1, &pos, Label5);
        Button48 -> Visible = true;
        Button19 -> Visible = true;
        Button44 -> Visible = false;
        Button45 -> Visible = false;
        Button46 -> Visible = false;
        Button47 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button48Click(TObject *Sender)
{
        Label5 -> Visible = false;
        Button48 -> Visible = false;
        Button44 -> Visible = true;
        Button45 -> Visible = true;
        Button46 -> Visible = true;
        Button47 -> Visible = true;
        Button19 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button49Click(TObject *Sender)
{
        kow.ulepsz(1, &pos, Label5);
        Button49 -> Visible = false;
        Button50 -> Visible = false;
        Button51 -> Visible = false;
        Button52 -> Visible = false;
        Button19 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button50Click(TObject *Sender)
{
        Button49 -> Visible = false;
        Button50 -> Visible = false;
        Button51 -> Visible = false;
        Button52 -> Visible = false;
        Button19 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button51Click(TObject *Sender)
{
        Button49 -> Visible = false;
        Button50 -> Visible = false;
        Button51 -> Visible = false;
        Button52 -> Visible = false;
        Button19 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button52Click(TObject *Sender)
{
        Button49 -> Visible = false;
        Button50 -> Visible = false;
        Button51 -> Visible = false;
        Button52 -> Visible = false;
        Button19 -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button53Click(TObject *Sender)
{
        arek.baluj(1, &pos, Label5);
        Button53 -> Visible = false;
        Button54 -> Visible = false;
        Button55 -> Visible = false;
        Sleep(10000);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button54Click(TObject *Sender)
{
        arek.baluj(2, &pos, Label5);
        Button53 -> Visible = false;
        Button54 -> Visible = false;
        Button55 -> Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button55Click(TObject *Sender)
{
        arek.baluj(3, &pos, Label5);
        Button53 -> Visible = false;
        Button54 -> Visible = false;
        Button55 -> Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer_do_koloseumTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = 0;
        y = -4;
        if (tmp < 40)
        {
         abc -> Left += x;
         abc -> Top += y;
         tmp++;
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_z_koloseumTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = 0;
        y = -4;
        if (tmp < 40)
        {
         abc -> Left -= x;
         abc -> Top -= y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_do_kowalaTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = -4;
        y = -5;
        if (tmp < 40)
        {
         abc -> Left += x;
         abc -> Top += y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_od_kowalaTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = -4;
        y = -5;
        if (tmp < 40)
        {
         abc -> Left -= x;
         abc -> Top -= y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_na_areneTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = -10;
        y = -3;
        if (tmp < 20)
        {
         abc -> Left += x;
         abc -> Top += y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_z_arenyTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = -10;
        y = -3;
        if (tmp < 20)
        {
         abc -> Left -= x;
         abc -> Top -= y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_do_arkaTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = -8;
        y = -3;
        if (tmp < 60)
        {
         abc -> Left += x;
         abc -> Top += y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_od_arkaTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = -8;
        y = -3;
        if (tmp < 60)
        {
         abc -> Left -= x;
         abc -> Top -= y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_do_handlarkiTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = -13;
        y = 1;
        if (tmp < 30)
        {
         abc -> Left += x;
         abc -> Top += y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_od_handlarkiTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = -13;
        y = 1;
        if (tmp < 30)
        {
         abc -> Left -= x;
         abc -> Top -= y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_do_tawernyTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = -13;
        y = 9;
        if (tmp < 20)
        {
         abc -> Left += x;
         abc -> Top += y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_z_tawernyTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = -13;
        y = 9;
        if (tmp < 20)
        {
         abc -> Left -= x;
         abc -> Top -= y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_do_zamkuTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = 5;
        y = -3;
        if (tmp < 48)
        {
         abc -> Left += x;
         abc -> Top += y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_z_zamkuTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = 5;
        y = -3;
        if (tmp < 48)
        {
         abc -> Left -= x;
         abc -> Top -= y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_na_pustynieTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = 13;
        y = 2;
        if (tmp < 24)
        {
         abc -> Left += x;
         abc -> Top += y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1_z_pustyniTimer(TObject *Sender)
{
        TImage *abc;
        abc = porownanie(w, l, s);
        int x, y;
        x = -13;
        y = -2;
        if (tmp < 24)
        {
         abc -> Left += x;
         abc -> Top += y;
         tmp++;
        }
}
//---------------------------------------------------------------------------

