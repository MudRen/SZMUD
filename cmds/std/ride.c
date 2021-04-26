// Code of ShenZhou
// ride.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;

	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->query_busy())
                return notify_fail("����æ���أ�\n");

	if( !ob->is_character() || ob->query("race") == "����")
		return notify_fail("�㲻����ô�ɣ�\n");

	if( !ob->query("ridable") )
		return notify_fail("�ⶫ�������\n");

	if (!living(ob))
		return notify_fail("�ȵ����ѹ�����˵�ɡ�\n");

	if( ob->query_lord() == me ) 
	{
		if( !me->query("rided") )
		{
			if( !ob->query("rider") || ob->query("rider") == me)  
			{
				me->set("rided", ob);
				ob->set("rider", me);
				ob->set_leader(me);

				message_vision("\n$Nһ�����������ݵ�������" + ob->name() +"���ϡ�\n", me);
				return 1;
			}
			else    return notify_fail( (ob->query("rider"))->name() + "�Ѿ������������ˣ�\n");
		}
		else	return notify_fail("���Ѿ�����" + (me->query("rided"))->name() + "���ˣ�\n");
	}
	else return notify_fail("�㲻���������ˣ�\n");

	return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : ride|qi <ĳ����>
 
���ָ�������������ĳһ�����ţ�������ȣ��ӿ������ٶȡ�
 
HELP
	);
	return 1;
}
