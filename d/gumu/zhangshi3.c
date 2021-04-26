// /gumu/zhangshi3.c
// copy from /gumu/zhangshi2.c
// motified by April 2001.11.07

#include <room.h>

inherit ROOM;

void create()
{
	set("short","������");

	set("long",@LONG
����������ӹ�Ĺ�����Ƶ�ʯ�ң�ʯǽ(wall)�Ͽ��������ĵ���ᡣ
����ר�Ź���Ĺ������ϰ(yanxi)֮�á�
LONG);

	set("exits",([
		"south" : __DIR__"mudao5",
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
	if ( me->query("gender") != "����" )
		return notify_fail("��ѧ������Ȼ�����ơ�\n");
	if ( arg != "wall" ) return notify_fail( "��Ҫ����ʲô?\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("�����ֶ�����ʶ��ô����ѽ��������ѧ���Ļ�(literate)�ɡ�\n");

	if (me->is_busy()) return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() ) return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if (me->query_skill("yunu-xinjing",1)<25) {
        write("�����Ů�ľ���Ϊ�������޷����Ҫ���ľ��壡\n");
		return 1;
	}

	check = (int)me->query_skill("xiaohun-zhang",1);

	if ( check * check * check > (int)me->query("combat_exp") * 10)
		return notify_fail("���ʵս���鲻�㣬������ô������Ȼ������Ҳ�޷���ߣ�\n");
	
	if( me->query_skill("strike",1) < check * 2/3 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");
		
	if ( check > 200 )
		return notify_fail("ǽ����Ȼ������Ҫ���ľ����㾡��������գ���Ҳ���ܴ���������ˡ�\n");

	if ( me->query("jing") < 40 || me->query("jingli") < 20 
		|| me->query("neili") <20 )
		return notify_fail("���۵���ǽ�ϵ��ֶ���������ˣ�����ЪϢһ�°ɡ�\n");

	me->receive_damage("jing", 30 ,"����ƣ������");
	me->receive_damage("jingli", 15 ,"����ƣ������");
	me->add("neili", -10 );
	message_vision("$N������ǽ�ϵ�Ҫ����ʼ������Ȼ�����Ƶľ��衭��\n", me);

	me->improve_skill("xiaohun-zhang", me->query_int()/2+me->query_skill("strike",1)/2);
		write("����ĥ��һ�������Ȼ����������ˡ�\n");

	if ( query("count") < 20 ) add("count",1);
	else {
		me->start_busy(1);
		set("count",0);
	}

	return 1;
}
	
