// Code of ShenZhou
//Kane

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���������ɴ��������ɵ����ȣ���Χ�������񣬷�βɭɭ������ϸϸ��
���˾���Ϊ֮һ��ǰ�治֪ʲ��ط�Ʈ��һ���������㲻�ɵ��е���ˣ���������
�ֱ����һ������ӵ���������������ˮ������
LONG
	);
	 set("exits", ([
		"south" : __DIR__"shuilong",
		"north" : __DIR__"chufang",
		"west" : __DIR__"liangong1",
		"east" : __DIR__"liangong2",
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
