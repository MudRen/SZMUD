// Code of ShenZhou
// Room: /d/shaolin/yidao2.c
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
		"southwest" : __DIR__"yidao1",
		"north" : __DIR__"yidao3",
	]));

	set("objects",([
		__DIR__"npc/shu-sheng" : 1,
	]));

 	set("outdoors", "taishan");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}



