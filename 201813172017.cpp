#include<iostream>
#include<stdlib.h>
using namespace std;

//Necati �st�n 201813172017

int yiginElemanSayisi = 0;
int kuyrukElemanSayisi = 0;
int bagliElemanSayisi = 0;

class Dugum
{
public:
    int data;
    Dugum* sonraki;
}*bas,*degisken,*trav;

class yigin 
{
    Dugum* bas;
    
public:  yigin() 
    {
        bas = NULL;
    }
    void push(int);       //Y���na Eleman Ekler.
    void pop();          //Y���ndan Eleman ��kart�r.
    void goster();      // Y�g�ndaki Elemanlar� G�sterir.
    void temizle();    //Y���ndaki T�m elemanlar�n� Temizler.
};

void yigin::temizle()//Y���ndaki T�m Elemanlar� Temizler.
{
    Dugum* temp = bas;
    bas = NULL;
    
    cout << "Yigin temizlendi";
    cout << endl;
}

void yigin::push(int deger)  //Y���na Eleman Ekler.
{
    Dugum* temp;
    temp = new Dugum();
    
    temp->data = deger;
    if (bas == NULL)
    {
        temp->sonraki = NULL;
    }
    else
    {
        temp->sonraki = bas;
    }
    bas = temp;
}

void yigin::goster()//Y���ndaki Elemanlar� G�sterir. 
{
    Dugum* temp = bas;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->sonraki;
    }
    cout <<  endl;
}

void yigin::pop()//Y�g�ndan eleman ��kar�r.
{

    if (bas == NULL)
        cout << "Yigin bos...\n";

    else
    {
        Dugum* temp = bas;
        
        bas = bas->sonraki;
        delete(temp);
    }
}

class Kuyruk 
{
    Dugum* kuyrukBasi;
    Dugum* kuyrukSonu;
    Dugum* onceki;
    Dugum* temp;

    bool bosmu()
    {
        return kuyrukBasi == NULL;
    }

public: Kuyruk()
    {
        kuyrukBasi = NULL;
        kuyrukSonu = NULL;
    }

    void kuyrukEkle(int x)
    {
        temp = new Dugum;
       
        temp->data = x;
        temp->sonraki = NULL;
        
        if (bosmu())
        {
            kuyrukBasi = temp;
            kuyrukSonu = temp;
        }
        else
        {
            onceki = kuyrukSonu;
            kuyrukSonu->sonraki = temp;
            kuyrukSonu = temp;
        }
    }
    void kuyrugutemizle()
    {
        kuyrukBasi = 0;
        kuyrukSonu = 0;
        
        cout << "Kuyruk temizlendi";
        cout << endl;
    }
    void kuyruktancikar()
    {
        temp = kuyrukBasi;
        
        kuyrukBasi = kuyrukSonu->sonraki;
        delete temp;
    }
    void kuyrukgoster()
    {
        if (!bosmu())
        {
            for (temp = kuyrukBasi; temp != NULL; temp = temp->sonraki)
                cout << temp->data << " ";
            cout << endl;

        }
        else
        {
            cout << "## Kuyruk Bos ##" << endl;
        }
    }
};

int aradanElemanCikar(int deger)
{
    Dugum* temp;
    temp = bas;
    if (bas == NULL)
    {
        cout << "#Liste bo� ilk �nce eleman ekle !\n";
        return 0;
    }
    
    
    while (temp != NULL)
    {
       
	   
	    if (temp->data == deger)
        {
            if (temp == bas)
            {
                bas = temp->sonraki;
                free(temp);
                return 0;
            }
            else
            {
                degisken->sonraki = temp->sonraki;
                free(temp);
                return 0;
            }
        }
        else {
            degisken = temp;
            temp = temp->sonraki;

        }
    }
}

int sondanElemancikar()
{
    Dugum* temp;
    temp = bas;
    while (temp->sonraki != NULL)
    {
        degisken = temp;
        temp = temp->sonraki;
    }
    if (temp == bas)
    {
        bas = temp->sonraki;
        free(temp);
        return 0;
    }
    cout << "Listenin son eleman� silindi ! " << temp->data;
    degisken->sonraki = NULL;
    free(temp);
    return 0;
}

