// Code of ShenZhou
// Room: /d/dali/nanbei.c

inherit ROOM;

void create()
{
	set("short", "��گ�»���");
	set("long", @LONG
��گ���߷��ڴ����챦��䣬ͬ�������ν�ս�����ƾ�ʮ����
���󣬸��߷��л��⣬Ϊһʱ���񣬡����ǰ�ǣ��������񡱡����ǣ�
������ʰ�ƾ�������ʿ����������֮���Դ���ɡ���ͬʱ������׫�ģ�
����챦ս���Ľ���ͽ������ﲻ���Ѷ����ƵĿ��ԣ������̳ɾ�
�������챦ʮһ����������̫�ͳǹ����⡣
LONG
	);

	set("cost", 2);
       set("fjing", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("exits", ([
		"north" : __DIR__"guandao.c",
		"south" : __DIR__"taihec.c",
		]));

	setup();
}
