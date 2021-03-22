typedef int ElementType;

#ifndef _Stack_h   //diretriz para o compilador
#define _Stack_h

struct StackRecord;
typedef struct StackRecord *Stack;

Stack CreateStack( int MaxElements );
void DisposeStack( Stack S );

int IsEmpty( Stack S );
int IsFull( Stack S );
void MakeEmpty( Stack S );

void Push( ElementType X, Stack S );
ElementType Top( Stack S );
//void Pop( Stack S );
//ElementType TopAndPop( Stack S );
ElementType Pop( Stack S );

#endif  /* _Stack_h */