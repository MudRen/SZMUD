// Code of ShenZhou
// Room: /city/beidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������ݳǵı����С�һ�����ʱ���������������˼���ˮй��ͨ������
��һ�������¥�󣬹��š�̫���ŷ硱���������Ŷ�������һ�����ң�������¥��
���ֲ�������������������ѧʿ���ֱʡ��������������㴹�����Ρ�������һ
�����ӵ����������ƣ��Ǿ�������ϰ��֮������ͬ�����������ˡ�
LONG
	);
        set("outdoors", "city");

        set("fanhua", 2);
	set("exits", ([
		"east" : __DIR__"zuixianlou",
		"south" : __DIR__"beidajie1",
		"west" : __DIR__"wumiao",
		"north" : __DIR__"beimen",
	]));

	set("objects", ([
                CLASS_D("shaolin") + "/xingzhe" : 1,
	]));

	set("cost", 1);
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir =="west" && this_player()->query("PKS") > 100
	&& this_player()->query_condition("killer") > 0
        && (int)this_player()->query("sg/exp") < 1000 )
	return notify_fail("��ĽŲ�����ͻȻŲ�����ˡ�\n");
        return ::valid_leave(me, dir);
}

