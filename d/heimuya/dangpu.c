// Code of ShenZhou
// Room: /d/heimuya/dangpu.c
// fear 1999/12/08 

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������ϵ�һ�ҵ��̣���̨�ϰ���һ������(paizi)��
��̨����ֱ�����Ÿ�ʽ����(weapon)�����ߴ���(armor)��
ҩ��(drug)�����(book)����������ʽ����(misc)�Ĺ��ӡ�
��̨�����Ű��ϰ壬һ˫�������۾��������´������㡣��
LONG
        );
        set("no_beg",1);
		set("no_sleep_room", "1");
        set("item_desc", ([
                "paizi" : "��ƽ����\n",
        ]));
        set("objects", ([
                __DIR__"npc/bai" : 1,
        ]));
        set("exits", ([
                "west" : __DIR__"northstreet1",
        ]));

        set("cost", 0);
        set("day_shop", 1);
        setup();
        replace_program(ROOM);
}

