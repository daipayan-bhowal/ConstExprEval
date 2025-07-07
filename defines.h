#define OPERAND 255
#define OPERATOR -255
//#define INT 33
#define INIT_PRIORITY -1


enum Ty
{
    INT,
    FLOAT,
    CHAR,
    STRING,
    FCONST,
    I_ARRAY,
    F_ARRAY,
    CONST = 256
};

enum Priority
{
    ZERO_OP=129,
    OR_EQ_OP, /* 130 */
    XOR_EQ_OP, /* 131 */
    AMP_EQ_OP, /* 132 */
    RSHR_EQ_OP, /* 133 */
    LSHR_EQ_OP, /* 134 */
    MOD_EQ_OP, /* 135 */
    DIV_EQ_OP, /* 136 */
    MUL_EQ_OP, /* 137 */
    SUB_EQ_OP, /* 138 */
    ADD_EQ_OP, /* 139 */
    MOV_OP, /* 140 */
    OR_OR_OP, /* 141 */
    AND_AND_OP, /* 142 */
    OR_OP,    /* 143 */
    XOR_OP,  /* 144 */
    AND_OP,  /* 145 */
    NOT_EQ_OP, /* 146 */
    EQ_EQ_OP, /* 147 */
    LSR_EQ_OP, /* 148 */
    LSR_OP,  /* 149 */
    GTR_EQ_OP,  /* 150 */
    GTR_OP, /* 151 */
    RSHR_OP, /* 152 */
    LSHR_OP, /* 153 */
    SUB_OP,  /* 155 */
    ADD_OP,  /* 156 */
    MOD_OP,  /* 154 */
    DIV_OP,  /* 157 */
    MUL_OP,  /* 158 */
    DEREF_OP,
    ADDR_OP,
    BNOT_OP,
    NOT_OP,
    SUB_SUB_OP,
    ADD_ADD_OP,
    LAST_OP
};
enum Operation
{
    NULL_OP,
    UNARY_OP,
    BINARY_OP,
    TERNARY_OP
};


enum Registers
{
    ax,
    bx,
    cx,
    dx,
    eax,
    ebx,
    LAST_REG
};
char *register_str[7] = {(char*)"ax",(char*)"bx",(char*)"cx",(char*)"dx", (char*)"eax", (char*)"ebx", (char*)"ecx"};
struct Symbol
{
   char *symbol;
   char type;
   char *value;
   enum Registers r;
   char qual;
};
struct Symbol symtbl[256];
int max_sym=0;
static int reg_count = 0;
void Symbol_insert(char *sym,char typ,char *val,enum Registers rtemp)
{
    symtbl[max_sym].symbol =(char*) calloc(strlen(sym)+1, sizeof(char));
    strncpy(symtbl[max_sym].symbol,sym,strlen(sym));
    symtbl[max_sym].type = typ;
    symtbl[max_sym].value = (char*) calloc(strlen(val)+1, sizeof(char));
    strncpy(symtbl[max_sym].value,val, strlen(sym));
    symtbl[max_sym].r = rtemp;

   if(reg_count >= 6)
      reg_count = reg_count%5;
    
    reg_count++;

    max_sym++;
}
int Symbol_search(char *sym)
{
    for(int i=0; i<max_sym; i++)
    {
        if(strcmp(sym,symtbl[i].symbol)==0)
        {
            
            return i;
        }
    }
   return -1;
}
struct ListNode
{
    struct ListNode* prev;
    int isOperatorOrOperand;
    int priority;
    struct Symbol *str;
    int op;
    int derefLevel;
    enum Operation opType; /* 1 for unary, 2 for binary, for ternary we don't need this */
    enum Ty type;
    struct ListNode* next;
};
