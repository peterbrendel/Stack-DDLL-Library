#include "main.h"

int solve(char* str, size_t len);
int isOpen(char a);
int isClose(char a);
int matches(char a, char b);

int emptyStack(pStack p); // meu professô n deixou editar o pub, eu so queria add uma funcao de ajuda :´[

int main(int argc, char *argv[]) {
    
    char* answers[] = {
        "FAILED",
        "VALID",
        "INVALID"
    };

    char validStr[] = "if (this.is_valid()) { return answers[TRUE] };";
    char invalidStr[] = "if (this.is_invalid() { return answers[FALSE] };";

    printf("Solving for string \"%s\"\n", validStr);
    printf("Result: %s\n", answers[solve(validStr, sizeof(validStr)) + 1]);

    printf("Solving for string \"%s\"\n", invalidStr);
    printf("Result: %s\n", answers[solve(invalidStr, sizeof(invalidStr)) + 1]);
  
    return 0;
}

int solve(char* str, size_t len) {
    pStack s = NULL;
    if (stack(&s, sizeof(char)) == FAIL) return -1;

    for (size_t i = 0; i < len; i++) {
        char *c = &str[i];

        if (isOpen(*c)) {
            push(s, (void*)c);
            continue;
        }

        if (isClose(*c)) {
            char t;
            pop(s, &t);

            if (!matches(t, *c)) {
                unstack(&s);
                return 1;
            }
        }
    }

    int isEmpty = emptyStack(s);
    unstack(&s);

    return !isEmpty;
}

int isOpen(char a) {
    return a == '(' || a == '{' || a == '[';
}

int isClose(char a) {
    return a == ')' || a == '}' || a == ']';
}

int matches(char a, char b) {
    return (a == '(' && b == ')')
        || (a == '{' && b == '}') 
        || (a == '[' && b == ']');
}
