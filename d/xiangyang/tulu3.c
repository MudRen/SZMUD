// Code of ShenZhou
// Room: /d/xiangyang/tulu3.c

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
        set("coordinates", ([ "x" : -8, "y" : 0 ]) );
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "westup" : __DIR__"tanxi",
  "southeast" : __DIR__"tulu2",
  "east" : __DIR__"tulu1",
]));

	setup();
	replace_program(ROOM);
}
