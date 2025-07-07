void DecodeNodeOp(struct ListNode *ptr) // used for debugging purpose only, not a functionality
{
   if(ptr == NULL)
   {
      printf("ptr is NULL\n");
      return;
   }
  if(ptr->isOperatorOrOperand == OPERATOR)
  {
 
     switch(ptr->op)
     {
       case OR_EQ_OP:
       printf("OR_EQ_OP\n");
       break;
       case XOR_EQ_OP:
       printf("XOR_EQ_OP\n");
       break;
       case AMP_EQ_OP:
       printf("AMP_EQ_OP\n");
       break;
       case RSHR_EQ_OP:
       printf("RSHR_EQ_OP\n");
       break;
       case LSHR_EQ_OP:
       printf("LSHR_EQ_OP\n");
       break;
       case MOD_EQ_OP:
       printf("MOD_EQ_OP\n");
       break;
       case DIV_EQ_OP:
       printf("DIV_EQ_OP\n");
       break;
       case MUL_EQ_OP:
       printf("MUL_EQ_OP\n");
       break; 
       case SUB_EQ_OP:
       printf("SUB_EQ_OP\n");
       break;
       case ADD_EQ_OP: 
       printf("ADD_EQ_OP\n");
       break;
       case MOV_OP: 
       printf("MOV_EQ_OP\n");
       break;

       case OR_OR_OP: 
       printf("OR_OR_OP\n");
       break;
       case AND_AND_OP: 
       printf("AND_AND_OP\n");
       break;
       case OR_OP: 
       printf("OR_OP\n");
       break;
       case XOR_OP: 
       printf("XOR_OP\n");
       break;
       case AND_OP: 
       printf("AND_OP\n");
       break;
       case NOT_EQ_OP: 
       printf("NOT_EQ_OP\n");
       break;
       case EQ_EQ_OP: 
       printf("EQ_EQ_OP\n");
       break;
       case LSR_EQ_OP:
       printf("LSR_EQ_OP\n");
       break;
       case LSR_OP:
       printf("LSR_OP\n");
       break;
       case GTR_EQ_OP:
       printf("GTR_EQ_OP\n");
       break;
       case GTR_OP:
       printf("GTR_OP\n");
       break;
       case RSHR_OP:
       printf("RSHR_OP\n");
       break;
       case LSHR_OP:
       printf("LSHR_OP\n");
       break;
       case MOD_OP:
       printf("MOD_OP\n");
       break;
       case SUB_OP:
       printf("SUB_OP\n");
       break;
       case ADD_OP:
       printf("ADD_OP\n");
       break;
       case DIV_OP:
       printf("DIV_OP\n");
       break;
       case MUL_OP:
       printf("MUL_OP\n");
       break;
       case DEREF_OP:
       printf("DEREF_OP\n");
       break;
       case ADDR_OP:
       printf("ADDR_OP\n");
       break; 
       case BNOT_OP:
       printf("BNOT_OP\n");
       break;
       case NOT_OP:
       printf("NOT_OP\n");
       break;
       case SUB_SUB_OP:
       printf("SUB_SUB_OP\n");
       break;
       case ADD_ADD_OP:
       printf("ADD_ADD_OP\n");
       break;
       default:
       printf("\nOperator is %d\n", ptr->op);
       break; 
     }

     switch(ptr->opType)
     {
      
       case NULL_OP:
        printf("NULL_OP\n");
       break;
       case UNARY_OP:
        printf("UNARY_OP\n");
       break;
       case BINARY_OP:
        printf("BINARY_OP\n");
       break;
       case TERNARY_OP:
        printf("TERNARY_OP\n");
       break;
       default:
        printf("\nOperator Type is %d\n", ptr->opType);
       break;
     }
  }
  else if(ptr->isOperatorOrOperand == OPERAND)
  {
      printf("Symbol is %s priority is %d\n", ptr->str->value, ptr->priority); 
  }
}
