#include <iostream>
#include <list>
#include <conio.h>
using namespace std;

class Ogrenci {
private:
	int okulno;
	string ad;
	int SinavNot;
public:
	Ogrenci(int  _okulno, string _ad, int _SinavNot);
	void setokulno(int _okulno);
	void setAd(string _ad);
	void setSinavNot(int _SinavNot);
	int getokulno();
	string getAd();
	int getSinavNot();
	void bilgileriniYaz();


};

Ogrenci::Ogrenci(int  _okulno, string _ad, int _SinavNot) {
	okulno = _okulno;
	ad = _ad;
	SinavNot = _SinavNot;
}
void Ogrenci::setokulno(int _okulno) {
	okulno = _okulno;
}
void Ogrenci::setAd(string _ad) {
	ad = _ad;
}
void Ogrenci::setSinavNot(int _SinavNot) {
	SinavNot = _SinavNot;
}
int Ogrenci::getokulno() {
	return okulno;
}
string Ogrenci::getAd() {
	return ad;
}

int Ogrenci::getSinavNot() {
	return SinavNot;
}
void Ogrenci::bilgileriniYaz() {
	cout << "Okul Numarasi: " << okulno << "   ----  Isim ve Soyisim: " << ad << "   ----   Sinav Not: " << SinavNot << endl;
}

void menuyugoster() {
	cout << "* * * * * * * * * *" << endl;
	cout << "*                 *" << endl;
	cout << "*       MENU      *" << endl;
	cout << "*                 *" << endl;
	cout << "* * * * * * * * * *" << endl;
	cout << "1. Yeni kayit ekle" << endl;
	cout << "2. Tum Listeyi goster" << endl;
	cout << "3. Ogrenci numarasina gore kayit sil" << endl;
	cout << "4. Ogrenci ara" << endl;
	cout << "5. Cikis" << endl;

}
void ogrenciekle(list<Ogrenci>* lst) {
	int okulno, SinavNot;
	string ad, soyad, isim;
	cout << "Lutfen ogrenci numarasini giriniz: ";
	cin >> okulno;
	cout << "Lutfen ogrenci adini ve soyadini giriniz: ";
	cin >> ad >> soyad;
	isim = ad + " " + soyad;
	cout << "Lutfen ogrenci notunu giriniz: ";
	cin >> SinavNot;
	Ogrenci ogr(okulno, isim, SinavNot);
	lst->push_back(ogr);
}
void showlist(list<Ogrenci>* lst) {
	list<Ogrenci>::iterator it;
	cout << endl << "------TUM OGRENCI LISTESI------\n";
	for (it = lst->begin(); it != lst->end(); it++) {
		it->bilgileriniYaz();
	}
	cout << endl;
}
void ogrencisil(list<Ogrenci>* lst) {
	int okulno;
	cout << "Lutfen silinecek ogrencinin numarasini giriniz: ";
	cin >> okulno;
	list<Ogrenci>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++) {
		if (it->getokulno() == okulno)
			break;
	}
	if (it == lst->end())
		cout << "Belirtilen okul numarasina ait kayit bulunamamistir,silme yapilamadi! " << endl;
	else
		lst->erase(it);

}
void ogrenciara(list<Ogrenci>* lst) {
	int okulno;
	cout << "Lutfen aranacak ogrencinin numarasini giriniz: ";
	cin >> okulno;
	list<Ogrenci>::iterator it;
	for (it = lst->begin(); it != lst->end(); it++) {
		if (it->getokulno() == okulno)
			break;
	}
	if (it == lst->end())
		cout << "Belirtilen id bulunamamistir. " << endl;
	else {
		cout << endl << " Aradaginiz ogrencinin bilgileri:\n  ";
		it->bilgileriniYaz();
		cout << endl;
	}

}

int main() {
	
	list<Ogrenci>* ogrencilist = new list<Ogrenci>();
	int secim = 0;
	do {
		menuyugoster();
		cout << "Seciminiz: ";
		cin >> secim;
		if (secim == 1)
			ogrenciekle(ogrencilist);
		else if (secim == 2)
			showlist(ogrencilist);
		else if (secim == 3)
			ogrencisil(ogrencilist);
		else if (secim == 4)
			ogrenciara(ogrencilist);
		else if (secim == 5)
			break;
		else
			cout << "Hatali secim yaptiniz, yeniden deneyin! ";

	} while (secim != 5);





	return 0;
}