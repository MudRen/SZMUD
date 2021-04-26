// Code of ShenZhou
// Room: /d/xiangyang/tulu5.c

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
        set("coordinates", ([ "x" : 2, "y" : 7 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"hanshuis",
  "southeast" : __DIR__"beimen",
]));

	setup();
	replace_program(ROOM);
}
