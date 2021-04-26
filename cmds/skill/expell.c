// Code of ShenZhou
// expell.c

#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	string *skname;
	mapping skills;
	int i;

	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("��Ҫ��˭���ʦ�ţ�\n");

	if( !ob->is_character() )
		return notify_fail("���𲻶�����\n");

	if( !userp(ob) )
		return notify_fail("��ֻ�ܿ�����������ݵ����\n");

	if( me->query("family/privs")==-1
	&& (string)me->query("family/family_name")==(string)ob->query("family/family_name")
	|| ob->is_apprentice_of(me) ) {
		message_vision(HIG"\n$N����$n˵�������������أ������Ź棬������������ɣ�", me, ob);
		message_vision("\n$N˵�꣬�������µ���ʿ�߹���������$n��̩ɽ������ȥ��\n\n"NOR, me, ob);

        log_file("Expell",sprintf("[%s] %s(%s)�����ؽ����ִ���\n",ctime(time())[0..15],ob->query("name"),ob->query("id"))); 
		ob->move("/d/taishan/jianyu");
		tell_object(ob, HIC"\n�㱻��Ѻ�����ִ����У�\n\n"NOR);
	} else
		return notify_fail("����˲�����ĵ��ӡ�\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : expell|kaichu <ĳ��>
 
���ָ��������㿪�����ɲŵĵ��ӣ��������ĵ������м��ܶ��ή��ԭ��
��һ�룬�����ۺ�����һ������㣬�����һ�����������һ����������
���ء��Ĵ���������ڿ���һ������֮ǰ����������ǡ�
 
HELP
	);
	return 1;
}
