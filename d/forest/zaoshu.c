// Code of ShenZhou
// Jay 7/11/96
inherit ROOM;


void create()
{
    int i;
        set("short", "������");
        set("long", @LONG
�����ϵ������ǳ�������ӣ�ɢ�������˵���ζ��
LONG
        );

        set("exits", ([
                "down" : __DIR__"mty1",
        ]));
        set("objects", ([
                __DIR__"npc/obj/zao" : 4,
        ]));

	set("cost", 3);
	set("outdoors", "city");
        setup();
        replace_program(ROOM);
}


