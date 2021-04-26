// Code of ShenZhou
// ��̶ӳ��
// Dong  11/03/1996.
// xbc 06/21/1997

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   
	set("short", "����ͤ");
	set("long", @LONG
ֻ������������ɸ��£�ˮ��ͤ¥��Ӱ��һ����紵��������ʹ
��������������ͨ�ģ��ϱ���һ��Сͤ��
LONG);

    	set("exits", ([ /* sizeof() == 2 */ 
        "south" : __DIR__"santan6", 
        "north" : __DIR__"santan4", 
                 ])
       );

	set("cost", 1);
        set("outdoors", "hangzhou");
        set("he_count", 2);
   	setup();
//   	replace_program(ROOM);
}

void init()
{
        add_action("do_pick", "pick");
        add_action("do_pick", "zhai");
}

int do_pick(string arg)
{
        object me = this_player();
        object ob = new("/d/gaibang/obj/heye");

        if ( !arg || arg == "") return 0;

        if ( arg == "he ye" || arg == "��Ҷ" ){
                if (query("he_count") < 1) {
                        tell_object(me, "��ժ����ժ�˼һ�����������Ժ��ɡ��ˣ�\n", me);
                        return 1;
                }
                message_vision("$N�Ӻ���ժ��һƬ��Ҷ����\n", me);
                ob->move(me);
                add("he_count", -1);
                return 1;
        }
        return 0;
}

