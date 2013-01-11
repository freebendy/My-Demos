#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HTTP_MAX_KEY_LEN 256

void getKey(const char* res,char *ret)
{
	char* pos = strstr(res, "key");

	if(pos !=NULL)
	{
		int i = 0 ;
		while( i < 6 && *pos !='\0' )
		{	
			++pos;
			++i ;
		}
		i = 0 ;
		while(*pos != '\0')
		{
			ret[i] = *pos ;
			++i ;
			++pos ;
		}
		ret[i-2]='\0';
	}
}

int main()
{
	char key[HTTP_MAX_KEY_LEN];
	char *pp = "asdkeyaasdsagggggggg11";
	getKey(pp,key) ;
	printf("%s\n",key) ;

	return 0 ;

}
