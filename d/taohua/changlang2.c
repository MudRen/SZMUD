// Code of ShenZhou
//Kane

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���������ɴ��������ɵ����ȣ���Χ�������񣬷�βɭɭ��
����ϸϸ�����˾���Ϊ֮һ�񡣲�֪ʲ��ط�Ʈ������ҩ�㣬�ƺ���һ
��ҩ����������һ���᷿��������ˮ�������������һ�������Ϣ�ҡ�
LONG
	);
	 set("exits", ([
		"north" : __DIR__"xiuxishi",
		"west" : __DIR__"hyjuchu",
		"east" : __DIR__"shuilong",
		"south" : __DIR__"yaofang",
	]));
/*
	 set("objects", ([
		__DIR__"obj/tiexiao" : 1,
		__DIR__"obj/zhuxiao" : 2,
		__DIR__"obj/yijing3" : 1,
		__DIR__"obj/yijing4" : 1,
	]));

	set("no_fight", 1);
*/
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ( (!myfam || myfam["family_name"] != "�һ���") && dir == "north" )
                return notify_fail("�һ���������ͣ��㲻��ס�����\n");

        if ( me->query("gender") == "����" && dir == "north" )
                return notify_fail("�㲻��ס�����\n");

        return ::valid_leave(me, dir);
}
