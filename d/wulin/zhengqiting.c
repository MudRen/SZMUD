// room /d/wulin/zhengqiting.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
    ����������ͬ�˵�������������ͬ�˷���ʹ��ƽʱ����ɽʱ��ͨ����
�������ﴦ�����ֹ������������з��Űѻ�Ƥ�Σ�����ʹ�߾��������濪
������������Ƿ��񴦡�
LONG
        );

        set("exits", ([
                "south" : __DIR__"xiayitang",
                "north" : __DIR__"dating",
                "east" : __DIR__"fachu",
        ]));

        set("objects",([
                __DIR__"npc/yishi" : 3,
        ]));

        set("no_clean_up", 0);
        set("cost", 2);
        setup();
}
 

