// Code of ShenZhou
// Room: /d/xiangyang/bingqidian.c

inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
�����Ǳ����⣬�������������������ۻ����ҡ��������������𹿰�����
�����������ڰ����̵����̽����̹�����ɫ�����ı���Ӧ�о��У���һʱ��֪
����ʲô�á�
LONG );
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : 4, "y" : 5 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jzjie3",
]));

	setup();
	replace_program(ROOM);
}
