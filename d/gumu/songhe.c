// songhe.c �ɺ�Ȫ
// by April 01.08.28

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", "�ɺ�Ȫ");
    set("long", @LONG
���ǹ�Ĺ�ڵ�һ����Ȫ��һ�����������Ƶ�Ȫ�ݣ��ӳص׵�ʯ�����
ͻͻ�������ƺ������ݽߣ����粻�ԡ���Ȫ����Ϊ����̶����ȡ�Ի�ǰ
����֮�⡣
LONG
    );
    
    set("exits", ([
		"south" : __DIR__"houtang",
    ]));

	set("cost", 1);
    set("resource/water", 1);

    setup();
}

void init()
{
	add_action("do_wash", "wash");
    add_action("do_drink", "drink");
}

int do_wash(string arg)
{
	object me = this_player();
	if ( !arg || arg != "face" ) return 0;

	message_vision(CYN"$N���������һЩ��Ȫˮϴ��ϴ����\n"NOR, me);

	if ( me->query("gender") == "Ů��" && 
    me->query_skill("beauty", 1) < 150) {
		tell_object(me, CYN"����÷�����һЩ�µ�פ�����š�\n"NOR);
		me->improve_skill("beauty", me->query_per()*2);
		me->receive_damage("jing", 10, "����ϴ�ƣ�������");
	}
	
	return 1;
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<me->max_water_capacity()) {
            me->set("water", current_water+10+random(20));
            message("vision", me->name()+"����һ����Ȫ������ȥ��\n"
            , environment(me), ({me}) );
            write("������һ����Ȫ������ȥ��Ȫˮ����һ���ظ���һ��������ů��Ƣ����Ѫͨ����\n");
        if ((int)me->query("eff_qi") != 
            (int)me->query("max_qi"))
            me->receive_curing("qi", random(10));
        }
        else write("��һ�������˺ö���ҺȪ���Ѿ���Ҳ�Ȳ����ˡ�\n");

        return 1;
}

