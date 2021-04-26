// Code of ShenZhou
// Room: /d/xiangyang/tulu2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����·���ǳ�����Ĺٵ�������������ս�����²��ϣ������ٸ�Ҳ��������
·�ϸߵͲ�ƽ���洦�ɼ������㳵��̤���Ŀӿ����ݡ�һ���꼾�����α���ˮһ
�壬�������Ţ������
LONG
	);
        set("coordinates", ([ "x" : -7, "y" : -7 ]) );
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"tulu3",
  "east" : __DIR__"ximen",
]));

	setup();
	replace_program(ROOM);
}
