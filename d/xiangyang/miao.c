// Code of ShenZhou
// Room: /d/xiangyang/miao.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ǣ�һ��ʩ�������ܽǸ��̡�������ǳ������󣬰�̨����
�����ơ���������Ϊ������������Ϊ���ǳ���ƽ�������ڴ˽����Ծ��ġ�
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -2, "y" : 4 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"beijie2",
  "southwest" : __DIR__"mihua",
]));

	setup();
	replace_program(ROOM);
}
