// Code of ShenZhou
// Room: /d/xiangyang/xiansi.c

inherit ROOM;

void create()
{
	set("short", "��˾��");
	set("long", @LONG
���μ������̰��죬�ƹ�һ·˾��������μ��������ԩ������˾����
����һ��������ר�������ĸ壬������˾�˳���������������֪�����¡�����
�ƺ��������ã�Ȼ�����ǳ������ܽ�ȥ�ġ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ysting",
  "out" : __DIR__"anfushi",
]));
        set("objects", ([
               __DIR__"npc/wenhuan" : 1, 
        ]));
	setup();
	replace_program(ROOM);
}
