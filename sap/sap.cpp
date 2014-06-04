#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include "sap.hh"

using namespace std;


void saper::instr()
    {
cout<<"- Pole wybiera się poprzez podanie odpowiedniej kolumny i wiersza np A6."<<endl;
cout<<endl;
cout<<"- Odkrycie miny kończy grę."<<endl;
cout<<endl;
cout<<"- Odkrycie pustego pola oznacza kontynuowanie rozgrywki."<<endl;
cout<<endl;
cout<<"- Odkrycie liczby informuje, ile min ukryto wśród ośmiu sąsiadujących z nią pól."<<endl<<"Na tej podstawie trzeba wydedukować, które pola dookoła można bezpiecznie wybrać."<<endl;
cout<<endl;
cout<<"- Jeśli podejrzewasz, że dane pole zawiera minę, oznacz je literą F np FA6."<<endl<<"Spowoduje to oznaczenie danego pola flagą."<<endl;
cout<<endl;
}




    void saper::graj()
    {
        int wait=0;
        int theone;
        int extra1=0;
        int extra2=0;
        char char1;
        char char2;
        char char3;
        char flag='n';
        int num=1;
        int x;
        int y;
        int count;
        int k=0;

        cout<<"Ile chcesz min ?"<<endl;
        cin>>count;
       
        srand (time(NULL));
       
        vector<char>cover; //brak miny wypełniamy plusami
        vector<int>nums;   //liczby okreslajace sasiedztwo min
        vector<int>waiter;
        vector<int>mines;   //miny wartość 0 lub 1
        vector<char>chars;  //gdy mines ma wart. 1, podstawiamy M
       
        for(int i=0;i<261;i++)
        {
            waiter.push_back(0);
            nums.push_back(0);
            mines.push_back(0);
            chars.push_back('0');
            cover.push_back('+');
        }
       
       
       
       
        cout<<endl;
       
       /* Losujemy indeksy, w wektorze min zamieniamy 0 na 1, gdy ustawiamy tam mine, gdy indeks sie powtorzy, losujemy
        jeszcze raz */
        for(int i=0;i<count;i++)
        {
            x=rand();
            y=x%260+1;
           
            if(mines[y]==0)
            {
                    mines[y]=1;
            }
            else
            {
                i--;
            }
        }    
       
       
       
       //Wstawiamy w wektor znaków litere M, gdy jest mina
        for(int i=0;i<261;i++)
        {
            if(mines[i]!=0)
                chars[i]='M';
        }
       
       
        x=0;
       //Wypełniamy wektor nums liczbami określającymi sąsiedztwo min
        if(chars[1]!='M')   //górny lewy corner
        {
            if(chars[2]=='M')
            {
                nums[1]++;
            }
            if(chars[27]=='M')
            {
                nums[1]++;
            }
            if(chars[28]=='M')
            {
                nums[1]++;
            }
        }
       
        if(chars[26]!='M')  //górny prawy corner
        {
            if(chars[25]=='M')
            {
                nums[26]++;
            }
            if(chars[51]=='M')
            {
                nums[26]++;
            }
            if(chars[52]=='M')
            {
                nums[26]++;
            }
        }
       
        if(chars[235]!='M') //dolny lewy corner
        {
            if(chars[209]=='M')
            {
                nums[235]++;
            }
            if(chars[210]=='M')
            {
                nums[235]++;
            }
            if(chars[236]=='M')
            {
                nums[235]++;
            }
        }
       
        if(chars[260]!='M') //dolny prawy corner
        {
            if(chars[233]=='M')
            {
                nums[260]++;
            }
            if(chars[234]=='M')
            {
                nums[260]++;
            }
            if(chars[259]=='M')
            {
                nums[260]++;
            }
        }
       
        for(int i=2;i<26;i++)   //górny wiersz
        {
            if(chars[i]!='M')
            {
                if(chars[i-1]=='M')
                    nums[i]++;
                if(chars[i+1]=='M')
                    nums[i]++;
                if(chars[i+25]=='M')
                    nums[i]++;
                if(chars[i+26]=='M')
                    nums[i]++;
                if(chars[i+27]=='M')
                    nums[i]++;
            }
        }
       
        for(int i=236;i<260;i++)   //dolny wiersz
        {
            if(chars[i]!='M')
            {
                if(chars[i-1]=='M')
                    nums[i]++;
                if(chars[i+1]=='M')
                    nums[i]++;
                if(chars[i-25]=='M')
                    nums[i]++;
                if(chars[i-26]=='M')
                    nums[i]++;
                if(chars[i-27]=='M')
                    nums[i]++;
            }
        }
       
        for(int i=26;i<210;i++)   //lewa kolumna
        {
            if(i%26==1&&chars[i]!='M')
            {
                if(chars[i-26]=='M')
                    nums[i]++;
                if(chars[i-25]=='M')
                    nums[i]++;
                if(chars[i+1]=='M')
                    nums[i]++;
                if(chars[i+26]=='M')
                    nums[i]++;
                if(chars[i+27]=='M')
                    nums[i]++;
            }
        }
       
        for(int i=50;i<235;i++)   //prawa kolumna
        {
            if(i%26==0&&chars[i]!='M')
            {
                if(chars[i-27]=='M')
                    nums[i]++;
                if(chars[i-26]=='M')
                    nums[i]++;
                if(chars[i-1]=='M')
                    nums[i]++;
                if(chars[i+25]=='M')
                    nums[i]++;
                if(chars[i+26]=='M')
                    nums[i]++;
            }
        }
       
        for(int i=28;i<234;i++)   //pozostale pola
        {
            if(i%26!=0&&i%26!=1&&chars[i]!='M')
            {
                if(chars[i-27]=='M')
                    nums[i]++;
                if(chars[i-26]=='M')
                    nums[i]++;
                if(chars[i-25]=='M')
                    nums[i]++;
                if(chars[i-1]=='M')
                    nums[i]++;
                if(chars[i+1]=='M')
                    nums[i]++;
                if(chars[i+25]=='M')
                    nums[i]++;
                if(chars[i+26]=='M')
                    nums[i]++;
                if(chars[i+27]=='M')
                    nums[i]++;
            }
        }
       //kopiujemy wartości z wektora nums do wektora chars
        for(int i=0;i<261;i++)
        {
            if(nums[i]==1)
                chars[i]='1';
            if(nums[i]==2)
                chars[i]='2';
            if(nums[i]==3)
                chars[i]='3';
            if(nums[i]==4)
                chars[i]='4';
            if(nums[i]==5)
                chars[i]='5';
            if(nums[i]==6)
                chars[i]='6';
            if(nums[i]==7)
                chars[i]='7';
            if(nums[i]==8)
                chars[i]='8';
        }
       
       //głowna petla
    while(k!=1)
    {
       
       
        cout<<"\n\nDostepnych flag: "<<count<<"\n\n    a b c d e f g h i j k l m n o p q r s t u v w x y z\n    ---------------------------------------------------\n 0| ";
        num=1;
        for(int i=0;i<260;i++)
        {
            if(cover[i+1]=='+')                     //wyswietlamy na planszy +, zgodnie z zawartoscia wektora cover            
                cout<<cover[i+1]<<" ";
            else if (chars[i+1]=='M')               //jezeli zamiast liczby otaczajacych min trafimy na mine, konczymy gre
            {
    cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"                                                                                "<<endl;
cout<<"            .           .   ________________    .        .                      "<<endl;
cout<<"                  .    ____/ (  (    )   )  \\___                               "<<endl;
cout<<"           .         /( (  (  )   _    ))  )   )\\        .   .                 "<<endl;
cout<<"                       ((     (   )(    )  )   (   )  )   .                     "<<endl;
cout<<"           .    .   ((/  ( _(   )   (   _) ) (  () )  )        .   .            "<<endl;
cout<<"                  ( (  ( (_)   ((    (   )  .((_ ) .  )_                        "<<endl;
cout<<"                                          )             )                       "<<endl;
cout<<"        #####  ####   ### ###  ###### ( _)     ####  #    # ###### #####        "<<endl;
cout<<"       #      #    # #   #   # #       )     #    # #    # #      #    #        "<<endl;
cout<<"      #  ### ###### #   #   # ######  ) (   #    # #    # ###### #####   .      "<<endl;
cout<<"     #    # #    # #   #   # #        ( _  #    # #    # #      #   #           "<<endl;
cout<<"     ##### #    # #   #   # ######  _  )   ####   ####  ###### #     #          "<<endl;
cout<<"                                    _        _  _ _     _       .   .   .       "<<endl;
cout<<"   .       .     (_((__(_(__(( ( ( |  ) ) ) )_))__))_)___)   .                  "<<endl;
cout<<"      .         ((__)        \\||lll|l||///          \\))       .               "<<endl;
cout<<"               .       . / (  |(||(|)|||//  \\     .    .      .      .         "<<endl;
cout<<"  .       .           .   (   /(/ (  )  ) )\\          .     .                  "<<endl;
cout<<"     .      .    .     (  . ( ( ( | | ) ) )\\   )               .               "<<endl;
cout<<"                        (   /(| / ( )) ) ) )) )    .   .  .       .  .  .       "<<endl;
cout<<" .     .       .  .   (  .  ( ((((_(|)_)))))     )            .                 "<<endl;
cout<<"         .  .          (    . ||||(|(|)|/|| . . )        .        .             "<<endl;
cout<<"     .           .   (   .    |(||(||)||||   .    ) .      .         .  .       "<<endl;
cout<<"  .      .      .       (     //|/l|||)|\\ \\     )      .      .   .           "<<endl;
cout<<"                      (/ / //  /|//||||\\  \\ \\  \\ _)                         "<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
            
                    k=1;
                    break;
            }
            else
                cout<<chars[i+1]<<" ";  //jezeli nie ma miny, wyswietlamy liczbe otaczajacych min
           
           
            if(i%26==25&&num!=10)   //numeracja wierszy
            {
                cout<<"|"<<num-1<<"\n "<<num<<"| ";
                num++;
            }
               
        }
        cout<<"|9\n    ---------------------------------------------------\n    a b c d e f g h i j k l m n o p q r s t u v w x y z";
       
       if (k!=1)
       {
           cout<<"\n\nWybor kolumny i wiersza: ";
        cin>>char1>>char2;
       }
     cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        flag='n';   //nie ma flagi
        if(char1=='F')          //Gdy pierwszy znak jest F, pobieramy dodatkowy znak i ustawiamy, ze mamy mniej flag dost. w grze
        {
            cin>>char3;
            char1=char2;
            char2=char3;
            flag='y'; //ustawiamy flage
            count--;
        }
            wait=1;
        if(char1=='a')          //Zmieniamy podany znak na numer kolumny
            extra1=1;
        else if(char1=='b')
            extra1=2;
        else if(char1=='c')
            extra1=3;
        else if(char1=='d')
            extra1=4;
        else if(char1=='e')
            extra1=5;
        else if(char1=='f')
            extra1=6;
        else if(char1=='g')
            extra1=7;
        else if(char1=='h')
            extra1=8;
        else if(char1=='i')
            extra1=9;
        else if(char1=='j')
            extra1=10;
        else if(char1=='k')
            extra1=11;
        else if(char1=='l')
            extra1=12;
        else if(char1=='m')
            extra1=13;
        else if(char1=='n')
            extra1=14;
        else if(char1=='o')
            extra1=15;
        else if(char1=='p')
            extra1=16;
        else if(char1=='q')
            extra1=17;
        else if(char1=='r')
            extra1=18;
        else if(char1=='s')
            extra1=19;
        else if(char1=='t')
            extra1=20;
        else if(char1=='u')
            extra1=21;
        else if(char1=='v')
            extra1=22;
        else if(char1=='w')
            extra1=23;
        else if(char1=='x')
            extra1=24;
        else if(char1=='y')
            extra1=25;
        else if(char1=='z')
            extra1=26;
       
        if(char2=='0')              //Zmieniamy podany znak na numer wiersza
            extra2=0;
        else if(char2=='1')
            extra2=1;
        else if(char2=='2')
            extra2=2;
        else if(char2=='3')
            extra2=3;
        else if(char2=='4')
            extra2=4;
        else if(char2=='5')
            extra2=5;
        else if(char2=='6')
            extra2=6;
        else if(char2=='7')
            extra2=7;
        else if(char2=='8')
            extra2=8;
        else if(char2=='9')
            extra2=9;
     
            theone=extra1+26*extra2;    //teraz znamy indeks wektora odpowiadajacy miejscu na planszy
           
       
        if(flag=='y')
        {
            chars[theone]='F';          //jezeli ustawilismy wczesniej flage, wstawiamy do wektora chars litere F
        }
            cover[theone]='-';
           
            waiter[wait]=theone;
           
    while(wait!=0&&flag=='n')
    {
           
       
        if(chars[theone]=='0')  //jezeli wartosc pola = 0
        {
            if(theone==1)   //gorny lewy corner
            {
               
                if(nums[2]==0&&cover[2]=='+')
                {
                    wait++;
                    waiter[wait]=2;
                }
                    cover[2]='-';
                if(nums[27]==0&&cover[27]=='+')
                {
                    wait++;
                    waiter[wait]=27;
                }
                    cover[27]='-';
                if(nums[28]==0&&cover[28]=='+')
                {
                    wait++;
                    waiter[wait]=28;
                }
                    cover[28]='-';
            }
            if(theone==26&&cover[26]=='+')  //gorny prawy
            {
                if(nums[25]==0&&cover[25]=='+')
                {
                    wait++;
                    waiter[wait]=25;
                }
                    cover[25]='-';
                if(nums[51]==0&&cover[51]=='+')
                {
                    wait++;
                    waiter[wait]=51;
                }
                    cover[51]='-';
                if(nums[52]==0&&cover[52]=='+')
                {
                    wait++;
                    waiter[wait]=52;
                }
                    cover[52]='-';
            }
            if(theone==235&&cover[235]=='+') //dolny lewy
            {
                if(nums[209]==0&&cover[209]=='+')
                {
                    wait++;
                    waiter[wait]=209;
                }
                    cover[209]='-';
               
                if(nums[210]==0&&cover[210]=='+')
                {
                    wait++;
                    waiter[wait]=210;
                }
                    cover[210]='-';
               
                if(nums[236]==0&&cover[236]=='+')
                {
                    wait++;
                    waiter[wait]=236;
                }
                    cover[236]='-';
               
            }
            if(theone==260&&cover[260]=='+') //dolny prawy
            {
                if(nums[233]==0&&cover[233]=='+')
                {
                    wait++;
                    waiter[wait]=233;
                }
                    cover[233]='-';
               
                if(nums[234]==0&&cover[234]=='+')
                {
                    wait++;
                    waiter[wait]=234;
                }
                    cover[234]='-';
               
                if(nums[259]==0&&cover[259]=='+')
                {
                    wait++;
                    waiter[wait]=259;
                }
                    cover[259]='-';
               
            }
            for(int i=2;i<26;i++)   //top
            {
                if(theone==i)
                {
                    if(nums[i-1]==0&&cover[i-1]=='+')
                    {
                        wait++;
                        waiter[wait]=i-1;
                    }
                        cover[i-1]='-';
                    if(nums[i+1]==0&&cover[i+1]=='+')
                    {
                        wait++;
                        waiter[wait]=i+1;
                    }
                        cover[i+1]='-';
                    if(nums[i+25]==0&&cover[i+25]=='+')
                    {
                        wait++;
                        waiter[wait]=i+25;
                    }
                        cover[i+25]='-';
                    if(nums[i+26]==0&&cover[i+26]=='+')
                    {
                        wait++;
                        waiter[wait]=i+26;
                    }
                        cover[i+26]='-';
                    if(nums[i+27]==0&&cover[i+27]=='+')
                    {
                        wait++;
                        waiter[wait]=i+27;
                    }
                        cover[i+27]='-';
                   
                }
            }
            for(int i=236;i<260;i++)   //dolne
            {
                if(theone==i)
                {
                    if(nums[i-1]==0&&cover[i-1]=='+')
                    {
                        wait++;
                        waiter[wait]=i-1;
                    }
                        cover[i-1]='-';
                   
                    if(nums[i+1]==0&&cover[i+1]=='+')
                    {
                        wait++;
                        waiter[wait]=i+1;
                    }
                        cover[i+1]='-';
                   
                    if(nums[i-25]==0&&cover[i-25]=='+')
                    {
                        wait++;
                        waiter[wait]=i-25;
                    }
                        cover[i-25]='-';
                    if(nums[i-26]==0&&cover[i-26]=='+')
                    {
                        wait++;
                        waiter[wait]=i-26;
                    }
                        cover[i-26]='-';
                    if(nums[i-27]==0&&cover[i-27]=='+')
                    {
                        wait++;
                        waiter[wait]=i-27;
                    }
                        cover[i-27]='-';
                }
            }
            for(int i=26;i<210;i++)   //lewe
            {
                if(i%26==1&&theone==i)
                {
                    if(nums[i-26]==0&&cover[i-26]=='+')
                    {
                        wait++;
                        waiter[wait]=i-26;
                    }
                        cover[i-26]='-';
                    if(nums[i-25]==0&&cover[i-25]=='+')
                    {
                        wait++;
                        waiter[wait]=i-25;
                    }
                        cover[i-25]='-';
                   
                    if(nums[i+1]==0&&cover[i+1]=='+')
                    {
                        wait++;
                        waiter[wait]=i+1;
                    }
                        cover[i+1]='-';
                    if(nums[i+26]==0&&cover[i+26]=='+')
                    {
                        wait++;
                        waiter[wait]=i+26;
                    }
                        cover[i+26]='-';
                    if(nums[i+27]==0&&cover[i+27]=='+')
                    {
                        wait++;
                        waiter[wait]=i+27;
                    }
                        cover[i+27]='-';
                }
            }
            for(int i=50;i<235;i++)   //prawe
            {
                if(i%26==0&&theone==i)
                {
                    if(nums[i-27]==0&&cover[i-27]=='+')
                    {
                        wait++;
                        waiter[wait]=i-27;
                    }
                        cover[i-27]='-';
                    if(nums[i-26]==0&&cover[i-26]=='+')
                    {
                        wait++;
                        waiter[wait]=i-26;
                    }
                        cover[i-26]='-';
                    if(nums[i-1]==0&&cover[i-1]=='+')
                    {
                        wait++;
                        waiter[wait]=i-1;
                    }
                        cover[i-1]='-';
                    if(nums[i+25]==0&&cover[i+25]=='+')
                    {
                        wait++;
                        waiter[wait]=i+25;
                    }
                        cover[i+25]='-';
                    if(nums[i+26]==0&&cover[i+26]=='+')
                    {
                        wait++;
                        waiter[wait]=i+26;
                    }
                        cover[i+26]='-';
                }
            }
            for(int i=28;i<234;i++)   //pozostale
            {
                if(i%26!=0&&i%26!=1&&theone==i)
                {
                    if(nums[i-27]==0&&cover[i-27]=='+')
                    {
                        wait++;
                        waiter[wait]=i-27;
                    }
                        cover[i-27]='-';
                    if(nums[i-26]==0&&cover[i-26]=='+')
                    {
                        wait++;
                        waiter[wait]=i-26;
                    }
                        cover[i-26]='-';
                    if(nums[i-25]==0&&cover[i-25]=='+')
                    {
                        wait++;
                        waiter[wait]=i-25;
                    }
                        cover[i-25]='-';
                    if(nums[i-1]==0&&cover[i-1]=='+')
                    {
                        wait++;
                        waiter[wait]=i-1;
                    }
                        cover[i-1]='-';
                    if(nums[i+1]==0&&cover[i+1]=='+')
                    {
                        wait++;
                        waiter[wait]=i+1;
                    }
                        cover[i+1]='-';
                    if(nums[i+25]==0&&cover[i+25]=='+')
                    {
                        wait++;
                        waiter[wait]=i+25;
                    }
                        cover[i+25]='-';
                    if(nums[i+26]==0&&cover[i+26]=='+')
                    {
                        wait++;
                        waiter[wait]=i+26;
                    }
                        cover[i+26]='-';
                    if(nums[i+27]==0&&cover[i+27]=='+')
                    {
                        wait++;
                        waiter[wait]=i+27;
                    }
                        cover[i+27]='-';
                }
            }
       
        }
           
            theone=waiter[wait];
            wait--;
    }
           
       
    }
       
       
    }

