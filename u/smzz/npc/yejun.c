// Code of ShenZhou
// yejun.c 叶俊

#include <ansi.h>
inherit NPC;
int learn_message(object ob,string skill); 
#include "/kungfu/class/quanzhen/auto_perform.h" 
string ask_zhang();
void create()

{
set_name(HIM"叶俊"NOR, ({ "yejun", "jun" })); 
set("nickname", HIR "办公室打字员" NOR); 
	set("gender", "男性");
	set("age", 19);
set("long", "他就是叶俊-沙漠之子的同事,这个大色狼,女孩小心哦。\n");
	
set("combat_exp", 2000000);
	set("shen_type", -1);

	set("attitude", "heroism");
	
	set_skill("unarmed", 20);
set("max_qi", 6500); 
set("eff_jingli", 9000);
set("max_neili", 60000);
set("neili", 60000); 
set("qi", 6500);  
set("jing", 4000);
set("jingli", 4000);
set("max_jing",4000);
set("jiali", 100);
set_skill("force", 550);
set_skill("sword", 550);
set_skill("quanzhen-jian", 550);
set_skill("xiantian-gong", 550);
set_skill("jinyangong", 550);
set_skill("parry", 550);
set_skill("cuff", 550);
set_skill("kick", 550);
set_skill("strike", 550);
set_skill("sanhua-juding", 550);
set_skill("chunyang-quan", 550);
map_skill("force", "xiantian-gong"); 
map_skill("dodge","jinyangong"); 
map_skill("sword","quanzhen-jian"); 
map_skill("cuff","chunyang-quan"); 
map_skill("strike","sanhua-juding"); 
prepare_skill("cuff", "chunyang-quan"); 
prepare_skill("strike", "sanhua-juding"); 
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

set("chat_chance", 50);
set("chat_msg", ({ 
(: auto_perform :), 
"叶俊说道：巫师们生活不知道过的怎么样了。\n", 
"叶俊说道: 你可以问我smzz然后根据有颜色的字符问我,到时就好东东你会高心的哦!\n",
"叶俊说道: 我其实是沙漠之子的同事我们一起侠客行,他现在把我放在这里好狠心哦!\n",
"叶俊说道: 你们哪个看见他了?\n",
"叶俊说道: 我真的不知道沙漠之子在干什么,难道那么忙吗?\n",
}) ); 
	setup();
	carry_object("/clone/misc/cloth")->wear();
set("inquiry", ([ 
"smzz":"他就是我的"HIW"老板"NOR",他现在不在我可以帮你干点什么吗?\n",
"老板":"老板就是smzz撒,不是说了吗?他是个"HIM"黄梅戏"NOR"演员和我一样\n",
"黄梅戏":"我和沙漠之子都是唱黄梅戏的哦!你要听吗?我可以给你"HIY"唱一段"NOR",让你解解闷,来这里就是开心的是吗?\n",
"唱一段":"树上的鸟儿成双队,绿水青山带笑颜,好听吗?这是著名的黄梅戏天仙配选段,"HIW"再唱一段"NOR"吗?\n",
"再唱一段":"你当我是机器人那?我的嗓子是肉长的耶,你给买一包"HIM"金嗓子"NOR"喉宝我就唱\n" 
]));
carry_object("/d/city/obj/changjian")->wield(); 
}
