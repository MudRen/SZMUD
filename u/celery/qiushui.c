//Cracked by Roath
// liumang.c 流氓

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIG"萧秋水"NOR, ({ "xiao qiushui", "qiushui", "xiao" }));
	set("gender", "男性");
	set("age", 26);
	set("long", "他就是伊斯第一大法师——萧秋水，现在在守护着爱妻蓝色飞羽的房间。\n");
	set("title", "伊斯第一大法师");
	set("nickname", "大肚皮");
	
	set("combat_exp", 1000);
	set("shen_type", -1);
	
	set("attitude", "heroism");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
