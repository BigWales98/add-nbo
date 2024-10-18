#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>

uint32_t read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    uint32_t num;
    size_t read_size = fread(&num, 1, sizeof(num), file);
    if (read_size != sizeof(num)) {
        fprintf(stderr, "Error: Could not read 4 bytes from file %s\n", filename);
        fclose(file);
        exit(1);
    }

    fclose(file);

    // Convert from network byte order to host byte order
    return ntohl(num);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    uint32_t num1 = read_file(argv[1]);
    uint32_t num2 = read_file(argv[2]);
    uint32_t sum = num1 + num2;

    printf("%u (0x%x) + %u (0x%x) = %u (0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}

