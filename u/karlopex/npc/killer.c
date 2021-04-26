//Cracked by Roath
// npc: /d/city/npc/ftb_killer.c
// Chu 2/10/99

#include <ansi.h>
inherit NPC;
#include "name.h"

string ask_cike();
string ask_move();

void create()
{
	if (random(10) == 5){
	        set_random_name("女性");
	        set("gender", "女性" );
	}else{
	        set_random_name("");
	        set("gender", "男性" );
	}
        set("title", "无聊的随机ＮＰＣ" );
        set("long", "我是刺客，如果想知道什么的话请ask me about all\n" );
        set("age", 32);
        set("str", 23);
        set("dex", 30);
        set("con", 23);
        set("int", 23);
        set("shen_type", -1);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);

        set("no_refresh", 1);

        setup();
/*        set("inquiry", ([
		"all" : "我可以告诉你有关\n【"+this_player()->name(1)+"、"+this_player()->query("id")+"、kill me ?、杀我？、刺客、cike】的事情。\n",
		this_player()->name(1) : "你可知道"+this_player()->name(1)+"的所在吗？\n",
		this_player()->query("id") : "你可知道"+this_player()->name(1)+"的所在吗？\n",
		"kill me ?" : (: ask_move :),
		"杀我？" : (: ask_move :),
		"刺客" : (: ask_cike :),
		"cike" : (: ask_cike :),
        ]));*/
        carry_object("/clone/armor/beixin")->wear();
        remove_call_out("self_destruct");
        call_out("self_destruct", 1200);

}
void init()
{
	add_action("do_ask","ask");
}
int do_ask(string arg)
{
	object me = this_player();
	string dest, topic;
	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("你要问谁什么事？\n");
	else{ 
		delete("inquiry");
	        set("inquiry", ([
			"all" : "我可以告诉你有关\n【"+me->name(1)+"、"+this_player()->query("id")+"、kill me ?、杀我？、刺客、cike】的事情。\n",
			me->name(1) : "你可知道"+me->name(1)+"的所在吗？\n",
			me->query("id") : "你可知道"+me->name(1)+"的所在吗？\n",
			"kill me ?" : (: ask_move :),
			"杀我？" : (: ask_move :),
			"刺客" : (: ask_cike :),
			"cike" : (: ask_cike :),
	        ]));
		return "/cmds/std/ask.c"->main(me, arg);
        }
}
void self_destruct() {
    object me = this_object();
    message("vision", name(1)+"说道：“只有鬼才知道我要暗杀的目标在哪里？”\n说完急急忙忙地离开了。\n", environment(me), me);
    destruct(me);
}

string ask_cike() 
{
	if (random(100) < 10)
		return "我怎么觉得你倒像是个杀手呢？";
	else return "别开玩笑，这里太平得很，哪里有刺客？";
}

string ask_move()
{
	object player, room;
	mapping exits;
	string  *dirs;
	
	player = this_player();
	if (random(100) < 10)  {
		room = environment(this_object());
		exits = room->query("exits");
		dirs = keys(exits);
		command("!!! ");
		command("go "+dirs[random(sizeof(dirs))]);
		return this_player()->name(1)+"大侠，你别。。。别杀我！";
	}else return "不可能，你决不会是"+this_player()->name(1)+"吧？";
}
