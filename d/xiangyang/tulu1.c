// Code of ShenZhou
// Room: /d/xiangyang/tulu1.c

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
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zhenxi",
  "west" : __DIR__"tulu3",
]));
	set("outdoors", "xiangyang");
	setup();
	replace_program(ROOM);
}
