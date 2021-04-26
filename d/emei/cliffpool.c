// Code of ShenZhou
// d/emei/cliffpool.c ˮ̶
// xbc: 96/02/02

#include <ansi.h>
inherit ROOM;
int do_climb(string arg);

void create()
{
        set("short", "ˮ̶");
	set("long", @LONG
����һ����ˮ̶��̶��ˮ�����ޱȣ�һ�¾Ͱ��㼤���ˡ�̶ˮ��������
��ȥ������ɽʯ���ͣ�ɽ��������Ρ���֪�����������أ�
LONG
	);
        set("no_clean_up", 0);
        set("outdoors", "emei" );
	set("cost", 6);
	setup();
}

void init()
{
	object me = this_player();
	object *inv;
	int i, flag;
	
	inv = all_inventory(me);	
	flag = 0;
	for (i=0; i < sizeof(inv); i++) {
		if ( !inv[i]->query("armor_prop/armor") ) {
			destruct(inv[i]);
			flag += 1;
		}
	}

	if ( flag ) write(MAG"\n�����ϵ�Ǯ�ﶼ����ˮ�У���Ҳ�Ҳ����ˣ���\n"NOR);

        me->set("water", 2*((int)me->max_water_capacity()));
	write(MAG"�㹾ཹ�������˺ü����ˮ��\n\n"NOR);
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");

}

int do_climb(string arg)
{
	object me = this_player();

	if ( arg && arg != "up" && arg != "an" && arg != "bank")
		return notify_fail("ʲô��\n");

	if ( arg == "up" || arg == "an" || arg == "bank") {
                message_vision("$N������ȥ��\n", me);
       		me->move(__DIR__"qingyin");
                message_vision("$Nˮ���ܵشӽ�������������\n", me);
	        return 1;
	}
	return 0;
}


