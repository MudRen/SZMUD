//Cracked by Roath
// Room: /d/beijing/east/majiu5.c

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
  "north" : __DIR__"majiu4",
  "east" : __DIR__"paomachang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
