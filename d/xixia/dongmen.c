// Code of ShenZhou
// Room: /d/xixia/dongmen.c

inherit ROOM;

void create()
{
	set("short", "���ݶ���");
	set("long", @LONG
���Ƕ����ţ��������Ϸ����ż����������֡���ǽ
�����ż��Źٸ���ʾ��һ��·������ͨ�����һƬ���֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"luorilin",
  "west" : __DIR__"dongdajie",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
