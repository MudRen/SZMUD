// Code of ShenZhou
// room: changlang2.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������һ������֮��, ������������, �������续����. ��ʱ
��������ææµµ���߹������ȱ���ͨ����ӥ�����ã��ϱ�����̳��
LONG );

        set("exits", ([
                "north" : __DIR__"zoulang7",
                "south" : __DIR__"zoulang3",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
