// Code of ShenZhou
// room: xiangfang3.c

inherit ROOM;

void create()
{
        set("short", "�᷿");
        set("long", @LONG
���ǽ�����Ϣ�ĵط���һ�Ŵ����ڶ��ף���������ɴ�����ӡ���
��һ�ż��Ϲ���һ��������������ͣ��һֻ�����ġ�
LONG );

        set("exits", ([
                "east" : __DIR__"dating",
        ]));

        setup();
        replace_program(ROOM);
}
