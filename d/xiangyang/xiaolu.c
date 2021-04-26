// Code of ShenZhou
// Room: /d/xiangyang/xiaolu.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "С·");
	set("long", @LONG
�����ڼ�ɽʯ�Ե�С·�ϣ��ƹ���ɽ��һ�����Ứ԰�����ϱ�
ͨ����ҩͤ��
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 2, "y" : -7 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"huayuan",
  "southeast" : __DIR__"ting",
  "west" : __DIR__"chenhou",
]));
	create_door("west", "С��", "east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
