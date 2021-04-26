// Code of ShenZhou
// niuxin.c ţ��ʯ
// haowen 10/10/00 add busy check in jump
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ţ��ʯ");
	set("long", @LONG
����Ŵ����ǿ�ں�ɫ�ľ�ʯ���������������ڴ˺�����ˮ��ţ�ģ�
�˻��ɽ�������ɽ�ȡ������ڴˣ���������֮ˮ�ӽ��±��ڶ�����������
��ɵ������ȷ��������Գ֡�
LONG
	);

        set("outdoors", "emei" );
	set("cost", 2);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_dazuo", "dazuo");
}

int do_jump(string arg)
{
	object me = this_player();
	if ( !arg || (arg != "back" && arg != "bank" ) )
		return 0;
	if(me->is_busy())
		{
             	tell_object(me,"��������æ���أ�\n");    
		return 0;
		}
	message_vision("$N����һ������һ�����򰶱���ȥ��\n", me);
	me->move(__DIR__"qingyin");
	message("vision", me->name() + "����һ��������ţ��ʯ�����˻�����\n",
		environment(me), ({me}) );
	
	return 1;
}

int do_dazuo(string arg)
{
	object me, where;
	string force_skill;
	int exercise_cost, level;
	me = this_player();
	where = environment(me);
	seteuid(geteuid(me));

	if (me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("ս���в������ڹ������߻���ħ��\n");

        if( !stringp(force_skill = me->query_skill_mapped("force")) )
                return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");

        if( !arg || !sscanf(arg, "%d", exercise_cost))
                return notify_fail("��Ҫ��������������\n");
        if (exercise_cost < 10)
                return notify_fail("����ڹ���û�дﵽ�Ǹ����磡\n");

        if( (int)me->query("qi") < exercise_cost )
                return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");

        if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
                return notify_fail("�����ھ��������޷�������Ϣ��������\n");

	level = me->query_skill("linji-zhuang", 1);

	if ( force_skill == "linji-zhuang" 
	  && level >= 30 && level < 105 
	  && me->query("combat_exp") > level*level*level/10 
	  && SKILL_D(force_skill)->valid_learn(me) ) {
		me->improve_skill("linji-zhuang", 
			random(me->query_int()+me->query_con()) );
		me->add("jing", -20-random(20));
		tell_object(me, HIY"�˴�������������ʮ��ׯ����֮�����ศҪּ�����κ������У�\n��ԡ��ټ�ʮ��ׯ����������\n"NOR);
	}
	return 0;
}
