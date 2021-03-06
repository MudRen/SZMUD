// Code of ShenZhou
// /d/huanghe/changle/npc/shijian.c 侍剑
// by aln 2 / 98

#include <ansi.h>
inherit NPC;

string ask_shi();
string ask_niren();

void create()
{
	set_name("侍剑", ({ "shijian" }));
	set("long", 
"她是长乐帮主的小丫鬟，脸庞略作圆形，倒也妩媚可喜。\n"
"她头发略见蓬松，雪白的赤足踏在一双绣花拖鞋中。\n");
	set("gender", "女性");
	set("age", 16);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 20);
   
	set("max_qi", 500);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 10);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 40);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 20);

        set("inquiry", ([
                "石破天" : (: ask_shi :),
                "少爷" : (: ask_shi :),
                "泥人儿" : (: ask_niren :),
        ]));
	setup();
	carry_object("/d/city/obj/pink_cloth")->wear();
}
string ask_shi()
{
	this_player()->set_temp("ask_shi",1);
	
        return "我以前伺候过石破天少爷，他是一个怪人。他还有一套泥人儿留在这里呢，都是些没穿衣服的玩偶。\n";
}

string ask_niren()
{	object me=this_player();
	object *obs , ob;
	
	if (me->query_temp("ask_shi") != 1)
		return "你忽然问我这个干吗呀？\n";
		
	if (!stringp (this_player()->query_temp("bangs/pos")))  
		return "我不能告诉你，除非是帮主和香主们来问才能说的。\n";
		
	obs = filter_array(children("/d/huanghe/obj/niren.c"), (: clonep :)); 
	
	if (sizeof(obs) > 0) 
                return "那套泥人儿我已经给本帮的香主了。\n";
		
	ob = new("/d/huanghe/obj/niren");
	ob->move(me);
        message_vision(CYN"$N说道：您是不是要那套泥人呀，我马上给你去拿。\n"NOR,this_object());
        message_vision("$N在柜子里搜索了一阵，拿出了一个大盒子，里面装着一套泥制玩偶。\n",this_object());
        message_vision("$N递给你一套泥制玩偶。\n",this_object());
                 CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到一套泥制玩偶。", me->query("name")));

	return "这就是石少爷的泥人儿，您收好了。\n";
}

	


		
	



