//Cracked by Roath
//ROOM: dadao_yongan_s.c

inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����ܾ����ĵġ������Ǿ��ǵ������ţ�
���������������Ĵ�·��
LONG
        );
        set("outdoors", "beijing");
        set("exits", ([
                "southwest" : "/d/beijing/yidao2",
                "north" : "/d/beijing/yonganmen",
                "southeast" : "/d/beijing/tanggu",
        ]));
        set("cost", 2);

        setup();
        replace_program(ROOM);
}
