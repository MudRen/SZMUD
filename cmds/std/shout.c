// shout.c
// Open to Players by Buwu.
#include <ansi.h>

inherit F_CLEAN_UP;

#define SHOUT_LIST      ({ })
int main(object me, string arg)
{
        if (!arg) return notify_fail("����Ҫ���ʲô��\n");
	if (!wizardp(me)) 
		{
		if ((me->query("jingli") < 3000) || (me->query("neili") < 4000))
			return notify_fail("����ͼ����Х��ȴ�����Լ������̵�������û�С�\n");
                me->set("jingli",random(500));
                me->set("neili",random(500));
	    shout(HIW + "��"+me->name() + "ʹ�����̵���������������" + arg + "\n" + NOR);
	    write(HIW +"����ʹ�����̵���������������" + arg + "\n" + NOR);
		}
	if (wizardp(me)) 
		{
	shout(HIY + "��"+ me->name() + "������Х��" + arg + "\n" + NOR);
    write(HIY +"����������Х��" + arg + "\n" + NOR);
		}
        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : shout <ѶϢ>
 
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶�
��������Ļ��������Ҫ�߱�������ǧ��������ǧ������
����ʹ�ú󣬽����ĵ����󲿷ֵľ�����������
 
HELP
    );
    return 1;
}
