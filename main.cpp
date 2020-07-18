#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf

void dump(void* p, size_t n) {
	uint8_t* u8 = static_cast<uint8_t*>(p);
	size_t i = 0;
	while (true) {
		printf("%02X ", *u8++);
		if (++i >= n) break;
		if (i % 8 == 0)
			printf("\n");
	}
	printf("\n");
}

void write_4660() {
	uint16_t port = 4660; // 0x1234
	printf("port number = %d\n", port);
	dump(&port, sizeof(port));
}

uint16_t my_ntohs(uint16_t n){
	uint16_t n1 = (n & 0xFF00) >> 8;
	uint16_t n2 = (n & 0x00FF) << 8;
	return (n2 | n1);
}

void  write_0x1234() {
	uint8_t network_buffer[] = { 0x12, 0x34 };
	uint16_t* p = reinterpret_cast<uint16_t*>(network_buffer);
	uint16_t n1 = my_ntohs(*p); // TODO
	uint16_t n2 = my_ntohs(*p);

	printf("16 bit number=0x%x\n", n1);
	printf("16 bit numver=0x%x\n", n2);
}

uint32_t my_ntohs2(uint32_t n){
	return (n & 0xFF000000) >> 24 | (n & 0x00FF0000) >> 8 
	| (n & 0x0000FF00) << 8 | (n & 0x000000FF) << 24;
}

void  write_0x12345678() {
	uint8_t network_buffer[] = { 0x12, 0x34, 0x56, 0x78 };
	uint32_t* p = reinterpret_cast<uint32_t*>(network_buffer);
	uint32_t n1 = my_ntohs2(*p); // TODO
	uint32_t n2 = my_ntohs(*p);
	
	printf("32 bit number=0x%x\n", n1);
}

int main() {
	write_4660();
	write_0x1234();
	write_0x12345678();
}
