// Code of ShenZhou
// room: zoulang3.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ǳ����������ȣ����Ӻ��������û������̴ľ�Ƴɣ�
���������������ͼ�����������ɣ�����ʤ�ա����ȵ�������һ����
�
LONG );

        set("exits", ([
                "east" : __DIR__"zoulang4",
                "west" : __DIR__"dadian",
		"north" : __DIR__"changlang2",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
