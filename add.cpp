#include <stdio.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
	FILE *fd, *dest;
	uint32_t buf_1[1];
	uint32_t buf_2[1];
	fd = fopen(argv[1], "rt");
	dest = fopen(argv[2], "rt");
	fread(buf_1, sizeof(uint32_t), 1, fd);
	fread(buf_2, sizeof(uint32_t), 1, dest);
	fclose(dest);
	fclose(fd);
	uint32_t num_1, num_2;
	num_1 = buf_1[0];
	num_2 = buf_2[0];
	num_1 = htonl(num_1);
	num_2 = htonl(num_2);

	printf("%d(ox%x) + %d(0x%x) = %d(0x%x)\n", num_1, num_1, num_2, num_2, num_1+num_2, num_1+num_2);
}
