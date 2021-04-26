// Code of ShenZhou
// ��Ժ���
// Dong  11/03/1996.
// xbc 06/21/97

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   	set("short", HIG"��Ժ���"NOR);
   	set("long", @LONG
�߽�ͤԺ��ֻ���ٺ�һ��С鿡�������һ����(duilian)�� ���
�ۺ���ֻ���ɻ����������������Զ���塣������������ӽ���Ͼ�
���������У���ⲻ����ʱͬ��������Ҷ����̣�ӳ�պɻ������족��
LONG );

   	set("item_desc",  ([
      		"duilian" : 
	    HIG	"	��		��\n"
	    	"	��		��\n"
            	"	��		С\n"
            	"	��		��\n"
	    	"	ˮ		��\n"
	    	"	Ӱ		��\n"
	    	"	��		��\n"NOR
   	   ]));

   	set("exits", ([ /* sizeof() == 1 */ 
  		  "out" : __DIR__"quyuan1",
                ]));

	set("cost", 1);
        set("fjing", 1);
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

