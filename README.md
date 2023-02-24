# Syntax_Analyzer
Developed a lexical analyzer that can identify lexemes and tokens found in a source code file provided
by the user. Once the analyzer has identified the lexemes of the language and matched them to a token group,
the program prints each lexeme / token pair to the screen.

The source code file provided by the user will be written in a new programming language called “DanC” and is
based upon the following grammar (in BNF):
P ::= S
S ::= V=E | read(V) | print(V) | do { S } while C | S;S
C ::= E < E | E > E | E == E | E <> E | E <= E | E >= E
E ::= T | E + T | E - T
T ::= F | T * F | T / F | T % F
F ::= (E) | N | V
V ::= a | b | … | y | z | aV | bV | … | yV | zV
N ::= 0 | 1 | … | 8 | 9 | 0N | 1N | … | 8N | 9N


Lexeme formation is guided using the BNF rules / grammar above. This application will output each lexeme
and its associated token. Invalid lexemes will output UNKNOWN as their token group. The following token
names are used to identify each valid lexeme:
![image](https://user-images.githubusercontent.com/65064098/221278384-125053ac-6a42-48df-969f-f271951743fa.png)
