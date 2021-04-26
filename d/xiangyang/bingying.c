// Code of ShenZhou
// Room: /d/xiangyang/bingying.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�������ڱ�Ӫ�У������������鵽�����ǹٱ���Ϊ��Ӧ����ʱ�������ɹŴ�
�������ڴ�ͷ�佫��ָ�����жӼӽ���������ǽ������������������ɫ����Ѱ��
�����ܡ��ϱ߸�ǽ��Ժ����һ������(door)����ǽ֮�¡���ȥ���Ǽ�������˧��
�ĵ�Уʿ̨��
LONG
	);
	set("outdoors", "xiangyang");
	set("no_sleep_room", 1);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -1, "y" : -2 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"bydamen",
  "west" : __DIR__"lianwuc",
  "south" : __DIR__"dalao",
]));

	create_door("south", "����", "north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("�ٱ���ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}