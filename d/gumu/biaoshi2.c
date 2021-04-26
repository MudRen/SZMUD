// /gumu/biaoshi2.c
// July 31,2000
// Code by April
// piao �޸��� 2001/09/22
// update by april 2001.11.11

inherit ROOM;

void create()
{
	set("short","������");

	set("long",@LONG
���������ҵĶ��ǡ���һ�ǳ������Σ�ʯǽ(wall)�������������
����Ҫ����ר�Ź���Ĺ��������֮�á�ʯ��һ�ǻ���һֱ��ʯ��(nian)��
��֪��ʲô�á�
LONG);

	set("item_desc",([
		"wall" : "�����ͨ������(yanxi)ǽ�ϵ�Ҫ��������Լ��İ�����\n",
		"nian" : "�������һЩ��������(nian)������\n"
		]));

	set("exits",([
		"southwest" : __DIR__"liangongshi2"
		]));

	set("cost",1);
	set("count",0);

	setup();

}

void init()
{
	add_action("do_yanxi", "yanxi");
	add_action("do_nian", "nian");
}

int do_yanxi(string arg)
{
	object me = this_player();
	int check;

	if ( !arg ) return notify_fail( "��Ҫ����ʲô?\n");
	if ( arg != "wall" ) return notify_fail( "��Ҫ����ʲô?\n");

	if ( (int)me->query_skill("literate", 1) < 1) 
		return notify_fail("�����ֶ�����ʶ��ô����ѽ��������ѧ���Ļ�(literate)�ɡ�\n");

	check = (int)me->query_skill("throwing",1);
	if ( check * check * check > (int)me->query("combat_exp") * 10)
		return notify_fail ("���ʵս���鲻�㣬��ô����Ҳ������ߣ�\n");

	if ( check < 200)
		return notify_fail("ǽ��Ҫ���Ķ�����˵̫����ˣ�\n");

	if( me->query("potential") < 0 ) return notify_fail("��Ǳ�ܲ��㣬�޷�������ϰ�ˡ�\n");

	if ((int)me->query("jing") < 20 || me->query("jingli") < 20 )
		return notify_fail("���۵���ǽ�ϵ��ֶ���������ˣ�����ЪϢһ�°ɡ�\n");

	me->receive_damage("jing", 15);
	me->receive_damage("jingli", 15);

	message_vision("$N������ǽ�ϵ�Ҫ����ʼ�������ľ��衣\n", me);

	me->improve_skill("throwing", me->query_int()/2);
	me->add("potential", -1);

	if ( query("count") < 20 ) add("count",1);
	else {
		me->start_busy(1);
		set("count",0);
	}
	return 1;
}

int do_nian(string arg)
{
	object me = this_player();
	object ob;

	if ( !arg && arg != "gold" ) return notify_fail( "��Ҫ��ʲô?\n");
	if ( !ob = present("gold",me) )	return notify_fail("������û�лƽ�\n");
	if ( me->is_busy()) return notify_fail("��������æ���ء�\n");
	if ( me->is_fighting()) return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");
	if ((int)me->query_skill("throwing",1) < 60 )
		return notify_fail("��İ���֪ʶ������\n");
	if ( me->query("neili") < 1000 ) return notify_fail("������������\n");
	if ( me->query("jingli") < 500 ) return notify_fail("�㾫��������\n");

	ob->add_amount(-1);
	me->add("jingli", -200-random(100));
	me->add("neili",-500-random(200));

	ob = new("/clone/anqi/jin-zhen");
	ob->set_amount(5);
	ob->move(me);

	message_vision("$Nȡ��һ���ƽ������������ƽ����һöö���롣\n", me);

	me->start_busy(3);
	return 1;
}




