//  /d/chengdu/shanlu.c 

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","山路");
        set("long",@LONG 
这里是川藏交界处，常有一些强盗在此出没，再往前就是进藏的驿道了。
一些来往的商旅都搭伴而行，不敢在此地久留。
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
                message_vision(HIR"只听得一阵播草声，一个强盗自路边跳了出来拦住$N。\n"NOR, ob);
                robber = new(__DIR__"npc/qiangdao");
                robber->move(environment(ob));
        }
}

int valid_leave(object me, string dir)
{
        if ( me->query_temp("biao/li") && present("cao kou", environment(me)) 
        || me->query_temp("rob_victim") && present("cao kou", environment(me)))
                return notify_fail("强盗向你一阵阴笑：爽快的将宝贝交出来，不然叫你后悔莫及！\n");
        else { me->delete_temp("rob_victim"); }

        return ::valid_leave(me, dir);
}


