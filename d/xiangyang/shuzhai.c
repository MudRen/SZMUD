// Code of ShenZhou
// Room: /d/xiangyang/shuzhai.c

inherit ROOM;

void create()
{
	set("short", "��ի");
	set("long", @LONG
һ���徲����ի��ľ���ϳ������ķ��ı�����ͷ��������ǹ�
�龭�䣬���������ձ�������һ����īɽˮ�����ⰻȻ��
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 4, "y" : -7 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huajing2",
]));

	setup();
	replace_program(ROOM);
}
