// Code of ShenZhou
// chchong 2002/02/01
// /d/kaifeng/hhbian.c
inherit FERRY;

void create()
{
    int i;
        set("short", "�ƺӰ���");
        set("long", @LONG
�����ǻƺӰ��ߡ��ƺ����ʵ�����Ѿ��������ٵ���ɳ����ɫ
�ĺ�ˮ�ںӴ��﷭���ţ������ţ�����һ�����޴�����ѡ��򱱾���
�����Ķɿڣ��ڹ����Ĵ�(river)�ߡ�
LONG
        );

        set("exits", ([
                "south" :"/d/huanghe/bank3",
        ]));
        set("item_desc", ([
        "river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
        ]));
        set("resource/water", 1);
        set("outdoors","kaifeng");
        set("cost", 1);
        set("name", "��");
        set("boat", __DIR__"duchuan");
         set("opposite", __DIR__"tiandi2");
        setup();
}

