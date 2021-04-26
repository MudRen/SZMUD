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
����֮ҹ�����¹ۺ��������������ԣ�����΢�磬���й���Ʈ�㣬
����Ϊ֮�����̱߲���С�������ο�ȥ��̶ӳ�µġ���������ȥ
���ۣ�����ɼ���̶ӳ��ң�����У������������ţ�����ӳ���š�
LONG        );

   set("exits", ([ /* sizeof() == 4 */ 
                  "south" : __DIR__"suti7", 
                  "north" : __DIR__"suti5", 
		  "west"  : __DIR__"huagang1",
                ])
       );
	set("cost", 1);
        set("fjing", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
