// Code of ShenZhou
// Room: /d/heimuya/nongshe1.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "ũ��");
        set("long", @LONG
�������һ��Сľ�ݣ�ľ���ڰ���Ϲ��Ÿ��磬��
����ׯ��ũ�˵ķ��ӡ�����������������һ��С����
�����Աߵ�һ����԰��
LONG
        );

        set("exits", ([
                "west" : __DIR__"lake",
        ]));

        set("objects", ([
                __DIR__"npc/yellowdog" : 1,
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

