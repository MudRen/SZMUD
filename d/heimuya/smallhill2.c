// Code of ShenZhou
// Room: /d/heimuya/smallhill2.c
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
                "northeast" : __DIR__"lake",
                "northdown" : __DIR__"eastgate",
                "southdown" : __DIR__"smallhill1",
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

