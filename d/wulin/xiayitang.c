// room /d/wulin/xiayitang.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����������ͬ�˵������ã�����ͬ������ʹ��ƽʱ����ɽʱ��ͨ����
��������������ֹ������������з��Ű�̫ʦ�Σ�����ʹ�߾��������濪
����������������ƴ���
LONG
        );

        set("exits", ([
                "south" : __DIR__"zoulang",
                "north" : __DIR__"zhengqiting",
                "west" : __DIR__"shangchu",
        ]));

        set("objects",([
                 __DIR__"npc/yishi" : 3,
        ]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("cost", 2);
        setup();
}
 