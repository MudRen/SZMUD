// Filename:  gongsun lve 公孙绿萼
// path:      /kungfu/class/jueqinggu/npc/gongsunle.c
// By jiuer-> 08/2001

#include <ansi.h>
inherit NPC;
void greeting(object);

void create()
{
	set_name("公孙绿萼", ({ "gongsun lue", "gongsun", "lue" }));
	set("long",
		"她就是绝情谷水仙庄庄主的女儿。\n\n"
		+"只见她肤色白里泛红，娇嫩异常，眉目清雅，眼神清澈，嘴边有粒小小黑痣，甚是娇美。\n\n");

	set("gender", "女性" );
	set("age", 17);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("inquiry", ([
		"name" : "「那我可不知道啦。我爹爹曾给他的独生女儿取个名字，叫做绿萼。」\n",
		"here" : "这庄叫「水仙山庄」，这谷叫做「绝情谷」。\n",
		"水仙山庄" : "这山庄可好玩呐，除了我爹爹和我，这里还有情花。\n",
		"爹爹" : "我爹爹是公孙止。\n",
		"公孙止" : "那是我爹爹。\n",
		"娘" : "我娘嘛，江湖人称「铁掌莲花裘千尺」。\n",
		"裘千尺" : "自我六岁那年娘就死了，说着流下了两滴泪水。\n",
		"情花"   : "情花的刺上有毒，人动了情欲之念，立时痛不可当，只有绝情丹能治得好。\n",
		"绝情丹" : "那是我绝情谷中世代相传，解救情花之毒的丹药。我娘收藏的紧。\n",
		"绝情谷" : "这绝情谷可大着哪，不知有多少人进去就没出来啦。\n",
		"龙女花" : "这龙女花是我杨大哥当年送给小龙儿姑娘的。\n",
	]));

	set("combat_exp", 100000); 
	set("per", 28); 
	set("str", 22); 
	set("int", 28);
	set("con", 25);

	set("chat_chance",1);
	set("chat_msg", ({
			"绿萼从树上摘下两朵情花，放入袋中。\n",
			"绿萼站在情花树下，垂下了头呆呆出神，随着一声叹息，一滴眼泪悄悄落下来。\n",
	}) );

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("jiajin", 10);
	set("jiali", 10);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jingli",1000);
	set("eff_jingli",1000);
	set("max_jingli",1000);

	set_skill("force", 100); 
	set_skill("blade", 100);
	set_skill("dodge", 100); 
	set_skill("parry", 100);
	set_skill("sword", 100);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	setup(); 
	
	carry_object("/d/jueqing/npc/obj/greenrobe")->wear(); 
	carry_object("/d/jueqing/npc/obj/pihuwan")->wear(); 
	carry_object("/d/city/obj/changjian")->wield();
}

void init()
{
	object ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	       {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
}

void greeting(object ob)
{
	if(!ob || environment(ob) != environment())
		return;
	say("绿萼说道: 「这谷里戒备森严，你怎么闯进来了？快快离去吧！」\n");
}

int accept_object(object me, object ob)
{
	object obn;

	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, me) ) return notify_fail("你没有这件东西。\n");

	if (  (string)ob->query("id") != "longnu hua")
		return notify_fail("绿萼不需要这件东西。\n");
	
	if(this_object()->query("longhua"))
	{
		command("say 「这花儿献多了就俗了，你还是快去找我娘吧。」\n");
		command("drop hua");
		return 1;
	}
	set("longhua",1);       
	write( HIY "绿萼双手捧着龙女花，泪如雨下：\n
   「杨大哥，您是不是还记挂着绿萼啊！~~呜~~」\n\n" NOR );

	message_vision( HIY "绿萼抹了把眼泪，不好意思笑笑说：「这位"
	+RANK_D->query_respect(me)+"见笑了。\n
我也没什么东西给你，当年我和杨大哥身陷绝情谷，这几样物件你带上。」\n\n" NOR, me);

    message_vision("绿萼从腰里解下一个荷包，从里面取出一把匕首和一卷羊皮递给了$N。\n", me);
	command("whisper "+me->query("id")+" 「照着地图走，见到我娘把图给她」。");
	
	obn = new("/d/jueqing/npc/obj/tu");
	obn->set_amount(1);
	obn->move(me);
    obn = new("/d/jueqing/npc/obj/bishou");
	obn->set_amount(1);
	obn->move(me);
      return 1;
}