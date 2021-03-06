// Code of ShenZhou
// gargoyle.c  白无常
// snowlf change by 2000/12/05

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;
int ask_death();

string *death_msg = ({
	HIW "白无常说道：喂！新来的，你叫什么名字？\n\n" NOR,
	HIW "白无常用奇异的眼光盯著你，好像要看穿你的一切似的。\n\n" NOR,
	HIW "白无常「哼」的一声，从袖中掏出一本像帐册的东西翻看著。\n\n" NOR,
	HIW "白无常合上册子，说道：咦？阳寿未尽？怎么可能？\n\n" NOR,
	HIW "白无常搔了搔头，叹道：罢了罢了，你走吧。\n\n"
		"一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
});

void create()
{
	set_name("白无常", ({ "white gargoyle", "gargoyle", "wuchang", "bai wuchang" }) );
	set("long",
		"白无常伸著长长的舌头瞪著你，死白的脸上看不出任何喜怒哀乐。\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	
	set("chat_msg", ({
//		(: this_object(), "random_move" :),
		"白无常发出一阵像呻吟的声音，当他发现你正注视著他的时候，瞪了你一眼。\n",
		"白无常把长长的舌头伸出来，缓缓地舔了舔自己又白又长的手指。\n"
	}) );
	set("age", 217);
	set("combat_exp", 20000);
	set("max_jing", 900);
	set("max_jingli", 900);
	set("max_qi", 900);
	set("max_neili", 900);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
        set("inquiry", ([
        
            "多死一次" : (: ask_death :),
            "再死一次" : (: ask_death :),
            "死一次" : (: ask_death :),
            "death" : (: ask_death :),
            "again death" : (: ask_death :),
        ]));

	setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object())
	||	wizardp(previous_object()) ) return;
	call_out( "death_stage", 30, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	int i;
	object *inv;
	if( !ob || !present(ob) ) return;

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();

        inv =  all_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
                DROP_CMD->do_drop(ob, inv[i]);
	if(ob->query("xkd/set", 1)) ob->move("/d/xiakedao/shatan");
	else ob->move(REVIVE_ROOM);
	message("vision",
		"你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
		"很久了，只是你一直没发觉。\n", environment(ob), ob);
	return;
}


int ask_death() 
{
        object me = this_player();
	object ob;
	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");
	
        command("say 这无缘无故多死一次可不是小事！");
        command("consider");	
        command("say 你不但会损失最多5000 的江湖经验，并且你的每项武功都还会降半级。");
        command("say 你可要好好想想！如果想好了，就输入你的保密密码吧！");
        
//       tell_object(me,HIR"这无故多死一次可不是小事，你不但会损失最多5000 的江湖经验，并且你的每项武功都还会降半级，你可要好好想想！\n");
//       tell_object(me,"如果想好了，就输入你的保密密码："NOR);      
        input_to("again_death", 1, ob);
	return 1;
}


private void again_death(string pass, object ob)
{
	object me = this_player();
	string old_pass;

	write("\n");
        old_pass = ob->query("check_password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("密码错误，你不能无缘无故多死一次！\n");
		return;
	}
	
	write("白无常摇了摇头，叹了口气道："+HIC+"你即然执意要无故多死一次，那就只好成全你了！\n"NOR);
	me -> die();
	return;
}

