// Code of ShenZhou
// dali kedian

inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
��ҿ͵�������¥�����¥�������ϣ����������ӿͷ��ﲻʱ��
�����Ĵ�����һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������
¥�µ��ƹ񴦸���Ǯ������˯����
LONG
	);

	set("exits", ([
		"down" : __DIR__"dlkd1",
		"enter" : __DIR__"dlkd3",
	]));

	set("cost", 1);
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
