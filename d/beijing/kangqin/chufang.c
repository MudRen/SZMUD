//Cracked by Roath
// Room: /d/beijing/kangqin/chufang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǿ��������ĳ������������ִ�һ�Ų����˰ˣ��ſڴ������������ŷ��˸���
׼�����˵İ��Ʒ��ֻ�����¹��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"garden.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
