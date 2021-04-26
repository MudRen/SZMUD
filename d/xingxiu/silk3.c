 // Code of ShenZhou
// /d/xingxiu/silk3.c
// Last Update By Scatter
#include <ansi.h> 
inherit ROOM;

// int do_climb();

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
������ԭ�������ͨ������ɳ����ء����������Ĵ�ɳĮ�ϣ�������
������ǰ���졣��Զ�������������ޱ��޼ʵ�ããɳ���ϣ�����������
ɳ����ʱ������ڿն������Ұ���������أ���Х������һ�����
���������̽���Զ�У�����ɢȥ��
LONG
        );
        set("outdoors", "xingxiuhai");

        set("exits", ([
                "southeast" : __DIR__"silk2",
                "west" : __DIR__"silk4",
       "north" : "/newjob/tiejiang/gate1",
        ]));
        set("item_desc", ([
                "mount" : 
        "����һ����ɳ�ѻ��γɵ�ɽ��΢�紵����ɳɽ�������˵���������\n" 
        "��������Ȼ�����﷢�����Ե���̾��\n"
        ]) );

        set("cost", 2);
        setup();
}


void init()
{
        if(query("exitopen"))
        {
                write(HIY"��ڤ��ʩ�����벻Ҫ�� NORTH��\n Scatter '2002\n"NOR);
        }
        add_action("do_open_men", "open");
        add_action("do_close_men", "close");
}


int do_open_men(string arg)
{
        object ob, me = this_player();
        object room;

        if (query("exits/enter"))
                  return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");

        if (!arg || (arg != "men" && arg != "west"))
                  return notify_fail("��Ҫ��ʲô��\n");

        if ( (string)SECURITY_D->get_status(me) != "(arch)" )
                  return notify_fail("ʲô��\n");

        set("exits/north", "/newjob/tiejiang/gate1");
                set("exitopen", 1);
        message_vision("$N����ָ���һ�㣬֨��һ������һ�����š�\n", this_player());

        return 1;
}

int do_close_men()
{
        if (!query("exits/north"))
                  return notify_fail("�������Ѿ��ǹ��ϵġ�\n");

        delete("exits/north");
        message("vision", "���������ع����ˡ�\n", this_object());
                delete("exitopen");
        return 1;
}
