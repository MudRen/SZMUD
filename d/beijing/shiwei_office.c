//Cracked by Roath
//
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������ܹܶ�¡���˰칫֮����ʱ�����Կ���������
��������������������ľ���϶����ŵľ��Ƕ��������
LONG
        );

        set("exits", ([
                "south" : __DIR__"jiaochang",
        ]));
        set("objects", ([
                __DIR__"npc/duolong" : 1,
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

