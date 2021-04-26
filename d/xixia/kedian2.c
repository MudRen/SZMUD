// Code of ShenZhou
// Room: /city/kedian2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ����Ĵ�����һ��
�߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������¥�µ��ƹ񴦸���Ǯ������˯����
LONG
	);

	set("exits", ([
		"down" : __DIR__"kedian",
		"enter" : __DIR__"kedian3",
	]));

	set("cost", 1);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
       if(me == present("xiao er"))
		return ::valid_leave(me, dir);
	                       
	if ( !me->query_temp("rent_paid") && dir == "enter" )
		return notify_fail("�������ţ�����ȥ! \n");

	return ::valid_leave(me, dir);
}
