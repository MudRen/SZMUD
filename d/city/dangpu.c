// Code of ShenZhou
// Room: /city/dangpu.c
// YZC 1995/12/04 
// Mantian remove Ssy south room path since mirror and @us ppl can't access wiz tree 05/12/2001

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ����̨��
����һ������(paizi)����̨�������������ӣ��ֱ�����Ÿ�ʽ����(weapon)��
���ߴ���(armor)��ҩ��(drug)�����(book)����������ʽ����(misc)����̨��
�������ϰ壬һ˫�������۾��������´������㡣��
LONG
        );
        set("no_beg",1);
        set("no_sleep_room", "1");
        set("item_desc", ([
                "paizi" : "��ƽ����\n",
        ]));
        set("objects", ([
                __DIR__"npc/tang" : 1,
        ]));
        set("exits", ([
                "west" : __DIR__"nandajie1",
//              "south" : "/u/ssy/paimai",
        ]));

        set("cost", 0);
        set("day_shop", 1);
        setup();
        replace_program(ROOM);
}
