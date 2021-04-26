// Code of ShenZhou
// Room: chufang.c
// qfy July 7, 1996.

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ܰ��м������Ӻ����ӣ�����̫��ū��æ���շ���ˡ����˵�
���������˴������Σ����ǸϿ��Ҹ�λ�����³Է��Ȳ�(serve)�ɡ�
LONG
	);

	set("exits", ([
                "east" : __DIR__"workroom",
	]));
	
        set("item_desc", ([
	    "table" : "һ�ų����ε�ľ�����������ˮ������ˮ��ʳ�\n",
	    "chair" : "һֻ��ͨ��ľ�ƿ��Ρ�\n",
	]));
	                                

	set("objects",([
                __DIR__"obj/xihulongjing" : 1,
                __DIR__"obj/thfish" : 1,
        //      __DIR__"obj/yrou" : 1,
                __DIR__"obj/santaoya" : 1,
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

        message_vision("$N��λ̫��ūҪЩʳ��Ժȡ�\n", me);

	if ( (int)me->max_food_capacity()-food_ind >= 40 && !f 
        && !present( "yrou", environment(me) ) 
        && !present( "thfish", environment(me) ) 
        && !present( "tao", environment(me) ) ) {
	   switch(random(3)) {
	   case 0: 
                ob1 = new(__DIR__"obj/thfish");
		break;
	   case 1:
                ob1 = new(__DIR__"obj/yrou");
		break;
           case 2:
                ob1 = new(__DIR__"obj/mitao");
		break;
	   }	
		ob1->move(me);
                message_vision("̫��ūЦ�������ó�"+ob1->name()+"��$N��\n", me);
	}
	else if ( (int)me->max_food_capacity()-food_ind >= 40 )
               message_vision("̫��ū��$N˵�����㲻���ж������𣿳�����˵�ɡ�\n", me); 
        else message_vision("̫��ū��$N˵������������ųԣ�̫���ɲ��á�\n", me);
	
	if ( (int)me->max_water_capacity()-water_ind >= 40 && !w 
	&& !present("tea", environment(me)) ) {
                ob2 = new(__DIR__"obj/xihulongjing");
		ob2->move(me);
                message_vision("̫��ūЦ�������ó�"+ob2->name()+"��$N��\n", me);
	}
	else if ( (int)me->max_water_capacity()-water_ind >= 40 )
                message_vision("̫��ū��$N˵�����㲻���ж������𣿺�����˵�ɡ�\n", me);
        else message_vision("̫��ū��$N˵������Ÿպȹ�����ô�ֿ�����\n", me);

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

        if ( f>0 || w>0 ) return notify_fail("̫��ū������˵�����ż������ǰѶ����������߰ɡ�\n");

	return ::valid_leave(me, dir);
}