// Code of ShenZhou
// Room: /d/taishan/yidao3.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
������Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������߷�
�۶���������һ·��������·��������������������֡�
LONG
	);

	set("exits", ([
		"south" : __DIR__"yidao2",
		"north" : __DIR__"daizong",
	]));

	set("objects",([
		__DIR__"npc/dao-ke" : 1,
	]));

	set("outdoors", "taishan");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}



