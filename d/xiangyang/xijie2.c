// Code of ShenZhou
// Room: /d/xiangyang/xijie2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����Ĵ����·������Ǭ��������������ʯ�������ֱȥ��ɵ���
���š�������һ���ž���С·��ͨ���׻��֡��ϱߴ���������ź�����ʿ����֮
���������š�
LONG
	);
        set("coordinates", ([ "x" : -5, "y" : 0 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xiaoshi",
  "north" : __DIR__"mihua",
  "east" : __DIR__"xijie1",
  "west" : __DIR__"zhenxi",
]));
	set("outdoors", "xiangyang");
	set("no_sleep_room", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
