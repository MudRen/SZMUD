// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "����̳");
	set("long", @LONG
�����Ƿ���̨���Ͻǵ�����̳����������̳�Ǹ����εĹ㳡��
���е�������Ƕ��һ���������ƺ�ȫ����ͭ���ɣ�������צ����֮
������������������Ƭ�������⣬��˵ÿһƬ����ս��ɳ���Ľ�ʿ
�����ϻ�á�ǧ��ԩ������������ޱ�������ѹ��̳��
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"fengchan",
		"west" : __DIR__"zhengqi",
	]));

	set("outdoors", "taishan");
	setup();

	replace_program(ROOM);
}


