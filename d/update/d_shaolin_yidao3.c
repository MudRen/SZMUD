// Code of ShenZhou
// Room: /d/shaolin/yidao4.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ�
���̣����Ŵ󳵵������Ͼ��Ͽ��������������������ǳ����֡�
��ʱ������������������߷ɳ۶���������һ·��������·����
����������������֡�����ֱͨ���⡣
LONG
	);

	set("exits", ([
		"south" : __DIR__"nanyang",
                "west" : "/d/kaifeng/dongmen",
		"north" : __DIR__"ruzhou",
	]));

	set("outdoors", "shaolin");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}


