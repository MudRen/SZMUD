//Cracked by Roath
// Room: /d/beijing/east/zhongtianlou.c

inherit ROOM;

void create()
{
	set("short", "������¥");
	set("long", @LONG
����һ���ߴ��ʯ����¥���������ߣ����Ǳ����ǵ���¥
�ͷ����Ĺ�¥��֣�����Ķ�ֱ�Ŵ����������������������
�ò����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/beijing/west/zhonglou",
  "north" : __DIR__"andingmen",
  "south" : __DIR__"dongzhidajie2",
  "east" : __DIR__"guozijianjie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
