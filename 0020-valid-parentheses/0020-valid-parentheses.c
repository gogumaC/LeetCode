#include <stdarg.h>

typedef struct stack{
    char *arr;
    int top,size;
} Stack;


void init_stack(Stack* st, int size)
{
    char *new_arr = (char*)malloc(size);
    st->top = -1;
    st->size = size;
    st->arr = new_arr;
}

char pop(Stack* st)
{
    if(st->top<0) 
    {
        return '\0';
    }
    char *arr = st->arr;
    char res = arr[st->top--];
    return res;

}

bool push(Stack* st, char value){
    st->top++;
    if(st->top==st->size) return false;
    st->arr[st->top]= value;
    return true;
}

bool find(Stack *st1, char find)
{
    char* arr = st1->arr;
    if(st1->top>=0)
    {
        return find==pop(st1);
    }

    return false;

}


bool isValid(char* s) {
    Stack st;
    init_stack(&st,strlen(s)); //sizeof vs strlen

    for(int i=strlen(s)-1;i>-1;i--)
    {
        char c=s[i];
        bool res = true;
       switch(c)
        {
            case '(':
                res=find(&st,')');
                break;
            case '[':
                res=find(&st,']');
                break;
            case '{':
                res=find(&st,'}');
                break;
            default:
                res=push(&st,c);
        }
        if(!res) return false;
    }
    return st.top==-1;
    
}