// Code of ShenZhou
// room: road1.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
�����ǰ����һ����������ʯ·��ֱͨ���㳡�������������д�
�����֣���ʱ����������У����˶�ʱ�����泩����ʯ�����ѱ�ĥ��
���ǹ⻬����������ľá�
LONG );

        set("exits", ([
                "north" : __DIR__"guangchang",
                "south" : __DIR__"damen",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
