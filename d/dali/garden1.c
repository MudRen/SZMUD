// Code of ShenZhou
// Room: /d/dali/garden1.c

inherit ROOM;

void create()
{
	set("short", "�軨԰���");
	set("long", @LONG
��һ����ɫ��ʯǽ���棬�������Կ���һ���ŵĴ�������
ʯ��ǰվ��һ���ϻ����������ŵ����Ư���ĵ����軨��ζ��
���в���һ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wangfu5.c",
  "enter" : __DIR__"garden2.c",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
