//Cracked by Roath
// Room: /d/beijing/east/majiu3.c

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
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"majiu4",
  "south" : __DIR__"paomachang",
  "east" : __DIR__"majiu2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
