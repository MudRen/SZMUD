//Cracked by Xuanyuan
//lingbo.c   �����貨

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

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

int exert(object me, object target)
{

	if( !target ) target = offensive_target(me);
/*
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����貨ֻ�ܶ�ս�����������ܡ�\n");
*/

	if( !me->is_fighting() || !target->is_fighting())
		return notify_fail("�����貨ֻ�ܶ�ս�����������ܡ�\n");

	if( me->query_skill_mapped("force") != "beiming-shengong" )
		return notify_fail("�����õĲ��Ǳ�ڤ�񹦣��޷�ʩչ�����貨��\n");

	if( me->query_skill("beiming-shengong", 1) < 60 )
		return notify_fail("��ı�ڤ�񹦻��δ�����޷�ʩչ�����貨��\n");

	if( me->query_skill("dodge",1) < 100 )
		return notify_fail("�����貨��Ҫ��տ���Ṧ���ף�������Чʩչ��\n");

	if( me->query_skill("lingbo-weibu",1) < 100 )
		return notify_fail("���貨΢����Ϊ���㣬������ʹ�������貨��\n");

	if( me->query_skill_mapped("dodge") != "lingbo-weibu" )
		return notify_fail("�����õĲ��貨΢�����޷�ʩչ�����貨\n");

	if( (int)me->query("jingli") < 400 ) 
		return notify_fail("��ľ������������ﻹ���ܶ��벽��\n");

	message_vision(HIC "\nֻ��$N˫��һ�գ�ʹ���貨΢������ת�һα�������սȦ��������˸������·��ȥ��\n\n" NOR, me, target);

	me->add("jingli", -250);	
	call_out("run_away",0);
	me->set_temp("lingbo",1);
	return 1;
}

void run_away()
{
	object obj, me=this_player();
	object here = environment(me);
	string *dirs,dir,dest,target_dir;
	mapping exit;
	if(!me)return;
	if(!here || !objectp(here) )return;
	if(random(16) != 0) call_out("run_away",0);
	exit = here->query("exits");
	if( !exit ) return;
	dirs = keys(exit);
	dir = dirs[random(sizeof(dirs))];
	if(!dir)return;
	dest = exit[dir];

	if( !dest )return;

	if( !(obj = find_object(dest)) )
		call_other(dest, "???");

	if( !(obj = find_object(dest)) )
		return;

	if( !wizardp(me) && obj->query("short") == "��ʦ��Ϣ��" )
		return;

	if( obj->query("short") == "��ɳĮ" || obj->query("short") == "ɳĮ" || obj->query("short") == "��ͤ" )
		return;

	if( !undefinedp(default_dirs[dir]) )
					 target_dir = default_dirs[dir];
		  else
					 target_dir = dir;

	message( "vision", "ֻ��"+me->name()+"�������ȣ���·���ߣ�һ��񱼣�������ʧ������\n"NOR,environment(me), ({me}));

	if( me->move(obj) ) {
			message( "vision", "ֻ��"+me->name()+"һ����ܹ�����\n" NOR,environment(me), ({me}));
	}

}
