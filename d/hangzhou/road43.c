// Code of ShenZhou
// ��·
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "��·");
   set("long", @LONG
·��һ��СϪ��Ϫˮ���������ţ���ʱ�����(fish)Ծ��ˮ�档
Ϫ�Լ����к�������ͷר���ڵ��㡣
LONG
       );
   set("item_desc", 
    	   ([
      	"fish" : 
                "������һ������Ծˮ���������ۡ���һ���ֵ���ˮ������к�һ��ˮ��\n",
   	   ])
	);

   set("exits", ([ /* sizeof() == 2 */ 
                  "northeast" : __DIR__"road42", 
                  "southwest" : __DIR__"road62", 
                ])
       );
                set("objects", ([ "/d/village/npc/boy" : 2]));

   setup();
   replace_program(ROOM);
}
