//  /d/chengdu/shanlu.c 

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","ɽ·");
        set("long",@LONG 
�����Ǵ��ؽ��紦������һЩǿ���ڴ˳�û������ǰ���ǽ��ص�����ˡ�
һЩ���������ö������У������ڴ˵ؾ�����
LONG);
        set("exits",([
                "southeast" : __DIR__"tulu1",
                "northup": __DIR__"shanlu"

        ]));
        set("outdoors", "xueshan");
        set("cost", 2);
        setup();
}
void init()
{
        object ob, robber, *inv, me=this_player();
        int i, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("value") >= 10000
                && !inv[i]->query("money_id")) j++;
        }
        if (j>0) me->set_temp("rob_victim", 1);

        if ( interactive(ob=this_player()) && ob->query_temp("biao/ma")
        && present("hong biao", ob) && random(5)==1
        || me->query_temp("rob_victim") && random(3)==1) {
                message_vision(HIR"ֻ����һ�󲥲�����һ��ǿ����·�����˳�����ס$N��\n"NOR, ob);
                robber = new(__DIR__"npc/qiangdao");
                robber->move(environment(ob));
        }
}

int valid_leave(object me, string dir)
{
        if ( me->query_temp("biao/li") && present("cao kou", environment(me)) 
        || me->query_temp("rob_victim") && present("cao kou", environment(me)))
                return notify_fail("ǿ������һ����Ц��ˬ��Ľ���������������Ȼ������Ī����\n");
        else { me->delete_temp("rob_victim"); }

        return ::valid_leave(me, dir);
}


