// Code of ShenZhou
// Jay 7/11/96
inherit ROOM;


void create()
{
    int i;
        set("short", "ɽ��");
        set("long", @LONG
ɽ������һЩ�򵥵������þߣ���ʾ����������˹��ż��ӵ�
����������Ŵ�����˯����
LONG
        );

        set("exits", ([
                "west" : __DIR__"mty1",
        ]));
	set("objects", ([
                "/clone/weapon/tieguo" : 1
        ]));
        set("sleep_room", "1");
        set("no_fight", "1");

	set("cost", 1);
        setup();
        replace_program(ROOM);
}


