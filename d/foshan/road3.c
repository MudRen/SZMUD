// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "�ּ���");
        set("long", @LONG
������һ���ּ����������������ѡ������Ǻ��Ͼ��ڡ�������
������·���пɹ�·����Ϣ��С��ͤ��
LONG
        );
        set("exits", ([
		"south" : __DIR__"road4",
		"north" : __DIR__"road2",
		"east" : __DIR__"chating",
	]));

	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
