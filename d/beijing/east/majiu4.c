//Cracked by Roath
// Room: /d/beijing/east/majiu4.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���Ǿ����������ϵ�һ����ǣ�����жѷ������Ѳ��ϣ�
������һ����ۣ�������һ��ɳ�ء��˴���Ϊ������������
��ƥЪ������֮�á�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"majiu5",
  "east" : __DIR__"majiu3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
