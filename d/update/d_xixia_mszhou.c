// Code of ShenZhou
// Room: /d/xixia/mszhou.c

inherit ROOM;

void create()
{
	set("short", "��ɳ��");
	set("long", @LONG
��ɳ�޾�����ͭϿ�����Σ��������������ɳ���������ô��ڷ�ڣ�ǿ��
�������紵�Ļ�ɳ�����ɡ��������죬��ɳ���ɴ˵�����һ�ߵ�������;���
͸���������ɳ�����������������ۣ������������۾���
LONG
	);
	set("cost", 4);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"qtxia",
  "southwest" : __DIR__"xhbao",
  "east" : "/d/kaifeng/daqiao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
