//Cracked by Roath
// Room: /d/beijing/west/fuyoujie3.c

inherit ROOM;

void create()
{
	set("short", "���ҽ�");
	set("long", @LONG
����һ��Ƨ������ʯ��֣�·��ֻ���������伸�����ˣ�������
��ֵ����־���������ԶԶ������������һ��������ϱ߾����Ͻ�
���ˣ�����ԶԶ���̫�͵�ĵ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"fuyoujie",
  "south" : "/d/beijing/zijin/xichangan",
  "east" : __DIR__"nanhaixian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