void arayaEkle(int deger, int yeri)
{
    Dugum* degisken2, * temp;
    degisken = (Dugum*)malloc(sizeof(Dugum));
    degisken->data = deger;
    temp = bas;

    if (bas == NULL)
    {
        bas = degisken;
        bas->sonraki = NULL;
    }
    else
    {
        while (temp->data != yeri && temp->sonraki != NULL)
        {
            temp = temp->sonraki;
        }
        degisken2 = temp->sonraki;
        temp->sonraki = degisken;
        degisken->sonraki = degisken2;
        
    }
}

void sonaEkle(int deger)//sona eleman ekler.
{
      Dugum *temp; 
      temp=bas;
      degisken=(Dugum *)malloc(sizeof (Dugum));
      degisken->data=deger;
     
      if(bas==NULL)
      {
          bas=degisken;
          bas->sonraki=NULL;
      }
        else
        {
            while(temp->sonraki!=NULL)
            {
                temp=temp->sonraki;
            }
        } 
}

void goster()
{
    //listenin son durumunu ekrana yazd�r�r.
    trav = bas;
    if (trav == NULL)
    {
        cout << "Liste Bo�";
    }
    else
    {
        cout << "Listenin Elemanlar�: ";
        while (trav != NULL)
        {
            cout << trav->data << "->";
            trav = trav->sonraki;
        }
        cout << "Liste Sonu";
        cout << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Turkish");
    bool cikis = false;
    int anaMenuSecim,yiginSecim,listSecim,kuyrukSecim,bagliSecim,bagliSecim2;
    
    yigin y;
    Kuyruk q;

anamenu:
    
	
	 cout << "\n************************** UYGULAMA L�STES� ************************** \n \n  "; 
        cout << "YAPMAK ISTEDIGINIZ UYGULAMAYI SE��N�Z\n";
        cout << "1 - Y���n Uygulamas�\n";
        cout << "2 - Kuyruk Uygulamasi\n";
        cout << "3 - Tek Y�nl� Ba�l� Liste Uygulamas�\n";
        cout << "4 - Programdan ��k��\n";
        cout << "��leminizi Se�iniz : ";
        cin >> anaMenuSecim;
	
	while(!cikis)
    
	{   
    
	   
        
        switch (anaMenuSecim)//Se�ilecek i�leme g�t�r�r.
        {
        case 1:
        yiginislemleri:
            cout << "\nY���n ��in ��lem Se�iniz: \n" << endl;
            cout << "1 - Y���na Eleman Ekle\n";
            cout << "2 - Y���ndan Eleman ��kar\n";
            cout << "3 - Y���n� Temizle\n";
            cout << "4 - Y���ndaki Elemanlari G�ster\n";
            cout << "5 - Y���ndaki Eleman Say�s�n� G�ster\n";
            cout << "6 - Ana Menuye Geri Don\n";
            cout << "��leminizi Se�iniz : ";
            
            cin >> (yiginSecim);
            
            switch (yiginSecim) {//Y���ndaki Se�ilen i�lemler.
            case 1:
                int eklenecek;
                cout << "\nEklenecek elemani giriniz  : ";
                cin >> eklenecek;
                y.push(eklenecek);
                yiginElemanSayisi++;
                goto yiginislemleri;
                break;
            case 2:
                cout <<"\n # Eleman ��kart�ld�" << endl;
                y.pop();
                yiginElemanSayisi--;
                goto yiginislemleri;
                break;
            case 3:
                y.temizle();
                yiginElemanSayisi = 0;
                goto yiginislemleri;
                
                break;
            case 4:
                y.goster();
                goto yiginislemleri;
                break;
            case 5:
                cout <<"# Eleman Say�s� : " << yiginElemanSayisi << endl;
                break;
            case 6:
                goto anamenu;
                break;
            default:
                cout << "\n !! Hatal� ��lem Se�imi Yapt�n�z !!\n";
                goto yiginislemleri;
            }
            break;

        case 2:
        kuyrukislemleri:
            cout << "\nKUYRUK ICIN ISLEM SECINIZ" << endl;
            cout << "1 - Kuyruga Eleman Ekle\n";
            cout << "2 - Kuyruktan Eleman Cikar\n";
            cout << "3 - Kuyrugu Temizle\n";
            cout << "4 - Kuyruktaki Elemanlari Goster\n";
            cout << "5 - Kuyruktaki Eleman Sayisini Goster\n";
            cout << "6 - Ana Menuye Geri Don\n";
            cout << "��leminizi Se�iniz : ";
            cin >> kuyrukSecim;
            
            switch (kuyrukSecim) {//Kuyruktaki Se�ilen i�lemler.
            case 1:
                int eklenecek;
                cout << "\nEklenecek elemani girin  : ";
                cin >> eklenecek;
                q.kuyrukEkle(eklenecek);
                kuyrukElemanSayisi++;
                cout << "\n## Eleman Eklendi ##";
                goto kuyrukislemleri;
                break;
                
            case 2:
                q.kuyruktancikar();
                cout << "\n## Eleman ��kart�ld� ## ";
                kuyrukElemanSayisi--;
                goto kuyrukislemleri;
                break;
            case 3:
                
                q.kuyrugutemizle();
                kuyrukElemanSayisi = 0;
                cout << "\n ## Kuyruk Temizlendi ## ";
                goto kuyrukislemleri;
                break;
            case 4:
               
                q.kuyrukgoster();
                cout << "\nKuyruktaki Elemanlar ";
                goto kuyrukislemleri;
                break;
                
            case 5:
            	cout <<"# Eleman Say�s� : " << kuyrukElemanSayisi << endl;
                break;
                
            case 6:
            	goto anamenu;
                break;
            default:
                cout << "\n !! Hatali islem secimi !! \n";
                goto kuyrukislemleri;
            }
            break;

        case 3:
        {listeislemleri:
            cout << "\nBAGLI L�STE ICIN ISLEM SECINIZ" << endl;
            cout << "1 Eleman ekle\n";
            cout << "2 Eleman ��kar\n";
            cout << "3 Temizle\n";
            cout << "4 Elemanlar� G�ster\n";
            cout << "5 Eleman say�s� goster\n";
            cout << "6 Ana menuye d�n\n";
			cout << "��leminizi Se�iniz :";
            cin >> bagliSecim;
            switch (bagliSecim)//Ba�l� liste se�imine g�re i�lemler.
            {
            eklemeislemleri:
            case 1:
                cout << "\nEkleme turunu seciniz : \n1 Araya ekle\n2 Sona ekle\n3 Liste i�lemlerine don\n\n";
                cin >> bagliSecim2;
                switch (bagliSecim2) {
                case 1:
                {int eleman, yeri;
                cout << "\nHangi Elemandan sonra Ekleme Yapmak istiyorsunuz ? :";
                cin >> yeri;
                cout << "\nEklenecek Elemani Giriniz :";
                cin >> eleman;
                arayaEkle(eleman, yeri);
                cout << "\n ## Araya Eleman Eklendi ##\n";
                bagliElemanSayisi++;
                goto eklemeislemleri;
                break;
                }
                case 2:
                {
                	int sayi;
                    cout << "\nSona Eklenecek Elaman�n�z: ";
                    cin>>sayi;
                    bagliElemanSayisi++;
                    sonaEkle(sayi);
                    cout<<endl;
                    goto eklemeislemleri;
                    break;
                }
                case 3:
                {
                    goto listeislemleri;
                    break;
                }
                }
            case  2:
            {
            cikartmaIslemleri:
                cout << "\n��karma turunu seciniz:\n1 Aradan Eleman ��kart\n2 Sondan Eleman ��kart\n3 Liste ��lemlerine Geri D�n \n\n";
                cin >> listSecim;
                
                switch (listSecim) {
                	
                case 1:
                {
				int eleman;
                cout << "\nSilmek istediginiz elemani belirtiniz : ";
                cin >> eleman;
                aradanElemanCikar(eleman);
                bagliElemanSayisi--;
                goto cikartmaIslemleri;
                break;
                }
                
                case 2:
                {
                    sondanElemancikar();
                    cout << "\n ## Eleman ��kart�ld�  ##";
                    bagliElemanSayisi--;
                    goto cikartmaIslemleri;
                    break;
                }
                
                case 3:
                {
                    goto listeislemleri;
                    
                    break;

                }
                
                default: {
                    cout << "\n!! Hatal� Say� Girdiniz !! ";

                }
                }
            }
            case 3:
            {   bagliElemanSayisi = 0;
                break;
            }

            case 4:
            {
                goster();
                cout << "\n******* Listedeki Elemanlar *******\n";
                goto listeislemleri;
                break;
             case 5:
             	cout <<"# Eleman Say�s� : " << bagliElemanSayisi << endl;
                
             case 6:
			       goto anamenu;
                break;	
             	
            } default:
                cout << "\n !! Hatali islem secimi yapt�n�z !!";
                goto anamenu;
            }
           
          
            
         }
        case 4:
        {   
           cout<<"\n ��k�� Yap�l�yor.....";
           cikis = true;
            break;
        }
        }
    }
       
        return 0;
}
   


