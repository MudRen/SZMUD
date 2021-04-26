// Code of ShenZhou
// drive.c ����
#include <ansi.h>
inherit F_CLEAN_UP;
//inherit F_TEAM;

mapping default_dirs = ([
        "north":        "��",
        "south":        "��",
        "east":         "��",
        "west":         "��",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":           "��",
        "down":         "��",
        "out":          "��",
        "enter":        "��",
]);

int main(object me, string arg)
{
	object env, obj, ob;
	string target_dir, dir, dest, victim;
	mapping exit;

	if (!arg) return notify_fail("��Ҫ����˭��\n");

	if( sscanf(arg, "%s %s", victim, dir) != 2 ) return notify_fail("ָ�����\n");

	if ( victim == me->query("id") ) return notify_fail("�αض��һ�٣�\n");

	ob = present(victim, environment(me));
	if (!ob) return notify_fail("���ﲢ�޴��ˣ�\n");
	if (!living(ob)) return notify_fail("�ⲻ�ǻ��\n");
	
//	if (!me->query_temp("curser", 1))
//		return notify_fail("�㲻����ô�ɣ�\n");

    if( ob->query_condition("xs_necromancy") < 0 || !ob->query_temp("block_msg/all", 1) 
		|| (me->query("id") != ob->query("xueshan/necromancy_singer")) )
//	if (!ob->query_temp("cursed", 1) || !ob->query_temp("block_msg/all", 1))
		return notify_fail("�㲻�����ϴ��ˣ�\n");

	if (ob->query("no_get", 1))
		return notify_fail("����˸ϲ��ߣ�\n");
	if (!wizardp(me) && wizardp(ob)) return notify_fail("�󵨣�����ı����ʦ��\n");			

	if (me->query_skill("necromancy", 1) < 30)
		return notify_fail("��Ľ�������򲻹���\n");

	env = environment(me);
	if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) 
		return notify_fail("�޴˷����ȥ��\n");

	dest = exit[dir];

//	if( !(obj = find_object(dest)) )
 //               call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("�޷��ߣ�\n");
	if( !wizardp(ob) && obj->query("short") == "��ʦ��Ϣ��" )
		return notify_fail("�޷��ߣ�\n");

	if( !undefinedp(default_dirs[dir]) )
                target_dir = default_dirs[dir];
        else
                target_dir = dir;

	if ( !me->query("env/invisibility") ) 
		message_vision(HIR "$N��Ц����$n��"+target_dir+"һָ��\n" NOR, me, ob);
	message("vision", HIR "ֻ��"+ob->name()+"ʧ�������Ƶ���"+target_dir+"�뿪��\n" NOR, environment(ob), ({ob}));
	tell_object(ob,"�������Ժ���������������"+target_dir+"�뿪��\n");

	if( ob->move(obj) ) {
		message( "vision", HIR "ֻ��"+ob->name()+"ʧ�������Ƶ����˹�����\n" NOR, environment(ob), ({ob}));
		return 1;
        }

	return 0; 
}
int help (object me)
{
        write(@HELP
ָ���ʽ : drive <����><����>]

���ָ�������ĳ����ĳ���������ϡ�

HELP
);
        return 1;
}
