//Cracked by Roath
// Room: /d/beijing/east/majiu1.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���Ǿ����������ϵ�һ�����ȣ�����жѷ������Ѳ��ϣ�
������һ����ۣ�������һ��ɳ�ء��˴���Ϊ������������
��ƥЪ������֮�á�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"paomachang",
  "north" : __DIR__"majiu2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
