// Code of ShenZhou
// Room: /d/xixia/smtan.c

inherit ROOM;

void create()
{
	set("short", "����������̯");
	set("long", @LONG
���ǳ����ﳣ��������������̯�ӣ�����ĳ���ܼ�, ���м�
һ�Ű������������һ����ͼ��������õ���, �Ա߷��ż��ѹ�����
��Ϣ������, �����������ܴ�, ����Զ������鵫������֪�ܵ���
��ȥ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dongdajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
