// Code of ShenZhou
// Room: didao1.c �ص�
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
�����Ǻ������ڵĵص������������ģ�ֻ�м�����Ѳ���ǽ�ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"up": __DIR__"didao",
		"east": __DIR__"didao_e",
		"west": __DIR__"didao_w",
		"north": __DIR__"didao_n",
		"south": __DIR__"didao_s",
]));
	set("no_clean_up", 1);
	set("cost", 1);

	setup();
//	replace_program(ROOM);
}
