// Code of ShenZhou
// changle/clguibin.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
���ǳ��ְ�Ĺ����Ϣ�ң�ʮ�ֵĻ�����
LONG );
        set("exits", ([
		"east" : __DIR__"clhoulang3",
        ]));

	
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_steal", 1);

        set("cost", 0);

        setup();

        // replace_program(ROOM);
}



