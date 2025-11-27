#include <stdio.h>

#define MAX_WORDS 200
#define MAX_WORD_LEN 65

int eh_separador(char c, char *sep) {
    int i = 0;
    while (sep[i] != '\0') {
        if (c == sep[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}

int meu_strlen(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int str_split(char * str, char m[][MAX_WORD_LEN], char * sep) {
    int i = 0;
    int j = 0;
    int cont_palavra = 0;

    while (str[i] != '\0') {
        
        while (str[i] != '\0' && eh_separador(str[i], sep) == 1) {
            i++;
        }

        if (str[i] == '\0') {
            break;
        }

        j = 0;
        while (str[i] != '\0' && eh_separador(str[i], sep) == 0) {
            if (j < MAX_WORD_LEN - 1) {
                m[cont_palavra][j] = str[i];
                j++;
            }
            i++;
        }
        m[cont_palavra][j] = '\0';

        if (j > 0) {
            cont_palavra++;
        }

        if (cont_palavra >= MAX_WORDS) {
            break;
        }
    }
    return cont_palavra;
}

int main() {
    char str[2049];
    char sep[257];
    char m[MAX_WORDS][MAX_WORD_LEN];
    int i;
    int cont;
    int max_len = 0;
    int len;

    scanf("%[^\n]%*c", str);
    scanf("%[^\n]%*c", sep);

    cont = str_split(str, m, sep);

    printf("%d\n", cont);
    
    for (i = 0; i < cont; i++) {
        printf("(%s)\n", m[i]);
        len = meu_strlen(m[i]);
        if (len > max_len) {
            max_len = len;
        }
    }
    
    printf("%d\n", max_len);
    
    return 0;
}