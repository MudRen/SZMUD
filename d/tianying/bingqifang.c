// Code of ShenZhou
// room: bingqifang.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��������ӥ�̵ı����������ܷ��⼸�������ܣ���������ӥ�̸�
����ƽʱ�����õı�����
LONG );

        set("exits", ([
                "north" : __DIR__"lianwuchang",
        ]));

        setup();
        replace_program(ROOM);
}
