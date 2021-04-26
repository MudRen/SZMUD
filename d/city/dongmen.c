// Code of ShenZhou
// Room: /city/dongmen.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "����");
        set("long",
"���Ƕ����ţ��������Ϸ����š�"+YEL"����"NOR+"������������֡���ǽ�����ż��Źٸ�
"+HIW"��ʾ"NOR+"(gaoshi)���ٱ��Ǿ����ע���Ź������ˣ��ò����ϡ����ﳵˮ����������
�������ˡ���Ȼ�����ǳ��ſڣ�����С����Ҳ���������Զ��������ˮ�ġ���
ƻ���ġ�������ϡ���ʳС�㣬����Ҫʲô��ʲô��һ����ֱ����ʯ������
���������졣�����ǽ��⣬������һƬïʢ�������֡�\n"
        );
        set("outdoors", "city");

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));
        set("exits", ([
                "east" : "/d/taishan/yidao",
                "north" : "/d/gaibang/ml1",
                "west" : __DIR__"dongdajie3",
                "south" : __DIR__"dongjiao3",
        ]));

        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
                "/clone/npc/zuo" : 1,
        ]));

        set("cost", 1);
        setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n�㽭�ᶽ\n�����\n";
}
int valid_leave(object me, string dir)
{
        if (dir =="west" )
        if(present("guan bing", (environment(me)))
        && me->query_condition("killer") > 0)
                return notify_fail("�ٱ����еĵ���ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}
