// Code of ShenZhou
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   object obj, *inv;
   int i, found;

   me->apply_condition("gb_job", duration - 1);

   inv = all_inventory(me);

   for (i=0; i<sizeof(inv); i++) {
		if ( inv[i]->is_container() && present("mihan", inv[i]) ) obj=present("mihan", inv[i]);
		if ( inv[i]->query("id") == "mihan" ) obj = inv[i];
   }

   if ( objectp(obj) && random(me->query("kar")) < 3 && random(40) < 5 ) {
   	switch( random(2) ) {
   	case 0:	
		message("vision", me->name()+"����ͻȻ����һ���š�\n", environment(me), ({me}) );
		break;
   	case 1:
		message("vision", "��������˹���������"+me->name()+"���ϰ���һ���š�\n", environment(me), ({me}) );
		break;
	}

	call_out("let_know", 3, me);	
	destruct(obj);
    }

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

void let_know(object me)
{
	tell_object(me, HIR "������������һ���������ܺ������ˣ�\n" NOR);
}
