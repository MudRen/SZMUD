// Code of ShenZhou
// Room: /d/xiangyang/kefang.c

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
����ʱ���б������ã����Էÿ͵��Է�Ҳ��ɨ���������࣬��
���̸Ǿ���һ����Ⱦ��������Լ�����԰�л�Ӱҡҷ��
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 6, "y" : -8 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huilang2",
]));
	set("sleep_room", "1");

	setup();
	replace_program(ROOM);
}
