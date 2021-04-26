//rama.c

inherit NPC;

#include <ansi.h>

void create()
{
        set_name("朱格亮",({"zhu geliang","zhu"}) );
        set("long","一个傻傻的打工仔。\n");
        set("title","售票伙计");
        set("gender","男性");
        set("age",20);
        set("combat_exp",100);
        set("inquiry",([
                "票" : "比武大会选票五两白银一张。",
                "piao" : "比武大会选票五两白银一张。",
                "比武大会选票" : "比武大会选票五两白银一张。",
                "选票" : "比武大会选票五两白银一张。",
                
                ]) );
        setup();
}


int accept_object(object who,object ob)
{
        object obj,ob2;
        
        if( present("xuan piao",who) || who->query("ask/piao",1) )
        {
                tell_object(who,"朱格亮笑道：“给钱我就拿着，不过票是不能再给你了。”\n");
                return 1;
        }
                        
        if( who->query("age") < 15)
        {
                command("heihei");
                tell_object(who,"朱格亮面有难色道：“布武老大交代，不许你们这种年纪买选票。\n");
                return 0;
        }
                        
        if( ob->query("money_id") && ob->value() < 50)
                return notify_fail("朱格亮瞅了你一眼道：“这么点钱能买到什么啊？”\n");
                
        if( ob->query("money_id") && ob->value() >= 50)
        {
                tell_object(who,"朱格亮脸上乐开了花，连忙递上票：“您老的票。”\n");
                tell_object(who,"朱格亮给了你一张比武大会的选票。\n");
                obj=new("/u/rama/obj/piao");
                obj->move(who);
                who->set("ask/piao",1);
                destruct(ob);
                this_object()->add("balance",50);
                return 1;
        }
        if( !ob->query("money_id"))
                return notify_fail("朱格亮接过"+ob->query("name")+"来细细的看了看，还用手指敲了敲然后还给了你,显然是不识货。\n");
}
int accept_kill(object me)
{
        tell_object(me,"朱格亮大叫一声：“别动我！我有老大罩着！”\n");
        return 0;
}
void accept_fight(object me)
{
        tell_object(me,"朱格亮眼睛一瞪：“我才没空和你胡闹呢！”\n");
        return;
}
        
        
                
        
        
        
