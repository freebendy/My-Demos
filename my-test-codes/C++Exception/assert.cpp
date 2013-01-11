/* debug version */
#undef NDEBUG
//#define NDEBUG
#include <assert.h>
#include <stdio.h>

int main(void)
{
	int i = 0;
	assert(++i == 0);
	//assert(++i != 0);
	printf("i is %d\n", i);
	return 0;
}
/* When run yields
i is 1
*/

