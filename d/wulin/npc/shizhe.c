
// NPC /d/wulin/npc/shizhe.c 侍者
//Piao 2001/10/17
#include <ansi.h>

inherit NPC;
void create()
{
	set_name("侍者", ({ "shi zhe"}) );
	set("gender", "男性");
	set("age", 15);
	set("long",
		"这位是饕餮楼的侍者。\n");
        setup();
}
int accept_object(object me, object obj)
{
      if(obj->name() == "请柬") {
                command("bow "+me->query("id"));
                message_vision(CYN"侍者说道："+RANK_D->query_respect(me)+"原来阁下是仙人的朋友, 快上楼享用仙果吧。\n"NOR,me);
                me->set_temp("guibinshi",1);
                call_out("destroy_it",1,obj);
                return 1;
	}
       	return 0;
}
void destroy_it(object obj)
{
        destruct(obj);
}

