//Cracked by Roath
// wdroad5.c
// by Xiang

inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����ܾ����ĵġ������������¶��߽��ˡ�������һ
Ƭ�յأ���֪����ʲôʱ����ƽ�������ġ�ңң����ȥ���յ���Χ����ľ��
������ï�ܡ�
LONG
        );
        set("outdoors", "sanbuguan");

        set("exits", ([
                "east" : __DIR__"road5",
                "north" : "/d/taohua/kongdi",
                "northwest" : __DIR__"xroad1",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
