// Code of ShenZhou
// Room: /d/dali/nanbei.c

inherit ROOM;

void create()
{
	set("short", "��گ�»���");
	set("long", @LONG
��گ���߷��ڴ����챦��䣬ͬ�������ν�ս�����ƾ�ʮ���򡣹��󣬸���
���л��⣬Ϊһʱ���񣬡����ǰ�ǣ��������񡱡����ǣ�������ʰ�ƾ�������
ʿ����������֮���Դ���ɡ���ͬʱ������׫�ģ�����챦ս���Ľ���ͽ����
��ﲻ���Ѷ����ƵĿ��ԣ������̳ɾޱ������챦ʮһ����������̫�ͳǹ����⡣
LONG);
	set("exits", ([
		"northeast" : __DIR__"guandao.c",
		"south" : __DIR__"taihec.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
