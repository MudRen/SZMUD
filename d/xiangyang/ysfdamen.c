// Code of ShenZhou
// Room: /d/xiangyang/ysfdamen.c

inherit ROOM;

void create()
{
	set("short", "Ԫ˧��");
	set("long", @LONG
����ǰһ�����ݣ���ǰ�������ӭ����չ����ͷ��ʯʨ�ֱ����ڴ������ң�
������צ���Ե�ʮ�����䡣�Ŷ���д�����֣������ǡ�Ԫ˧�����ˡ������ٱ���
������ȥѲ�ߣ��䱸ɭ��֮����
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -1, "y" : -4 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"nanjie1",
  "enter" : __DIR__"bingyi",
]));

	setup();
	replace_program(ROOM);
}
