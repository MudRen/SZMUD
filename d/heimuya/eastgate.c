// Code of ShenZhou
// Room: /d/heimuya/eastgate.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "ƽ���ݶ���");
        set("long", @LONG
������ƽ���ݵĶ��ţ�ƽʱ�������ﲻ����������
�������Ϸ���һƬɽ�£���һ������С����ɽ�����Ѷ�
�ϡ�
LONG
        );

        set("exits", ([
                "west" : __DIR__"eaststreet2",
                "southup" : __DIR__"smallhill2",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

