// Code of ShenZhou
// Room: /d/xiangyang/ting.c

inherit ROOM;

void create()
{
	set("short", "��ҩͤ");
	set("long", @LONG
����λ�ڼ�ɽ�˶˵�һ��Сͤ�ӣ�ͤ�����ٽ����ʸ���бб����
��׾��ɽʯ�����ܳ�����ҩ֮�⣬����ֲ�˹𻨡���������÷�Ȼ�ľ
�������񾲡�
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : -8 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"xiaolu",
]));

	setup();
	replace_program(ROOM);
}
