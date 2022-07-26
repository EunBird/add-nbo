#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf

int main(int argc,char* argv[]) {

	// 1000 ----- ----- -----
	FILE* fp = fopen(argv[1], "rb");
	

	uint8_t buf[4] = {0,};
	fread(buf, sizeof(uint32_t),4, fp);
    uint32_t* p = reinterpret_cast<uint32_t*>(buf);
	uint32_t n = *p; 

	uint32_t n1 = (n & 0xFF000000) >>24 ;
	uint32_t n2 = (n & 0x00FF0000) >>8 ;
	uint32_t n3 = (n & 0x0000FF00) <<8 ;
	uint32_t n4 = (n & 0x000000FF) <<24 ;
	n = n1 | n2 | n3 | n4 ;

	// 500 ----- ----- -----
	FILE* fp2 = fopen(argv[2], "rb");
	
	uint8_t buf2[4] = {0,};
	fread(buf2, sizeof(uint32_t),4, fp2);
    uint32_t* p2 = reinterpret_cast<uint32_t*>(buf2);
	uint32_t nn = *p2; 

	uint32_t nn1 = (nn & 0xFF000000) >>24 ;
	uint32_t nn2 = (nn & 0x00FF0000) >>8 ;
	uint32_t nn3 = (nn & 0x0000FF00) <<8 ;
	uint32_t nn4 = (nn & 0x000000FF) <<24 ;
	nn = nn1 | nn2 | nn3 | nn4 ;

	printf("%d(0x%x)+%d(0x%x) = %d(0x%x)\n",n,n,nn,nn,n + nn,n + nn);


	return 0;
}
