// Code of ShenZhou
// Room: /d/xiangyang/dongjie1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����������ʯ�����ֱ���������ȥ�������������壬·��������
�ࡣ����һ��ׯ�ϵĸ�Ժ����������Ϲ��ſ���ң�����д�š�����ʹ�����ĸ�
�̽���֣���ǰվ�Ų��ٻ���������ȥ�������Ƽ����ʵĸ�¥��
LONG
	);
	set("no_sleep_room", 1);
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : 1, "y" : 0 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"dongjie2",
  "west" : __DIR__"guangc",
  "south" : __DIR__"anfushi",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
