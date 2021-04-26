// Code of ShenZhou
// Room: /d/dali/tianlong3.c

inherit ROOM;

void create()
{
	set("short", "ɮ��");
	set("long", @LONG
����Ĳ��ü�򵥵�������������ľ�Ρ���齣�����ɢ
ɢ���ҵķ��˼������š���������Ҳû�б��ʲ��������
��������ɮ���������ڡ�
LONG
	);
	set("cost", 4);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tianlong4.c",
  "north" : __DIR__"tianlong2.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
