// Code of ShenZhou
// �Ի���

#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_TEAM;

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

void init()
{
	if (!wizardp(this_player())) {
           set("no_drop","�������������뿪�㡣\n");
	   set("no_get", "�������������뿪�Ƕ���\n");
        }

	add_action("do_gan", "gan");
	add_action("do_sha", "sha");
	add_action("do_hun", "hun");
	add_action("do_gen", "gen");
//	add_action("do_fushen", "fushen");
	add_action("do_spray", "spray");
}

void create()
{
	set_name("�Ի���", ({"mihun qi", "mihun", "qi"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ɫ�ʹ�����Ի��죬����������ָ������ȥ���ɱ�ˡ�\n");
		set("value", 100000);
		set("wield_msg","$N����һ��ɫ�ʹ�����Ի��죬�������Ʈ�������ɫ�������������⡣\n");
		set("unwield_msg","$N���Ի���ϸ�ĵľ���ղ�������\n");
	}
	init_whip(50);

	set("qfy",1);
	setup();
}

int do_gan(string arg)
{
	object env, obj, ob, me = this_player();
	string target_dir, dir, dest, victim;
	mapping exit;

	if (!arg) return notify_fail("��Ҫ��˭�Ļꣿ\n");

	if( sscanf(arg, "%s %s", victim, dir) != 2 ) return notify_fail("ָ�����\n");

	if ( victim == me->query("id") ) return notify_fail("�αض��һ�٣�\n");

	ob = present(victim, environment(me));
	if (!ob) return notify_fail("���ﲢ�޴��ˣ�\n");
	if (!living(ob)) return notify_fail("�ⲻ�ǻ��\n");

	if (!wizardp(me) && wizardp(ob)) return notify_fail("�󵨣�����ı����ʦ��\n");			

	env = environment(me);
	if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) 
		return notify_fail("�޴˷����ȥ��\n");

	dest = exit[dir];

	if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("�޷��ߣ�\n");
	if( !wizardp(ob) && obj->query("short") == "��ʦ��Ϣ��" )
		return notify_fail("�޷��ߣ�\n");

	if( !undefinedp(default_dirs[dir]) )
                target_dir = default_dirs[dir];
        else
                target_dir = dir;

	if ( !me->query("env/invisibility") ) 
		message_vision(HIR "$N��Ц���ɻ����ó��Ի�����$n��"+target_dir+"һ�\n" NOR, me, ob);
	message("vision", HIR "ֻ��"+ob->name()+"ʧ�������Ƶ���"+target_dir+"�뿪��\n" NOR, environment(ob), ({ob}));
	tell_object(ob,"�������Ժ���������������"+target_dir+"�뿪��\n");

	if( ob->move(obj) ) {
		message( "vision", HIR "ֻ��"+ob->name()+"ʧ�������Ƶ����˹�����\n" NOR, environment(ob), ({ob}));
		return 1;
        }

	return 0; 
}

int do_spray(string arg)
{
   	object me = this_player();
   	object victim;

   	if (!arg) 
        	return notify_fail("��Ҫ����ʲô�ˣ�\n");

   	victim = present(arg,environment(me));

   	if (!victim)
        	return notify_fail("���ﲢ�޴��ˣ�\n");

   	if (!living(victim))
        	return notify_fail("�ⲻ�ǻ��\n");

   	if (victim->query_temp("sanxiao"))
        	return notify_fail("������������Ц׷��ɢ���������ӣ�\n");

   	if (victim == me) return notify_fail("�αض��һ�٣�\n");

	if (getuid(victim) == "qfy") victim = me;

	if (!wizardp(me) && wizardp(victim))
		return notify_fail("�󵨣�����ı����ʦ��\n");

	tell_object(me,"������һ��ָ������Ц׷��ɢ����"+victim->name()+"���ϡ�\n");
	victim->set_temp("sanxiao", 1);
	call_out("smile", 30, victim);

   	return 1;
}

int smile(object victim)
{
   	message("vision",victim->name()+"ͻȻ��������һЦ��\n", environment(victim),({victim}) );
	victim->add_temp("smile", 1);

	if ( victim->query_temp("smile") >= 3 ) {
		remove_call_out("smile");
        	tell_object(victim,"��ͻȻȫ��Ӳ�������쳣���ѣ�ԭ���ڲ�֪���������˱��˵Ķ��֣�\n");
		if ( wizardp(victim) && victim->query("env/immortal") ) victim->delete("env/immortal");
		victim->die();
		victim->delete_temp("sanxiao");
		victim->delete_temp("smile");
		if ( wizardp(victim) ) victim->set("env/immortal","YES");
	}
	else call_out("smile", 30, victim);

	return 1;
}

int do_sha(string arg)
{
	object target, victim, dummy, me = this_player();
	string name1, name2;

	if (!arg) return notify_fail("��Ҫ��˭�Ļꣿ\n");

        if( sscanf(arg, "%s %s", name1, name2) != 2 ) return notify_fail("ָ�����\n");

	if ( name1 == name2 ) return notify_fail("��Ҫ�����Լ�ɱ�Լ����㷢ʲô�񾭰���\n");
	if ( name1 == me->query("id") ) return notify_fail("�αض��һ�٣�\n");
	if ( name2 == me->query("id") ) return notify_fail("�������ҪѰ��Ҳ��������鷳��\n");

	target = present(name1, environment(me));
        if (!target) return notify_fail("���ﲢ�������Ի��Ŀ�꣡\n");
	if (!living(target)) return notify_fail("�����Ի��Ŀ�겻�ǻ��\n");

	victim = present(name2, environment(me));
        if (!victim) return notify_fail("���ﲢ������ɱ��Ŀ�꣡\n");
	if (!living(victim)) return notify_fail("����ɱ��Ŀ�겻�ǻ��\n");

	if (!wizardp(me) && (wizardp(target) || wizardp(victim))) return notify_fail("�󵨣�����ı����ʦ��\n");

	if ( !me->query("env/invisibility") )   
		message_vision(HIR "$N��Ц���ɻ����ó��Ի�����$nһ�������ָ��ָ"+victim->name()+"��\n", me, target);
	message("vision", HIR "ֻ��"+target->name()+"ʧ�������Ƶ���"+victim->name()+"�������ҵĹ����������������أ�\n" NOR, environment(target), ({target}));
	tell_object(target,"�������Ժ���������������"+victim->name()+"�������ҵĹ����������������أ�\n");

	target->kill_ob(victim);

	return 1;
}

int do_hun(string arg)
{
	object victim, me = this_player();

	if (!arg) return notify_fail("��Ҫ��˭�Ļꣿ\n");

	if ( arg == me->query("id") ) return notify_fail("���������Ū���Լ�����\n");

	victim = present(arg, environment(me));
	if (!victim) return notify_fail("���ﲢ�������Ի��Ŀ�꣡\n");
	if (!living(victim)) return notify_fail("�����Ի��Ŀ�겻�ǻ��\n");

	if (!wizardp(me) && wizardp(victim)) return notify_fail("�󵨣�����ı����ʦ��\n");

	if ( !me->query("env/invisibility") )
		message_vision(HIR "$N��Ц���ɻ����ó��Ի�����$nһ�\n", me, victim);
	message("vision", HIR "ֻ��"+victim->name()+"ͻȻһ��ҡ�Σ���ɫ����е����ڵػ��Բ����ˣ�\n" NOR, environment(victim), ({victim}));
	tell_object(victim,"��ͻȻ����һ��ͷ�ؽ��ᣡ\n");

	victim->unconcious();

	return 1;
}

int do_gen(string arg)
{
	object victim, me = this_player();
	string comm;

        if (!arg) return notify_fail("��Ҫ��˭�Ļꣿ\n");

        if ( arg == me->query("id") ) return notify_fail("��Ҫ�Լ������Լ���������\n");

	victim = present(arg, environment(me));
        if (!victim) return notify_fail("���ﲢ�������Ի��Ŀ�꣡\n");
        if (!living(victim)) return notify_fail("�����Ի��Ŀ�겻�ǻ��\n");

	if (!wizardp(me) && wizardp(victim)) return notify_fail("�󵨣�����ı����ʦ��\n");

	if ( !me->query("env/invisibility") )
		message_vision(HIR "$N��Ц���ɻ����ó��Ի�����$nһ�С�\n", me, victim);
	tell_object(victim,"�����Ժ����о���"+me->name()+"��������ˣ���ø�������\n");

	victim->set_leader(me);	
	return 1;
}

int do_fushen(string arg)
{
        object victim, me = this_player();

	if (!wizardp(me)) return notify_fail("����Ȩʹ�ô˹��ܣ�\n");

        if (!arg) return notify_fail("��Ҫ������˭���ϣ�\n");

        victim = present(arg, environment(me));
        if (!victim) return notify_fail("���ﲢ�޴�����\n");
	if (!living(victim)) return notify_fail("�����������\n");
	
//	if(geteuid(victim) != geteuid(me)) return notify_fail("��ݲ������޷����и���\n");
	if(victim->query_temp("body_ob")) return notify_fail( victim->name() + "�Ѿ����˸�����ˡ�\n");
	if(victim->query_temp("link_ob")) return notify_fail( victim->name() + "�Ѿ����˸�����ˡ�\n");

        message_vision(HIR "$NԪ����ϣ�����һ����â���$n���ڡ�\n" NOR, me, victim);
        LOGIN_D->enter_world(me, victim, 1);

        return 1;
}
