
%token AUTO_tok
%token BREAK_tok
%token CASE_tok
%token CHAR_tok
%token CONST_tok
%token CONTINUE_tok
%token DEFAULT_tok
%token DO_tok
%token DOUBLE_tok
%token ELSE_tok
%token ENUM_tok
%token EXTERN_tok
%token FLOAT_tok
%token FOR_tok
%token GOTO_tok
%token IF_tok
%token INT_tok
%token LONG_tok
%token REGISTER_tok
%token RETURN_tok
%token SHORT_tok
%token SIGNED_tok
%token SIZEOF_tok
%token STATIC_tok
%token STRUCT_tok
%token SWITCH_tok
%token TYPEDEF_tok
%token UNION_tok
%token UNSIGNED_tok
%token VOID_tok
%token VOLATILE_tok
%token WHILE_tok
%token ERROR_tok
%token ID_tok
%token PLUS_tok
%token MINUS_tok
%token STAR_tok
%token SEMI_tok
%token OPEN_BRACKET_tok
%token CLOSE_BRACKET_tok
%token EQUAL_tok
%token COLON_tok
%token COMMA_tok
%token OPEN_PAREN_tok
%token CLOSE_PAREN_tok
%token OPEN_BRACE_tok
%token CLOSE_BRACE_tok
%token QUESTION_MARK_tok
%token BAR_tok
%token CARET_tok
%token AMP_tok
%token GT_tok
%token LT_tok
%token PERCENT_tok
%token TILDA_tok
%token NOT_tok
%token INC_OP_tok
%token DEC_OP_tok
%token INTEGER_CONSTANT_tok
%token FLOATING_CONSTANT_tok

%token CHARACTER_CONSTANT_tok
%token ENUMERATION_CONSTANT_tok
%token STRING_LITERAL_tok

%token PTR_OP_tok
%token LEFT_OP_tok
%token RIGHT_OP_tok
%token LE_OP_tok
%token GE_OP_tok
%token EQ_OP_tok
%token NE_OP_tok
%token AND_OP_tok
%token OR_OP_tok
%token MULT_ASSIGN_tok
%token DIV_ASSIGN_tok
%token MOD_ASSIGN_tok
%token ADD_ASSIGN_tok
%token SUB_ASSIGN_tok
%token LEFT_ASSIGN_tok
%token RIGHT_ASSIGN_tok
%token AND_ASSIGN_tok
%token XOR_ASSIGN_tok
%token OR_ASSIGN_tok
%token TYPEDEF_NAME_tok
%token ELIPSIS_tok
%token DIV_tok
%token PERIOD_tok

%start translation_unit
%%

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declarator compound_statement
	| declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declaration_specifiers declarator declaration_list compound_statement
	;

declaration
	: declaration_specifiers SEMI_tok
	| declaration_specifiers init_declarator_list SEMI_tok

declaration_list
	: declaration
	| declaration_list declaration
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

storage_class_specifier
	: AUTO_tok
	| REGISTER_tok
	| STATIC_tok
	| EXTERN_tok
	| TYPEDEF_tok
	;

type_specifier
	: VOID_tok
	| CHAR_tok
	| SHORT_tok
	| INT_tok
	| LONG_tok
	| FLOAT_tok
	| DOUBLE_tok
	| SIGNED_tok
	| UNSIGNED_tok
	| struct_or_union_specifier
	| ENUM_tok
	| TYPEDEF_NAME_tok
	;

type_qualifier
	: CONST_tok
	| VOLATILE_tok
	;

struct_or_union_specifier
	: struct_or_union identifier OPEN_BRACE_tok struct_declaration_list CLOSE_BRACE_tok
	| struct_or_union OPEN_BRACE_tok struct_declaration_list CLOSE_BRACE_tok
	| struct_or_union identifier
	;

struct_or_union
	: STRUCT_tok
	| UNION_tok
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

init_declarator_list
	: init_declarator
	| init_declarator_list COMMA_tok init_declarator
	;

init_declarator
	: declarator
	| declarator EQUAL_tok initializer
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMI_tok
	;

specifier_qualifier_list
	: type_specifier
	| type_specifier specifier_qualifier_list
	| type_qualifier
	| type_qualifier specifier_qualifier_list
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list COMMA_tok struct_declarator
	;

