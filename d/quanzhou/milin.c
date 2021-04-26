// Code of ShenZhou
// /d/shenlong/milin.c ����
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������Դɽ�����һƬ���֡������ľïʢ��������գ�������
������·�����ƺ�����һ��֨֨�������������һȺ�����ڸ�����ˣ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "northdown": "/d/quanzhou/wangzhou",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "quanzhou");
        set("cost", 2);
        setup();
}

void init()
{
        object me = this_player();

        if( interactive(me) && ! present("old monkey", this_object()) 
         && !random(2) && time() > (int)query("lastshow") + 600
         && (int)me->query("combat_exp") < 100000 ) {
                remove_call_out("monkeyshowup");
                call_out("monkeyshowup", 5 + random(5));
         }
}

void monkeyshowup()
{
        object ob;

        ob = new("/clone/beast/bmonkey");
        ob->move(this_object());
        set("lastshow", time());
        message_vision("ֻ��һֻ�Ϻ��Ӵ�ҡ��ڵ����˹�����\n", ob);

        remove_call_out("monkeydisappear");
        call_out("monkeydisappear", 20 + random(10), ob);
}

void monkeydisappear(object ob)
{
        if( !ob ) return;

        if( !living(ob) || ob->is_busy() || random(3) > 0 ) {
                remove_call_out("monkeydisappear");
                call_out("monkeydisappear", 5 + random(5), ob);
                return;
        }

        message("vision", "ֻ���Ϻ��ӷɿ�������ˡ�\n", this_object());
        destruct(ob);
}
