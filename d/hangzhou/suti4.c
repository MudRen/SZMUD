// Code of ShenZhou
// �յ�
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "�յ�");
   set("long", @LONG
����������������ϣ�������ɴ��ȸ������һƬ�������յ̴�
������Ϊ����ʮ��֮�ף���Ȼ�����鴫��������ѹ���ţ���������ɽ
�š�����һƬ÷�֣��ֺ��ƺ�����Ժ�䣬���������С�
LONG
        );

   set("exits", ([ /* sizeof() == 3 */ 
                  "south" : __DIR__"suti5", 
                  "north" : __DIR__"suti3", 
                ])
       );
	set("objects" , ([
                "/d/jiaxing/npc/wuya" : 1,
                "/d/city/npc/maque" : 2,
	]));
        set("fjing", 1);
	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
