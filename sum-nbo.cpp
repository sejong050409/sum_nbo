#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) 
{
	uint32_t total_sum = 0;
        for (int i = 1; i < argc; i++) 
	{
        	FILE *fp = fopen(argv[i], "rb");
        	if (fp == NULL) 
		{
           		printf("Error : Not Open File");
			return -1;
		}
        	uint32_t n;
       		if (fread(&n, 1, sizeof(uint32_t), fp) < sizeof(uint32_t)) 
		{
            		printf("Error : File Size Is Smaller Than 4 Bytes");
            		fclose(fp);
            		return -1;
        	}
		uint32_t host_n = ntohl(n);
        	printf("%u(0x%08x)", host_n, host_n);
        
        	if (i < argc - 1) printf(" + ");
        
        	total_sum += host_n;
        	fclose(fp);
    	}
	printf(" = %u(0x%08x)\n", total_sum, total_sum);
	return 0;
}
