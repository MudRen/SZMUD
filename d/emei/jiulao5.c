// Code of ShenZhou
// jiulao5.c ���϶�
// Shan: 96/06/22

inherit ROOM;

int do_use(string arg);
int do_zuan(string arg);
int do_leave(string arg);

void create()
{
	string *directions; 
	mapping exits;
	int entry = random(8);
	int exit = (entry + random(7) + 1) % 8;
				
        set("short", "���϶�");
        set("long", @LONG
����Ƕ��ҵ�һ�󶴣���������ޱȣ������Ѳ⡣��һ�߽������㷢����
�в�涴�����Թ�������Ī�⣬�ƺ�����޵ס���������������Ȯ����֮����
���˾���䣬��������Ⱥӿ��������Ϩ��档���ǿ���뿪�ɡ�
LONG
        );
        set("objects", ([
                __DIR__"npc/bat": 4]));

	set("hidden_exits", ([
                "northeast": __FILE__,
                "southeast": __FILE__,
                "southwest": __FILE__,
                "northwest": __FILE__,
                "north": __FILE__,
                "west": __FILE__,
                "south": __FILE__,
                "east": __FILE__ 
	]));

	exits = query("hidden_exits");
	directions = keys(exits);
	exits[directions[entry]] = __DIR__"jiulao4";
	exits[directions[exit]] = __DIR__"jiulao6";

	set("cost", 5);
        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_zuan", "zuan");
        add_action("do_zuan", "leave");
}

int do_use(string arg)
{
        object me = this_player();
	object ob = present("fire", me);

        if ( !arg || arg=="" ) return 0;
        if ( !ob )  return 0;
        if( arg=="fire" ) {
             	write("���ȼ���ۣ��Ѷ���������һЩ��\n");
        	set("exits", query("hidden_exits"));
               	message("vision", "��������һЩ��΢���Ļ��һ��һ���ġ�\n", environment(me));
		remove_call_out("fire_out");
		call_out("fire_out", 3, me, ob);
             	return 1;
       }
}


#include "/d/emei/jiulao.h"
