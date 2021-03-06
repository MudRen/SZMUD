// pin.c 小颦
// Long, 6/13/97

#include <ansi.h>
inherit NPC;

void greeting(object);


void create()
{
        set_name("小颦", ({ "xiao pin", "pin"}));
        set("long", "她是个年龄不大的小女孩，但已出落得很标致了。\n");
        set("gender", "女性");
        set("age", 14);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("race", "人类");    
        set("max_qi", 150);
        set("eff_qi", 150);
        set("qi", 150);
        set("max_jing", 150);
        set("eff_jing", 150);
        set("jing", 150);
        set("max_neili", 150);
        set("eff_neili", 150);
        set("neili", 150);
        set("max_jingli", 150);
        set("eff_jingli", 150);
        set("jingli", 150);
        set("combat_exp", 1000);
        set("score", 1000);

        set_skill("force", 5);
        set_skill("dodge", 5);
        set_skill("parry", 5);
        set_skill("cuff", 5);
        set_skill("sword", 5);
        
		set("inquiry", ([
			"all"   :  "孙婆婆教我做会了好多菜呐，想尝尝吗？\n",
					 ]));
        setup();
         carry_object("/kungfu/class/gumu/obj/white_silk")->wear();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{       command("bow " + me->query("id"));
        command("say 你如果要些吃的或喝的只要叫我一声"+HBRED+HIW"(serve)"NOR+"。");
}
