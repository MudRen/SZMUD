// Code of ShenZhou
// treeup.c 

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
һ���ȳ�֮�������������̧ͷһ������ʱë���Ȼ��һ����ڴ�ϸ�ľ�
�������������ϣ��ſ���ڣ���Ҫ����������
LONG
	);
	set("exits", ([
		"down" : __DIR__"dao9"+(random(4)+6),
	]));
	
	set("objects", ([
		__DIR__"npc/jumang" : 1,
	]));

	set("cost", 3);
	setup();
	replace_program(ROOM);
}
