#include <iostream>
#define TRUE 1
#define FALSE 0
using namespace std;
typedef int Boolean;
typedef struct L *Lref;
typedef struct T *Tref;


typedef struct L
{
  int Key;
  int Count;
  Boolean Flag;
  Tref Trail;
  Lref Next;
} Leader;

typedef struct T
{
  Lref Id;
  Tref Next;
} Trailer;

typedef Tref TipElement;
typedef struct Zveno *svqz;
typedef struct Zveno
{
  TipElement Element;
  svqz Sled;
} St;

class Spisok
{
  private:
    Lref Head;
    Lref Tail;
    void SearchGraph (int, Lref *);
    void W_S (svqz *, TipElement);
    void YDALENIE (svqz *, TipElement *);
  public:
    Spisok() {
              Head = Tail =  new (Leader); }
    Lref GetHead() { return Head; }
    Lref GetTail() { return Tail; }
    void MakeGraph ();
    void PrintGraph ();
    void Depth_First_Search (Lref);
    void Depth_First_Search_1 (Lref);
};

int main ()
{
  Spisok A;
  Lref t;
  A.MakeGraph ();
  A.PrintGraph (); cout<<endl;
  cout<<"Результат рекурсивного обхода...\n";
  t = A.GetHead();
  while (t!=A.GetTail())
    { (*t).Flag = TRUE; t = (*t).Next; }
  A.Depth_First_Search (A.GetHead()); cout<<endl;
  cout<<"Результат нерекурсивного обхода...\n";
  t = A.GetHead();
  while (t!=A.GetTail())
   { (*t).Flag = TRUE; t = (*t).Next;}
  A.Depth_First_Search_1 (A.GetHead()); cout<<endl;
}

void Spisok::SearchGraph (int w, Lref *h)
{
  *h = Head; (*Tail).Key = w;
  while ((**h).Key!=w) *h = (**h).Next;
  if (*h==Tail)

  { Tail = new (Leader); (**h).Count = 0;
    (**h).Trail = NULL; (**h).Next = Tail; }
}

void Spisok::MakeGraph ()
{
  int x,y;
  Lref p,q;
  Tref t,r;
  Boolean Res;
  cout<<"Вводите начальную вершину дуги: ";
  cin>>x;
  while (x!=0)
  {
     cout<<"Вводите конечную вершину дуги: "; cin>>y;
     SearchGraph (x, &p); SearchGraph (y,&q);
     r = (*p).Trail; Res = FALSE;
     while ((r!=NULL)&&(!Res))
       if ((*r).Id==q) Res = TRUE;
       else r = (*r).Next;
     if (!Res)
      { t = new (Trailer); (*t).Id = q;
        (*t).Next = (*p).Trail; (*p).Trail = t; (*q).Count++; }
     cout<<"Вводите начальную вершину дуги: "; cin>>x;
  }
}

void Spisok::PrintGraph ()
{
  Lref p;
  Tref q;

  p = Head;
  while (p!=Tail)
  {
     cout<<"("<<(*p).Key; q = (*p).Trail;
     while (q!=NULL)
      { cout<<(*(*q).Id).Key; q = (*q).Next; }
     cout<<")"; p = (*p).Next; cout<<" ";
  }
}

void Spisok::W_S (svqz *stk, TipElement el)
{
  svqz q=new (St);
  (*q).Element = el; (*q).Sled = *stk; *stk = q;
}

void Spisok::YDALENIE (svqz *stk, TipElement *klad)
{
  svqz q;

  if (*stk==NULL) cout<<"Попытка выбора из пустого стека!\n";
  else
   { *klad = (**stk).Element; q = *stk; *stk = (**stk).Sled; delete q; }
}

void Spisok::Depth_First_Search (Lref r)
{
  Tref t;

  t = (*r).Trail; cout<<(*r).Key; (*r).Flag = FALSE;
  while (t!=NULL)
  { if ((*(*t).Id).Flag) Depth_First_Search ((*t).Id); t = (*t).Next; }
}

void Spisok::Depth_First_Search_1 (Lref r)
{
  Tref t;
  svqz Stack = NULL;
  cout<<(*r).Key; (*r).Flag = FALSE;
  W_S (&Stack,(*r).Trail);
  while (Stack!=NULL)
  {
    t = (*Stack).Element;
    if ((*(*t).Id).Trail!=NULL)
      {
        if ((*(*t).Id).Flag)
        {
          cout<< (*(*t).Id).Key; (*(*t).Id).Flag = FALSE;
          W_S (&Stack,(*(*t).Id).Trail);
        }
        else {
          t = (*Stack).Element;
          if ((*t).Next!=NULL)
             { YDALENIE (&Stack,&t); W_S (&Stack,(*t).Next); }
          else YDALENIE (&Stack,&t);
        }
     }
     else {
            if ((*(*t).Id).Flag)
             { cout<<(*(*t).Id).Key; (*(*t).Id).Flag = FALSE; }
            t = (*Stack).Element;
            if ((*t).Next!=NULL)
             { YDALENIE (&Stack,&t); W_S (&Stack,(*t).Next); }
            else YDALENIE (&Stack,&t);
           }
  }
}

