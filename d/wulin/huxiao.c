// room /d/wulin/huxiao.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "��Хƺ");
        set("long", @LONG
��Хƺ��һ����̨��С��ƽ�أ�����Ҫ��һ�ζ��͵�ɽ·���ܵ�����
���¡�ÿ�������Ҷ���㣬һ����紵�������ܻ��������ͻ���������
�˲��ɵ�����������ɱ�Ĺ�ս����
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"shanmen",
                "northup" : __DIR__"longyin",
        ]));

        set("objects",([
                __DIR__"npc/yishi" : 1,
        ]));

        set("no_clean_up", 0);      
        set("cost", 1);
        setup();
}
