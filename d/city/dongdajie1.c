 // Code of ShenZhou
// Room: /city/dongdajie1.c
// YZC 1995/12/04  
// Last Modify by Scatter
#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣���߲�ʱ�ش�������ײ������
�����������ӡ�������һ�����ӵ�Ժ�ӣ������εĴ����Ϸ�д�š���¹��Ժ����
���̽���֣��Ծ����������治ʱ�ش���ѧ��������ٴ�Ķ��������ϱ���һ��
�ӻ��̡�
LONG
        );
        set("outdoors", "city");
              set("fanhua",1); 

        set("exits", ([
                "east" : __DIR__"dongdajie2",
                "south" : __DIR__"zahuopu",
                "west" : __DIR__"guangchang",
                "north" : __DIR__"shuyuan",
              "southeast" : "/newjob/tiejiang/datiechang",
        ]));
        set("objects", ([
                __DIR__"npc/xunbu" : 1,
        ]));

        set("cost", 1);
        setup();
}


void init()
{
        if(query("exitopen"))
        {
                write(HIY"��ڤ��ʩ�����벻Ҫ�� SOUTHEAST��\n Scatter '2002\n"NOR);
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

        set("exits/southeast", "/newjob/tiejiang/datiechang");
                set("exitopen", 1);
        message_vision("$N����ָ���һ�㣬֨��һ������һ�����š�\n", this_player());

        return 1;
}

int do_close_men()
{
        if (!query("exits/southeast"))
                  return notify_fail("�������Ѿ��ǹ��ϵġ�\n");

        delete("exits/southeast");
        message("vision", "���������ع����ˡ�\n", this_object());
                delete("exitopen");
        return 1;
}
