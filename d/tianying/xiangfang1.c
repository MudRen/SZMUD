// Code of ShenZhou
// room: xiangfang1.c

inherit ROOM;

void create()
{
        set("short", "���᷿");
        set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������
ֻ���м����һ����ʰ����������Ĵ󴲣����ž�������˯����
LONG );

        set("exits", ([
                "west" : __DIR__"yuanzi",
        ]));

        set("sleep_room", 1);
        set("no_fight", 1);
	set("no_steal",1);

        setup();
        replace_program(ROOM);
}
