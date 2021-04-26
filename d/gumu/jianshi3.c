// /gumu/jianshi3.c
// copy from /gumu/jianshi2.c
// motified by april 2001.11.10

#include <room.h>

inherit ROOM;

void create()
{
	set("short","������");

	set("long",@LONG
����������ӹ�Ĺ��������ʯ�ң�ʯǽ(wall)�Ͽ��������ĵ���ᡣ
����ר�Ź���Ĺ������ϰ(yanxi)֮�á�
LONG);

	set("item_desc",([
		"wall" : "�����ͨ����ϰ(yanxi)ǽ�ϵ�Ҫ��������Լ�������������Ϊ��\n",
		"stone" : "һ�鿴�ƺ���ֵ���ʯ��\n"
		]));
 
	set("exits",([
		"south" : __DIR__"mudao6",
		]));

	set("cost",1);
	set("count",0);
	setup();

}

void init()
{
	add_action("do_yanxi", "yanxi");
}

int do_yanxi(string arg)
{       
	object me = this_player();
	int check;
	if ( !arg ) return notify_fail( "��Ҫ����ʲô?\n");
	if ( arg!="wall") return notify_fail( "��Ҫ����ʲô?\n");

	if ( me->query("gender") != "����" )
		return notify_fail("��ѧ��������������\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("�����ֶ�����ʶ��ô����ѽ��������ѧ���Ļ�(literate)�ɡ�\n");

	if (me->is_busy()) return notify_fail("��������æ���ء�\n");
	if( me->is_fighting()) return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if ( me->query_skill("yunu-xinjing",1) < 25 )
        return notify_fail("����ڹ���Ϊ�������޷����Ҫ���ľ��壡\n");

	if( me->query_skill("sword",1) < me->query_skill("xuantie-jian",1) *2/3 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

	check = (int)me->query_skill("xuantie-jian",1);
	if ( check * check * check > (int)me->query("combat_exp") * 10)
		return notify_fail ("���ʵս���鲻�㣬��ô����Ҳ������ߣ�\n");

	if ( check > 200) 
		return notify_fail("ǽ�ϵ���������Ҫ���ľ����㾡��������գ���Ҳ���ܴ���������ˡ�\n");

	if ((!present("jian",me))&&(!present("sword",me)))
		return notify_fail("������һ�ѽ���û�У��޷����������ϰ����������\n");

	if ( me->query("jing") < 40 || me->query("jingli") < 20 
		|| me->query("neili") < 10 )
		return notify_fail("���۵���ǽ�ϵ��ֶ���������ˣ�����ЪϢһ�°ɡ�\n");
	
	me->receive_damage("jing", 30 ,"����ƣ������");
	me->receive_damage("jingli", 15 ,"����ƣ������");
	me->add("neili", -5);

	message_vision("$N������ǽ�ϵ�Ҫ����ʼ�������������ľ��衭��\n", me);

	me->improve_skill("xuantie-jian", me->query_int()/2 + me->query_skill("sword",1)/2);
	
	if ( query("count") < 20 ) add("count",1);
	else {
		me->start_busy(1);
		set("count",0);
	}
	return 1;
}



