// Code of ShenZhou
// unride.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;

	if( !arg 
	|| !objectp(ob = present(arg, environment(me)))
	|| ob != me->query("rided")
	|| ob->query("rider") != me)
		return notify_fail("��Ҫ��ʲô��\n");

	me->delete("rided");
	ob->delete("rider" );
	message_vision("\n$Nһ������" + ob->name() +"����Ծ��������\n", me);

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : unride|buqi <ĳ����>
 
���ָ��������������ĳһ������������������ţ�������ȡ�
 
HELP
	);
	return 1;
}
