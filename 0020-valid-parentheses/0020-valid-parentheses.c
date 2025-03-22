#include <stdarg.h>

#define LOG 0


void print_arr(char* arr,int len);

void logm(const char* format, ...)
{
    va_list args;
    va_start(args,format);
    vprintf(format,args);
    va_end(args);
}

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
    printf("top %d",st1->top);
    if(st1->top>=0)
    {
        printf("find : %c , last : %c",find,arr[st1->top]);
        return find==pop(st1);
    }

    return false;

}

void print_arr(char* arr,int len){
    printf("arrs : ");
    for(int i=0;i<len;i++){
        printf("%c ",*(arr+i));//arr[i],*(arr+i)로 하니까 heap buffer overflow남
    }
    printf("\n");

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
                printf("() %d\n",res);
                break;
            case '[':
                res=find(&st,']');
                printf("[] %d\n",res);
                break;
            case '{':
                res=find(&st,'}');
                printf("{} %d\n",res);
                break;
            default:
                printf("default\n");
                res=push(&st,c);
        }
        if(!res) return false;
    }
    return st.top==-1;
    
}