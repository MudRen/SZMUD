//Cracked by Roath
// Room: /d/beijing/kangqin/neijiu.c

inherit ROOM;

void create()
{
	set("short", "�ھ�");
	set("long", @LONG
�������������Ҫ�ɾ��ö࣬���ϲ��������ҲҪ
��ϸ�öࡣ�������˺��ĸɲݡ��Ա������ţ����Ѿ�����
���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"majiu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
