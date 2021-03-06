// Code of ShenZhou
// zhucong.c   江南七怪 朱聪

#include <ansi.h>

inherit NPC;

int improve_gbskill(string arg);
int do_steal(string);

void create()
{
	set_name("朱聪", ({"zhu cong", "zhu"}));
	set("title", "江南七怪  老二");
	set("nickname", "妙手书生");
	set("gender", "男性");
	set("age", 35);
	set("long", "
一个中年的穷酸士人，穿着斯文的书生长衫，却拖着鞋皮，啼嗒啼嗒
的直响，一路走一路打着哈欠。此人似笑非笑，挤眉弄眼，一副惫懒
神气，全身油腻，衣冠不整，满面污垢，看来少说也有十多天没洗澡
了，拿着一柄破烂的油纸黑扇，边摇边行。\n");
	
	set("attitude", "peaceful");
	
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 3);
	set("chat_msg", ({
		"朱聪摇头摆脑的吟道：“不义之财……放他过，……玉皇大帝……发脾气！”\n",
	}));

	set("inquiry", ([
		"江南七怪" : "我就是七怪里的老二，你找我们有什么事儿吗？\n",
	]));


	set("qi", 800);
	set("max_qi", 800);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 60);
	
	set("combat_exp", 200000);
	 
	set_skill("force", 80);
	set_skill("huntian-qigong", 80);
	set_skill("hand", 100);
	set_skill("shexing-diaoshou", 100);
	set_skill("dodge", 100);
	set_skill("xiaoyaoyou", 100);
	set_skill("parry", 80);
	set_skill("stealing", 200);  
	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "shexing-diaoshou");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "shexing-diaoshou");

	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	set_heart_beat(1);

	add_action("do_steal", "steal");
}

int do_steal(string arg)
{
	object me=this_object(), who=this_player();
	string a,b,c;
	if (!arg || sscanf(arg, "%s %s %s", a, b, c) != 3 ) return 0;
	if ( !who->query_temp("stealing") && b=="from" && (c=="zhu cong" || c=="zhu")) {
        tell_object(who, "你不动声色地慢慢靠近朱聪，等待机会下手 ...\n\n");
		who->set_temp("stealing",1);
		remove_call_out("stealzhu");
		call_out("stealzhu",3, me,who);
		return 1;
	}
	return 0;
}

int stealzhu(object me, object who)
{
	who->delete_temp("stealing",1);
	if (present(who,environment(me))) {
		who->add_temp("stealzhu", 1);
		if (who->query_temp("stealzhu")>5) {
			if (who->query("kar")>(10+random(15)) && random(4)!=0) {
				command("hehehe "+who->query("id"));
				command("say "+RANK_D->query_rude(who)+"偷瘾这么重？跟老子倒是颇有同病，不如我们交个朋友，切蹉切蹉偷技吧。");
				command("hehe zhu cong");
				who->add("jn7g/jiaoqing",1);
				who->delete_temp("stealzhu");
				return 1;
			}
			else {
				command("killair "+who->query("id"));
				command("say 老虎不发威，"+RANK_D->query_rude(who)+"你把我当病猫！");
				who->delete_temp("stealzhu");
				me->kill_ob(who);
				return 1;
			}
		}
		if (who->query_temp("stealzhu")>2) {
			message_vision("$N一回头，一把捉住了$n的手，哈哈大笑道：“"+RANK_D->query_rude(who)+"手痒痒偷到祖师爷头上来了，快滚你的吧。\n",me,who);
			command("killair "+who->query("id"));
			message_vision("$N怒气冲冲地对$n说道：“"+RANK_D->query_rude(who)+"一而再，再而三地跟老子捣乱，再来一次老子就不客气了！\n",me,who);
		}
	}
	return 1;
}