struct_declarator
	: declarator
	| COLON_tok constant_expression
	| declarator COLON_tok constant_expression
	;

enum_specifier
	: ENUM_tok OPEN_BRACE_tok enumerator_list CLOSE_BRACE_tok
	| ENUM_tok identifier OPEN_BRACE_tok enumerator_list CLOSE_BRACE_tok
	| ENUM_tok identifier
	;

enumerator_list
	: enumerator
	| enumerator_list COMMA_tok enumerator
	;

enumerator
	: identifier
	| identifier EQUAL_tok constant_expression
	;

declarator
	: direct_declarator
	| pointer direct_declarator
	;

direct_declarator
	: identifier
	| OPEN_PAREN_tok declarator CLOSE_PAREN_tok
	| direct_declarator OPEN_BRACKET_tok CLOSE_BRACKET_tok
	| direct_declarator OPEN_BRACKET_tok constant_expression CLOSE_BRACKET_tok
	| direct_declarator OPEN_PAREN_tok CLOSE_PAREN_tok
	| direct_declarator OPEN_PAREN_tok parameter_type_list CLOSE_PAREN_tok
	| direct_declarator OPEN_PAREN_tok identifier_list CLOSE_PAREN_tok
	;

pointer
	: STAR_tok
	| STAR_tok type_qualifier_list
	| STAR_tok pointer
	| STAR_tok type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;

parameter_type_list
	: parameter_list
	| parameter_list COMMA_tok ELIPSIS_tok
	;

parameter_list
	: parameter_declaration
	| parameter_list COMMA_tok parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers
	| declaration_specifiers abstract_declarator
	;

identifier_list
	: identifier
	| identifier_list COMMA_tok identifier
	;

initializer
	: assignment_expression
	| OPEN_BRACE_tok initializer_list CLOSE_BRACE_tok
	| OPEN_BRACE_tok initializer_list COMMA_tok CLOSE_BRACE_tok
	;

initializer_list
	: initializer
	| initializer_list COMMA_tok initializer
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: OPEN_PAREN_tok abstract_declarator CLOSE_PAREN_tok
	| OPEN_BRACKET_tok CLOSE_BRACKET_tok
	| OPEN_BRACKET_tok constant_expression CLOSE_BRACKET_tok
	| direct_abstract_declarator OPEN_BRACKET_tok CLOSE_BRACKET_tok
	| direct_abstract_declarator OPEN_BRACKET_tok constant_expression CLOSE_BRACKET_tok
	| OPEN_PAREN_tok CLOSE_PAREN_tok
	| OPEN_PAREN_tok parameter_type_list CLOSE_PAREN_tok
	| direct_abstract_declarator OPEN_PAREN_tok CLOSE_PAREN_tok
	| direct_abstract_declarator OPEN_PAREN_tok parameter_type_list CLOSE_PAREN_tok
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: identifier COLON_tok statement
	| CASE_tok constant_expression COLON_tok statement
	| DEFAULT_tok COLON_tok statement
	;

expression_statement
	: SEMI_tok
	| expression SEMI_tok
	;

compound_statement
	: OPEN_BRACE_tok CLOSE_BRACE_tok
	| OPEN_BRACE_tok statement_list CLOSE_BRACE_tok
	| OPEN_BRACE_tok declaration_list CLOSE_BRACE_tok
	| OPEN_BRACE_tok declaration_list statement_list CLOSE_BRACE_tok
	;

statement_list
	: statement
	| statement_list statement
	;

selection_statement
	: IF_tok OPEN_PAREN_tok expression CLOSE_PAREN_tok statement
	| IF_tok OPEN_PAREN_tok expression CLOSE_PAREN_tok statement ELSE_tok statement
	| SWITCH_tok OPEN_PAREN_tok expression CLOSE_PAREN_tok statement
	;

