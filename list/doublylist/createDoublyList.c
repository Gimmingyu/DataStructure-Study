#include "doublylist.h"

DoublyList	*createDoublyList()
{
	DoublyList	*buf;

	buf = calloc(1, sizeof(DoublyList));
	NULLCHECK(buf);
	return (buf);
}