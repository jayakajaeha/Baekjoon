#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  char e;
  struct node* next;
  struct node* prev;
}node;

node* getNode(char e)
{
  node* n = (node*)malloc(sizeof(node));
  n->next = NULL;
  n->prev = NULL;
  n->e=e;
  return n;
}

void putNode(node* l)
{
  free(l);
}

void add(node* l, char e)
{
  node *n = getNode(e);
  l->prev->next = n;
  n->prev = l->prev;
  l->prev=n;
  n->next=l;
}

void del(node* l)
{
  node *tmp = l->prev;
  l->prev->prev->next=l;
  l->prev=l->prev->prev;
  putNode(tmp);
}

void write(node* l)
{
  if(l->e=='\0') return;
  else
  {
    printf("%c",l->e);
    write(l->next);
  }
}

int main()
{
  node* H = getNode('\0');
  node* T = getNode('\0');
  H->next=T;
  T->prev=H;
  char e;
  scanf("%c",&e);
  while(e!='\n')
  {
    add(T,e);
    scanf("%c",&e);
  }

  int n;
  char inst;
  node* pres = T;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    {
      scanf(" %c",&inst);
      if(inst=='L'&&pres->prev->e!='\0') pres = pres->prev;
      else if(inst=='D'&&pres->next!=NULL) pres=pres->next;
      else if(inst=='B'&&pres->prev->e!='\0') del(pres);
      else if(inst=='P'){
        scanf(" %c",&e);
        add(pres,e);
      }
    }
  write(H->next);
  return 0;
}