// Code of ShenZhou
// practice.c
// Modified by xQin 04/01 to fix the negative value bug

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object where = environment(me);
	string skillarg, skillname, skillzhao, multiple;
	int times,skill, skill_basic, qi;

	seteuid(getuid());

	if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (where->query("sleep_room"))
					 return notify_fail("��˯���ﲻ�����������Ӱ�����ˡ�\n");

	if (where->query("no_fight"))
					 return notify_fail("���ﲻ�������ĵط���\n");

	if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if( arg=="parry" )
		return notify_fail("�㲻��ͨ����ϰ�м����������ܡ�\n");

	if( !arg ) return (__DIR__"enable")->main(me, arg);

	if(sscanf(arg, "%s %d", skillarg, times)!=2 )
		skillarg = arg;

	if( skillarg=="parry" )
                return notify_fail("�㲻��ͨ����ϰ�м����������ܡ�\n");

	if(!times || times == 0) {
		times = 1;
		multiple="";
	}
	else	multiple="����";

	if(!stringp(skillname = me->query_skill_mapped(skillarg)) )
		return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

	skill_basic = me->query_skill(skillarg, 1);
	skill = me->query_skill(skillname, 1);

	if( skill < 1 )
		return notify_fail("�����û��ѧ������ܰɣ������ȥ��̱��ˡ�\n");
	if( skill_basic < 1 )
		return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
	if( skill_basic/2 <= skill/3 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

	notify_fail("�����ڲ�����ϰ����ܡ�\n");
	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

	notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");
	
	if(times < 0 ) return notify_fail("��Ҫ��ʲô��\n");
	
	for(times; times > 0; times--) {
		if( SKILL_D(skillname)->practice_skill(me) )
			me->improve_skill(skillname, skill_basic/5 +1, skill_basic > skill? 0: 1);
		else return 0;
	}

	if(skillzhao = SKILL_D(skillname)->query_skill_name(me->query_skill(skillname, 1)))
		message_vision( "$N" + multiple + "��ϰ��" + to_chinese(skillname) + "�еġ�" 
				+ skillzhao +"����һ�У�������Щ������\n", me);
	else 
		message_vision( "$N" + multiple + "��ϰ��" + to_chinese(skillname) + "��������Щ������\n", me);
	return 1;
}

int help(object me)
{
	write(@TEXT
ָ���ʽ��practice|lian <��������> <��ϰ����> 

���ָ��������ϰ����ĳ������ļ��ܣ�������ܱ����Ǿ��� enable ��רҵ���ܡ�

�������ⷽ��Ļ������ܹ��ߣ����Ծ�����ϰֱ����������������������ֻ��
��������ܵĵȼ��йأ����仰˵���ڼ���ϰ��ʹ�����ѧ���������ʤ������
��Ψһ;������Ȼ������֮ǰ������ʵ�������л���㹻�ľ�����������Ļ�
�����ܡ�
TEXT
	);
	return 1;
}
