// Code of ShenZhou
// Room: /d/dali/dlkd2.c

inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
��ҿ͵�������¥�����¥�������ϣ����������ӿͷ��ﲻʱ�غ����Ĵ�
����һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������¥�µ��ƹ񴦸���Ǯ��
����˯����
LONG);
	set("exits", ([
		"down" : __DIR__"dlkd1",
		"enter" : __DIR__"dlkd3",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
}
int valid_leave(object me, string dir)
{
	if(me == present("xiao er"))
		return ::valid_leave(me, dir);

	if ( !me->query_temp("rent_paid") && dir == "enter" )
		return notify_fail("�������ţ�����ȥ! \n");

	return ::valid_leave(me, dir);
}
