// Code of ShenZhou
// Room: /d/heimuya/smallhill1.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "Сɽ��");
        set("long", @LONG
����ƽ�������Сɽ�£������Ǿ��ǻ�ɽҰ�롣��
ɽ����ң���������ƺ����Կ���Զ��ƽ����ϡϡ�����
���̺ͷ��ᡣ
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"road2",
                "northup" : __DIR__"smallhill2",
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

