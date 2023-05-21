#Arithmetic Expression Tokenizer

This program is a simple arithmetic expression tokenizer written in C. It reads an arithmetic expression from the user, tokenizes it into individual components, and displays the tokens with their corresponding types.

#Table of Contents

Overview
  Token Types
  Token Structure
  Token Binding
  Token Display
  Lexical Analysis
  Main Function
  
#1. Overview
The code provided is divided into several functions to perform different tasks. It starts by reading an arithmetic expression from the user and then passes it to the lexical analysis function. The lexical analysis function tokenizes the expression and creates a linked list of tokens. Finally, the tokens are displayed on the screen, and memory is freed.

#2. Token Types
The program defines three token types using an enumeration: TOK_OPER represents operators like '+', '-', '*', or '/', TOK_NUM represents numeric values, and TOK_PARENTH represents parentheses.

#3. Token Structure
The tokens are stored in a linked list structure defined by the Token structure. Each token has a type (token_type), a value (value), and a pointer to the next token in the list (next).

#4. Token Binding
The bind_token function is responsible for creating a new token, assigning the provided type and value to it, and adding it to the linked list. It allocates memory for the new token using calloc and ensures proper initialization. If the token list is empty, the new token becomes the head; otherwise, it is added to the end of the list.

#5. Token Display
The show_tokens function iterates over the token list and displays each token along with its type.
