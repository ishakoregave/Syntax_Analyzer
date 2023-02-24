# Syntax_Analyzer
Developed a lexical analyzer that can identify lexemes and tokens found in a source code file provided
by the user. Once the analyzer has identified the lexemes of the language and matched them to a token group,
the program prints each lexeme / token pair to the screen.

The source code file provided by the user will be written in a new programming language called “DanC” and is
based upon the following grammar (in BNF):
![image](https://user-images.githubusercontent.com/65064098/221278690-1a76a76d-25fb-4a3a-8909-d8ca837918ad.png)



Lexeme formation is guided using the BNF rules / grammar above. This application will output each lexeme
and its associated token. Invalid lexemes will output UNKNOWN as their token group. The following token
names are used to identify each valid lexeme:
![image](https://user-images.githubusercontent.com/65064098/221278384-125053ac-6a42-48df-969f-f271951743fa.png)
