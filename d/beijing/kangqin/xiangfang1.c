//Cracked by Roath
// Room: /d/beijing/kangqin/xiangfang1.c

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
�����ǿ�������������ʦ��ס�ĵط�����������費
�࣬������ȫ�����ﾭ������������ɨ������������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xiaoyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
