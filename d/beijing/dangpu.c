//Cracked by Roath
// Room: �ʳǵ���
// Ssy 

inherit ROOM;

void create()
{
        set("short", "�ʳǵ���");
        set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ����̨��
����һ������(paizi)����̨�������������ӣ��ֱ�����Ÿ�ʽ����(weapon)��
���ߴ���(armor)��ҩ��(drug)�����(book)����������ʽ����(misc)����̨����
�ŵ����ϰ壬һ˫�������۾��������´������㡣��
LONG
        );
        set("no_beg",1);

        set("item_desc", ([
			   "paizi" : "��ƽ���ף�ͯ�����ۡ�\n",
        ]));
        set("objects", ([
			 __DIR__"npc/dpboss" : 1,
        ]));
        set("exits", ([
		       "west" : __DIR__"fuchengdajie_s",
        ]));

        set("cost", 0);
        set("day_shop", 1);
        setup();
        replace_program(ROOM);
}

