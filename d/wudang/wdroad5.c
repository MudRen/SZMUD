// Code of ShenZhou
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
        set("outdoors", "wudang");

        set("exits", ([
                "east" : __DIR__"wdroad4",
                "north" : __DIR__"kongdi",
                "northwest" : "/d/emei/emroad6",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
