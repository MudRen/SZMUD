// Code of ShenZhou
// Room: /d/dali/yaopu.c

#include <room.h> 
inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ�����ص�ҩ�̣������ڴ�ͽֺ������ĵĽ��紦����ͨ��
��������ƣ��ַ��Ƕ�˵���ҩ�̵�ҩ����ĺܡ���ҩ���ϵļ��ٸ�
С������ɢ��������һ��ŨŨ��ҩζ�����㼸����Ϣ����˵��ҵ���
��һ�ֺ����ܵ�ҩ�
LONG
	);
      set("no_sleep_room", "1"); 
       set("no_beg",1); 
       set("no_steal", 1); 
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hongyao" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road8",
]));

	setup();
	replace_program(ROOM);
}
