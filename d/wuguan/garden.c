//Created by Zyu on k1-08-13
// road: /d/wuguan/garden.c

inherit ROOM;

void create()
{
        set("short", "��ݻ�԰");
        set("long", @LONG
���������ݵĻ�԰�ˡ��ʻ��ڿ��ţ���ľ�ڳ�֦������ڸ質����
�е��Լ�������һ�����ˡ�һ��С���ӻ�԰�����������������㼣����
ʧ����ס�����ߵ���ľ�����Ƕ�����ʲô�أ�
LONG
        );
        set("outdoors", "wuguan");
        set("item_desc", ([
        ]));

        set("objects", ([
                 __DIR__"obj/shizi" : 1,
                 __DIR__"obj/flower1" : 1,
                 __DIR__"obj/flower2" : 1,
                 __DIR__"obj/flower1" : 1,
        ]));

        set("exits", ([
                "north" : __DIR__"gardeno",
                "east" : __DIR__"gardeni",
        ]));

        set("cost", 1);
        setup();
}