//Cracked by Roath
// Room: /d/beijing/east/guandedian.c

inherit ROOM;

void create()
{
	set("short", "�۵µ�");
	set("long", @LONG
�����ǻʵۡ��ʺ�������ʱͣ�ŹײĴ������ܵ��ų����ơ�
��紵�������ҡ�������ܺ�Ӱ�㿣���ı����ϲ�������
һ˿���⡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shouhuangdian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
