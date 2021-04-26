// Code of ShenZhou
// ��ׯ
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "��ׯ");
   set("long", @LONG
ׯ԰�Ĵ������ǡ���ׯ���������֡�����(gate)���գ����澲��
�ĵ�һ��������û�С�
LONG
      );

   set("item_desc", 
    	   ([
      	"gate" : 
		"���Ĵ��Ž����ţ�����(knock)���ɡ�\n"
   	   ])
	);

   set("exits", ([ /* sizeof() == 1 */ 
                  "east" : __DIR__"road51", 
                ])
       );
	set("objects", ([
                "/d/city/npc/wolfdog" : 2,
        ]));

	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
}
void init()
{
   add_action("do_knock","knock");
   add_action("do_knock","��");
}

int do_knock(string arg)
{  
   if( !arg || arg=="" ) return 0;
   if( arg=="gate" || arg=="��")
   {			
	message_vision("$N ���ˣ��ˣ��ˣ����������������ţ�������ȴһ�㶯����û�С�\n", this_player());
	return 1;
   }
}

