// hell.c

#include <ansi.h>

inherit F_CLEAN_UP;

#include "/u/huaishi/teamlist.h"

int main(object me, string arg)
{
	if ( is_member(me) ){
			me->move("/u/huaishi/hell.c");
			return 1;
		}
	else return 0;
}

