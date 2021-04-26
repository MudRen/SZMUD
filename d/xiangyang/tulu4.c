// Code of ShenZhou
// Room: /d/xiangyang/tulu4.c

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
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 0, "y" : 7 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hanshuis",
  "south" : __DIR__"qisheng",
]));

	setup();
	replace_program(ROOM);
}
