// Code of ShenZhou
// room: changlang1.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������һ������֮��, ������������, �������续����. ��ʱ
��������ææµµ���߹������ȱ���ͨ����ӥ�����ã��ϱ�����̳��
LONG );

        set("exits", ([
                "north" : __DIR__"zoulang6",
                "south" : __DIR__"zoulang1",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
