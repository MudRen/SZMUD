//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "�����ʿԺ");
        set("long", @LONG
��������������ɮ��������ڣ�����Ժ������ʯ�̵أ�
�ڷ�϶��������ϸ��ɳ��ʯ����ƽ�������һ�����ӿ�����
�ػ��羵��
LONG
        );
        set("objects", ([
"/d/shaolin/obj/mu-ren" : 1,
        ]));

        set("exits", ([
		"west" : __DIR__"tianls9.c",
        "north" : __DIR__"tianls12",
        "south" : __DIR__"tianlong2",		]));
    set("cost", 1);
        setup();
        replace_program(ROOM);
}

