#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strcpy(buffer, "EstoTambienEsDemasiadoLargo");
    printf("Buffer content: %s\n", buffer);
    return 0;
}