iteration_statement
	: WHILE_tok OPEN_PAREN_tok expression CLOSE_PAREN_tok statement
	| DO_tok statement WHILE_tok OPEN_PAREN_tok expression CLOSE_PAREN_tok SEMI_tok
	| FOR_tok OPEN_PAREN_tok SEMI_tok SEMI_tok CLOSE_PAREN_tok statement
	| FOR_tok OPEN_PAREN_tok SEMI_tok SEMI_tok expression CLOSE_PAREN_tok statement
	| FOR_tok OPEN_PAREN_tok SEMI_tok expression SEMI_tok CLOSE_PAREN_tok statement
	| FOR_tok OPEN_PAREN_tok SEMI_tok expression SEMI_tok expression CLOSE_PAREN_tok statement
	| FOR_tok OPEN_PAREN_tok expression SEMI_tok SEMI_tok CLOSE_PAREN_tok statement
	| FOR_tok OPEN_PAREN_tok expression SEMI_tok SEMI_tok expression CLOSE_PAREN_tok statement
	| FOR_tok OPEN_PAREN_tok expression SEMI_tok expression SEMI_tok CLOSE_PAREN_tok statement
	| FOR_tok OPEN_PAREN_tok expression SEMI_tok expression SEMI_tok expression CLOSE_PAREN_tok statement
	;

jump_statement
	: GOTO_tok identifier SEMI_tok
	| CONTINUE_tok SEMI_tok
	| BREAK_tok SEMI_tok
	| RETURN_tok SEMI_tok
	| RETURN_tok expression SEMI_tok
	;

expression
	: assignment_expression
	| expression COMMA_tok assignment_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: EQUAL_tok
	| MULT_ASSIGN_tok
	| DIV_ASSIGN_tok
	| MOD_ASSIGN_tok
	| ADD_ASSIGN_tok
	| SUB_ASSIGN_tok
	| LEFT_ASSIGN_tok
	| RIGHT_ASSIGN_tok
	| AND_ASSIGN_tok
	| XOR_ASSIGN_tok
	| OR_ASSIGN_tok
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression QUESTION_MARK_tok expression COLON_tok conditional_expression
	;

constant_expression
	: conditional_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP_tok logical_and_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP_tok inclusive_or_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression BAR_tok exclusive_or_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression CARET_tok and_expression
	;

and_expression
	: equality_expression
	| and_expression AMP_tok equality_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP_tok relational_expression
	| equality_expression NE_OP_tok relational_expression
	;

relational_expression
	: shift_expression
	| relational_expression LT_tok shift_expression
	| relational_expression GT_tok shift_expression
	| relational_expression LE_OP_tok shift_expression
	| relational_expression GE_OP_tok shift_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP_tok additive_expression
	| shift_expression RIGHT_OP_tok additive_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression PLUS_tok multiplicative_expression
	| additive_expression MINUS_tok multiplicative_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression STAR_tok cast_expression
	| multiplicative_expression DIV_tok cast_expression
	| multiplicative_expression PERCENT_tok cast_expression
	;

cast_expression
	: unary_expression
	| OPEN_PAREN_tok type_name CLOSE_PAREN_tok cast_expression
	;

unary_expression
	: postfix_expression
	| INC_OP_tok unary_expression
	| DEC_OP_tok unary_expression
	| unary_operator cast_expression
	| SIZEOF_tok unary_expression
	| SIZEOF_tok OPEN_PAREN_tok type_name CLOSE_PAREN_tok
	;

unary_operator
	: AMP_tok
	| STAR_tok
	| PLUS_tok
	| MINUS_tok
	| TILDA_tok
	| NOT_tok
	;

postfix_expression
	: primary_expression
	| postfix_expression OPEN_BRACKET_tok expression CLOSE_BRACKET_tok
	| postfix_expression OPEN_PAREN_tok CLOSE_PAREN_tok
	| postfix_expression OPEN_PAREN_tok argument_expression_list CLOSE_PAREN_tok
	| postfix_expression PERIOD_tok identifier
	| postfix_expression PTR_OP_tok identifier
	| postfix_expression INC_OP_tok
	| postfix_expression DEC_OP_tok
	;

primary_expression
	: identifier
	| constant
	| string
	| OPEN_PAREN_tok expression CLOSE_PAREN_tok
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list COMMA_tok assignment_expression
	;

constant
	: INTEGER_CONSTANT_tok
	| CHARACTER_CONSTANT_tok
	| FLOATING_CONSTANT_tok
	| ENUMERATION_CONSTANT_tok
	;

string
	: STRING_LITERAL_tok
	;

identifier
	: ID_tok
	;
%%

#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
