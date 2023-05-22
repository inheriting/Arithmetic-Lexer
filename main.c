#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 20

/* Token Types */

typedef enum {
        TOK_OPER,
        TOK_NUM,
        TOK_PARENTH,
    
} token_type;

typedef struct Token {
        token_type type;
        char value[MAX_TOKEN_LENGTH];
        struct Token* next;
} Token;

void bind_token(Token** head, Token** tail, token_type type, const char* value) {
        Token* new_tok = (Token*)calloc(sizeof(Token),1);

        if (new_tok == NULL) { fprintf(stderr, "Failed whilst allocating memory\n"); exit(1); }

        strncpy(new_tok->value, value, sizeof(new_tok->value) - 1);
        new_tok ->  value[sizeof(new_tok -> value) - 1] = '\0';
        new_tok ->  type = type;
        new_tok ->  next = NULL;

        if (*head == NULL) {
                *head = new_tok;
        }   else {
                Token* current_token = *head;
                while (current_token -> next != NULL) {
                current_token = current_token -> next;
        }
                current_token->next = new_tok;
    }
    
        return;

}

void free_tokens(Token* head) {
        Token* current_token = head;
        while (current_token != NULL) {
            Token* tmp = current_token;
            current_token = current_token -> next;
            free(tmp);
    }
    
        return;
}

void show_tokens(const Token* head) {
        const Token* current_token = head;
        while (current_token != NULL) {

        switch (current_token -> type) {
                case TOK_OPER:          printf("Found <OPER> @ [%s] \n", current_token -> value);              break;
                case TOK_NUM:           printf("Found <NUMB> @ [%s] \n", current_token -> value);              break;
                case TOK_PARENTH:       printf("Found <PARENTH> @ [%s] \n", current_token -> value);           break;
                default:                printf("Found <N/A> @ [%s] \n", current_token -> value);               break;
        }
        current_token = current_token -> next;
    }
        printf("\n");

        return;
}

void lex_expression(const char* expression, Token** head) {
        char* buffer = (char*)calloc(MAX_TOKEN_LENGTH, 1);
        size_t buffer_index = 0;

        for (size_t i = 0; i < strlen(expression); ++i) {
                if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
                        if (buffer_index > 0) {
                                buffer[buffer_index] = '\0';
                                bind_token(head, NULL, TOK_NUM, buffer);
                                buffer_index = 0;
                        }
                        bind_token(head, NULL, TOK_OPER, (char[]){expression[i], '\0'});
                } else if (isdigit(expression[i])) {
                        buffer[buffer_index] = expression[i];
                        ++buffer_index;
                } else {
                        if (isspace(expression[i]))
                                continue;
                        if (expression[i] == '(' || expression[i] == ')') {
                                if (buffer_index > 0) {
                                        buffer[buffer_index] = '\0';
                                        bind_token(head, NULL, TOK_NUM, buffer);
                                        buffer_index = 0;
                                }
                                bind_token(head, NULL, TOK_PARENTH, (char[]){expression[i], '\0'});
                        } else {
                                continue;
                        }
                }
        }

        if (buffer_index > 0) {
                buffer[buffer_index] = '\0';
                bind_token(head, NULL, TOK_NUM, buffer);
        }

        return;
}


int main() {
        char *expression = (char*) calloc(100,1);
        printf(":3 expr: ");
        scanf(" %[^\n]", expression);

        Token* head = NULL;
        lex_expression(expression, &head);
        show_tokens(head);
        free_tokens(head);

        return 0;
}
