// Code of ShenZhou
// Room: /d/xiangyang/dalao.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "����");
	set("long", @LONG
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ı�����ȥ�������Ҽ�Ӳ��
�ƺ������ôֲڵ�Ƭ���ݶ���ɣ�һ�ſ�ˮ������ǽ�ڹ����������ڵ��ϡ�ֻ��
������һ��С�ţ����Ͽ��˸����ƴ�Ķ��������ͷ��õġ�
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -1, "y" : -3 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"bingying",
]));

	create_door("north", "����", "south", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
