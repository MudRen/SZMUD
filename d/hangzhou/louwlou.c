// Code of ShenZhou
// ¥��¥
// Dong  11/03/1996.

//  NTA : Need to add npc here and food.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", HIR"¥��¥"NOR);
    set("long", @LONG
����¥��¥����Բ�������˲�֪�������ʽ�����Ǻ���һ����
���κ������Ƕ�һ���������ﳢ�������������ֺ��ļ����˸�ʽ��
�ȡ���С��������ȥ��æ���к����ˡ�ǽ�Ϲ��ż۸�����(paizi)��
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                   "west" : __DIR__"road21", 
                 ])
       );
	set("objects", ([
                __DIR__"npc/xiaoer2" : 1,
	]));
   set("item_desc", 
    	   ([
      	"paizi" : 
		"������ۺ�����������\n"
		"  ������(pork)\n"
		"  ��������(fish)\n"
		"  ����Ϻ��(shrimp)\n"
		"  �л�ͯ��(chicken)\n"
		"  ��������(soup)\n"
		"  �ٹ��Ͱ�(baozi)\n"
   	   ])
	);

	set("cost", 0);
    setup();
    replace_program(ROOM);
}
