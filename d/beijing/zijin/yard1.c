//Cracked by Roath
// Room: /d/beijing/zijincheng/yard1.c

inherit ROOM;

void create()
{
	set("short", "��ʯͨ��");
	set("long", @LONG
����һ��������ʯ�����ͨ��,������Ǭ�幬��Ǭ����,ͨ����
�������ϵ����һ���������������.ͨ������������������С
�㳡.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qianqingmen",
  "north" : __DIR__"qianqinggong",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
