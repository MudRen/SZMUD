// Code of ShenZhou
// Room: /d/xingxiu/xxroad1.c
//Modified by Sure 9/17/2000

inherit ROOM;

void create()
{
        set("short", "���");

        set("long", 
"��ʯ��������������졣���Բ�û��ʲô�ر�ľ��¿���������פ�㡣����
����ԼԼ�Ŀ��Կ������ݳǵĶ�ڡ�����һ��С·ͨ��������������к�����
����һ�㵭���İ���������ø��ӹ��ء�\n"
        );
        set("exits", ([
  "east" : __DIR__"xxroad1",
  "northwest" : "/d/wudang/wdroad2",
                "west" : __DIR__"btroad",
]));
        set("objects", ([ 
            CLASS_D("baituo")+"/jiading" : 2,
        ]));
        set("outdoors", "xingxiuhai");

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
