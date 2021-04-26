// /gumu/biaoshi2.c
// July 31,2000
// Code by April
// piao �޸��� 2001/09/22
// update by arpil 2001.11.10

inherit ROOM;

void create()
{
	set("short","������");

	set("long",@LONG
���������ҵ����ǡ���һ�ǳ������Σ�ʯǽ(wall)�������������
����Ҫ����ר�Ź���Ĺ��������֮�á�
LONG);

	set("item_desc",([
		"wall" : "�����ͨ������(yanxi)ǽ�ϵ�Ҫ��������Լ��İ�����\n"
		]));

	set("exits",([
		"northeast" : __DIR__"liangongshi1"
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
	if ( arg != "wall" ) return notify_fail( "��Ҫ����ʲô?\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("�����ֶ�����ʶ��ô����ѽ��������ѧ���Ļ�(literate)�ɡ�\n");

	if (me->is_busy()) return notify_fail("��������æ���ء�\n");
	if( me->is_fighting()) return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	check = (int)me->query_skill("throwing",1);
	if ( check * check * check > (int)me->query("combat_exp") * 10)
		return notify_fail ("���ʵս���鲻�㣬��ô����Ҳ������ߣ�\n");

	if ( check > 200)
		return notify_fail("ǽ��Ҫ���ľ����㾡���������֮�У���Ҳ���ܴ�����ѧ��ʲô��\n");

	if ((int)me->query("jing") < 20 || me->query("jingli") < 20 )
        return notify_fail("���۵���ǽ�ϵ��ֶ���������ˣ�����ЪϢһ�°ɡ�\n");

	me->receive_damage("jing", 15);
	me->receive_damage("jingli", 15);
	message_vision("$N������ǽ�ϵ�Ҫ����ʼ�������ľ��衣\n", me);

	me->improve_skill("throwing", me->query_int()/2);

	if ( query("count") < 20 ) add("count",1);
	else {
		me->start_busy(1);
		set("count",0);
	}
	return 1;
}
