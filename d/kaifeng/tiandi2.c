// Code of ShenZhou
// chchong 2002/02/01
// /d/kaifeng/tiandi1.c
inherit FERRY;

void create()
{
    int i;
        set("short", "���");
        set("long", @LONG
������ľ����ϡ�裬��Զ����Щ��ׯ�������������𡣴�ׯ��Χ
��һ������أ����Ͼ���һ�����η����Ĵ�(river)������������
�������ɴ���������������һ�����������̯����Ҿͽ������ڰ��ߣ�
��������֧һ��ľ�壬���ϰ����˻�������ĺ������㡣
LONG
        );

        set("exits", ([
                "north" : __DIR__"tiandi1",
        ]));
        set("item_desc", ([
        "river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
        ]));
        set("resource/water", 1);
        set("outdoors","kaifeng");
        set("cost", 1);
        set("name", "��");
        set("boat", __DIR__"duchuan");
         set("opposite", __DIR__"hhbian");
        setup();
}

