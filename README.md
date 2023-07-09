# SSCD-18CSL6
To execute YACC and Lex programs, you can follow the steps outlined below. Please note that this guide assumes you are using a Unix-like operating system, such as Linux.

Installation:

Ensure that Lex (Flex) and YACC (Bison) are installed on your system. If they are not installed, you can use the package manager for your operating system to install them. For example, on Ubuntu, you can run the following commands:
"sudo apt update"
"sudo apt install flex bison"
Write the Lex program:

Create a new file with a .l extension, such as program.l, and write your Lex program in it. Lex programs define lexical analyzers that tokenize input streams.
Here's an example of a simple Lex program that recognizes integers and operators:
%{
#include <stdio.h>
%}

%%
[0-9]+    { printf("INTEGER: %s\n", yytext); }
"+"       { printf("PLUS\n"); }
"-"       { printf("MINUS\n"); }
"*"       { printf("MULTIPLY\n"); }
"/"       { printf("DIVIDE\n"); }
.         { /* Ignore unrecognized characters */ }
%%

int main() {
    yylex();
    return 0;
}
Compile the Lex program:

Open the terminal and navigate to the directory where your Lex program file is located.
Use the following command to compile the Lex program:
"flex program.l"
This command generates a C source file named lex.yy.c based on your Lex program.
Write the YACC program:

Create a new file with a .y extension, such as program.y, and write your YACC program in it. YACC programs define grammars and specify the parsing rules for input streams.
Here's an example of a simple YACC program that recognizes arithmetic expressions using the Lex program we defined earlier:
%{
#include <stdio.h>
%}

%token INTEGER PLUS MINUS MULTIPLY DIVIDE

%%
statement : expression { printf("Valid expression\n"); }
          ;

expression : INTEGER
           | expression PLUS expression
           | expression MINUS expression
           | expression MULTIPLY expression
           | expression DIVIDE expression
           ;

%%

int main() {
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Error: %s\n", s);
    return 0;
}
Compile the YACC program:

Use the following command to compile the YACC program and link it with the Lex-generated C source file:
yacc -d program.y
"gcc -o program y.tab.c lex.yy.c -ly -ll"
This command generates an executable file named program.
Execute the program:

Run the executable by executing the following command:
"./program"
You can then provide input expressions, and the program will recognize and process them based on the grammar and rules defined in your YACC program.
That's it! You now have a basic understanding of how to execute YACC and Lex programs. Feel free to modify the programs according to your requirements and experiment with different input scenarios.


