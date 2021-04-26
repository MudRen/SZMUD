// Code of ShenZhou
// Room: chufang.c
// qfy August 22, 1996.

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ܰ��м������Ӻ����ӣ����������Ӻ�Ѿ����æ���շ���ˡ�����
���������Ʈ�ͣ���Զ�����ŵ������˴������Ρ���Ҫ��Զ���������������
Ҫ(serve)�����ˮ���Ը���������ľ�ȥ��(fill)��
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"zoulang2",
	]));
	
        set("item_desc", ([
	    "table" : "һ�ų����ε�ľ�����������ˮ������ˮ��ʳ�\n",
	    "chair" : "һֻ��ͨ��ľ�ƿ��Ρ�\n",
	]));
	                                

	set("objects",([
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
	int food_ind, f, i;

	if ( !me->query_temp("mark/��") )
		return notify_fail("�����ݵ��ӣ�������ȡʳ�\n");

	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
	}

	food_ind = me->query("food");

	if ( (int)me->max_food_capacity()-food_ind < 10 )
		return notify_fail("���ѳԱ����㣬���ǵȻ����Ҫ�ɣ�\n");	

	message_vision("$N��λ������ҪЩʳ��Ժȡ�\n", me);

	if ( (int)me->max_food_capacity()-food_ind >= 40 && !f ) {
	   switch(random(2)) {
	   case 0: 
		ob1 = new(__DIR__"obj/zongzi");
		break;
	   case 1:
		ob1 = new(__DIR__"obj/dianxin");
		break;
           case 2:
		ob1 = new(__DIR__"obj/tangbao");
		break;
	   }	
		ob1->move(me);
		message_vision("�����ӵ��ó�"+ob1->name()+"��$N��\n", me);
	}
	else if ( (int)me->max_food_capacity()-food_ind >= 40 )
		message_vision("�����Ӷ�$N˵�����㲻���ж������𣿳�����˵�ɡ�\n", me); 
	else message_vision("�����Ӷ�$N˵������������ųԣ�̫���ɲ��á�\n", me);
	
	return 1;
}

int valid_leave(object me, string dir)
{
	int i, f;
	object *inv;
	
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
        }

	if ( f>0 ) return notify_fail("Ѿ��������˵�����ż������ǰѶ����������߰ɡ�\n");

	return ::valid_leave(me, dir);
}
