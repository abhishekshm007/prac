#include<stdio.h>
char *int2bin(int a, char *buffer, int buf_size) {
    buffer += (buf_size - 1);
int i;
    for (i = 31; i >= 0; i--) {
        *buffer-- = (a & 1) + '0';

        a >>= 1;
    }

    return buffer;
}

#define BUF_SIZE 33

int main() {
    char buffer[BUF_SIZE];
    buffer[BUF_SIZE - 1] = '\0';


    int a = -8;
    unsigned u = -8;
    int2bin(a, buffer, BUF_SIZE - 1);

    printf("a = %s", buffer);

    printf("\n");
    int2bin(u, buffer, BUF_SIZE -1 );

    printf("u = %s", buffer);

    printf("\n");
}
