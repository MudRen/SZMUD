// Code of ShenZhou
// Room: /d/mingjiao/xiaolu37.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
�˴�Ұ�ݴ��ӣ���·�ѱ棬���ܱ��ߴ��ܼ��������ְ�Χ�š���ϸ��
�����ƺ��к�¡��¡�����������д�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"milin36",
  "northeast" : __DIR__"shenchu",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
