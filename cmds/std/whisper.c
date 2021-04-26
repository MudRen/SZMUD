// Code of ShenZhou
// whisper.c
// removed the hacking code, sdong, 6/17/2000
// thanks to acep for finding out the problem.

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dest, msg, mz, hs, cs;
	object ob;
	mixed *args, result;
	int i;

	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("��Ҫ��˭���\n"); 
	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("��Ҫ��˭���\n");
	if ( ob == me )
		return notify_fail("��Ҫ���Լ����\n");
	write( GRN "����" + ob->name() + "�Ķ�������˵����" + msg + "\n" NOR);
    if ( !me->query( "env/invisibility" ) )
	tell_room( environment(me), me->name() + "��" + ob->name()
		+ "����С����˵��Щ����\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, GRN + me->name() + "����Ķ�������˵����" + msg + "\n" NOR);
	return 1;
}

int help(object me)
{
	write( @TEXT
ָ���ʽ��whisper <ĳ��> <ѶϢ>

���ָ�����������ͬһ�����е��˶������ NPC ���ڡ�
TEXT
	);
	return 1;
}
