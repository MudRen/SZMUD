// Code of ShenZhou
// Room: /d/shaolin/yidao1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
������Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������߷�
�۶���������һ·���������ϵ��˸������ž�װ���¼��������еĻ����������
��������������ЩЩϰ��Ľ����ˡ���·��������������������֡�
LONG
	);

	set("exits", ([
		"west" : __DIR__"yidao",
		"northeast" : __DIR__"yidao2",
	]));

	set("objects",([
		__DIR__"npc/tangzi" : 2,
              //   "/clone/npc/zuo" : 1,
	]));

	set("outdoors", "taishan");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}



