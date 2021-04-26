// Code of ShenZhou
// Room: /d/xiangyang/beijie1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ڿ������ı�����ϣ�ȴ����·�Ե��̲����Ǻܶࡣ��������Ľֵ�
��ż�������˴Ҵ�ææ���߹����ϱ���һ���ϴ�Ĺ㳡�����������ǵ����ġ���
����ͨ�������������ڣ�������һ����¥��
LONG
	);
        set("coordinates", ([ "x" : 0, "y" : 2 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"gengloux",
  "south" : __DIR__"guangc",
  "north" : __DIR__"beijie2",
  "west" : __DIR__"jicang",
]));
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
