//Cracked by Roath
// say.c

#include <ansi.h>

inherit F_CLEAN_UP;

string* words = ({
	"���겻��",
	"�ɸ�����",
	"��������",
	"��ͨ���",
	"ս�޲�ʤ",
	"���޲���",
	"�޼᲻��",
	"�޵в���",
	"������ѵ��ʱ������",
	"��Ŀ��磬�����ķ�",
});

int main(object me, string arg)
{
	int i;
	int point, count;
	object *inv;	

	if (!arg) {
		write("���������ﲻ֪����˵Щʲô��\n");
		message("sound", me->name() + "�������ﲻ֪����˵Щʲô��\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("qi") < (int)me->query("max_qi") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}

	if( me->query("family/family_name") == "������" 
	&&  me->query("jing") >= 30
	&&  me->query("jingli") >= 30 ) {

		inv = all_inventory(environment(me));
		if( !sizeof(inv) ) count = 0;
		for(i=0; i<sizeof(inv); i++) {
			if( !me->visible(inv[i]) ) continue;
			if( userp(inv[i]) && inv[i] != me ) count++;
		}

		point = me->query_skill("dulong-dafa", 1);
		for(i=0; i<sizeof(words); i++) {
			if( (strsrch(arg, "�����") >= 0 || strsrch(arg, "�����") >= 0) 
			&& strsrch(arg, words[i]) >= 0 
			&& point <= 100 && point >= 30 
			&& count > 0 ) {
				me->improve_skill("dulong-dafa", random(point*2 + count*10));
				me->receive_damage("jing", random(point*2), "�����ź�������˥�߶���");
				me->receive_damage("jingli", random(point*2), "�����ź�������˥�߶���");
				break;
			}
		}
	}

	if( me->query_condition("say_c") && userp(me)) return notify_fail("����ЪЪ�ɣ�һ����˵��\n");
        if( arg==(string)me->query_temp("last_say_msg") )
                me->add_temp("say_msg_cnt", 1);

        if( living(me) && userp(me))
        {
                me->set_temp("last_say_msg", arg);
        }

	if (me->query_temp("say_msg_cnt") > 20 && userp(me))
	{
		me->apply_condition("say_c", 2);
		return notify_fail("��˵�ķϻ�̫�࣬ЪЪ�ɣ�\n");
	}
	write( CYN "��˵����" + arg + "\n" NOR);
	message("sound", CYN + me->name() + "˵����" +  arg + "\n" NOR,
		environment(me), me);

	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: say <ѶϢ>
 
˵�������и�����ͬһ��������˶���������˵�Ļ���
 
ע: ��ָ����� ' ȡ��.
 
HELP
	);
	return 1;
}
