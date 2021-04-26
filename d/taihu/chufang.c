// Code of ShenZhou
// Room: chufang.c
//

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ���ׯ�ĳ�����һ�����¸����������æ��æȥ������������
����ĳ����ˡ�������Ӷ��ˣ��͸Ͽ��ҳ���Ҫ(serve)Щ�Եİɡ�
LONG
	);
	 set("exits", ([
		"south" : __DIR__"huayuan",
	]));


	set("item_desc", ([
	    "table" : "һ�ų����ε�ľ�����������ˮ������ˮ��ʳ�\n",
	    "chair" : "һֻ��ͨ��ľ�ƿ��Ρ�\n",
	]));


	set("objects",([
		__DIR__"obj/mitao" : 1,
		__DIR__"obj/xiangcha" : 2,
		__DIR__"obj/zongzi" : 1,
		__DIR__"obj/jitui" : 1,
	]));

	set("no_fight", 1);

	set("cost", 0);
	setup();
}

void init()
{
	add_action("do_serve", "serve");
}

int do_serve()
{
	object ob1, ob2, *inv, me = this_player();
	int food_ind, water_ind, f, w, i;
	mapping myfam;

	myfam = (mapping)me->query("family");
	if ( !myfam || myfam["family_name"] != "�һ���" )
		return notify_fail("����һ������ӣ�������ȡʳ�\n");

	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
		if (inv[i]->query("drink_supply") && inv[i]->value() >= 0) w++;
	}

	food_ind = me->query("food");
	water_ind = me->query("water");

	if ( (int)me->max_food_capacity()-food_ind < 10
	&& (int)me->max_water_capacity()-water_ind < 10 )
		return notify_fail("���ѳԱ����㣬���ǵȻ����Ҫ�ɣ�\n");

	message_vision("$N�������ЦҪЩʳ��Ժȡ�\n", me);

	if ( (int)me->max_food_capacity()-food_ind >= 40 && !f
	&& !present( "zongzi", environment(me) )
	&& !present( "baozi", environment(me) )
	&& !present( "tao", environment(me) ) ) {
	   switch(random(3)) {
	   case 0:
		ob1 = new(__DIR__"obj/zongzi");
		break;
	   case 1:
		ob1 = new(__DIR__"obj/baozi");
		break;
	   case 2:
		ob1 = new(__DIR__"obj/mitao");
		break;
	   }
		ob1->move(me);
		message_vision("����Ц�Ǻǵ��ó�"+ob1->name()+"��$N��\n", me);
	}
	else if ( (int)me->max_food_capacity()-food_ind >= 40 )
		message_vision("�����$N˵�����㲻���ж������𣿳�����˵�ɡ�\n", me);
	else message_vision("�����$N˵������������ųԣ�̫���ɲ��á�\n", me);

	if ( (int)me->max_water_capacity()-water_ind >= 40 && !w
	&& !present("tea", environment(me)) ) {
		ob2 = new(__DIR__"obj/xiangcha");
		ob2->move(me);
		message_vision("����Ц�Ǻǵ��ó�"+ob2->name()+"��$N��\n", me);
	}
	else if ( (int)me->max_water_capacity()-water_ind >= 40 )
		message_vision("�����$N˵�����㲻���ж������𣿺�����˵�ɡ�\n", me);
	else message_vision("�����$N˵������Ÿպȹ�����ô�ֿ�����\n", me);

	return 1;
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i, f, w;

	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
		if (inv[i]->query("drink_supply") && inv[i]->value() >= 0) w++;
	}

	if ( f>0 || w>0 ) return notify_fail("����������˵�����ż������ǰѶ����������߰ɡ�\n");

	return ::valid_leave(me, dir);
}
