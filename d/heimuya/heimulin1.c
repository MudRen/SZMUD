// Code of ShenZhou
// Room: /d/heimuya/heimulin1.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "��ľ�ֱ�");
        set("long", @LONG
���������ֵı�Ե�����ֱ߿�����������Ũ�ܸߴ�
����ľ����˵������и�������֮ɥ�������ޣ��к�
�������﷥ľ���Է���ʧ�������Ҳû�л�ȥ�ˡ�
LONG
        );

        set("exits", ([
                "west" : __DIR__"forest",
                "northeast" : __DIR__"heimulin2",
        ]));

        set("objects", ([
                "/clone/beast/deer" : 1,
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

