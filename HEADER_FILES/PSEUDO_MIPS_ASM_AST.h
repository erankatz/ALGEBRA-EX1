#ifndef __PSEUDO_MIPS_ASM_AST_H__
#define __PSEUDO_MIPS_ASM_AST_H__

/********************************/
/* FILE NAME: PSEUDO_MIPS_ASM_AST.h */
/********************************/

/*****************/
/* INCLUDE FILES */
/*****************/
#include <stdio.h>

/***************/
/* DEFINITIONS */
/***************/
#define MAX_NAME_LENGTH_OF_LABEL 100

/*********/
/* ENUMS */
/*********/
typedef enum
{
	PSEUDO_MIPS_ASM_AST_LOAD_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_LOAD_REGISTERS_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_ADD_IMMEDIATE_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_STORE_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_LOAD_IMMEDIATE_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_ADD_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_SUB_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_MUL_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_DIV_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_LABEL_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_MOVE_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_JUMP_LABEL_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_JUMP_AND_LINK_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_JUMP_REGISTER_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_PUSH_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_POP_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_BEQ_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_BNE_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_BGT_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_BGE_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_BLT_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_BLE_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_PRINT_INT_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_PRINT_CHAR_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_ALLOCATE_EXP_TYPE,
	PSEUDO_MIPS_ASM_AST_EXIT_EXP_TYPE,
}	PSEUDO_MIPS_ASM_AST_EXP_TYPE;

/*********/
/* TYPES */
/*********/
typedef struct PSEUDO_MIPS_ASM_AST_exp_		*PSEUDO_MIPS_ASM_AST_exp;
typedef struct PSEUDO_MIPS_ASM_AST_Var_		*PSEUDO_MIPS_ASM_AST_Var;
typedef struct PSEUDO_MIPS_ASM_AST_expList_	*PSEUDO_MIPS_ASM_AST_expList;

typedef struct
{
	char name[MAX_NAME_LENGTH_OF_LABEL];
	int serial_number;
}
PSEUDO_MIPS_ASM_AST_Label_Type_;

typedef enum
{
	TEMPORARY_VAR,
	REGISTER_VAR,
}
PSEUDO_MIPS_ASM_AST_Var_Type;

struct PSEUDO_MIPS_ASM_AST_Var_
{
	union
	{
		int temp;
		char *reg;
	} u;

	PSEUDO_MIPS_ASM_AST_Var_Type type;
};

struct PSEUDO_MIPS_ASM_AST_exp_
{
	PSEUDO_MIPS_ASM_AST_EXP_TYPE type;

	union
	{
		char jump_and_link[MAX_NAME_LENGTH_OF_LABEL];
		char jump_register[MAX_NAME_LENGTH_OF_LABEL];
 
		struct {char name[MAX_NAME_LENGTH_OF_LABEL]; int serial_number;} label;
		struct {char name[MAX_NAME_LENGTH_OF_LABEL]; int serial_number;} jump_label;

		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;PSEUDO_MIPS_ASM_AST_Label_Type_ label;} beq;
		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;PSEUDO_MIPS_ASM_AST_Label_Type_ label;} bne;
		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;PSEUDO_MIPS_ASM_AST_Label_Type_ label;} bgt;
		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;PSEUDO_MIPS_ASM_AST_Label_Type_ label;} blt;
		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;PSEUDO_MIPS_ASM_AST_Label_Type_ label;} bge;
		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;PSEUDO_MIPS_ASM_AST_Label_Type_ label;} ble;

		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;PSEUDO_MIPS_ASM_AST_Var var3;} add;
		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;PSEUDO_MIPS_ASM_AST_Var var3;} sub;
		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;PSEUDO_MIPS_ASM_AST_Var var3;} mul;
		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;PSEUDO_MIPS_ASM_AST_Var var3;} div;

		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;} move;

		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;int value;} add_immediate;

		struct {PSEUDO_MIPS_ASM_AST_Var var; int value;} load_immediate;

		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;int offset;} load;
		struct {PSEUDO_MIPS_ASM_AST_Var var1;PSEUDO_MIPS_ASM_AST_Var var2;int offset;} store;

	} u;
};

/***********************************/
/* Linked lists and nodes of lists */
/***********************************/
struct PSEUDO_MIPS_ASM_AST_expList_ {PSEUDO_MIPS_ASM_AST_exp head; PSEUDO_MIPS_ASM_AST_expList tail;};

/***********************/
/* Function Prototypes */
/***********************/
PSEUDO_MIPS_ASM_AST_expList PSEUDO_MIPS_ASM_AST_ExpList(PSEUDO_MIPS_ASM_AST_exp head, PSEUDO_MIPS_ASM_AST_expList tail);

PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_LOAD( PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2,int offset);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_STORE(PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2,int offset);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_MOVE( PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2);

PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_ADD(PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2,PSEUDO_MIPS_ASM_AST_Var var3);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_SUB(PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2,PSEUDO_MIPS_ASM_AST_Var var3);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_MUL(PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2,PSEUDO_MIPS_ASM_AST_Var var3);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_DIV(PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2,PSEUDO_MIPS_ASM_AST_Var var3);

PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_ADD_IMMEDIATE( PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2,int value);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_LOAD_IMMEDIATE(PSEUDO_MIPS_ASM_AST_Var var,int value);

PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_JUMP_LABEL(PSEUDO_MIPS_ASM_AST_Label_Type_ label);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_JUMP_REGISTER(char *register_name);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_JUMP_AND_LINK(char *label);

PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_LABEL(PSEUDO_MIPS_ASM_AST_Label_Type_ label);

PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_BEQ(PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2,PSEUDO_MIPS_ASM_AST_Label_Type_ label);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_BNE(PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2,PSEUDO_MIPS_ASM_AST_Label_Type_ label);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_BGT(PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2,PSEUDO_MIPS_ASM_AST_Label_Type_ label);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_BLT(PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2,PSEUDO_MIPS_ASM_AST_Label_Type_ label);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_BGE(PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2,PSEUDO_MIPS_ASM_AST_Label_Type_ label);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_BLE(PSEUDO_MIPS_ASM_AST_Var var1,PSEUDO_MIPS_ASM_AST_Var var2,PSEUDO_MIPS_ASM_AST_Label_Type_ label);

PSEUDO_MIPS_ASM_AST_Var PSEUDO_MIPS_ASM_AST_TEMP_VAR(int temp_serial_number);
PSEUDO_MIPS_ASM_AST_Var PSEUDO_MIPS_ASM_AST_REGISTER_VAR(char *register_name);

PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_PRINT_INT(void);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_PRINT_CHAR(void);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_ALLOCATE(void);
PSEUDO_MIPS_ASM_AST_exp PSEUDO_MIPS_ASM_AST_EXIT(void);

#endif