//Code of ShenZhou (5/25/2001)
// tell.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(mud, target, me, msg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
	}

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("û�������....��\n");
	if (!wizardp(me) && obj->query_temp("pigging_seat"))
		return notify_fail("���ڹ���������������Ļ�������\n");
	if (!wizardp(me) && wizardp(obj) && obj->query("env/block")=="YES" && obj->query("env/no_block") != (string)me->query("id"))
	return notify_fail(obj->name()+"��æ����ʲô�´������˵�ɡ�\n");
	if (!wizardp(me) && obj->query("env/block") == (string)me->query("id"))
		return notify_fail(obj->name()+"��������������\n");
	if (!wizardp(me) && obj->query("env/block")=="ALL" && obj->query("env/no_block") != (string)me->query("id"))     
        return notify_fail(obj->name()+"���ڲ������˵����\n");

	if (obj==me)
		return notify_fail("�Լ�˵���Լ�����\n");

	if( me->query_condition("tell_c")) return notify_fail("����ЪЪ�ɣ�һ����˵��\n");

	if( me->query_temp("tell_blk")) return notify_fail("��˵��̫�࣬Ъһ�����˵�ɣ�\n");

	if (me->query_temp("tell_cnt") > 10 )
	{
		me->delete_temp("tell_cnt");
		me->set_temp("tell_blk", "yes");
		me->start_call_out( (: call_other, me, "delete_temp", "tell_blk" :), 2 + random(2));
	}

        if( msg==(string)me->query_temp("last_tell_msg") )
                me->add_temp("tell_msg_cnt", 1);

        if( living(me) )
        {
                me->set_temp("last_tell_msg", msg);
		me->add_temp("tell_cnt", 1);
	}

	if (me->query_temp("tell_msg_cnt") > 20)
	{
		me->apply_condition("tell_c", 2);
		return notify_fail("��˵�ķϻ�̫�࣬ЪЪ�ɣ�\n");
	}

	write(GRN "�����" + obj->name(1) + "��" + msg + "\n" NOR);
	tell_object(obj, sprintf( GRN "%s�����㣺%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;
	
	if( ob = find_player(to) ) {
		if( wizardp(ob) && ob->query("env/block")=="YES" )
			return 0;
			
		if( ob->query("env/block")=="ALL" )
    		    return notify_fail(ob->name()+"���ڲ������˵����\n");

		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)ǧ�ﴫ�������㣺%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s �����㣺%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��tell <ĳ��> <ѶϢ>

����������ָ��������ط�������վ���ʹ����˵����

�������ָ�reply, mudlist
HELP
	);
	return 1;
}
