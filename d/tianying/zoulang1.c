// Code of ShenZhou
// room: zoulang1.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ǳ����������ȣ����Ӻ��������û������̴ľ�Ƴɣ�
���������������ͼ�����������ɣ�����ʤ�ա����ȵĶ�����һ����
�
LONG );

        set("exits", ([
                "east" : __DIR__"dadian",
                "west" : __DIR__"zoulang2",
		"north" : __DIR__"changlang1",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
