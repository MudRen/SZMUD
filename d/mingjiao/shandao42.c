// Code of ShenZhou
// Room: /d/mingjiao/shandao42.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
ɽ����������ʯ�ף�ɽ�������˵���Ӳ��Ҳ��ʮ����Ţ��������
ľ���࣬Ұ����ȴ�Ǳ�ء���紵������ɽ����Ӣһ��һ��ظ���������
������������Ұ���������̣��ǻ������ꡣ����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"shanqiu",
  "southwest" : __DIR__"shenwei",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
