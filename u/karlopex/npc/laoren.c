/***************************************************************************
[19] 我的第一个npc描述                        闪烁(spark)(Wed May 29)
----------------------------------------------------------------------
l laoren
这是一个须发皆白的老人。衣着简朴，面目慈祥。他靠着石碑安静地坐着。

ask laoren about all
老人叹了一口气，慢慢地说：想知道这里的什么呢？（here、风云人物、神州巨变、江湖沧桑、石碑、老人）

ask laoren about here
你向老人打听有关『here』的消息。
老人说道：这里是神州的历史博物馆。

ask laoren about 风云人物
老人微微一笑，说道：所谓风云，风吹云动，风止云散。看开些吧。

ask laoren about 神州巨变
老人停了一停，说道：神仙们的努力不息，人世间的变幻莫测，谁又说得好呢？

ask laoren about 江湖沧桑
老人似乎看着远方，淡淡地说：一入江湖岁月催。去问那些江湖中人的感受吧。

ask laoren about 石碑
老人看看石碑，沉默了一会儿，说道：功过自在人心啊。

ask laoren about 老人
老人缓缓转头看了看你，露出一丝微笑：我只是个看客，看着看着就沧桑千年了。



谢谢lisser 
    :)
*******************************************************************************/
//create by Karlopex@sz
//送给spark做个小礼物。
#include <ansi.h>
inherit NPC;
#include "/newjob/doctor/list.h"
string ask_maple();
string ask_sword();
void create()
{
        set_name("无名老人", ({ "wuming laoren", "laoren", "oldman"}));
        set("long", "这是一个须发皆白的老人。衣着简朴，面目慈祥。他靠着石碑安静地坐着。\n");
        set("gender", "男性");
        set("age", 1000);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 100);
        set("con", 50);
        set("dex", 50);
        set("kar", 30);
        set("per", 30);

        set("max_qi", 10000);
        set("max_jing", 6000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 100);
        set("score", 5000);

        setup();
        carry_object("/d/city/obj/cloth")->wear();
}
void init()
{
        add_action("do_ask","ask");
}
int do_ask(string arg)
{
        object me = this_player(), ob;
        string dest, topic;
        if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
                return notify_fail("你要问谁什么事？\n");

        if( !objectp(ob = present(dest, environment(me))) )
                return notify_fail("这里没有这个人。\n");
                
        if( ob == this_object())
        { 
                if ( topic == "all" ){
	                message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);
                        command("sigh");
                        message_vision(WHT"$N慢慢说道：想知道这里的什么呢？（here、风云人物、神州巨变、江湖沧桑、石碑、老人）\n"NOR, this_object());
                }else if ( topic == "here" ){
	                message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);
                        command("hehe");
                        message_vision(WHT"$N说道：这里是神州的历史博物馆。\n"NOR, this_object());
                }else if ( topic == "风云人物" ){
	                message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);
                        command("smile");
                        message_vision(WHT"$N说道：所谓风云，风吹云动，风止云散。看开些吧。\n"NOR, this_object());
                }else if ( topic == "神州巨变"){                                        
	                message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);
	                 message_vision(WHT"$N停了一停，说道：神仙们的努力不息，人世间的变幻莫测，谁又说得好呢？\n"NOR, this_object()); 
                }else if ( topic == "江湖沧桑" ){                       
	                message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);
                        command("idle2");
                        message_vision(WHT"$N淡淡地说：一入江湖岁月催。去问那些江湖中人的感受吧。\n"NOR, this_object());
                }else if ( topic == "石碑" ){                   
	                message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);
                        message_vision(WHT"$N看看石碑，沉默了一会儿，说道：功过自在人心啊。\n"NOR, this_object());
                }else if ( topic == "老人" ){                   
	                message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);
                        message_vision(WHT"$N缓缓转头看了看你，露出一丝微笑：我只是个看客，看着看着就沧桑千年了。\n"NOR, this_object());
                }else return "/cmds/std/ask.c"->main(me, arg);
                return 1;
        }
        return "/cmds/std/ask.c"->main(me, arg);
}
