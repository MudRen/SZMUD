// Code of ShenZhou
// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ħ��̲");
	set("long", @LONG
�����߹���������ֲ��ĵش���������һ��ʯ�Ӷ�û�С���䴫
˵���﷢����һЩ��ֵ����顣̲ͷ���ܵ���ľ����һ���᳤�ţ���
����һ��޴�İ��ݴ����ƺ���һ�ɾ޴������Ҫ������̲���
LONG
	);

	set("exits", ([ 
	    "west" : __DIR__"shegu_maze3",
	]));

	if(random(2) == 0)
		set("objects", ([
		    "/clone/money/jinsha" : 1+random(3),
		]));

	set("cost", 2);
	set("hide_snake", 1);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

void init()
{
	object me = this_player();

	if(me->query("race") == "����") return;

	me->set("enter_shegu", 1);
	me->add("jingli", -7);
	me->apply_condition("snake_poison", 100 + me->query_condition("snake_poison") );
	if( query("hide_snake") ) {
		remove_call_out("snake_attack");
		call_out("snake_attack", 3+random(3), me); 
		tell_object(me, HIB"��һ�߽�ħ��̲����ʱ��������˷�������ΪŨ���Ķ��������Ѱ������\n"NOR,);
	}
}

void snake_attack(object me)
{
	object snake, here;
	int i;

	here = this_object();
	i = random(12);

	if ( environment(me) != here) return;

	if ( time() - here->query("last_enter") > 300 )
		add("hide_snake", 1);

	if ( query("hide_snake") < 1 ) return;

	add("hide_snake", -1);
	set("last_enter", time());
	
	if( i == 0 ) snake = new("/d/baituo/npc/lt_snake");
	else if( i == 11 ) snake = new("/d/baituo/npc/cy_snake");
	else snake = new("/d/baituo/npc/pu_snake");

	snake->move(here);

	message("vision", HIR"��ͻȻ����ɳɳ������һ��"+snake->name()+HIR"��ħ��̲�������״ܳ�������һ���ȷ磬��"+me->name()+"�ſ�ҧȥ��\n"NOR, environment(me), me);
	tell_object(me, HIR"����к���ɳɳ��������Ȼ����������һ��"+snake->name()+HIR"��ħ��̲�������Ӵܳ����ſ�����ҧ����\n"NOR);
	COMBAT_D->do_attack(snake, me, snake->query_temp("weapon"));
	snake->kill_ob(me);
}
