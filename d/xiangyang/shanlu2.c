// Code of ShenZhou
// Room: /d/xiangyang/shanlu2.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һƬ������ԭ������������Ӳݴ�����ˮ���λ�ʱʱ�ɼ�ս��������
�µĺ��ǡ����Ϯ����һ������֮����Ȼ������
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 1, "y" : 10 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "westdown" : __DIR__"migonglu",
  "northeast" : __DIR__"wangcg",
  "east" : __DIR__"huiguan",
]));

	setup();
	replace_program(ROOM);
}
