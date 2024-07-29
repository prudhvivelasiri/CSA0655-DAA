#include <stdio.h>
void copyString(char *source, char *destination) {
    if (*source == '\0') {
        *destination = '\0';
        return;
    }
    *destination = *source;
    copyString(source + 1, destination + 1); 
}
int main() {
    char source[] = "cricket";
    char destination[50]; 
    copyString(source, destination);
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    return 0;
}

