//Cracked by Roath
//yidao3.c
inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����ܾ����ĵġ���������������ɽ�����ˣ�������
��֮����
LONG
        );
        set("outdoors", "shenlong");
        set("exits", ([
		"west" : __DIR__"chaoyangmen",
        "northeast": "/d/changbai/shguan2",
        ]));
	set("cost", 1);

        setup();
        replace_program(ROOM);
}
