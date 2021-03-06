// NPC: /d/jueqing/npc/zhang.c
// jiuer 09/2001

// Please don't move this npc from the local site.
// Please use call_out if npc disappearred.
// Zhang is a quest npc.

#include <ansi.h>  
inherit NPC;
void destroying(object, object);
string ask_key();

private string *homes_locations = ({
	"/d/jueqing/dating",
	"/d/jueqing/chufang",
	"/d/jueqing/shishi1",
	"/d/jueiqng/danfang",
});

void create()
{
	set_name("张二叔", ({ "zhang ershu","zhang" }));
	set("long","一个忠诚老实的老仆人\n");
	set("title", "管家");
	set("age", 50);
	set("gender","男性");
	set("attitude","peaceful");
	
	set("str", 22);
	set("dex", 22);

	set("shen_type",0);
	set("combat_exp", 50000);
	set("no_get_from", 1);
    
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("force",60);
	set_skill("parry",60);
	set_skill("strike",60);
	set_skill("throwing",60);
	
	    //set("qi", 3000);
        set("max_qi", 3000);
	//	set("jing", 3000);
        set("max_jing", 3000);
	//	set("jingli", 3000);
     //   set("max_jingli", 3000);
	//	set("neili",3000);
	//	set("max_neili",3000);

        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

	set("chat_chance",30);
	set("chat_msg", ({
		"张二叔快步走了过来，神色紧张地环视着四周。\n",
			(: random_move :)
	}) );
   
	set("inquiry", ([
		"all" : "我在这谷里三十年啦，娃儿要问什么就问吧。\n",
		"裘千尺" : "那是我的主母呀！ 她死了好多年了。\n",
		"公孙止" : "我家庄主的名字也是你叫的？没规矩。\n",
		"公孙绿萼" : "我家小姐从小没了娘，是我一手拉扯大的。\n",
		"key" : "没我家主人的手令，这钥匙不能给你。\n",
		"钥匙" : "没我家主人的手令，这钥匙不能给你。\n",
		"贿赂" : "嘿嘿，您这是从何说起呐？\n",
		"灵芝" : "听说主人的芝房里藏着宝贝。\n",
		"手令" : "我们下人一向依庄主手令行事。\n",
		"庄主" : "这水仙山庄属我家庄主公孙止所有。\n",
		]));
	
	set("stay_chance", 1);
	setup();
	
        carry_object("/d/jueqing/npc/obj/greenrobe")->wear();
	carry_object("/d/jueqing/obj/ciping");
}

private void go_home()
{
        if( !living(this_object()) ) return;
        message_vision("$N快步走了过来。\n$N慌张地离开了。\n", this_object());
		this_object()->move(homes_locations[random(sizeof(homes_locations))]);
		message_vision("$N快步走了过来。\n", this_object());
}
void init()
{
        if( strsrch(file_name(environment()), "/d/jueqing/") == -1 ) {
                remove_call_out("go_home");
                call_out("go_home", 1);
                return;
		}
}
int accept_object(object me, object obj)
{
	object key;
	if ((string)obj->query("id")=="shou ling") 
	{
		message("vision",me->name()+"给张二叔一卷手令。\n",environment(me),
			({me}));
        command("bow "+me->query("id"));
        command("say " + RANK_D->query_respect(me) + 
			"既然有庄主的手令，那我就给你芝房钥匙。");
        
                key = new("/d/jueqing/npc/obj/zfkey");
        key->move(me);
        
		message_vision("$n递给$N一把钥匙。\n", me, this_object() );
        remove_call_out("destroying");
        call_out("destroying", 1, this_object(), obj);
        return 1;
	}
		return notify_fail("没我家主人的手令，这钥匙不能给你。\n");
}
void destroying(object me,object obj)
{
        destruct(obj);
        return;
}
int accept_kill(object me)
{
	command("say 光天化日之下竟敢行凶杀人，没王法了吗？\n");
	kill_ob(me);
	return 1;
}
